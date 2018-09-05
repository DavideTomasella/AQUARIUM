/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QAction *actionVersion;
    QAction *actionPARAMS;
    QAction *actionCALIBRATION;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnSTATUS;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_7;
    QProgressBar *barTEMP;
    QLabel *lblTEMP;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_8;
    QProgressBar *barPH;
    QLabel *lblPH;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_9;
    QProgressBar *barLEV;
    QLabel *lblLEV;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_8;
    QLCDNumber *lcdHOUR;
    QLabel *lblDATE;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QProgressBar *barLIG;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_3;
    QLCDNumber *lcdRISE;
    QLCDNumber *lcdSET;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnFAN;
    QPushButton *btnCO2;
    QPushButton *btnPOT;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QMenuBar *menubar;
    QMenu *menuSETTINGS;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName(QStringLiteral("home"));
        home->resize(776, 461);
        home->setStyleSheet(QStringLiteral("background-color:rgb(245, 235, 191);"));
        home->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionVersion = new QAction(home);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        actionPARAMS = new QAction(home);
        actionPARAMS->setObjectName(QStringLiteral("actionPARAMS"));
        actionCALIBRATION = new QAction(home);
        actionCALIBRATION->setObjectName(QStringLiteral("actionCALIBRATION"));
        centralwidget = new QWidget(home);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 0, 767, 411));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 5, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 40));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font.setPointSize(40);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(250, 43, 6);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(370, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font1.setPointSize(14);
        font1.setItalic(false);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        btnSTATUS = new QPushButton(horizontalLayoutWidget);
        btnSTATUS->setObjectName(QStringLiteral("btnSTATUS"));
        sizePolicy.setHeightForWidth(btnSTATUS->sizePolicy().hasHeightForWidth());
        btnSTATUS->setSizePolicy(sizePolicy);
        btnSTATUS->setMinimumSize(QSize(370, 50));
        btnSTATUS->setMaximumSize(QSize(370, 50));
        QFont font2;
        font2.setFamily(QStringLiteral("Courier New"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        btnSTATUS->setFont(font2);
        btnSTATUS->setStyleSheet(QStringLiteral("background-color: rgb(6, 192, 76);"));

        verticalLayout_3->addWidget(btnSTATUS);


        verticalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(100, 20));
        label_3->setMaximumSize(QSize(130, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font3.setPointSize(14);
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_5->addWidget(label_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        barTEMP = new QProgressBar(horizontalLayoutWidget);
        barTEMP->setObjectName(QStringLiteral("barTEMP"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(barTEMP->sizePolicy().hasHeightForWidth());
        barTEMP->setSizePolicy(sizePolicy3);
        barTEMP->setMinimumSize(QSize(0, 200));
        barTEMP->setMaximumSize(QSize(80, 300));
        barTEMP->setAutoFillBackground(false);
        barTEMP->setStyleSheet(QLatin1String("QProgressBar{\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgb(236, 23, 45), stop:0.666 rgb(144, 38, 232), stop:1 rgb(30, 101, 241));\n"
"	border:1px solid rgb(82, 74, 74);\n"
"}\n"
"QProgressBar::Chunk{\n"
"	background-color:rgba(255, 255, 255, 0);\n"
"	border-top: 8px solid black;\n"
"}"));
        barTEMP->setMinimum(-1);
        barTEMP->setMaximum(100);
        barTEMP->setValue(91);
        barTEMP->setAlignment(Qt::AlignCenter);
        barTEMP->setOrientation(Qt::Vertical);
        barTEMP->setInvertedAppearance(false);

        horizontalLayout_7->addWidget(barTEMP);


        verticalLayout_5->addLayout(horizontalLayout_7);

        lblTEMP = new QLabel(horizontalLayoutWidget);
        lblTEMP->setObjectName(QStringLiteral("lblTEMP"));
        lblTEMP->setMaximumSize(QSize(16777215, 20));
        QFont font4;
        font4.setFamily(QStringLiteral("Courier New"));
        font4.setPointSize(14);
        lblTEMP->setFont(font4);
        lblTEMP->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lblTEMP);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, -1);
        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(120, 20));
        label_4->setMaximumSize(QSize(130, 20));
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_7->addWidget(label_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        barPH = new QProgressBar(horizontalLayoutWidget);
        barPH->setObjectName(QStringLiteral("barPH"));
        sizePolicy3.setHeightForWidth(barPH->sizePolicy().hasHeightForWidth());
        barPH->setSizePolicy(sizePolicy3);
        barPH->setMinimumSize(QSize(0, 200));
        barPH->setMaximumSize(QSize(80, 300));
        barPH->setStyleSheet(QLatin1String("QProgressBar{\n"
"	background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:1 rgba(255, 255, 0, 255), stop:0.666 rgba(0, 255, 0, 255), stop:0.333 rgb(4, 170, 124),stop:0 rgb(46, 125, 223));\n"
"	border:1px solid rgb(82, 74, 74);\n"
"}\n"
"QProgressBar::Chunk{\n"
"	background-color:rgb(255, 255, 255,0);\n"
"	border-top:8px solid black;\n"
"}"));
        barPH->setMinimum(-1);
        barPH->setValue(70);
        barPH->setAlignment(Qt::AlignCenter);
        barPH->setOrientation(Qt::Vertical);

        horizontalLayout_8->addWidget(barPH);


        verticalLayout_7->addLayout(horizontalLayout_8);

        lblPH = new QLabel(horizontalLayoutWidget);
        lblPH->setObjectName(QStringLiteral("lblPH"));
        lblPH->setMaximumSize(QSize(16777215, 20));
        lblPH->setFont(font4);
        lblPH->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(lblPH);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setMinimumSize(QSize(120, 20));
        label_9->setMaximumSize(QSize(130, 20));
        label_9->setFont(font3);
        label_9->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_4->addWidget(label_9);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        barLEV = new QProgressBar(horizontalLayoutWidget);
        barLEV->setObjectName(QStringLiteral("barLEV"));
        sizePolicy3.setHeightForWidth(barLEV->sizePolicy().hasHeightForWidth());
        barLEV->setSizePolicy(sizePolicy3);
        barLEV->setMinimumSize(QSize(0, 200));
        barLEV->setMaximumSize(QSize(80, 300));
        barLEV->setStyleSheet(QLatin1String("QProgressBar{\n"
"	background-color:rgba(205, 200, 203, 145);\n"
"	border:1px solid rgb(82, 74, 74);\n"
"}\n"
"QProgressBar::Chunk{\n"
"	background-color:rgb(29, 144, 231);\n"
"}"));
        barLEV->setMinimum(0);
        barLEV->setMaximum(100);
        barLEV->setValue(5);
        barLEV->setAlignment(Qt::AlignCenter);
        barLEV->setOrientation(Qt::Vertical);

        horizontalLayout_9->addWidget(barLEV);


        verticalLayout_4->addLayout(horizontalLayout_9);

        lblLEV = new QLabel(horizontalLayoutWidget);
        lblLEV->setObjectName(QStringLiteral("lblLEV"));
        lblLEV->setMaximumSize(QSize(16777215, 20));
        lblLEV->setFont(font4);
        lblLEV->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lblLEV);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, 10, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        lcdHOUR = new QLCDNumber(horizontalLayoutWidget);
        lcdHOUR->setObjectName(QStringLiteral("lcdHOUR"));
        sizePolicy2.setHeightForWidth(lcdHOUR->sizePolicy().hasHeightForWidth());
        lcdHOUR->setSizePolicy(sizePolicy2);
        lcdHOUR->setMinimumSize(QSize(200, 100));
        lcdHOUR->setMaximumSize(QSize(360, 16777215));
        lcdHOUR->setSmallDecimalPoint(false);
        lcdHOUR->setProperty("value", QVariant(21.25));

        verticalLayout_8->addWidget(lcdHOUR);

        lblDATE = new QLabel(horizontalLayoutWidget);
        lblDATE->setObjectName(QStringLiteral("lblDATE"));
        lblDATE->setMaximumSize(QSize(360, 20));
        lblDATE->setFont(font3);
        lblDATE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_8->addWidget(lblDATE);


        horizontalLayout_6->addLayout(verticalLayout_8);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 10, 0);
        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMinimumSize(QSize(0, 20));
        label_7->setMaximumSize(QSize(16777215, 30));
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_6->addWidget(label_7);

        barLIG = new QProgressBar(horizontalLayoutWidget);
        barLIG->setObjectName(QStringLiteral("barLIG"));
        barLIG->setMinimumSize(QSize(360, 50));
        barLIG->setMaximumSize(QSize(360, 16777215));
        barLIG->setStyleSheet(QLatin1String("QProgressBar{\n"
"	background-color:rgba(205, 200, 203, 145);\n"
"	border:1px solid rgb(82, 74, 74);\n"
"}\n"
"QProgressBar::Chunk{\n"
"	background-color:rgb(246, 154, 62);\n"
"}"));
        barLIG->setValue(78);
        barLIG->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(barLIG);

        label_8 = new QLabel(horizontalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setMinimumSize(QSize(0, 20));
        label_8->setMaximumSize(QSize(370, 30));
        QFont font5;
        font5.setFamily(QStringLiteral("DejaVu Sans Mono"));
        font5.setPointSize(12);
        label_8->setFont(font5);
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_6->addWidget(label_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lcdRISE = new QLCDNumber(horizontalLayoutWidget);
        lcdRISE->setObjectName(QStringLiteral("lcdRISE"));
        sizePolicy.setHeightForWidth(lcdRISE->sizePolicy().hasHeightForWidth());
        lcdRISE->setSizePolicy(sizePolicy);
        lcdRISE->setMinimumSize(QSize(0, 50));
        lcdRISE->setMaximumSize(QSize(170, 170));
        lcdRISE->setProperty("value", QVariant(7.32));

        horizontalLayout_3->addWidget(lcdRISE);

        lcdSET = new QLCDNumber(horizontalLayoutWidget);
        lcdSET->setObjectName(QStringLiteral("lcdSET"));
        sizePolicy.setHeightForWidth(lcdSET->sizePolicy().hasHeightForWidth());
        lcdSET->setSizePolicy(sizePolicy);
        lcdSET->setMinimumSize(QSize(0, 50));
        lcdSET->setMaximumSize(QSize(170, 170));
        lcdSET->setProperty("value", QVariant(20.32));

        horizontalLayout_3->addWidget(lcdSET);


        verticalLayout_6->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 10, 0);
        btnFAN = new QPushButton(horizontalLayoutWidget);
        btnFAN->setObjectName(QStringLiteral("btnFAN"));
        sizePolicy1.setHeightForWidth(btnFAN->sizePolicy().hasHeightForWidth());
        btnFAN->setSizePolicy(sizePolicy1);
        btnFAN->setMinimumSize(QSize(110, 70));
        btnFAN->setFont(font2);
        btnFAN->setStyleSheet(QStringLiteral("background-color: rgb(6, 192, 76);"));

        horizontalLayout_5->addWidget(btnFAN);

        btnCO2 = new QPushButton(horizontalLayoutWidget);
        btnCO2->setObjectName(QStringLiteral("btnCO2"));
        sizePolicy1.setHeightForWidth(btnCO2->sizePolicy().hasHeightForWidth());
        btnCO2->setSizePolicy(sizePolicy1);
        btnCO2->setMinimumSize(QSize(110, 70));
        btnCO2->setFont(font2);
        btnCO2->setStyleSheet(QStringLiteral("background-color: rgb(6, 192, 76);"));

        horizontalLayout_5->addWidget(btnCO2);

        btnPOT = new QPushButton(horizontalLayoutWidget);
        btnPOT->setObjectName(QStringLiteral("btnPOT"));
        sizePolicy1.setHeightForWidth(btnPOT->sizePolicy().hasHeightForWidth());
        btnPOT->setSizePolicy(sizePolicy1);
        btnPOT->setMinimumSize(QSize(110, 70));
        btnPOT->setFont(font2);
        btnPOT->setStyleSheet(QStringLiteral("background-color: rgb(6, 192, 76);"));

        horizontalLayout_5->addWidget(btnPOT);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 0, 10, -1);
        label_12 = new QLabel(horizontalLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setMinimumSize(QSize(0, 20));
        label_12->setMaximumSize(QSize(360, 20));
        label_12->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout_10->addWidget(label_12);


        verticalLayout->addLayout(horizontalLayout_10);


        horizontalLayout->addLayout(verticalLayout);

        home->setCentralWidget(centralwidget);
        menubar = new QMenuBar(home);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 776, 27));
        menubar->setStyleSheet(QStringLiteral("background-color:rgb(244, 213, 114);"));
        menuSETTINGS = new QMenu(menubar);
        menuSETTINGS->setObjectName(QStringLiteral("menuSETTINGS"));
        menuSETTINGS->setStyleSheet(QStringLiteral(""));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        home->setMenuBar(menubar);
        statusbar = new QStatusBar(home);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        home->setStatusBar(statusbar);

        menubar->addAction(menuSETTINGS->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuSETTINGS->addAction(actionPARAMS);
        menuSETTINGS->addAction(actionCALIBRATION);
        menuAbout->addAction(actionVersion);

        retranslateUi(home);
        QObject::connect(actionPARAMS, SIGNAL(triggered()), home, SLOT(openPARAMS()));
        QObject::connect(btnSTATUS, SIGNAL(clicked()), home, SLOT(openLOG()));
        QObject::connect(actionVersion, SIGNAL(triggered()), home, SLOT(openVERSION()));
        QObject::connect(actionCALIBRATION, SIGNAL(triggered()), home, SLOT(openCALIBRATE()));

        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QMainWindow *home)
    {
        home->setWindowTitle(QApplication::translate("home", "MISURE ACQUARIO", 0));
        actionVersion->setText(QApplication::translate("home", "Version", 0));
        actionPARAMS->setText(QApplication::translate("home", "PARAMS", 0));
        actionCALIBRATION->setText(QApplication::translate("home", "CALIBRATION", 0));
        label->setText(QApplication::translate("home", "AQUARIUM", 0));
        label_2->setText(QApplication::translate("home", "AUTOMATIC MONITORING SYSTEM", 0));
        btnSTATUS->setText(QApplication::translate("home", "STATO DEL SISTEMA", 0));
        label_3->setText(QApplication::translate("home", "TEMPERATURA", 0));
        barTEMP->setFormat(QApplication::translate("home", "-------------------", 0));
        lblTEMP->setText(QApplication::translate("home", "24\302\260C", 0));
        label_4->setText(QApplication::translate("home", "ACIDITA'", 0));
        barPH->setFormat(QApplication::translate("home", "-------------------", 0));
        lblPH->setText(QApplication::translate("home", "7.05", 0));
        label_9->setText(QApplication::translate("home", "LIVELLO", 0));
        barLEV->setFormat(QString());
        lblLEV->setText(QApplication::translate("home", "OK", 0));
        lblDATE->setText(QApplication::translate("home", "Mer 15 Feb 2018", 0));
        label_7->setText(QApplication::translate("home", "PERCENTUALE POTENZA LUCI", 0));
        label_8->setText(QApplication::translate("home", "PROGRAMMAZIONE ACCENSIONE SPEGNIMENTO", 0));
        btnFAN->setText(QApplication::translate("home", "VENTOLE", 0));
        btnCO2->setText(QApplication::translate("home", "CO2", 0));
        btnPOT->setText(QApplication::translate("home", "POTASSIO", 0));
        label_12->setText(QApplication::translate("home", "Davide Tomasella 2017/2018", 0));
        menuSETTINGS->setTitle(QApplication::translate("home", "SETTINGS", 0));
        menuAbout->setTitle(QApplication::translate("home", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H
