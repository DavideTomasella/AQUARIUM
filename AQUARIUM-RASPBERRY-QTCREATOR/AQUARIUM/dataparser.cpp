#include "dataparser.h"
#include <QtMath>
#include <QDebug>

DataParser::DataParser(QObject *parent) :
    QObject(parent)
{
}

float DataParser::unpackTEMP(quint16 inout){

    float tensioneAdc = (inout + ADC_OFFSET) / ADC_SLOPE;
    tensioneAdc /= 1000;

    float R = TEMP_RESISTENZAPARTITORE * (TENSIONEPARTITORE / tensioneAdc -1);
    float T = 1 / (1/NTC_TEMPERATURACAMPIONE + 1/NTC_BETA*qLn(R/NTC_RESISTENZACAMPIONE));
    T -= 273.15;
    qDebug()<<inout<<" "<<tensioneAdc<<" "<<R<<" "<<T;
    return T;
}

float DataParser::unpackPH(quint16 inout){

    float tensioneAdc = (inout + ADC_OFFSET) / ADC_SLOPE;
    tensioneAdc /= 1000;

    float T = tensioneAdc/(AD622_tensOMax-AD622_tensOMin)*(AD622_tensIMax-AD622_tensIMin) + AD622_tensIMin;
    float m = (PH_ph2cal-PH_ph1cal) / (PH_t2cal-PH_t1cal);
    float q = -PH_t1cal * (PH_ph2cal-PH_ph1cal)/(PH_t2cal-PH_t1cal) + PH_ph1cal;
    float PH = m * T + q;
    qDebug()<<inout<<" "<<tensioneAdc<<" "<<PH<<" "<<T<<" "<<m<<" "<<q;
    return PH;
}

quint16 DataParser::unpackLEVEL(quint16 inout){
    quint16 level = 0;
    if(inout<500&&inout>0)
        level = LEV_zeroDistance - inout;
    return level;
}

float DataParser::unpackLIGHT(quint16 inout){

    float L = inout / BITPWM * PERCENTMAX;
    //WARNING: NEGATIVE LOGIC
    L = PERCENTMAX - L;
    qDebug()<<inout<<" "<<L;
    return L;
}

bool DataParser::unpackFANS(quint16 inout){
    //WARNING: NEGATIVE LOGIC
    bool F = !(inout&0x04);
    qDebug()<<inout<<" "<<F;
    return F;
}

bool DataParser::unpackPOTASSIUM(quint16 inout){
    bool P = inout&0x08;
    qDebug()<<inout<<" "<<P;
    return P;
}

bool DataParser::unpackCO2(quint16 inout){
    bool C = inout&0x10;
    qDebug()<<inout<<" "<<C;
    return C;
}

quint16 DataParser::packLIGHTFUTURE(bool myLIGHTFUTURE){
    quint16 L = 0x00;
    //WARNING: NEGATIVE LOGIC
    L += (!myLIGHTFUTURE&0x01);
    qDebug()<<L;
    return L;
}

quint16 DataParser::packFANSPOTASSIUMCO2(bool myFANS, bool myPOTASSIUM, bool myCO2){
    quint16 O = 0x00;
    //WARNING: NEGATIVE LOGIC
    O += (!myFANS) ? 0x04 : 0x00;
    O += (myPOTASSIUM) ? 0x08 : 0x00;
    O += (myCO2) ? 0x10 : 0x00;
    qDebug()<<O;
    return O;
}

