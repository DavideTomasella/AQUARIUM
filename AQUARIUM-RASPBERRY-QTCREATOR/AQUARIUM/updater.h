#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>
#include "globals.h"
#include "autocontrol.h"
#include <QLCDNumber>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>

class Updater : public QObject
{
    Q_OBJECT
public:
    explicit Updater(QObject *parent = 0);
    void setControl(AutoControl *control);
    AutoControl* myAutoControl;
    void updateHour(QLCDNumber *lcdHOUR);
    void updateDate(QLabel *lblDATE);
    void updateSTATUS(QPushButton *btnSTATUS);
    void updateTemp(QProgressBar *barTEMP, QLabel *lblTEMP);
    void updatePh(QProgressBar *barPH, QLabel *lblPH);
    void updateLev(QProgressBar *barLEV, QLabel *lblLEV);
    void updateLig(QProgressBar *barLIG);
    void updateFan(QPushButton *btnFAN);
    void updateCo2(QPushButton *btnCO2);
    void updatePot(QPushButton *btnPOT);
    void updateRISE(QLCDNumber *lcdRISE);
    void updateSET(QLCDNumber *lcdSET);

private:
    bool flash;

};

#endif // GRAPHICUPDATER_H
