#include <globals.h>

#include <QObject>
#include <QTime>
#include <QFile>
#include <QDebug>


//------------------------------------------------------------------------

float TEMP_MIN = 21.0; //°C
float TEMP_MAX = 25.0;
float TEMP_START_FAN = 25.0;
float TEMP_STOP_FAN = 24.0;

float PH_MIN = 6.0;
float PH_MAX = 8.0;
float PH_STOP_CO2 = 6.0;
float PH_START_CO2 = 7.5;

quint16 LEV_MIN = 100; //mm
quint16 LEV_MAX = 400; //mm

QTime SUNRISE = QTime(7,30);
QTime SUNSET = QTime(19,30);
QTime SUNRISE_START_CO2 = QTime(6,30);
QTime SUNSET_STOP_CO2 = QTime(20,30);

QTime HOUR_START_POT = QTime(10,0,0);
QTime HOUR_STOP_POT = QTime(10,0,10);
quint16 DELAY_POT = HOUR_STOP_POT.second() - HOUR_START_POT.second(); //sec


//------------------------------------------------------------------------

float ADC_SLOPE = 2.24;
float ADC_OFFSET = 223;
float TEMP_RESISTENZAPARTITORE = 10000;//Ohm
float TENSIONEPARTITORE = 3.30;//V

float NTC_BETA = 3565;
float NTC_RESISTENZACAMPIONE = 10000;//Ohm //BIG_TODO misurare!
float NTC_TEMPERATURACAMPIONE = 25+273.15;//K

float AD622_tensIMax = 0.200;//V
float AD622_tensIMin = -0.100;//V
float AD622_tensOMax = 2.27;//V //BIG_TODO ricalcolare!
float AD622_tensOMin = 0.0;//V

float PH_t2cal = 0.038;//V
float PH_ph2cal = 7.00;
float PH_t1cal = -0.045;//V
float PH_ph1cal = 9.00;
float PH_t3cal = 0.180;//V
float PH_ph3cal = 4.00;

quint16 LEV_zeroDistance = 500; //mm

float BITPWM = 8191.0;
float PERCENTMAX = 100.00;//%


//------------------------------------------------------------------------

QString REMOTE_IP = "192.168.1.103";
QString LOCAL_IP = "";

QFile data("/home/pi/Documents/data.dat");
