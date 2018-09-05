#ifndef AUTOCONTROL_H
#define AUTOCONTROL_H

#include <QObject>
#include "datastate.h"
#include "globals.h"

class AutoControl : public QObject
{
    Q_OBJECT
public:
    explicit AutoControl(QObject *parent = 0);
    DataState* myDataState;
    quint8 STATUSOK;

public slots:
    void doAutoControl();
    void finallyAutoControl();
    void noConnectionAutoControl(int errorCode);
    void checkPotassium();

private:
    void initAutoControl();
    int oldLIGHT;
    bool oldFANS;
    bool oldCO2;
    bool oldPOTASSIUM;
    int countDownPotassium;
    int statePotassium;
    bool co2HasBeenLow;
    bool checkAutoControl();
    void logAutoControl();
    void rangedAutoControl();
    quint8 tempOOR;
    quint8 phOOR;
    quint8 levOOR;

};

#endif // AUTOCONTROL_H
