#include "inoutconnection.h"
#include <QUdpSocket>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QNetworkInterface>

InOutConnection::InOutConnection(QObject *parent) :
    QObject(parent)
{
    //WARNIG THIS SHOULD NOT BE HERE
    LOAD_GLOBALS();
    SAVE_GLOBALS();
    initInOutConnection();
}

void InOutConnection::initInOutConnection(){
    //preparo connessione QUDP
    PORT = 6789;
    qDebug()<<REMOTE_IP;
    IP.setAddress(REMOTE_IP);
    initializeQUDPSocket();

    foreach(const QHostAddress &address, QNetworkInterface::allAddresses()){
        if(address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
            LOCAL_IP = address.toString();
    }

    //preparo strutture per i dati
    myINOUTDATA = new INOUTDATA();
    myINOUTDATAtosend = new INOUTDATAtosend();

    MAXTRIES = 5;
    nERRSEND = 0;
    nERRWAIT = 0;

    //preparo macchina stati
    udpstate = STATE::NOTHING;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(udpUpdateState()));
    timer->start(100);
}

void InOutConnection::udpUpdateState(){
    QMessageBox msgBox; //DO NOT REMOVE
    switch(udpstate){
    case STATE::NOTHING: //NON DEVO FARE NULLA
        break;
    case STATE::SENDVERSION: //settato dall'utente
    case STATE::SENDINOUTSTATE:
    case STATE::SENDINOUTREQUEST:
    case STATE::SENDCLOCK:
        sendData();
        tries=0;
        break;
    case STATE::WAITVERSION: //settato da sendData()
    case STATE::WAITINOUTSTATE:
    case STATE::WAITINOUTREQUEST:
    case STATE::WAITCLOCK:
        tries++;
        if(tries>2*MAXTRIES){
            udpstate=STATE::ERRORWAIT;
            break;
        }
        if(socket->hasPendingDatagrams()){
            receiveData();
            tries=0;
        }
        break;
    case STATE::READYVERSION: //settato da receiveData()
        updateVersion();
        break;
    case STATE::READYINOUTREQUEST:
    case STATE::READYINOUTSTATE:
        updateINOUTdata();
        break;
    case STATE::READYCLOCK:
        udpstate=STATE::NOTHING;
        break;
    case STATE::ERRORSEND:
        udpstate=STATE::NOTHING;
        nERRSEND++;
        if(nERRSEND>23){
            nERRSEND = 0;
            connectionError(93);
            //addErrori(90,true);
            //addErrori(93);
        }
        break;
    case STATE::ERRORWAIT:
        udpstate=STATE::NOTHING;
        nERRWAIT++;
        if(nERRWAIT>23){
            nERRWAIT = 0;
            connectionError(91);
            //addErrori(90,true);
            //addErrori(91);
        }
        break;
    case STATE::DONE:
        udpstate=STATE::NOTHING;
        nERRSEND = 0;
        nERRWAIT = 0;
        break;
    }//TODO aggiungi >3 volte
}

void InOutConnection::initializeQUDPSocket(){
    socket = new QUdpSocket(this);
    socket->bind(IP, PORT);
}

void InOutConnection::sendData(){
    QByteArray Data;
    try{
        switch(udpstate){
        case STATE::SENDVERSION: //invio versione
            Data.append(char(1));
            Data.append(char(0));
            socket->writeDatagram(Data, Data.size(), IP, PORT);
            udpstate=STATE::WAITVERSION;
            break;
        case STATE::SENDINOUTSTATE: //invio stato
            Data.append(char(2));
            Data.append(char(0));
            Data.append(myINOUTDATAtosend->toQByteArray());
            qDebug()<<Data.toHex();
            socket->writeDatagram(Data, Data.size(), IP, PORT);
            udpstate=STATE::WAITINOUTSTATE;
            break;
        case STATE::SENDINOUTREQUEST: //invio richiesta stato
            Data.append(char(3));
            Data.append(char(0));
            socket->writeDatagram(Data, Data.size(), IP, PORT);
            udpstate=STATE::WAITINOUTREQUEST;
            break;
        case STATE::SENDCLOCK:
            break;
        }
    }
    catch (std::exception e){
        udpstate=STATE::ERRORSEND;
    }
}

void InOutConnection::receiveData(){
    QByteArray datarec;
    datarec.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;
    try{
        socket->readDatagram(datarec.data(), datarec.size(), &sender, &senderPort);
    }
    catch(std::exception e){
        udpstate=STATE::ERRORWAIT;
    }

    switch(udpstate){
    case STATE::WAITVERSION:
        StringRec = datarec;
        udpstate=STATE::READYVERSION;
        break;
    case STATE::WAITINOUTSTATE:
        if(datarec.size()==14){
            BytesRec = datarec;
            udpstate=STATE::READYINOUTSTATE;
        }
        else{
            udpstate=STATE::ERRORWAIT;
        }
        break;
    case STATE::WAITINOUTREQUEST:
        if(datarec.size()==14){
            BytesRec = datarec;
            udpstate=STATE::READYINOUTREQUEST;
        }
        else{
            udpstate=STATE::ERRORWAIT;
        }
        break;
    case STATE::WAITCLOCK:
        BytesRec = datarec;
        udpstate=STATE::READYCLOCK;
        break;
    }
}

void InOutConnection::updateVersion(){
    udpstate=STATE::DONE;
}

void InOutConnection::updateINOUTdata(){
    myINOUTDATA->fromQByteArray(BytesRec);
    udpstate=STATE::DONE;
    emit dataReady();
}

void InOutConnection::requestVersion(){
    if(udpstate==STATE::NOTHING)
        udpstate=STATE::SENDVERSION;
}

void InOutConnection::requestINOUTdata(){
    if(udpstate==STATE::NOTHING)
        udpstate=STATE::SENDINOUTREQUEST;
}

void InOutConnection::sendINOUTdata(){
    if(udpstate==STATE::NOTHING)
        udpstate=STATE::SENDINOUTSTATE;
}

void InOutConnection::requestClock(){
    if(udpstate==STATE::NOTHING)
        udpstate=STATE::SENDCLOCK;
}



//-----------------------
void InOutConnection::INOUTDATA::fromQByteArray(QByteArray BytesRec){
    qDebug()<<BytesRec.toHex();
    Inpins=BytesRec.at(0)+(BytesRec.at(1)<<8);
    Outpins=BytesRec.at(2)+(BytesRec.at(3)<<8);
    AdcCh1=BytesRec.at(4)+(BytesRec.at(5)<<8);
    AdcCh2=BytesRec.at(6)+(BytesRec.at(7)<<8);
    PwmCh1=BytesRec.at(8)+(BytesRec.at(9)<<8);
    PwmCh2=BytesRec.at(10)+(BytesRec.at(11)<<8);
    Echo1=BytesRec.at(12)+(BytesRec.at(13)<<8);
}

QByteArray InOutConnection::INOUTDATAtosend::toQByteArray(){
    QByteArray datatosend;
    datatosend.append((char)(Outpins));
    datatosend.append((char)(0));
    datatosend.append((char)(PwmState));
    datatosend.append((char)(0));
    qDebug()<<datatosend.toHex();
    return datatosend;
}
