#include "datastate.h"
#include <QDebug>
#include <QDateTime>

DataState::DataState(QObject *parent) :
    QObject(parent)
{
    initDataState();
}

void DataState::initDataState(){
    myInOutConnection = new InOutConnection();
    myDataParser = new DataParser();

    //WARNIG THIS SHOULD NOT BE HERE
    initDB();
    addErrori(1,true);

    qDebug() << QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    myTEMP = 0;
    myPH = 0;
    myLEVEL = 0;
    myLIGHT = 0.0;
    myLIGHTFUTURE = false;
    myFANS = false;
    myPOTASSIUM = false;
    myCO2 = false;

    connect(myInOutConnection, SIGNAL(dataReady()),this,SLOT(updateDataState()));
}

void DataState::updateDataState(){
    fromINOUTDATA();
    updateDATABASE();
    emit readyDataState();
}

void DataState::getDataState(){
    myInOutConnection->requestINOUTdata();
}

void DataState::sendDataState(){
    toINOUTDATAtosend();
    myInOutConnection->sendINOUTdata();
}

void DataState::updateDATABASE(){
    toDATABASE();
}


void DataState::fromINOUTDATA(){
    myPH = myDataParser->unpackPH(myInOutConnection->myINOUTDATA->AdcCh1);
    myTEMP = myDataParser->unpackTEMP(myInOutConnection->myINOUTDATA->AdcCh2);
    myLEVEL = myDataParser->unpackLEVEL(myInOutConnection->myINOUTDATA->Echo1);
    myLIGHT = myDataParser->unpackLIGHT(myInOutConnection->myINOUTDATA->PwmCh1);
    myFANS = myDataParser->unpackFANS(myInOutConnection->myINOUTDATA->Outpins);
    myPOTASSIUM = myDataParser->unpackPOTASSIUM(myInOutConnection->myINOUTDATA->Outpins);
    myCO2 = myDataParser->unpackCO2(myInOutConnection->myINOUTDATA->Outpins);
}

void DataState::toINOUTDATAtosend(){
    myInOutConnection->myINOUTDATAtosend->PwmState = myDataParser->packLIGHTFUTURE(myLIGHTFUTURE);
    myInOutConnection->myINOUTDATAtosend->Outpins = myDataParser->packFANSPOTASSIUMCO2(myFANS,myPOTASSIUM,myCO2);
}

bool DataState::toDATABASE(){
    return addMisure(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"),
              myTEMP,myPH,myLEVEL,myLIGHT,myFANS,myPOTASSIUM,myCO2);
}
