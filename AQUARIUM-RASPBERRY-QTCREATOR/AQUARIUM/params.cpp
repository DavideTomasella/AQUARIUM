#include "params.h"
#include "ui_params.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QCloseEvent>

params::params(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::params)
{
    ui->setupUi(this);

    initParams();
}

params::~params()
{
    timerR->stop();
    delete ui;
}

void params::closeEvent(QCloseEvent *event) {
    QMessageBox msgBox;
    msgBox.setText("The Params Have Been Modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setWindowTitle("GLOBAL PARAMS");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    //spostato ignore prima dell'if per evitare crash
    event->ignore();
    if(ret==QMessageBox::Save){
        saveTempValues();
        emit paramsModified();
        event->accept(); // close window
    }
    else if(ret==QMessageBox::Discard){
        event->accept(); // close window
    }
    else{
        //event->ignore(); // keep window
    }
}

void params::show()
{
    QMainWindow::show();
    loadLocalIP();
    initTempValues();
    initCalALL();

    timerR->start(100);//100ms
}

void params::initParams(){
    ui->listIP->addItem("");
    ui->listIP->addItem("172.16.9.11");
    ui->listIP->addItem("172.16.9.12");
    ui->listIP->addItem("192.168.1.100");
    ui->listIP->addItem("192.168.1.101");
    ui->listIP->addItem("192.168.1.102");
    ui->listIP->addItem("192.168.1.103");
    ui->listIP->addItem("192.168.1.104");
    ui->listIP->addItem("192.168.1.105");
    ui->listIP->setCurrentRow(0);

    timerR = new QTimer(this);
    connect(timerR, SIGNAL(timeout()), this, SLOT(refreshALL()));
}


void params::loadLocalIP(){
    ui->lblIPlocal->setText(LOCAL_IP);
}

//-------------------------------------------------
//GESTIONE PULSANTI
//-------------------------------------------------

void params::refreshALL(){

    updateRemoteIP();

    //aggiorno parametri dinamici
    ui->sli_lev_sup->setMaximum(LEV_zeroDistance);
    ui->sli_lev_inf->setMaximum(LEV_zeroDistance);

    updateTempSupLcd();
    updateTempInfLcd();
    updateFanSupLcd();
    updateFanInfLcd();
    updatePhSupLcd();
    updatePhInfLcd();
    updateCo2SupLcd();
    updateCo2InfLcd();
    updateLevSupLcd();
    updateLevInfLcd();

    updateHRiseLcd();
    updateHSetLcd();
    updateHRiseCo2Lcd();
    updateHSetCo2Lcd();
    updateHPotLcd();
    updateDPotLcd();

    updateCalALL();
}

void params::initTempValues(){
    _t_remote_IP = REMOTE_IP;

    _t_TEMP_MIN = TEMP_MIN;
    _t_TEMP_MAX = TEMP_MAX;
    _t_TEMP_START_FAN = TEMP_START_FAN;
    _t_TEMP_STOP_FAN = TEMP_STOP_FAN;

    _t_PH_MIN = PH_MIN;
    _t_PH_MAX = PH_MAX;
    _t_PH_STOP_CO2 = PH_STOP_CO2;
    _t_PH_START_CO2 = PH_START_CO2;

    _t_LEV_MIN = LEV_MIN;
    _t_LEV_MAX = LEV_MAX;

    _t_SUNRISE = SUNRISE;
    _t_SUNSET = SUNSET;
    _t_SUNRISE_START_CO2 = SUNRISE_START_CO2;
    _t_SUNSET_STOP_CO2 = SUNSET_STOP_CO2;

    _t_HOUR_START_POT = HOUR_START_POT;
    _t_HOUR_STOP_POT = HOUR_STOP_POT;
    _t_DELAY_POT = DELAY_POT;

    _t_ADC_SLOPE = ADC_SLOPE;
    _t_ADC_OFFSET = ADC_OFFSET;
    _t_TEMP_RESISTENZAPARTITORE = TEMP_RESISTENZAPARTITORE;//Ohm
    _t_TENSIONEPARTITORE = TENSIONEPARTITORE;//V

    _t_NTC_BETA = NTC_BETA;
    _t_NTC_RESISTENZACAMPIONE = NTC_RESISTENZACAMPIONE;//Ohm //BIG_TODO misurare!
    _t_NTC_TEMPERATURACAMPIONE = NTC_TEMPERATURACAMPIONE;//K

    _t_AD622_tensIMax = AD622_tensIMax;//V
    _t_AD622_tensIMin = AD622_tensIMin;//V
    _t_AD622_tensOMax = AD622_tensOMax;//V //BIG_TODO ricalcolare!
    _t_AD622_tensOMin = AD622_tensOMin;//V

    _t_PH_t2cal = PH_t2cal;//V
    _t_PH_ph2cal = PH_ph2cal;
    _t_PH_t1cal = PH_t1cal;//V
    _t_PH_ph1cal = PH_ph1cal;
    _t_PH_t3cal = PH_t3cal;//V
    _t_PH_ph3cal = PH_ph3cal;

    _t_LEV_zeroDistance = LEV_zeroDistance; //mm
}

void params::saveTempValues(){

    openFile();
    if(_t_remote_IP != REMOTE_IP){
        REMOTE_IP = _t_remote_IP;
        SAVE_PARAM(DATATYPE::REMOTE_IP,FILETYPE::Nothing);
    }

    if(_t_TEMP_MIN != TEMP_MIN){
        TEMP_MIN = _t_TEMP_MIN;
        SAVE_PARAM(DATATYPE::TEMP_MIN,FILETYPE::Nothing);
    }
    if(_t_TEMP_MAX != TEMP_MAX){
        TEMP_MAX = _t_TEMP_MAX;
        SAVE_PARAM(DATATYPE::TEMP_MAX,FILETYPE::Nothing);
    }
    if(_t_TEMP_START_FAN != TEMP_START_FAN){
        TEMP_START_FAN = _t_TEMP_START_FAN;
        SAVE_PARAM(DATATYPE::TEMP_START_FAN,FILETYPE::Nothing);
    }
    if(_t_TEMP_STOP_FAN != TEMP_STOP_FAN){
        TEMP_STOP_FAN = _t_TEMP_STOP_FAN;
        SAVE_PARAM(DATATYPE::TEMP_STOP_FAN,FILETYPE::Nothing);
    }
    if(_t_PH_MIN != PH_MIN){
        PH_MIN = _t_PH_MIN;
        SAVE_PARAM(DATATYPE::PH_MIN,FILETYPE::Nothing);
    }
    if(_t_PH_MAX != PH_MAX){
        PH_MAX = _t_PH_MAX;
        SAVE_PARAM(DATATYPE::PH_MAX,FILETYPE::Nothing);
    }
    if(_t_PH_STOP_CO2 != PH_STOP_CO2){
        PH_STOP_CO2 = _t_PH_STOP_CO2;
        SAVE_PARAM(DATATYPE::PH_STOP_CO2,FILETYPE::Nothing);
    }
    if(_t_PH_START_CO2 != PH_START_CO2){
        PH_START_CO2 = _t_PH_START_CO2;
        SAVE_PARAM(DATATYPE::PH_START_CO2,FILETYPE::Nothing);
    }
    if(_t_LEV_MIN != LEV_MIN){
        LEV_MIN = _t_LEV_MIN;
        SAVE_PARAM(DATATYPE::LEV_MIN,FILETYPE::Nothing);
    }
    if(_t_LEV_MAX != LEV_MAX){
        LEV_MAX = _t_LEV_MAX;
        SAVE_PARAM(DATATYPE::LEV_MAX,FILETYPE::Nothing);
    }
    if(_t_SUNRISE != SUNRISE){
        SUNRISE = _t_SUNRISE;
        SAVE_PARAM(DATATYPE::SUNRISE,FILETYPE::Nothing);
    }

    if(_t_SUNSET != SUNSET){
        SUNSET = _t_SUNSET;
        SAVE_PARAM(DATATYPE::SUNSET,FILETYPE::Nothing);
    }
    if(_t_SUNRISE_START_CO2 != SUNRISE_START_CO2){
        SUNRISE_START_CO2 = _t_SUNRISE_START_CO2;
        SAVE_PARAM(DATATYPE::SUNRISE_START_CO2,FILETYPE::Nothing);
    }
    if(_t_SUNSET_STOP_CO2 != SUNSET_STOP_CO2){
        SUNSET_STOP_CO2 = _t_SUNSET_STOP_CO2;
        SAVE_PARAM(DATATYPE::SUNSET_STOP_CO2,FILETYPE::Nothing);
    }
    if(_t_HOUR_START_POT != HOUR_START_POT){
        HOUR_START_POT = _t_HOUR_START_POT;
        SAVE_PARAM(DATATYPE::HOUR_START_POT,FILETYPE::Nothing);
    }
    if(_t_HOUR_STOP_POT != HOUR_STOP_POT){
        HOUR_STOP_POT = _t_HOUR_STOP_POT;
        SAVE_PARAM(DATATYPE::HOUR_STOP_POT,FILETYPE::Nothing);
    }
    if(_t_DELAY_POT != DELAY_POT){
        DELAY_POT = _t_DELAY_POT;
        SAVE_PARAM(DATATYPE::DELAY_POT,FILETYPE::Nothing);
    }
    if(_t_ADC_SLOPE != ADC_SLOPE){
        ADC_SLOPE = _t_ADC_SLOPE;
        SAVE_PARAM(DATATYPE::ADC_SLOPE,FILETYPE::Nothing);
    }
    if(_t_ADC_OFFSET != ADC_OFFSET){
        ADC_OFFSET = _t_ADC_OFFSET;
        SAVE_PARAM(DATATYPE::ADC_OFFSET,FILETYPE::Nothing);
    }
    if(_t_TEMP_RESISTENZAPARTITORE != TEMP_RESISTENZAPARTITORE){
        TEMP_RESISTENZAPARTITORE = _t_TEMP_RESISTENZAPARTITORE;
        SAVE_PARAM(DATATYPE::TEMP_RESISTENZAPARTITORE,FILETYPE::Nothing);
    }
    if(_t_TENSIONEPARTITORE != TENSIONEPARTITORE){
        TENSIONEPARTITORE = _t_TENSIONEPARTITORE;
        SAVE_PARAM(DATATYPE::TENSIONEPARTITORE,FILETYPE::Nothing);
    }
    if(_t_NTC_BETA != NTC_BETA){
        NTC_BETA = _t_NTC_BETA;
        SAVE_PARAM(DATATYPE::NTC_BETA,FILETYPE::Nothing);
    }
    if(_t_NTC_RESISTENZACAMPIONE != NTC_RESISTENZACAMPIONE){
        NTC_RESISTENZACAMPIONE = _t_NTC_RESISTENZACAMPIONE;
        SAVE_PARAM(DATATYPE::NTC_RESISTENZACAMPIONE,FILETYPE::Nothing);
    }
    if(_t_NTC_TEMPERATURACAMPIONE != NTC_TEMPERATURACAMPIONE){
        NTC_TEMPERATURACAMPIONE = _t_NTC_TEMPERATURACAMPIONE;
        SAVE_PARAM(DATATYPE::NTC_TEMPERATURACAMPIONE,FILETYPE::Nothing);
    }
    if(_t_AD622_tensIMax != AD622_tensIMax){
        AD622_tensIMax = _t_AD622_tensIMax;
        SAVE_PARAM(DATATYPE::AD622_tensIMax,FILETYPE::Nothing);
    }
    if(_t_AD622_tensIMin != AD622_tensIMin){
        AD622_tensIMin = _t_AD622_tensIMin;
        SAVE_PARAM(DATATYPE::AD622_tensIMin,FILETYPE::Nothing);
    }
    if(_t_AD622_tensOMax != AD622_tensOMax){
        AD622_tensOMax = _t_AD622_tensOMax;
        SAVE_PARAM(DATATYPE::AD622_tensOMax,FILETYPE::Nothing);
    }
    if(_t_AD622_tensOMin != AD622_tensOMin){
        AD622_tensOMin = _t_AD622_tensOMin;
        SAVE_PARAM(DATATYPE::AD622_tensOMin,FILETYPE::Nothing);
    }
    if(_t_PH_t2cal != PH_t2cal){
        PH_t2cal = _t_PH_t2cal;
        SAVE_PARAM(DATATYPE::PH_t2cal,FILETYPE::Nothing);
    }
    if(_t_PH_ph2cal != PH_ph2cal){
        PH_ph2cal = _t_PH_ph2cal;
        SAVE_PARAM(DATATYPE::PH_ph2cal,FILETYPE::Nothing);
    }
    if(_t_PH_t1cal != PH_t1cal){
        PH_t1cal = _t_PH_t1cal;
        SAVE_PARAM(DATATYPE::PH_t1cal,FILETYPE::Nothing);
    }
    if(_t_PH_ph1cal != PH_ph1cal){
        PH_ph1cal = _t_PH_ph1cal;
        SAVE_PARAM(DATATYPE::PH_ph1cal,FILETYPE::Nothing);
    }
    if(_t_PH_t3cal != PH_t3cal){
        PH_t3cal = _t_PH_t3cal;
        SAVE_PARAM(DATATYPE::PH_t3cal,FILETYPE::Nothing);
    }
    if(_t_PH_ph3cal != PH_ph3cal){
        PH_ph3cal = _t_PH_ph3cal;
        SAVE_PARAM(DATATYPE::PH_ph3cal,FILETYPE::Nothing);
    }
    if(_t_LEV_zeroDistance != LEV_zeroDistance){
        LEV_zeroDistance = _t_LEV_zeroDistance;
        SAVE_PARAM(DATATYPE::LEV_zeroDistance,FILETYPE::Nothing);
    }


    closeFile();
}

//--------------------------------------------------------------------
void params::updateRemoteIP(){
    _t_remote_IP = ui->listIP->currentItem()->text();
    if(_t_remote_IP == "")
        _t_remote_IP = REMOTE_IP;
    ui->lblIPremote->setText(_t_remote_IP);

}

//---------------------------------
//temp-sup-------------------------
void params::modifyTempSupBtnMin(){
    _t_TEMP_MAX -= 0.1;
    checkTempSup();
}

void params::modifyTempSupBtnMax(){
    _t_TEMP_MAX += 0.1;
    checkTempSup();
}

void params::modifyTempSupSlider(){
    _t_TEMP_MAX = ui->sli_temp_sup->value() / 10.0;
    //TEMP_MAX = (int)(TEMP_MAX * 10) / 10.0;
    checkTempSup();
}

void params::updateTempSupLcd(){
    QString s;
    s.sprintf("%2.1f",_t_TEMP_MAX);
    ui->lcd_temp_sup->display(s);
    checkTempSup();
}

void params::checkTempSup(){
    //TEMP_MAX = (int)(TEMP_MAX * 10) / 10.0;
    if(_t_TEMP_MAX < _t_TEMP_MIN + 1) _t_TEMP_MAX = _t_TEMP_MIN + 1;
    if(_t_TEMP_MAX > 30) _t_TEMP_MAX = 30;
    if(_t_TEMP_MAX < 16) _t_TEMP_MAX = 16;
    ui->sli_temp_sup->setValue(_t_TEMP_MAX * 10);
}

//temp-inf-------------------------
void params::modifyTempInfBtnMin(){
    _t_TEMP_MIN -= 0.1;
    checkTempInf();
}

void params::modifyTempInfBtnMax(){
    _t_TEMP_MIN += 0.1;
    checkTempInf();
}

void params::modifyTempInfSlider(){
    _t_TEMP_MIN = ui->sli_temp_inf->value() / 10.0;
    checkTempInf();
}

void params::updateTempInfLcd(){
    QString s;
    s.sprintf("%2.1f",_t_TEMP_MIN);
    ui->lcd_temp_inf->display(s);
    checkTempInf();
}

void params::checkTempInf(){
    if(_t_TEMP_MIN > _t_TEMP_MAX - 1) checkTempSup();
    if(_t_TEMP_MIN < 15) _t_TEMP_MIN = 15;
    if(_t_TEMP_MIN > 29) _t_TEMP_MIN = 29;
    ui->sli_temp_inf->setValue(_t_TEMP_MIN * 10);
}

//--------------------------------
//fan-sup-------------------------
void params::modifyFanSupBtnMin(){
    _t_TEMP_START_FAN -= 0.1;
    checkFanSup();
}

void params::modifyFanSupBtnMax(){
    _t_TEMP_START_FAN += 0.1;
    checkFanSup();
}

void params::modifyFanSupSlider(){
    _t_TEMP_START_FAN = ui->sli_fan_sup->value() / 10.0;
    checkFanSup();
}

void params::updateFanSupLcd(){
    QString s;
    s.sprintf("%2.1f",_t_TEMP_START_FAN);
    ui->lcd_fan_sup->display(s);
    checkFanSup();
}

void params::checkFanSup(){
    if(_t_TEMP_START_FAN < _t_TEMP_STOP_FAN + 1) _t_TEMP_START_FAN = _t_TEMP_STOP_FAN + 1;
    if(_t_TEMP_START_FAN > 30) _t_TEMP_START_FAN = 30;
    if(_t_TEMP_START_FAN < 16) _t_TEMP_START_FAN = 16;
    ui->sli_fan_sup->setValue(_t_TEMP_START_FAN * 10);
}

//fan-inf-------------------------
void params::modifyFanInfBtnMin(){
    _t_TEMP_STOP_FAN -= 0.1;
    checkFanInf();
}

void params::modifyFanInfBtnMax(){
    _t_TEMP_STOP_FAN += 0.1;
    checkFanInf();
}

void params::modifyFanInfSlider(){
    _t_TEMP_STOP_FAN = ui->sli_fan_inf->value() / 10.0;
    checkFanInf();
}

void params::updateFanInfLcd(){
    QString s;
    s.sprintf("%2.1f",_t_TEMP_STOP_FAN);
    ui->lcd_fan_inf->display(s);
    checkFanInf();
}

void params::checkFanInf(){
    if(_t_TEMP_STOP_FAN > _t_TEMP_START_FAN - 1) checkFanSup();
    if(_t_TEMP_STOP_FAN < 15) _t_TEMP_STOP_FAN = 15;
    if(_t_TEMP_STOP_FAN > 29) _t_TEMP_STOP_FAN = 29;
    ui->sli_fan_inf->setValue(_t_TEMP_STOP_FAN * 10);
}

//-------------------------------
//ph-sup-------------------------
void params::modifyPhSupBtnMin(){
    _t_PH_MAX -= 0.01;
    checkPhSup();
}

void params::modifyPhSupBtnMax(){
    _t_PH_MAX += 0.01;
    checkPhSup();
}

void params::modifyPhSupSlider(){
    _t_PH_MAX = ui->sli_ph_sup->value() / 100.0;
    //PH_MAX = (int)(PH_MAX * 100) / 100.0;
    checkPhSup();
}

void params::updatePhSupLcd(){
    QString s;
    s.sprintf("%1.2f",_t_PH_MAX);
    ui->lcd_ph_sup->display(s);
    checkPhSup();
}

void params::checkPhSup(){
    //PH_MAX = (int)(PH_MAX * 100) / 100.0;
    if(_t_PH_MAX < _t_PH_MIN + 0.1) _t_PH_MAX = _t_PH_MIN + 0.1;
    if(_t_PH_MAX > 9) _t_PH_MAX = 9;
    if(_t_PH_MAX < 4.1) _t_PH_MAX = 4.1;
    ui->sli_ph_sup->setValue(_t_PH_MAX * 100);
}

//ph-inf-------------------------
void params::modifyPhInfBtnMin(){
    _t_PH_MIN -= 0.01;
    checkPhInf();
}

void params::modifyPhInfBtnMax(){
    _t_PH_MIN += 0.01;
    checkPhInf();
}

void params::modifyPhInfSlider(){
    _t_PH_MIN = ui->sli_ph_inf->value() / 100.0;
    checkPhInf();
}

void params::updatePhInfLcd(){
    QString s;
    s.sprintf("%1.2f",_t_PH_MIN);
    ui->lcd_ph_inf->display(s);
    checkPhInf();
}

void params::checkPhInf(){
    if(_t_PH_MIN > _t_PH_MAX - 0.1) checkPhSup();
    if(_t_PH_MIN < 4) _t_PH_MIN = 4;
    if(_t_PH_MIN > 8.9) _t_PH_MIN = 8.9;
    ui->sli_ph_inf->setValue(_t_PH_MIN * 100);
}

//-------------------------------
//co2-sup-------------------------
void params::modifyCo2SupBtnMin(){
    _t_PH_START_CO2 -= 0.01;
    checkCo2Sup();
}

void params::modifyCo2SupBtnMax(){
    _t_PH_START_CO2 += 0.01;
    checkCo2Sup();
}

void params::modifyCo2SupSlider(){
    _t_PH_START_CO2 = ui->sli_co2_sup->value() / 100.0;
    //PH_STOP_CO2 = (int)(PH_STOP_CO2 * 100) / 100.0;
    checkCo2Sup();
}

void params::updateCo2SupLcd(){
    QString s;
    s.sprintf("%1.2f",_t_PH_START_CO2);
    ui->lcd_co2_sup->display(s);
    checkCo2Sup();
}

void params::checkCo2Sup(){
    //PH_STOP_CO2 = (int)(PH_STOP_CO2 * 100) / 100.0;
    if(_t_PH_START_CO2 < _t_PH_STOP_CO2 + 0.1) _t_PH_START_CO2 = _t_PH_STOP_CO2 + 0.1;
    if(_t_PH_START_CO2 > 9) _t_PH_START_CO2 = 9;
    if(_t_PH_START_CO2 < 4.1) _t_PH_START_CO2 = 4.1;
    ui->sli_co2_sup->setValue(_t_PH_START_CO2 * 100);
}

//co2-inf-------------------------
void params::modifyCo2InfBtnMin(){
    _t_PH_STOP_CO2 -= 0.01;
    checkCo2Inf();
}

void params::modifyCo2InfBtnMax(){
    _t_PH_STOP_CO2 += 0.01;
    checkCo2Inf();
}

void params::modifyCo2InfSlider(){
    _t_PH_STOP_CO2 = ui->sli_co2_inf->value() / 100.0;
    checkCo2Inf();
}

void params::updateCo2InfLcd(){
    QString s;
    s.sprintf("%1.2f",_t_PH_STOP_CO2);
    ui->lcd_co2_inf->display(s);
    checkCo2Inf();
}

void params::checkCo2Inf(){
    if(_t_PH_STOP_CO2 > _t_PH_START_CO2 - 0.1) checkCo2Sup();
    if(_t_PH_STOP_CO2 < 4) _t_PH_STOP_CO2 = 4;
    if(_t_PH_STOP_CO2 > 8.9) _t_PH_STOP_CO2 = 8.9;
    ui->sli_co2_inf->setValue(_t_PH_STOP_CO2 * 100);
}

//-------------------------------
//lev-sup------------------------
void params::modifyLevSupBtnMin(){
    _t_LEV_MAX -= 1;
    checkLevSup();
}

void params::modifyLevSupBtnMax(){
    _t_LEV_MAX += 1;
    checkLevSup();
}

void params::modifyLevSupSlider(){
    _t_LEV_MAX = ui->sli_lev_sup->value();
    checkLevSup();
}

void params::updateLevSupLcd(){
    QString s;
    s.sprintf("%3i",_t_LEV_MAX);
    ui->lcd_lev_sup->display(s);
    checkLevSup();
}

void params::checkLevSup(){
    if(_t_LEV_MAX < _t_LEV_MIN + 10) _t_LEV_MAX = _t_LEV_MIN + 10;
    if(_t_LEV_MAX > _t_LEV_zeroDistance - 10) _t_LEV_MAX = _t_LEV_zeroDistance - 10;
    if(_t_LEV_MAX < 20) _t_LEV_MAX = 20;
    ui->sli_lev_sup->setValue(_t_LEV_MAX);
}

//lev-inf------------------------
void params::modifyLevInfBtnMin(){
    _t_LEV_MIN -= 1;
    checkLevInf();
}

void params::modifyLevInfBtnMax(){
    _t_LEV_MIN += 1;
    checkLevInf();
}

void params::modifyLevInfSlider(){
    _t_LEV_MIN = ui->sli_lev_inf->value();
    checkLevInf();
}

void params::updateLevInfLcd(){
    QString s;
    s.sprintf("%3i",_t_LEV_MIN);
    ui->lcd_lev_inf->display(s);
    checkLevInf();
}

void params::checkLevInf(){
    if(_t_LEV_MIN > _t_LEV_MAX - 10) checkLevSup();
    if(_t_LEV_MIN < 10) LEV_MIN = 10;
    if(_t_LEV_MIN > _t_LEV_zeroDistance - 20) _t_LEV_MIN = _t_LEV_zeroDistance - 20;
    ui->sli_lev_inf->setValue(_t_LEV_MIN);
}

//-------------------------------
//hrise--------------------------
void params::modifyHRiseHBtnMin(){
    _t_SUNRISE = QTime((_t_SUNRISE.hour()>0) ? _t_SUNRISE.hour()-1 : 23, _t_SUNRISE.minute());
    //updateHRiseLcd();
}

void params::modifyHRiseHBtnMax(){
    _t_SUNRISE = QTime((_t_SUNRISE.hour()<23) ? _t_SUNRISE.hour()+1 : 0, _t_SUNRISE.minute());
    //updateHRiseLcd();
}

void params::modifyHRiseMBtnMin(){
    _t_SUNRISE = QTime(_t_SUNRISE.hour(), (_t_SUNRISE.minute()>0) ? _t_SUNRISE.minute()-1 : 59);
    //updateHRiseLcd();
}

void params::modifyHRiseMBtnMax(){
    _t_SUNRISE = QTime(_t_SUNRISE.hour(), (_t_SUNRISE.minute()<59) ? _t_SUNRISE.minute()+1 : 0);
    //updateHRiseLcd();
}

void params::updateHRiseLcd(){
    int hour = _t_SUNRISE.hour();
    int minute = _t_SUNRISE.minute();
    float t = hour+minute/100.0;
    QString s;
    s.sprintf("%4.2f",t);
    ui->lcd_hrise->display(s);
}

//hset---------------------------
void params::modifyHSetHBtnMin(){
    _t_SUNSET = QTime((_t_SUNSET.hour()>0) ? _t_SUNSET.hour()-1 : 23, _t_SUNSET.minute());
    //updateHSetLcd();
}

void params::modifyHSetHBtnMax(){
    _t_SUNSET = QTime((_t_SUNSET.hour()<23) ? _t_SUNSET.hour()+1 : 0, _t_SUNSET.minute());
    //updateHSetLcd();
}

void params::modifyHSetMBtnMin(){
    _t_SUNSET = QTime(_t_SUNSET.hour(), (_t_SUNSET.minute()>0) ? _t_SUNSET.minute()-1 : 59);
    //updateHSetLcd();
}

void params::modifyHSetMBtnMax(){
    _t_SUNSET = QTime(_t_SUNSET.hour(), (_t_SUNSET.minute()<59) ? _t_SUNSET.minute()+1 : 0);
    //updateHSetLcd();
}

void params::updateHSetLcd(){
    int hour = _t_SUNSET.hour();
    int minute = _t_SUNSET.minute();
    float t = hour+minute/100.0;
    QString s;
    s.sprintf("%4.2f",t);
    ui->lcd_hset->display(s);
}

//-------------------------------
//hrise_co2----------------------
void params::modifyHRiseCo2HBtnMin(){
    _t_SUNRISE_START_CO2 = QTime((_t_SUNRISE_START_CO2.hour()>0) ? _t_SUNRISE_START_CO2.hour()-1 : 23, _t_SUNRISE_START_CO2.minute());
    //updateHRiseCo2Lcd();
}

void params::modifyHRiseCo2HBtnMax(){
    _t_SUNRISE_START_CO2 = QTime((_t_SUNRISE_START_CO2.hour()<23) ? _t_SUNRISE_START_CO2.hour()+1 : 0, _t_SUNRISE_START_CO2.minute());
    //updateHRiseCo2Lcd();
}

void params::modifyHRiseCo2MBtnMin(){
    _t_SUNRISE_START_CO2 = QTime(_t_SUNRISE_START_CO2.hour(), (_t_SUNRISE_START_CO2.minute()>0) ? _t_SUNRISE_START_CO2.minute()-1 : 59);
    //updateHRiseCo2Lcd();
}

void params::modifyHRiseCo2MBtnMax(){
    _t_SUNRISE_START_CO2 = QTime(_t_SUNRISE_START_CO2.hour(), (_t_SUNRISE_START_CO2.minute()<59) ? _t_SUNRISE_START_CO2.minute()+1 : 0);
    //updateHRiseCo2Lcd();
}

void params::updateHRiseCo2Lcd(){
    int hour = _t_SUNRISE_START_CO2.hour();
    int minute = _t_SUNRISE_START_CO2.minute();
    float t = hour+minute/100.0;
    QString s;
    s.sprintf("%4.2f",t);
    ui->lcd_hrise_co2->display(s);
}

//hset_co2-----------------------
void params::modifyHSetCo2HBtnMin(){
    _t_SUNSET_STOP_CO2 = QTime((_t_SUNSET_STOP_CO2.hour()>0) ? _t_SUNSET_STOP_CO2.hour()-1 : 23, _t_SUNSET_STOP_CO2.minute());
    //updateHSetCo2Lcd();
}

void params::modifyHSetCo2HBtnMax(){
    _t_SUNSET_STOP_CO2 = QTime((_t_SUNSET_STOP_CO2.hour()<23) ? _t_SUNSET_STOP_CO2.hour()+1 : 0, _t_SUNSET_STOP_CO2.minute());
    //updateHSetCo2Lcd();
}

void params::modifyHSetCo2MBtnMin(){
    _t_SUNSET_STOP_CO2 = QTime(_t_SUNSET_STOP_CO2.hour(), (_t_SUNSET_STOP_CO2.minute()>0) ? _t_SUNSET_STOP_CO2.minute()-1 : 59);
    //updateHSetCo2Lcd();
}

void params::modifyHSetCo2MBtnMax(){
    _t_SUNSET_STOP_CO2 = QTime(_t_SUNSET_STOP_CO2.hour(), (_t_SUNSET_STOP_CO2.minute()<59) ? _t_SUNSET_STOP_CO2.minute()+1 : 0);
    //updateHSetCo2Lcd();
}

void params::updateHSetCo2Lcd(){
    int hour = _t_SUNSET_STOP_CO2.hour();
    int minute = _t_SUNSET_STOP_CO2.minute();
    float t = hour+minute/100.0;
    QString s;
    s.sprintf("%4.2f",t);
    ui->lcd_hset_co2->display(s);
}

//-------------------------------
//hpot---------------------------
void params::modifyHPotHBtnMin(){
    _t_HOUR_START_POT = QTime((_t_HOUR_START_POT.hour()>0) ? _t_HOUR_START_POT.hour()-1 : 23, _t_HOUR_START_POT.minute());
    //updateHPotLcd();
}

void params::modifyHPotHBtnMax(){
    _t_HOUR_START_POT = QTime((_t_HOUR_START_POT.hour()<23) ? _t_HOUR_START_POT.hour()+1 : 0, _t_HOUR_START_POT.minute());
    //updateHPotLcd();
}

void params::modifyHPotMBtnMin(){
    _t_HOUR_START_POT = QTime(_t_HOUR_START_POT.hour(), (_t_HOUR_START_POT.minute()>0) ? _t_HOUR_START_POT.minute()-1 : 59);
    //updateHPotLcd();
}

void params::modifyHPotMBtnMax(){
    _t_HOUR_START_POT = QTime(_t_HOUR_START_POT.hour(), (_t_HOUR_START_POT.minute()<59) ? _t_HOUR_START_POT.minute()+1 : 0);
    //updateHPotLcd();
}

void params::updateHPotLcd(){
    int hour = _t_HOUR_START_POT.hour();
    int minute = _t_HOUR_START_POT.minute();
    _t_HOUR_STOP_POT = QTime(hour, minute, 30);
    float t = hour+minute/100.0;
    QString s;
    s.sprintf("%4.2f",t);
    ui->lcd_hpot->display(s);
}

//dpot---------------------------
void params::modifyDPotBtnMin(){
    _t_DELAY_POT = _t_DELAY_POT>1 ? _t_DELAY_POT-1 : _t_DELAY_POT;
}

void params::modifyDPotBtnMax(){
    _t_DELAY_POT = _t_DELAY_POT<30 ? _t_DELAY_POT+1 : _t_DELAY_POT;
}

void params::updateDPotLcd(){
    int t = _t_DELAY_POT;
    QString s;
    s.sprintf("%3i",t);
    ui->lcd_dpot->display(s);
}


//----------------------------------------------
//CAL-------------------------------------------

void params::initCalALL(){
    ui->cal_adc_1->setText(QString::number(_t_ADC_SLOPE));
    ui->cal_adc_2->setText(QString::number(_t_ADC_OFFSET));
    ui->cal_temp_1->setText(QString::number(_t_TEMP_RESISTENZAPARTITORE));
    ui->cal_temp_2->setText(QString::number(_t_TENSIONEPARTITORE));
    ui->cal_lev_1->setText(QString::number(_t_LEV_zeroDistance));
    ui->cal_ad622_1->setText(QString::number(_t_AD622_tensIMax));
    ui->cal_ad622_2->setText(QString::number(_t_AD622_tensIMin));
    ui->cal_ad622_3->setText(QString::number(_t_AD622_tensOMax));
    ui->cal_ad622_4->setText(QString::number(_t_AD622_tensOMin));
    ui->cal_ntc_1->setText(QString::number(_t_NTC_BETA));
    ui->cal_ntc_2->setText(QString::number(_t_NTC_RESISTENZACAMPIONE));
    ui->cal_ntc_3->setText(QString::number(_t_NTC_TEMPERATURACAMPIONE - 273.15));
    ui->cal_ph_1->setText(QString::number(_t_PH_t1cal));
    ui->cal_ph_2->setText(QString::number(_t_PH_ph1cal));
    ui->cal_ph_3->setText(QString::number(_t_PH_t2cal));
    ui->cal_ph_4->setText(QString::number(_t_PH_ph2cal));
    ui->cal_ph_5->setText(QString::number(_t_PH_t3cal));
    ui->cal_ph_6->setText(QString::number(_t_PH_ph3cal));
}

void params::updateCalALL(){
    //check range all values
    /*
    checkCAdc$1();
    checkCAdc$2();
    checkCTemp$1();
    checkCTemp$2();
    checkCLev$1();
    checkCAd622$1();
    checkCAd622$2();
    checkCAd622$3();
    checkCAd622$4();
    checkCNtc$1();
    checkCNtc$2();
    checkCNtc$3();
    checkCPh$1();
    checkCPh$2();
    checkCPh$3();
    checkCPh$4();
    checkCPh$5();
    checkCPh$6();
    */

    //update values to variables
    _t_ADC_SLOPE = ui->cal_adc_1->text().toFloat();
    _t_ADC_OFFSET = ui->cal_adc_2->text().toFloat();
    _t_TEMP_RESISTENZAPARTITORE = ui->cal_temp_1->text().toFloat();
    _t_TENSIONEPARTITORE = ui->cal_temp_2->text().toFloat();
    _t_LEV_zeroDistance = ui->cal_lev_1->text().toInt();
    _t_AD622_tensIMax = ui->cal_ad622_1->text().toFloat();
    _t_AD622_tensIMin = ui->cal_ad622_2->text().toFloat();
    _t_AD622_tensOMax = ui->cal_ad622_3->text().toFloat();
    _t_AD622_tensOMin = ui->cal_ad622_4->text().toFloat();
    _t_NTC_BETA = ui->cal_ntc_1->text().toFloat();
    _t_NTC_RESISTENZACAMPIONE = ui->cal_ntc_2->text().toFloat();
    _t_NTC_TEMPERATURACAMPIONE = ui->cal_ntc_3->text().toFloat()+273.15;
    _t_PH_t1cal = ui->cal_ph_1->text().toFloat();
    _t_PH_ph1cal = ui->cal_ph_2->text().toFloat();
    _t_PH_t2cal = ui->cal_ph_3->text().toFloat();
    _t_PH_ph2cal = ui->cal_ph_4->text().toFloat();
    _t_PH_t3cal = ui->cal_ph_5->text().toFloat();
    _t_PH_ph3cal = ui->cal_ph_6->text().toFloat();
}

/*
void params::checkCAdc$1(){

}

void params::checkCAdc$2(){

}

void params::checkCTemp$1(){

}

void params::checkCTemp$2(){

}

void params::checkCLev$1(){

}

void params::checkCAd622$1(){

}

void params::checkCAd622$2(){

}

void params::checkCAd622$3(){

}

void params::checkCAd622$4(){

}

void params::checkCNtc$1(){

}

void params::checkCNtc$2(){

}

void params::checkCNtc$3(){

}

void params::checkCPh$1(){

}

void params::checkCPh$2(){

}

void params::checkCPh$3(){

}

void params::checkCPh$4(){

}

void params::checkCPh$5(){

}

void params::checkCPh$6(){

}
*/
