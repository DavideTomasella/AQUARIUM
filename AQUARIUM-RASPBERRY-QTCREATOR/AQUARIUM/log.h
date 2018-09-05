#ifndef LOG_H
#define LOG_H

#include <QDialog>
#include "dbconnect.h"

namespace Ui {
class log;
}

class log : public QDialog
{
    Q_OBJECT

public:
    explicit log(QWidget *parent = 0);
    ~log();
    void show();
    void refreshErrors();

private:
    Ui::log *ui;
};

#endif // LOG_H
