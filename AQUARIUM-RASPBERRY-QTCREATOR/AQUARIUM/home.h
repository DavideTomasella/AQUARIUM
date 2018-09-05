#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include "autocontrol.h"
#include "updater.h"
#include "params.h"
#include "log.h"
#include "calibrate.h"

namespace Ui {
class home;
}

class home : public QMainWindow
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = 0);
    AutoControl* myAutoControl;
    Updater* myUpdater;
    ~home();

protected slots:
    void openPARAMS();
    void openLOG();
    void openVERSION();
    void openCALIBRATE();
    void refreshALL();
    void refreshHome();
    void refreshTime();
    void refreshSun();
    void refreshStatus();
    void refreshParams();

private:
    Ui::home *ui;
    void init();
    params* myPARAMS;
    log* myLOG;
    calibrate* myCALIBRATE;

};

#endif // HOME_H
