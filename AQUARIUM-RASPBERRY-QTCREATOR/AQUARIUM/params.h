#ifndef PARAMS_H
#define PARAMS_H

#include <QMainWindow>
#include "globals.h"
#include "file.h"
#include <QTime>

namespace Ui {
class params;
}

class params : public QMainWindow
{
    Q_OBJECT

public:
    void initTempValues();
    void saveTempValues();
    explicit params(QWidget *parent = 0);
    void show();
    QTimer *timerR;
    ~params();

protected slots:
    void closeEvent(QCloseEvent *event);

    void refreshALL();

    void updateRemoteIP();
    //temp
    void modifyTempSupBtnMin();
    void modifyTempSupBtnMax();
    void modifyTempSupSlider();
    void updateTempSupLcd();
    void modifyTempInfBtnMin();
    void modifyTempInfBtnMax();
    void modifyTempInfSlider();
    void updateTempInfLcd();
    //fan
    void modifyFanSupBtnMin();
    void modifyFanSupBtnMax();
    void modifyFanSupSlider();
    void updateFanSupLcd();
    void modifyFanInfBtnMin();
    void modifyFanInfBtnMax();
    void modifyFanInfSlider();
    void updateFanInfLcd();
    //ph
    void modifyPhSupBtnMin();
    void modifyPhSupBtnMax();
    void modifyPhSupSlider();
    void updatePhSupLcd();
    void modifyPhInfBtnMin();
    void modifyPhInfBtnMax();
    void modifyPhInfSlider();
    void updatePhInfLcd();
    //co2
    void modifyCo2SupBtnMin();
    void modifyCo2SupBtnMax();
    void modifyCo2SupSlider();
    void updateCo2SupLcd();
    void modifyCo2InfBtnMin();
    void modifyCo2InfBtnMax();
    void modifyCo2InfSlider();
    void updateCo2InfLcd();
    //lev
    void modifyLevSupBtnMin();
    void modifyLevSupBtnMax();
    void modifyLevSupSlider();
    void updateLevSupLcd();
    void modifyLevInfBtnMin();
    void modifyLevInfBtnMax();
    void modifyLevInfSlider();
    void updateLevInfLcd();

    //hrise
    void modifyHRiseHBtnMin();
    void modifyHRiseHBtnMax();
    void modifyHRiseMBtnMin();
    void modifyHRiseMBtnMax();
    void updateHRiseLcd();
    //hset
    void modifyHSetHBtnMin();
    void modifyHSetHBtnMax();
    void modifyHSetMBtnMin();
    void modifyHSetMBtnMax();
    void updateHSetLcd();
    //hrise_co2
    void modifyHRiseCo2HBtnMin();
    void modifyHRiseCo2HBtnMax();
    void modifyHRiseCo2MBtnMin();
    void modifyHRiseCo2MBtnMax();
    void updateHRiseCo2Lcd();
    //hset_co2
    void modifyHSetCo2HBtnMin();
    void modifyHSetCo2HBtnMax();
    void modifyHSetCo2MBtnMin();
    void modifyHSetCo2MBtnMax();
    void updateHSetCo2Lcd();
    //hpot
    void modifyHPotHBtnMin();
    void modifyHPotHBtnMax();
    void modifyHPotMBtnMin();
    void modifyHPotMBtnMax();
    void updateHPotLcd();
    //dpot
    void modifyDPotBtnMin();
    void modifyDPotBtnMax();
    void updateDPotLcd();

    //cal
    void initCalALL();
    void updateCalALL();

signals:
    void paramsModified();

private:
    Ui::params *ui;
    void loadLocalIP();
    void initParams();

    QString _t_remote_IP;

    float _t_TEMP_MIN;
    float _t_TEMP_MAX;
    float _t_TEMP_START_FAN;
    float _t_TEMP_STOP_FAN;

    float _t_PH_MIN;
    float _t_PH_MAX;
    float _t_PH_STOP_CO2;
    float _t_PH_START_CO2;

    quint16 _t_LEV_MIN;
    quint16 _t_LEV_MAX;

    QTime _t_SUNRISE;
    QTime _t_SUNSET;
    QTime _t_SUNRISE_START_CO2;
    QTime _t_SUNSET_STOP_CO2;

    QTime _t_HOUR_START_POT;
    QTime _t_HOUR_STOP_POT;
    quint16 _t_DELAY_POT;

    float _t_ADC_SLOPE;
    float _t_ADC_OFFSET;
    float _t_TEMP_RESISTENZAPARTITORE;//Ohm
    float _t_TENSIONEPARTITORE;//V

    float _t_NTC_BETA;
    float _t_NTC_RESISTENZACAMPIONE;//Ohm
    float _t_NTC_TEMPERATURACAMPIONE;//K

    float _t_AD622_tensIMax;//V
    float _t_AD622_tensIMin;//V
    float _t_AD622_tensOMax;//V
    float _t_AD622_tensOMin;//V

    float _t_PH_t2cal;//V
    float _t_PH_ph2cal;
    float _t_PH_t1cal;//V
    float _t_PH_ph1cal;
    float _t_PH_t3cal;//V
    float _t_PH_ph3cal;

    quint16 _t_LEV_zeroDistance; //mm

    //check values
    void checkTempSup();
    void checkTempInf();
    void checkFanSup();
    void checkFanInf();
    void checkPhSup();
    void checkPhInf();
    void checkCo2Sup();
    void checkCo2Inf();
    void checkLevSup();
    void checkLevInf();

    //check cal
    /*
    void checkCAdc$1();
    void checkCAdc$2();
    void checkCTemp$1();
    void checkCTemp$2();
    void checkCLev$1();
    void checkCAd622$1();
    void checkCAd622$2();
    void checkCAd622$3();
    void checkCAd622$4();
    void checkCNtc$1();
    void checkCNtc$2();
    void checkCNtc$3();
    void checkCPh$1();
    void checkCPh$2();
    void checkCPh$3();
    void checkCPh$4();
    void checkCPh$5();
    void checkCPh$6();
    */
};

#endif // PARAMS_H
