#ifndef CALIBRATE_H
#define CALIBRATE_H

#include <QMainWindow>
#include "autocontrol.h"
#include "globals.h"

namespace Ui {
class calibrate;
}

class calibrate : public QMainWindow
{
    Q_OBJECT

public:
    explicit calibrate(QWidget *parent = 0);
    void setControl(AutoControl *control);
    AutoControl* myAutoControl;
    ~calibrate();

protected slots:
    void updateCalState();
    void startCalibration();
    void stopCalibration();

private:
    Ui::calibrate *ui;
    class STATE {
    public:
        static const int NOTHING = 1;
        static const int START = 2;
        static const int STOP = 3;
        static const int INSERTED = 4;
        static const int READY = 5;
        static const int CALIBRATE = 6;
        static const int DONE = 7;
    };
    static const int CALIBRATIONSECONDS = 20;
    int calstate;    
    bool calibrating;
    int calTimeOutSec;
    QList<float> calSamples;
    int calPoint;
    void updateCalibrationPoint(int calPoint, QList<float> calSamples);
};

#endif // CALIBRATE_H
