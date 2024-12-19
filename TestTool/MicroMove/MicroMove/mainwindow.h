#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QtCharts>
#include "BaseMotionPlatform.h"
#include "TaskThread.h"
#include "ForceSensor.h"
#include "DataSaver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Connect_clicked(bool checked);

    void on_But_Back_clicked();

    void on_But_Forward_clicked();

    void on_But_Stop_clicked();

    void on_But_Forward_V_pressed();

    void on_But_Forward_V_released();

    void on_But_Back_V_pressed();

    void on_But_Back_V_released();

    void on_But_SetVoltage_clicked();

    void on_But_Forward_Scan_clicked();

    void on_But_Back_Scan_clicked();

    void on_But_UpData_clicked(bool checked);

    void on_But_ClearChart_clicked();

    void on_But_ConnectToForce_clicked(bool checked);

    void on_But_Zero_clicked();

    void on_But_Goto_clicked();

    void on_But_Save_clicked();

private:
    Ui::MainWindow *ui;
    QLineSeries *BlueSeries;
    qreal minYBlue, maxYBlue;
    QLineSeries *RedSeries;
    qreal minYRed, maxYRed;
    QLineSeries *GreenSeries;
    qreal minYGreen, maxYGreen;
    qreal minYBlueSeries, maxYBlueSeries;
    QChart *chart;
    QChart *chartForce;
//    QChart *chartVoltage;

private:
    BaseMotionPlatform *Platform1;
    ForceSensor *forceSensor;

    TaskThread *UpdataThread;
    TaskThread *GetdataThread;
    int time;

    DataSaver *Saver;

private:
    void UpData();
    void GetData();
    void updateChart(QChartView *chartView, double t,  qreal minY, qreal maxY);
    void getdateSeries(QLineSeries *series, double t, double pos, qreal &minY, qreal &maxY);
};
#endif // MAINWINDOW_H
