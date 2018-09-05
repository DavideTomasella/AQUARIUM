/********************************************************************************
** Form generated from reading UI file 'calibrate.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATE_H
#define UI_CALIBRATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calibrate
{
public:
    QWidget *centralwidget;
    QPushButton *btnCStart;
    QPushButton *btnCStop;
    QFrame *frame;
    QRadioButton *selPh9;
    QRadioButton *selPh7;
    QRadioButton *selPh4;
    QLabel *lblCurrPh;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *calibrate)
    {
        if (calibrate->objectName().isEmpty())
            calibrate->setObjectName(QStringLiteral("calibrate"));
        calibrate->resize(591, 369);
        calibrate->setStyleSheet(QStringLiteral("background-color:rgb(245, 235, 191);"));
        centralwidget = new QWidget(calibrate);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btnCStart = new QPushButton(centralwidget);
        btnCStart->setObjectName(QStringLiteral("btnCStart"));
        btnCStart->setGeometry(QRect(30, 190, 241, 51));
        btnCStart->setStyleSheet(QStringLiteral("background-color:rgb(243, 157, 40);"));
        btnCStop = new QPushButton(centralwidget);
        btnCStop->setObjectName(QStringLiteral("btnCStop"));
        btnCStop->setGeometry(QRect(30, 260, 241, 51));
        btnCStop->setStyleSheet(QStringLiteral("background-color:rgb(243, 157, 40);"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 60, 241, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        selPh9 = new QRadioButton(frame);
        selPh9->setObjectName(QStringLiteral("selPh9"));
        selPh9->setGeometry(QRect(10, 40, 141, 26));
        selPh9->setChecked(false);
        selPh7 = new QRadioButton(frame);
        selPh7->setObjectName(QStringLiteral("selPh7"));
        selPh7->setGeometry(QRect(10, 10, 141, 26));
        selPh7->setChecked(true);
        selPh4 = new QRadioButton(frame);
        selPh4->setObjectName(QStringLiteral("selPh4"));
        selPh4->setGeometry(QRect(10, 70, 221, 26));
        lblCurrPh = new QLabel(centralwidget);
        lblCurrPh->setObjectName(QStringLiteral("lblCurrPh"));
        lblCurrPh->setGeometry(QRect(30, 20, 141, 21));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(16);
        lblCurrPh->setFont(font);
        calibrate->setCentralWidget(centralwidget);
        menubar = new QMenuBar(calibrate);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 591, 27));
        calibrate->setMenuBar(menubar);
        statusbar = new QStatusBar(calibrate);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        calibrate->setStatusBar(statusbar);

        retranslateUi(calibrate);
        QObject::connect(btnCStart, SIGNAL(clicked()), calibrate, SLOT(startCalibration()));
        QObject::connect(btnCStop, SIGNAL(clicked()), calibrate, SLOT(stopCalibration()));

        QMetaObject::connectSlotsByName(calibrate);
    } // setupUi

    void retranslateUi(QMainWindow *calibrate)
    {
        calibrate->setWindowTitle(QApplication::translate("calibrate", "PH CALIBRATION", 0));
        btnCStart->setText(QApplication::translate("calibrate", "START CALIBRATION", 0));
        btnCStop->setText(QApplication::translate("calibrate", "STOP CALIBRATION", 0));
        selPh9->setText(QApplication::translate("calibrate", "PH 9 SOLUTION", 0));
        selPh7->setText(QApplication::translate("calibrate", "PH 7 SOLUTION", 0));
        selPh4->setText(QApplication::translate("calibrate", "PH 4 SOLUTION (not used)", 0));
        lblCurrPh->setText(QApplication::translate("calibrate", "PH : 7.00", 0));
    } // retranslateUi

};

namespace Ui {
    class calibrate: public Ui_calibrate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATE_H
