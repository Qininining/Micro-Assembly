/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *But_UpData;
    QtCharts::QChartView *charts;
    QPushButton *But_ClearChart;
    QPushButton *But_Zero;
    QtCharts::QChartView *chartsForce;
    QWidget *widget_5;
    QWidget *widget_3;
    QLabel *label_16;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_Distance;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *But_Forward;
    QPushButton *But_Back;
    QPushButton *But_Goto;
    QLabel *label_18;
    QWidget *widget_2;
    QLabel *label_13;
    QLabel *label_15;
    QPushButton *But_Stop;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_Velocity;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *But_Forward_V;
    QPushButton *But_Back_V;
    QWidget *widget_4;
    QLabel *label_19;
    QLabel *label_21;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_24;
    QLabel *Voltage;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_ScanA;
    QPushButton *But_SetVoltage;
    QLineEdit *lineEdit_ScanR;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *But_Forward_Scan;
    QPushButton *But_Back_Scan;
    QLabel *label_25;
    QWidget *widget_6;
    QLabel *label_33;
    QPushButton *Connect;
    QPushButton *But_ConnectToForce;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox_CHx;
    QLabel *label_34;
    QPushButton *But_Save;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1323, 745);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        But_UpData = new QPushButton(centralwidget);
        But_UpData->setObjectName(QString::fromUtf8("But_UpData"));
        But_UpData->setGeometry(QRect(610, 550, 161, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(16);
        But_UpData->setFont(font);
        But_UpData->setCheckable(true);
        charts = new QtCharts::QChartView(centralwidget);
        charts->setObjectName(QString::fromUtf8("charts"));
        charts->setGeometry(QRect(20, 30, 541, 321));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        charts->setFont(font1);
        But_ClearChart = new QPushButton(centralwidget);
        But_ClearChart->setObjectName(QString::fromUtf8("But_ClearChart"));
        But_ClearChart->setGeometry(QRect(750, 630, 161, 41));
        But_ClearChart->setFont(font);
        But_Zero = new QPushButton(centralwidget);
        But_Zero->setObjectName(QString::fromUtf8("But_Zero"));
        But_Zero->setGeometry(QRect(800, 550, 161, 41));
        But_Zero->setFont(font);
        chartsForce = new QtCharts::QChartView(centralwidget);
        chartsForce->setObjectName(QString::fromUtf8("chartsForce"));
        chartsForce->setGeometry(QRect(20, 380, 541, 321));
        chartsForce->setFont(font1);
        widget_5 = new QWidget(centralwidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(550, 10, 751, 521));
        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(30, 270, 361, 241));
        label_16 = new QLabel(widget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(10, 10, 331, 211));
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgba(137, 245, 255, 15);\n"
"border-width: 1px;border-style: solid;border-color: rgb(0, 0, 0);"));
        layoutWidget = new QWidget(widget_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 50, 291, 101));
        layoutWidget->setFont(font1);
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        lineEdit_Distance = new QLineEdit(layoutWidget);
        lineEdit_Distance->setObjectName(QString::fromUtf8("lineEdit_Distance"));
        lineEdit_Distance->setFont(font);
        lineEdit_Distance->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lineEdit_Distance);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font2);
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_17);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        But_Forward = new QPushButton(layoutWidget);
        But_Forward->setObjectName(QString::fromUtf8("But_Forward"));
        But_Forward->setFont(font);

        horizontalLayout_6->addWidget(But_Forward);

        But_Back = new QPushButton(layoutWidget);
        But_Back->setObjectName(QString::fromUtf8("But_Back"));
        But_Back->setFont(font);

        horizontalLayout_6->addWidget(But_Back);


        verticalLayout->addLayout(horizontalLayout_6);

        But_Goto = new QPushButton(widget_3);
        But_Goto->setObjectName(QString::fromUtf8("But_Goto"));
        But_Goto->setGeometry(QRect(30, 170, 291, 31));
        But_Goto->setFont(font);
        label_18 = new QLabel(widget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(120, 0, 121, 56));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        label_18->setFont(font3);
        label_18->setAlignment(Qt::AlignCenter);
        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(380, 270, 361, 241));
        label_13 = new QLabel(widget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 10, 331, 211));
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgba(137, 245, 255, 15);\n"
"border-width: 1px;border-style: solid;border-color: rgb(0, 0, 0);"));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(110, 0, 121, 56));
        label_15->setFont(font3);
        label_15->setAlignment(Qt::AlignCenter);
        But_Stop = new QPushButton(widget_2);
        But_Stop->setObjectName(QString::fromUtf8("But_Stop"));
        But_Stop->setGeometry(QRect(30, 170, 281, 32));
        But_Stop->setFont(font);
        layoutWidget1 = new QWidget(widget_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(31, 51, 281, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        lineEdit_Velocity = new QLineEdit(layoutWidget1);
        lineEdit_Velocity->setObjectName(QString::fromUtf8("lineEdit_Velocity"));
        lineEdit_Velocity->setFont(font);
        lineEdit_Velocity->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(lineEdit_Velocity);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font2);
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_14);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        But_Forward_V = new QPushButton(layoutWidget1);
        But_Forward_V->setObjectName(QString::fromUtf8("But_Forward_V"));
        But_Forward_V->setFont(font);
        But_Forward_V->setCheckable(true);

        horizontalLayout_7->addWidget(But_Forward_V);

        But_Back_V = new QPushButton(layoutWidget1);
        But_Back_V->setObjectName(QString::fromUtf8("But_Back_V"));
        But_Back_V->setFont(font);

        horizontalLayout_7->addWidget(But_Back_V);


        verticalLayout_2->addLayout(horizontalLayout_7);

        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(380, 40, 361, 241));
        label_19 = new QLabel(widget_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 10, 331, 211));
        label_19->setStyleSheet(QString::fromUtf8("background-color: rgba(137, 245, 255, 15);\n"
"border-width: 1px;border-style: solid;border-color: rgb(0, 0, 0);"));
        label_21 = new QLabel(widget_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(70, 20, 225, 24));
        label_21->setFont(font3);
        label_21->setAlignment(Qt::AlignCenter);
        layoutWidget2 = new QWidget(widget_4);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 60, 271, 144));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_24 = new QLabel(layoutWidget2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font2);
        label_24->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_24);

        Voltage = new QLabel(layoutWidget2);
        Voltage->setObjectName(QString::fromUtf8("Voltage"));
        Voltage->setFont(font);
        Voltage->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(Voltage);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lineEdit_ScanA = new QLineEdit(layoutWidget2);
        lineEdit_ScanA->setObjectName(QString::fromUtf8("lineEdit_ScanA"));
        lineEdit_ScanA->setFont(font);
        lineEdit_ScanA->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(lineEdit_ScanA);

        But_SetVoltage = new QPushButton(layoutWidget2);
        But_SetVoltage->setObjectName(QString::fromUtf8("But_SetVoltage"));
        But_SetVoltage->setFont(font);

        horizontalLayout_5->addWidget(But_SetVoltage);


        verticalLayout_3->addLayout(horizontalLayout_5);

        lineEdit_ScanR = new QLineEdit(layoutWidget2);
        lineEdit_ScanR->setObjectName(QString::fromUtf8("lineEdit_ScanR"));
        lineEdit_ScanR->setFont(font);
        lineEdit_ScanR->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lineEdit_ScanR);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        But_Forward_Scan = new QPushButton(layoutWidget2);
        But_Forward_Scan->setObjectName(QString::fromUtf8("But_Forward_Scan"));
        But_Forward_Scan->setFont(font);

        horizontalLayout_4->addWidget(But_Forward_Scan);

        But_Back_Scan = new QPushButton(layoutWidget2);
        But_Back_Scan->setObjectName(QString::fromUtf8("But_Back_Scan"));
        But_Back_Scan->setFont(font);

        horizontalLayout_4->addWidget(But_Back_Scan);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label_25 = new QLabel(widget_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(20, 20, 721, 481));
        label_25->setStyleSheet(QString::fromUtf8("\n"
"border-width: 1px;border-style: solid;border-color: rgb(0, 0, 0);"));
        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(30, 40, 351, 241));
        label_33 = new QLabel(widget_6);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(10, 10, 331, 211));
        label_33->setStyleSheet(QString::fromUtf8("background-color: rgba(137, 245, 255, 15);\n"
"border-width: 1px;border-style: solid;border-color: rgb(0, 0, 0);"));
        Connect = new QPushButton(widget_6);
        Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->setGeometry(QRect(50, 60, 241, 41));
        Connect->setFont(font2);
        Connect->setCheckable(true);
        But_ConnectToForce = new QPushButton(widget_6);
        But_ConnectToForce->setObjectName(QString::fromUtf8("But_ConnectToForce"));
        But_ConnectToForce->setGeometry(QRect(60, 110, 211, 41));
        But_ConnectToForce->setFont(font2);
        But_ConnectToForce->setCheckable(true);
        layoutWidget3 = new QWidget(widget_6);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(70, 160, 191, 40));
        layoutWidget3->setFont(font1);
        horizontalLayout_2 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        horizontalLayout_2->addWidget(label);

        comboBox_CHx = new QComboBox(layoutWidget3);
        comboBox_CHx->addItem(QString());
        comboBox_CHx->addItem(QString());
        comboBox_CHx->addItem(QString());
        comboBox_CHx->setObjectName(QString::fromUtf8("comboBox_CHx"));
        comboBox_CHx->setFont(font);
        comboBox_CHx->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(comboBox_CHx);

        label_34 = new QLabel(widget_6);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(110, 10, 121, 41));
        label_34->setFont(font3);
        label_34->setAlignment(Qt::AlignCenter);
        label_25->raise();
        widget_3->raise();
        widget_2->raise();
        widget_4->raise();
        widget_6->raise();
        But_Save = new QPushButton(centralwidget);
        But_Save->setObjectName(QString::fromUtf8("But_Save"));
        But_Save->setGeometry(QRect(940, 630, 161, 41));
        But_Save->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        chartsForce->raise();
        charts->raise();
        But_UpData->raise();
        But_ClearChart->raise();
        But_Zero->raise();
        widget_5->raise();
        But_Save->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1323, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        comboBox_CHx->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        But_UpData->setText(QApplication::translate("MainWindow", "UpData", nullptr));
        But_ClearChart->setText(QApplication::translate("MainWindow", "ClearChart", nullptr));
        But_Zero->setText(QApplication::translate("MainWindow", " SetPosZero", nullptr));
        label_16->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\344\275\215\347\275\256", nullptr));
        lineEdit_Distance->setInputMask(QString());
        label_17->setText(QApplication::translate("MainWindow", "nm", nullptr));
        But_Forward->setText(QApplication::translate("MainWindow", "Forward", nullptr));
        But_Back->setText(QApplication::translate("MainWindow", "Back", nullptr));
        But_Goto->setText(QApplication::translate("MainWindow", "Goto", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "\344\275\215\347\275\256\346\216\247\345\210\266", nullptr));
        label_13->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246\346\216\247\345\210\266", nullptr));
        But_Stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246", nullptr));
        lineEdit_Velocity->setInputMask(QString());
        label_14->setText(QApplication::translate("MainWindow", "nm/s", nullptr));
        But_Forward_V->setText(QApplication::translate("MainWindow", "Forward", nullptr));
        But_Back_V->setText(QApplication::translate("MainWindow", "Back", nullptr));
        label_19->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\346\216\247\345\210\266", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\347\224\265\345\216\213\357\274\232", nullptr));
        Voltage->setText(QApplication::translate("MainWindow", "0", nullptr));
        lineEdit_ScanA->setInputMask(QString());
        But_SetVoltage->setText(QApplication::translate("MainWindow", "SetVoltage", nullptr));
        lineEdit_ScanR->setInputMask(QString());
        But_Forward_Scan->setText(QApplication::translate("MainWindow", "Forward", nullptr));
        But_Back_Scan->setText(QApplication::translate("MainWindow", "Back", nullptr));
        label_25->setText(QString());
        label_33->setText(QString());
        Connect->setText(QApplication::translate("MainWindow", "Platform Connect", nullptr));
        But_ConnectToForce->setText(QApplication::translate("MainWindow", "Force Connect", nullptr));
        label->setText(QApplication::translate("MainWindow", "\351\200\232\351\201\223\357\274\232", nullptr));
        comboBox_CHx->setItemText(0, QApplication::translate("MainWindow", "CH1", nullptr));
        comboBox_CHx->setItemText(1, QApplication::translate("MainWindow", "CH2", nullptr));
        comboBox_CHx->setItemText(2, QApplication::translate("MainWindow", "CH3", nullptr));

        label_34->setText(QApplication::translate("MainWindow", "Init", nullptr));
        But_Save->setText(QApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
