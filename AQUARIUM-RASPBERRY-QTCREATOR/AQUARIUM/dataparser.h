#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <QObject>
#include "globals.h"

class DataParser : public QObject
{
    Q_OBJECT
public:
    explicit DataParser(QObject *parent = 0);
    float unpackTEMP(quint16 inout);
    float unpackPH(quint16 inout);
    quint16 unpackLEVEL(quint16 inout);
    float unpackLIGHT(quint16 inout);
    bool unpackFANS(quint16 inout);
    bool unpackPOTASSIUM(quint16 inout);
    bool unpackCO2(quint16 inout);
    quint16 packLIGHTFUTURE(bool myLIGHTFUTURE);
    quint16 packFANSPOTASSIUMCO2(bool myFANS, bool myPOTASSIUM, bool myCO2);

};

#endif // DATAPARSER_H
