#include "file.h"
#include "globals.h"
#include <QString>
#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QTime>

void LOAD_GLOBALS(){
    qDebug()<<"LOADING GLOBALS";
    openFile();

    for(int i=1; i<=36; i++){
        LOAD_PARAM(i,FILETYPE::Nothing);
    }

    closeFile();
}

void SAVE_GLOBALS(){
    qDebug()<<"SAVING GLOBALS";
    openFile();

    for(int i=1; i<=36; i++){
        SAVE_PARAM(i,FILETYPE::Nothing);
    }

    closeFile();
}

void LOAD_PARAM(int _DATATYPE, int _FILETYPE){
    if(_FILETYPE==FILETYPE::Open||_FILETYPE==FILETYPE::OpenNClose){
        openFile();
    }

    QByteArray datRead = "";
    data.seek(3+_DATATYPE*19);
    char* buff = new char[15];
    data.read(buff,15);
    datRead.append(buff);
    if(!datRead.endsWith('*'))
        qDebug()<<"error reading param "<<_DATATYPE<<" -> "<<datRead;
    datRead=datRead.left(datRead.indexOf('*'));

    switch(_DATATYPE){
    case DATATYPE::ADC_SLOPE:
        ADC_SLOPE = datRead.toFloat();
        break;
    case DATATYPE::ADC_OFFSET:
        ADC_OFFSET = datRead.toFloat();
        break;
    case DATATYPE::TEMP_RESISTENZAPARTITORE:
        TEMP_RESISTENZAPARTITORE = datRead.toFloat();
        break;
    case DATATYPE::TENSIONEPARTITORE:
        TENSIONEPARTITORE = datRead.toFloat();
        break;
    case DATATYPE::NTC_BETA:
        NTC_BETA = datRead.toFloat();
        break;
    case DATATYPE::NTC_RESISTENZACAMPIONE:
        NTC_RESISTENZACAMPIONE = datRead.toFloat();
        break;
    case DATATYPE::NTC_TEMPERATURACAMPIONE:
        NTC_TEMPERATURACAMPIONE = datRead.toFloat();
        break;
    case DATATYPE::AD622_tensIMax:
        AD622_tensIMax = datRead.toFloat();
        break;
    case DATATYPE::AD622_tensIMin:
        AD622_tensIMin = datRead.toFloat();
        break;
    case DATATYPE::AD622_tensOMax:
        AD622_tensOMax = datRead.toFloat();
        break;
    case DATATYPE::AD622_tensOMin:
        AD622_tensOMin = datRead.toFloat();
        break;
    case DATATYPE::PH_t2cal:
        PH_t2cal = datRead.toFloat();
        break;
    case DATATYPE::PH_ph2cal:
        PH_ph2cal = datRead.toFloat();
        break;
    case DATATYPE::PH_t1cal:
        PH_t1cal = datRead.toFloat();
        break;
    case DATATYPE::PH_ph1cal:
        PH_ph1cal = datRead.toFloat();
        break;
    case DATATYPE::PH_t3cal:
        PH_t3cal = datRead.toFloat();
        break;
    case DATATYPE::PH_ph3cal:
        PH_ph3cal = datRead.toFloat();
        break;
    case DATATYPE::LEV_zeroDistance:
        LEV_zeroDistance = datRead.toUInt();
        break;
    //---------------------------------------------------------------
    case DATATYPE::TEMP_MIN:
        TEMP_MIN = datRead.toFloat();
        break;
    case DATATYPE::TEMP_MAX:
        TEMP_MAX = datRead.toFloat();
        break;
    case DATATYPE::TEMP_START_FAN:
        TEMP_START_FAN = datRead.toFloat();
        break;
    case DATATYPE::TEMP_STOP_FAN:
        TEMP_STOP_FAN = datRead.toFloat();
        break;
    case DATATYPE::PH_MIN:
        PH_MIN = datRead.toFloat();
        break;
    case DATATYPE::PH_MAX:
        PH_MAX = datRead.toFloat();
        break;
    case DATATYPE::PH_STOP_CO2:
        PH_STOP_CO2 = datRead.toFloat();
        break;
    case DATATYPE::PH_START_CO2:
        PH_START_CO2 = datRead.toFloat();
        break;
    case DATATYPE::LEV_MIN:
        LEV_MIN = datRead.toUInt();
        break;
    case DATATYPE::LEV_MAX:
        LEV_MAX = datRead.toUInt();
        break;
    case DATATYPE::SUNRISE:
        SUNRISE = QTime::fromString(QString(datRead.data()),"hh:mm:ss");
        break;
    case DATATYPE::SUNSET:
        SUNSET = QTime::fromString(QString(datRead.data()),"hh:mm:ss");
        break;
    case DATATYPE::SUNRISE_START_CO2:
        SUNRISE_START_CO2 = QTime::fromString(QString(datRead.data()),"hh:mm:ss");
        break;
    case DATATYPE::SUNSET_STOP_CO2:
        SUNSET_STOP_CO2 = QTime::fromString(QString(datRead.data()),"hh:mm:ss");
        break;
    case DATATYPE::HOUR_START_POT:
        HOUR_START_POT = QTime::fromString(QString(datRead.data()),"hh:mm:ss");
        break;
    case DATATYPE::HOUR_STOP_POT:
        HOUR_STOP_POT = QTime::fromString(QString(datRead.data()),"hh:mm:ss");
        break;
    case DATATYPE::DELAY_POT:
        DELAY_POT = datRead.toUInt();
        break;
    case DATATYPE::REMOTE_IP:
        REMOTE_IP = datRead;
    }

    if(_FILETYPE==FILETYPE::Close||_FILETYPE==FILETYPE::OpenNClose){
        closeFile();
    }
}

void SAVE_PARAM(int _DATATYPE, int _FILETYPE){
    if(_FILETYPE==FILETYPE::Open||_FILETYPE==FILETYPE::OpenNClose){
        openFile();
    }

    data.seek(3+_DATATYPE*19);
    data.write("***************",15);
    data.seek(3+_DATATYPE*19);
    QByteArray datToSave = "";
    switch(_DATATYPE){
    case DATATYPE::ADC_SLOPE:
        datToSave = QByteArray::number(ADC_SLOPE);
        break;
    case DATATYPE::ADC_OFFSET:
        datToSave = QByteArray::number(ADC_OFFSET);
        break;
    case DATATYPE::TEMP_RESISTENZAPARTITORE:
        datToSave = QByteArray::number(TEMP_RESISTENZAPARTITORE);
        break;
    case DATATYPE::TENSIONEPARTITORE:
        datToSave = QByteArray::number(TENSIONEPARTITORE);
        break;
    case DATATYPE::NTC_BETA:
        datToSave = QByteArray::number(NTC_BETA);
        break;
    case DATATYPE::NTC_RESISTENZACAMPIONE:
        datToSave = QByteArray::number(NTC_RESISTENZACAMPIONE);
        break;
    case DATATYPE::NTC_TEMPERATURACAMPIONE:
        datToSave = QByteArray::number(NTC_TEMPERATURACAMPIONE);
        break;
    case DATATYPE::AD622_tensIMax:
        datToSave = QByteArray::number(AD622_tensIMax);
        break;
    case DATATYPE::AD622_tensIMin:
        datToSave = QByteArray::number(AD622_tensIMin);
        break;
    case DATATYPE::AD622_tensOMax:
        datToSave = QByteArray::number(AD622_tensOMax);
        break;
    case DATATYPE::AD622_tensOMin:
        datToSave = QByteArray::number(AD622_tensOMin);
        break;
    case DATATYPE::PH_t2cal:
        datToSave = QByteArray::number(PH_t2cal);
        break;
    case DATATYPE::PH_ph2cal:
        datToSave = QByteArray::number(PH_ph2cal);
        break;
    case DATATYPE::PH_t1cal:
        datToSave = QByteArray::number(PH_t1cal);
        break;
    case DATATYPE::PH_ph1cal:
        datToSave = QByteArray::number(PH_ph1cal);
        break;
    case DATATYPE::PH_t3cal:
        datToSave = QByteArray::number(PH_t3cal);
        break;
    case DATATYPE::PH_ph3cal:
        datToSave = QByteArray::number(PH_ph3cal);
        break;
    case DATATYPE::LEV_zeroDistance:
        datToSave = QByteArray::number(LEV_zeroDistance);
        break;
    //---------------------------------------------------------------
    case DATATYPE::TEMP_MIN:
        datToSave = QByteArray::number(TEMP_MIN);
        break;
    case DATATYPE::TEMP_MAX:
        datToSave = QByteArray::number(TEMP_MAX);
        break;
    case DATATYPE::TEMP_START_FAN:
        datToSave = QByteArray::number(TEMP_START_FAN);
        break;
    case DATATYPE::TEMP_STOP_FAN:
        datToSave = QByteArray::number(TEMP_STOP_FAN);
        break;
    case DATATYPE::PH_MIN:
        datToSave = QByteArray::number(PH_MIN);
        break;
    case DATATYPE::PH_MAX:
        datToSave = QByteArray::number(PH_MAX);
        break;
    case DATATYPE::PH_STOP_CO2:
        datToSave = QByteArray::number(PH_STOP_CO2);
        break;
    case DATATYPE::PH_START_CO2:
        datToSave = QByteArray::number(PH_START_CO2);
        break;
    case DATATYPE::LEV_MIN:
        datToSave = QByteArray::number(LEV_MIN);
        break;
    case DATATYPE::LEV_MAX:
        datToSave = QByteArray::number(LEV_MAX);
        break;
    case DATATYPE::SUNRISE:
        datToSave.append(SUNRISE.toString());
        break;
    case DATATYPE::SUNSET:
        datToSave.append(SUNSET.toString());
        break;
    case DATATYPE::SUNRISE_START_CO2:
        datToSave.append(SUNRISE_START_CO2.toString());
        break;
    case DATATYPE::SUNSET_STOP_CO2:
        datToSave.append(SUNSET_STOP_CO2.toString());
        break;
    case DATATYPE::HOUR_START_POT:
        datToSave.append(HOUR_START_POT.toString());
        break;
    case DATATYPE::HOUR_STOP_POT:
        datToSave.append(HOUR_STOP_POT.toString());
        break;
    case DATATYPE::DELAY_POT:
        datToSave = QByteArray::number(DELAY_POT);
        break;
    case DATATYPE::REMOTE_IP:
        datToSave.append(REMOTE_IP);
    }
    if(datToSave.size()<16)
        data.write((const char*)datToSave,datToSave.size());

    if(_FILETYPE==FILETYPE::Close||_FILETYPE==FILETYPE::OpenNClose){
        closeFile();
    }
}

void openFile(){
    qDebug()<<data.fileName()<<" opened";
    if(!data.open(QIODevice::ReadWrite|QIODevice::Text))
        return;
}

void closeFile(){
    qDebug()<<data.fileName()<<" closed";
    data.close();
}
