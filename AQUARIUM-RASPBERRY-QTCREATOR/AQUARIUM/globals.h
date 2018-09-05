#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtGlobal>

QT_BEGIN_NAMESPACE
class QObject;
class QTime;
class QFile;
QT_END_NAMESPACE


//------------------------------------------------------------------------

extern float TEMP_MIN;
extern float TEMP_MAX;
extern float TEMP_START_FAN;
extern float TEMP_STOP_FAN;

extern float PH_MIN;
extern float PH_MAX;
extern float PH_STOP_CO2;
extern float PH_START_CO2;

extern quint16 LEV_MIN;
extern quint16 LEV_MAX;

extern QTime SUNRISE;
extern QTime SUNSET;
extern QTime SUNRISE_START_CO2;
extern QTime SUNSET_STOP_CO2;

extern QTime HOUR_START_POT;
extern QTime HOUR_STOP_POT;
extern quint16 DELAY_POT;


//------------------------------------------------------------------------

extern float ADC_SLOPE;
extern float ADC_OFFSET;
extern float TEMP_RESISTENZAPARTITORE;//Ohm
extern float TENSIONEPARTITORE;//V

extern float NTC_BETA;
extern float NTC_RESISTENZACAMPIONE;//Ohm //BIG_TODO misurare!
extern float NTC_TEMPERATURACAMPIONE;//K

extern float AD622_tensIMax;//V
extern float AD622_tensIMin;//V
extern float AD622_tensOMax;//V //BIG_TODO ricalcolare!
extern float AD622_tensOMin;//V

extern float PH_t2cal;//V
extern float PH_ph2cal;
extern float PH_t1cal;//V
extern float PH_ph1cal;
extern float PH_t3cal;//V
extern float PH_ph3cal;

extern quint16 LEV_zeroDistance; //mm

extern float BITPWM;
extern float PERCENTMAX;//%

//------------------------------------------------------------------------

extern QString LOCAL_IP;
extern QString REMOTE_IP;
extern QFile data;

class DATATYPE {
public:
    static const int ADC_SLOPE = 1;
    static const int ADC_OFFSET = 2;
    static const int TEMP_RESISTENZAPARTITORE = 3;
    static const int TENSIONEPARTITORE = 4;
    static const int NTC_BETA = 5;
    static const int NTC_RESISTENZACAMPIONE = 6;
    static const int NTC_TEMPERATURACAMPIONE = 7;
    static const int AD622_tensIMax = 8;
    static const int AD622_tensIMin = 9;
    static const int AD622_tensOMax = 10;
    static const int AD622_tensOMin = 11;
    static const int PH_t2cal = 12;
    static const int PH_ph2cal =13;
    static const int PH_t1cal = 14;
    static const int PH_ph1cal = 15;
    static const int PH_t3cal = 16;
    static const int PH_ph3cal = 17;
    static const int LEV_zeroDistance = 18;
    //----------------------------------------
    static const int TEMP_MIN = 19;
    static const int TEMP_MAX = 20;
    static const int TEMP_START_FAN = 21;
    static const int TEMP_STOP_FAN = 22;
    static const int PH_MIN = 23;
    static const int PH_MAX = 24;
    static const int PH_STOP_CO2 = 25;
    static const int PH_START_CO2 = 26;
    static const int LEV_MIN = 27;
    static const int LEV_MAX =28;
    static const int SUNRISE = 29;
    static const int SUNSET = 30;
    static const int SUNRISE_START_CO2 = 31;
    static const int SUNSET_STOP_CO2 =32;
    static const int HOUR_START_POT = 33;
    static const int HOUR_STOP_POT = 34;
    static const int DELAY_POT = 35;
    static const int REMOTE_IP = 36;
};


//------------------------------------------------------------------------

#endif // GLOBALS_H
