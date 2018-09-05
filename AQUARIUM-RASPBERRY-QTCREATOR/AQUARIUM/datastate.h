#ifndef DATASTATE_H
#define DATASTATE_H

#include <QObject>
#include "dbconnect.h"
#include "inoutconnection.h"
#include "dataparser.h"

class DataState : public QObject
{
    Q_OBJECT
public:
    explicit DataState(QObject *parent = 0);
    InOutConnection* myInOutConnection;
    DataParser* myDataParser;
    float myTEMP;
    float myPH;
    quint16 myLEVEL;
    float myLIGHT;
    bool myLIGHTFUTURE;
    bool myFANS;
    bool myPOTASSIUM;
    bool myCO2;

signals:
    void readyDataState();

public slots:
    void updateDataState();
    void getDataState();
    void sendDataState();
    void updateDATABASE();

private:
    void initDataState();
    void fromINOUTDATA();
    void toINOUTDATAtosend();
    bool toDATABASE();
};

#endif // DATASTATE_H
