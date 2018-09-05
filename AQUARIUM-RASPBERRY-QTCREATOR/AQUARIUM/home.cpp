#include "home.h"
#include "ui_home.h"
#include <qtimer.h>
#include <QMessageBox>

home::home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);

    init();

}

home::~home()
{
    delete ui;
}


void home::init(){
    myAutoControl = new AutoControl();
    myUpdater = new Updater();
    myUpdater->setControl(myAutoControl);

    myPARAMS = new params;
    myLOG = new log;
    myCALIBRATE = new calibrate;
    myCALIBRATE->setControl(myAutoControl);

    QTimer *timerrefresh = new QTimer(this);
    connect(timerrefresh, SIGNAL(timeout()), this, SLOT(refreshALL()));
    timerrefresh->start(500);//500ms
    connect(myPARAMS, SIGNAL(paramsModified()), this, SLOT(refreshParams()));

    refreshHome();
    refreshTime();
    refreshSun();
    refreshStatus();
}

void home::openPARAMS(){
    myPARAMS->show();
}

void home::openLOG(){
    myLOG->show();
}

void home::openVERSION(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("ABOUT");
    msgBox.setText("Version : " + QString::number(VERSION, 'f', 1));
    msgBox.exec();
}

void home::openCALIBRATE(){
    myCALIBRATE->show();
}

void home::refreshALL(){
    refreshHome();
    refreshTime();
    refreshStatus();
    refreshSun();
    refreshParams();
}

void home::refreshHome(){
    myUpdater->updateTemp(ui->barTEMP, ui->lblTEMP);
    myUpdater->updatePh(ui->barPH, ui->lblPH);
    myUpdater->updateLev(ui->barLEV, ui->lblLEV);
    myUpdater->updateLig(ui->barLIG);
    myUpdater->updateFan(ui->btnFAN);
    myUpdater->updateCo2(ui->btnCO2);
    myUpdater->updatePot(ui->btnPOT);
}

void home::refreshTime(){
    myUpdater->updateHour(ui->lcdHOUR);
    myUpdater->updateDate(ui->lblDATE);
}

void home::refreshStatus(){
    myUpdater->updateSTATUS(ui->btnSTATUS);
}

void home::refreshSun(){
    myUpdater->updateRISE(ui->lcdRISE);
    myUpdater->updateSET(ui->lcdSET);
}

void home::refreshParams(){
    refreshSun();
}
