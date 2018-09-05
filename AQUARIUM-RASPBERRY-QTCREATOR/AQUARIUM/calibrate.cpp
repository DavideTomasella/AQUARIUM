#include "calibrate.h"
#include "ui_calibrate.h"
#include <QTimer>
#include <QMessageBox>

calibrate::calibrate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calibrate)
{
    ui->setupUi(this);

    calstate = STATE::NOTHING;
    calibrating = false;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCalState()));
    timer->start(1000);
}

calibrate::~calibrate()
{
    delete ui;
}

void calibrate::setControl(AutoControl *control){
    myAutoControl = control;
}


void calibrate::startCalibration(){
    calibrating = true;
}


void calibrate::stopCalibration(){
    calibrating = false;
}

void calibrate::updateCalState(){
    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Abort);
    msgBox.setWindowTitle("CALIBRATION");
    int res = 0;
    QString s;
    float currPh = myAutoControl->myDataState->myPH;
    ui->lblCurrPh->setText("PH : " + s.sprintf("%3.2f",currPh));
    switch(calstate){
    case STATE::NOTHING:
        if(calibrating) calstate = STATE::START;
        break;
    case STATE::START:
        if(!calibrating){ calstate = STATE::STOP; break; }
        msgBox.setText("Insert the probe in chosen solution.");
        res = msgBox.exec();
        if(res != QMessageBox::Ok) { calstate = STATE::STOP; break; }
        calstate = STATE::INSERTED;
        break;
    case STATE::INSERTED:
        if(!calibrating){ calstate = STATE::STOP; break; }
        msgBox.setText("Wait some minutes unlit the values will stable.");
        res = msgBox.exec();
        if(res != QMessageBox::Ok) { calstate = STATE::STOP; break; }
        calstate = STATE::READY;
        break;
    case STATE::READY:
        if(!calibrating){ calstate = STATE::STOP; break; }
        msgBox.setText("Start calibration?");
        res = msgBox.exec();
        if(res != QMessageBox::Ok) { calstate = STATE::STOP; break; }
        calTimeOutSec = CALIBRATIONSECONDS;
        calSamples.clear();
        //selectCalibrationPointToUpdate(selPoint)
        if(ui->selPh4->isChecked()) calPoint = DATATYPE::PH_ph3cal;
        else if(ui->selPh9->isChecked()) calPoint = DATATYPE::PH_ph2cal;
        else calPoint = DATATYPE::PH_ph1cal;
        calstate = STATE::CALIBRATE;
        break;
    case STATE::CALIBRATE:
        if(!calibrating){ calstate = STATE::STOP; break; }
        if(calTimeOutSec%5 == 0) calSamples.append(currPh);
        if(--calTimeOutSec < 0){
            updateCalibrationPoint(calPoint,calSamples);
            calstate = STATE::DONE;
        }
        break;
    case STATE::DONE:
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setText("DONE!");
        msgBox.exec();
        calibrating = false;
        calstate = STATE::NOTHING;
        break;
    case STATE::STOP:
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setText("STOP!");
        msgBox.exec();
        calibrating = false;
        calstate = STATE::NOTHING;
        break;
    }
}

void calibrate::updateCalibrationPoint(int calPoint, QList<float> calSamples){
   float sum = 0;
   foreach(float sample, calSamples) sum += sample;
   float prePH = sum/calSamples.size();

   float m = (PH_ph2cal-PH_ph1cal) / (PH_t2cal-PH_t1cal);
   float q = -PH_t1cal * (PH_ph2cal-PH_ph1cal)/(PH_t2cal-PH_t1cal) + PH_ph1cal;
   float T = (prePH-q)/m;
   T = (int)(T*10000) / 10000.0;

   if(calPoint == DATATYPE::PH_ph1cal){
       PH_t1cal = T;
       SAVE_PARAM(DATATYPE::PH_t1cal, FILETYPE::OpenNClose);
   }
   else if(calPoint == DATATYPE::PH_ph2cal){
       PH_t2cal = T;
       SAVE_PARAM(DATATYPE::PH_t2cal, FILETYPE::OpenNClose);
   }
   else if(calPoint == DATATYPE::PH_ph3cal){
       PH_t3cal = T;
       SAVE_PARAM(DATATYPE::PH_t3cal, FILETYPE::OpenNClose);
   }
}

