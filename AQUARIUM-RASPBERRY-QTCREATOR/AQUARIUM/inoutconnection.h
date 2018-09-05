#ifndef INOUTCONNECTION_H
#define INOUTCONNECTION_H

#include <QUdpSocket>
#include "dbconnect.h"
#include "globals.h"
#include "file.h"

namespace Ui {
class InOutConnection;
}

class InOutConnection : public QObject
{
    Q_OBJECT

public:
    explicit InOutConnection(QObject *parent = 0);
    //------------
    //dati ricevuti
    class INOUTDATA {
    public:
        void fromQByteArray(QByteArray BytesRec);
        quint16 Inpins;
        quint16 Outpins;
        quint16 AdcCh1;
        quint16 AdcCh2;
        quint16 PwmCh1;
        quint16 PwmCh2;
        quint16 Echo1;
    };
    INOUTDATA *myINOUTDATA;
    //dati inviati
    class INOUTDATAtosend {
    public:
        QByteArray toQByteArray();
        quint16 Outpins;
        quint16 PwmState;
    };
    INOUTDATAtosend *myINOUTDATAtosend;
    //------------
public slots:
    void initInOutConnection();
    void requestVersion();
    void requestINOUTdata();
    void sendINOUTdata();
    void requestClock();

protected slots:
    void udpUpdateState();
    void initializeQUDPSocket();
    void sendData();
    void receiveData();
    void updateVersion();
    void updateINOUTdata();

signals:
    void dataReady();
    void connectionError(int errorCode);

private:
    class STATE {
    public:
        static const int NOTHING = 1;
        static const int SENDVERSION = 2;
        static const int SENDCLOCK = 3;
        static const int SENDINOUTSTATE = 4;
        static const int SENDINOUTREQUEST = 5;
        static const int WAITVERSION = 6;
        static const int WAITCLOCK = 7;
        static const int WAITINOUTSTATE = 8;
        static const int WAITINOUTREQUEST = 9;
        static const int READYVERSION = 10;
        static const int READYCLOCK = 11;
        static const int READYINOUTSTATE = 12;
        static const int READYINOUTREQUEST =13;
        static const int ERRORSEND = 14;
        static const int ERRORWAIT = 15;
        static const int DONE = 16;
    };
    int udpstate;
    int tries;
    int MAXTRIES;
    int nERRSEND;
    int nERRWAIT;
    QString StringRec;  //dati cod. ASCII
    QByteArray BytesRec; //dati cod. numeri
    QUdpSocket *socket;
    quint16 PORT;
    QHostAddress IP;
};

#endif // INOUTCONNECTION_H
