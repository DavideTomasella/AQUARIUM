#include "log.h"
#include "ui_log.h"
#include <QDebug>
#include <QTimer>

log::log(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log)
{
    ui->setupUi(this);

}

log::~log()
{
    delete ui;
}

void log::show(){
    QDialog::show();
    refreshErrors();
}

void log::refreshErrors(){
    QStringList list;
    getLastError(10,&list);
    ui->listWidget->clear();
    ui->listWidget->addItems(list);
}
