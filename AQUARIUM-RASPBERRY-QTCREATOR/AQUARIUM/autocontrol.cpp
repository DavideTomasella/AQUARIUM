#include "autocontrol.h"
#include <QTimer>
#include <QTime>

AutoControl::AutoControl(QObject *parent) :
    QObject(parent)
{
    initAutoControl();
}

void AutoControl::initAutoControl(){

    myDataState = new DataState();
    statePotassium = 0;
    myDataState->getDataState();

    co2HasBeenLow = false;

    tempOOR = 0;
    phOOR = 0;
    levOOR = 0;
    STATUSOK = 5;

    QTimer *timerstate = new QTimer(this);
    connect(timerstate, SIGNAL(timeout()), this, SLOT(doAutoControl()));
    timerstate->start(5000); //5s

    QTimer *timerpotassium = new QTimer(this);
    connect(timerpotassium, SIGNAL(timeout()), this, SLOT(checkPotassium()));
    timerpotassium->start(100); //10ms

    connect(myDataState,SIGNAL(readyDataState()),this,SLOT(finallyAutoControl()));
    connect(myDataState->myInOutConnection,SIGNAL(connectionError(int)),this,SLOT(noConnectionAutoControl(int)));
}

void AutoControl::doAutoControl(){
    qDebug()<<"NEW CONTROL";
    if(checkAutoControl()){
        myDataState->sendDataState();
    }
    else{
        myDataState->getDataState();
    }
}

void AutoControl::finallyAutoControl(){
    logAutoControl();
    rangedAutoControl();
}

void AutoControl::noConnectionAutoControl(int errorCode){
    addErrori(90,true);
    addErrori(errorCode);
    STATUSOK = 0;
}

bool AutoControl::checkAutoControl(){
    QTime now = QTime::currentTime();

    oldLIGHT = myDataState->myLIGHT;
    oldFANS = myDataState->myFANS;
    oldCO2 = myDataState->myCO2;
    oldPOTASSIUM = myDataState->myPOTASSIUM;

    //LIGHT
    myDataState->myLIGHTFUTURE = (now>SUNRISE && now<SUNSET);

    //FANS
    if(myDataState->myFANS==false)
        myDataState->myFANS = myDataState->myTEMP>TEMP_START_FAN;
    else if(myDataState->myFANS==true)
        myDataState->myFANS = myDataState->myTEMP>TEMP_STOP_FAN;

    //CO2
    if(now>SUNRISE_START_CO2 && now<SUNSET_STOP_CO2){
        if(myDataState->myPH < PH_START_CO2)
            co2HasBeenLow = true;
        else if(myDataState->myPH > PH_STOP_CO2)
            co2HasBeenLow = false;
        myDataState->myCO2 = !co2HasBeenLow;
    }
    else{
        co2HasBeenLow = false;
        myDataState->myCO2 = co2HasBeenLow;
        //DI NOTTE chiedere a Peccolo
    }

    //POTASSIUM
    switch(statePotassium){
    case 0: //ready
        myDataState->myPOTASSIUM = false;
        if(now>HOUR_START_POT && now<HOUR_STOP_POT) {
            statePotassium = 1;
            myDataState->myPOTASSIUM = true;
        }
        break;
    case 1:
        break;
    case 2:
        myDataState->myPOTASSIUM = 0;
        if(now<HOUR_START_POT || now>HOUR_STOP_POT) statePotassium = 0;
        break;
    }

    return (oldLIGHT!=myDataState->myLIGHTFUTURE*100) |
            (oldFANS!=myDataState->myFANS) |
            (oldCO2!=myDataState->myCO2) |
            (oldPOTASSIUM!=myDataState->myPOTASSIUM);

}


void AutoControl::checkPotassium(){

    if(statePotassium==1){
        countDownPotassium++;
        if(countDownPotassium >= DELAY_POT * 10){
            statePotassium=2;
            doAutoControl();
        }
    }
    else{
        countDownPotassium=0;
    }
}


void AutoControl::logAutoControl(){
    //LIGHT
    if(myDataState->myLIGHT>oldLIGHT){
        if(oldLIGHT==0&&myDataState->myLIGHT>1)
            addErrori(47);
        else if(myDataState->myLIGHT==100)
            addErrori(45);
    }
    if(myDataState->myLIGHT<oldLIGHT){
        if(oldLIGHT==100)
            addErrori(48);
        else if(myDataState->myLIGHT==0)
            addErrori(46);
    }

    //FAN
    if(myDataState->myFANS!=oldFANS){
        if(myDataState->myFANS)
            addErrori(55);
        else
            addErrori(56);
    }

    //POTASSIUM
    if(myDataState->myPOTASSIUM!=oldPOTASSIUM){
        if(myDataState->myPOTASSIUM)
            addErrori(65);
        else
            addErrori(66);
    }

    //CO2
    if(myDataState->myCO2!=oldCO2){
        if(myDataState->myCO2)
            addErrori(75);
        else
            addErrori(76);
    }
}

void AutoControl::rangedAutoControl(){

    //TEMP
    if(myDataState->myTEMP>TEMP_MAX || myDataState->myTEMP<TEMP_MIN){
        tempOOR++;
        if(tempOOR > 124) tempOOR = 5;
        if(tempOOR == 5) {
            addErrori(10);
            if(myDataState->myTEMP > TEMP_MAX && myDataState->myTEMP-TEMP_MAX < 10)
                addErrori(11);
            else if(myDataState->myTEMP < TEMP_MIN && myDataState->myTEMP-TEMP_MIN > -10)
                addErrori(12);
            else addErrori(13);
        }
    }
    else{
        if(tempOOR > 3) tempOOR = 2;
        if(tempOOR > 0) tempOOR--;
    }

    //PH
    if(myDataState->myPH>PH_MAX || myDataState->myPH<PH_MIN){
        phOOR++;
        if(phOOR > 124) phOOR = 5;
        if(phOOR == 5) {
            addErrori(20);
            if(myDataState->myPH > PH_MAX && myDataState->myPH-PH_MAX < 1)
                addErrori(21);
            else if(myDataState->myPH < PH_MIN && myDataState->myPH-PH_MIN > -1)
                addErrori(22);
            else addErrori(23);
        }
    }
    else{
        if(phOOR > 3) phOOR = 2;
        if(phOOR > 0) phOOR--;
    }

    //LEV
    if(myDataState->myLEVEL>LEV_MAX || myDataState->myLEVEL<LEV_MIN){
        levOOR++;
        if(levOOR > 124) levOOR = 5;
        if(levOOR == 5) {
            addErrori(30);
            if(myDataState->myLEVEL > LEV_MAX && myDataState->myLEVEL < LEV_zeroDistance - 10)
                addErrori(31);
            else if(myDataState->myLEVEL < LEV_MIN && myDataState->myLEVEL > 10)
                addErrori(32);
            else addErrori(33);
        }
    }
    else{
        if(levOOR > 3) levOOR = 2;
        if(levOOR > 0) levOOR--;
    }


    STATUSOK++;
    if(tempOOR > 2) STATUSOK = 0;
    if(phOOR > 2) STATUSOK = 0;
    if(levOOR > 2) STATUSOK = 0;
    if(STATUSOK > 125){
        STATUSOK = 5;
        addErrori(0);
    }
}
