#include "updater.h"
#include "QTime"

Updater::Updater(QObject *parent) :
    QObject(parent)
{
    flash = false;
}

void Updater::setControl(AutoControl *control){
    myAutoControl=control;
}

void Updater::updateHour(QLCDNumber *lcdHOUR){
    int hour = QDateTime::currentDateTime().time().hour();
    int minute = QDateTime::currentDateTime().time().minute();
    float t = hour+minute/100.0;
    QString s;
    s.sprintf("%4.2f",t);
    lcdHOUR->display(s);
}

void Updater::updateDate(QLabel *lblDATE){
    QString date = QDateTime::currentDateTime().toString("ddd d MMM yyyy");
    lblDATE->setText(date);
}

void Updater::updateSTATUS(QPushButton *btnSTATUS){
    bool sts = myAutoControl->STATUSOK>=5 ? true : false;
    flash = !flash;
    if(sts || flash)
        btnSTATUS->setStyleSheet("background-color: rgb(6, 192, 76);");
    else
        btnSTATUS->setStyleSheet("background-color: rgb(241, 11, 87);");//rgb(246, 61, 13)
}


void Updater::updateTemp(QProgressBar *barTEMP, QLabel *lblTEMP){
    //min 15 ok 25 max 35
    float TEMPMIN = 15.0;
    float TEMPMAX = 35.0;

    float temp = myAutoControl->myDataState->myTEMP;
    float p = (temp-TEMPMIN)/(TEMPMAX-TEMPMIN)*100;
    if(p<1) p=1;
    if(p>100) p=100;
    QString s;
    s.sprintf("%3.1f°C",temp);
    barTEMP->setValue((int)p);
    lblTEMP->setText(s);
}

void Updater::updatePh(QProgressBar *barPH, QLabel *lblPH){
    //min 5 ok 7 max 9
    float PHMIN = 5.0;
    float PHMAX = 9.0;

    float ph = myAutoControl->myDataState->myPH;
    float p = (ph-PHMIN)/(PHMAX-PHMIN)*100;
    if(p<1) p=1;
    if(p>100) p=100;
    QString s;
    s.sprintf("%3.2f",ph);
    barPH->setValue((int)p);
    lblPH->setText(s);
}

void Updater::updateLev(QProgressBar *barLEV, QLabel *lblLEV){
    //min 0 max 500
    float LEVMIN = 0;
    float LEVMAX = 500.0;

    int lev = myAutoControl->myDataState->myLEVEL;
    float p = (lev-LEVMIN)/(LEVMAX-LEVMIN)*100;
    if(p<1) p=1;
    if(p>100) p=100;
    QString s;
    s.sprintf("%3imm",lev);
    barLEV->setValue((int)p);
    lblLEV->setText(s);
}

void Updater::updateLig(QProgressBar *barLIG){
    float lig = myAutoControl->myDataState->myLIGHT;
    barLIG->setValue((int)lig);
}

void Updater::updateFan(QPushButton *btnFAN){
    bool fan = myAutoControl->myDataState->myFANS;
    if(fan)
        btnFAN->setStyleSheet("background-color: rgb(6, 192, 76);");
    else
        btnFAN->setStyleSheet("background-color: rgb(241, 11, 87);");//rgb(246, 61, 13)
}

void Updater::updateCo2(QPushButton *btnCO2){
    bool co2 = myAutoControl->myDataState->myCO2;
    if(co2)
        btnCO2->setStyleSheet("background-color: rgb(6, 192, 76);");
    else
        btnCO2->setStyleSheet("background-color: rgb(241, 11, 87);");//rgb(246, 61, 13)
}

void Updater::updatePot(QPushButton *btnPOT){
    bool pot = myAutoControl->myDataState->myPOTASSIUM;
    if(pot)
        btnPOT->setStyleSheet("background-color: rgb(6, 192, 76);");
    else
        btnPOT->setStyleSheet("background-color: rgb(241, 11, 87);");//rgb(246, 61, 13)
}


void Updater::updateRISE(QLCDNumber *lcdRISE){
    int hour = SUNRISE.hour();
    int minute = SUNRISE.minute();
    float t = hour+minute/100.0;
    QString s;
    s.sprintf("%4.2f",t);
    lcdRISE->display(s);
}

void Updater::updateSET(QLCDNumber *lcdSET){
    int hour = SUNSET.hour();
    int minute = SUNSET.minute();
    float t = hour+minute/100.0;
    QString s;
    s.sprintf("%4.2f",t);
    lcdSET->display(s);
}
