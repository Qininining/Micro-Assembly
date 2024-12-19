#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_Distance->setText("1000000");
    ui->lineEdit_Velocity->setText("10000");
    ui->lineEdit_ScanA->setText("2048");
    ui->lineEdit_ScanR->setText("50");

    BlueSeries = new QLineSeries();
    BlueSeries->setColor(Qt::blue);
    RedSeries = new QLineSeries();
    RedSeries->setColor(Qt::red);
    GreenSeries = new QLineSeries();
    GreenSeries->setColor(Qt::green);
    minYBlue = 0, maxYBlue = 0;
    minYRed = 0, maxYRed = 0;
    minYGreen = 0, maxYGreen = 0;


    chart = new QChart();
    chart->legend()->hide(); // 隐藏图例
    chart->addSeries(BlueSeries);
    chart->createDefaultAxes(); // 创建默认轴
    chart->setTitle("Position");
    ui->charts->setChart(chart);
    ui->charts->setRenderHint(QPainter::Antialiasing); // 抗锯齿


    chartForce = new QChart();
    chartForce->legend()->hide(); // 隐藏图例
    chartForce->addSeries(RedSeries);
    chartForce->createDefaultAxes(); // 创建默认轴
    chartForce->setTitle("Force");
    ui->chartsForce->setChart(chartForce);
    ui->chartsForce->setRenderHint(QPainter::Antialiasing); // 抗锯齿

    forceSensor = new ForceSensor();
    Platform1 = new BaseMotionPlatform("usb:id:1139993081");
    UpdataThread = new TaskThread;
    GetdataThread = new TaskThread;
    time = 0;

    Saver = new DataSaver();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete Platform1;
    delete UpdataThread;
    delete BlueSeries;
    delete RedSeries;
    delete chart;
    delete forceSensor;
    delete chartForce;
    delete GreenSeries;
    delete GetdataThread;
    delete Saver;
    qDebug()<< "Program Ended";
}

void MainWindow::UpData()
{
    unsigned int channel = ui->comboBox_CHx->currentIndex();
    ui->Voltage->setText(QString::number(Platform1->GetVoltage(channel)));

    updateChart(ui->charts, time, minYBlue, maxYBlue);
    updateChart(ui->chartsForce, time, minYRed, maxYRed);
}

void MainWindow::GetData()
{
    unsigned int channel = ui->comboBox_CHx->currentIndex();
    long long pos = Platform1->GetPosition(channel);
    long long absForce = 0;
    long long relForce = forceSensor->ReadCurrentForce(1, absForce);
    getdateSeries(BlueSeries, time++, pos, minYBlue, maxYBlue);
    if(absForce>=0){
        getdateSeries(RedSeries, time, relForce, minYRed, maxYRed);
        Saver->addDataPoint(time, absForce, pos);
    }


}

void MainWindow::on_But_UpData_clicked(bool checked)
{
    if(checked){
        GetdataThread->runTask(50, this, &MainWindow::GetData);
        UpdataThread->runTask(500, this, &MainWindow::UpData);
    }
    else{
        UpdataThread->stopTask();
        GetdataThread->stopTask();
    }
}


void MainWindow::updateChart(QChartView *chartView, double t, qreal minY, qreal maxY)
{
    // 更新x轴范围
    auto axesX = chartView->chart()->axes(Qt::Horizontal);
    if (!axesX.isEmpty()) {
        QValueAxis *axisX = qobject_cast<QValueAxis*>(axesX.first());
        if (axisX) {
            axisX->setRange(0, t); // 更新x轴范围以适应新数据
        }
    }

    // 更新y轴范围
    auto axesY = chartView->chart()->axes(Qt::Vertical);
    if (!axesY.isEmpty()) {
        QValueAxis *axisY = qobject_cast<QValueAxis*>(axesY.first());
        if (axisY) {
            const qreal margin = 0;
            // 设置y轴范围
            axisY->setRange(minY - margin, maxY + margin);
        }
    }
}


void MainWindow::getdateSeries(QLineSeries *series, double t, double pos, qreal &minY, qreal &maxY)
{
    // 添加新的数据点
    series->append(t, pos);

    // 增量更新最小值和最大值
    if (series->count() == 1) { // 初始化第一个点的情况
        minY = pos;
        maxY = pos;
    } else {
        minY = std::min(minY, pos);
        maxY = std::max(maxY, pos);
    }
}



void MainWindow::on_But_ClearChart_clicked()
{
    RedSeries->clear(); // 清除所有数据点
    BlueSeries->clear(); // 清除所有数据点
    Saver->clearCache();

    time = 0;

    minYBlue = 0, maxYBlue = 0;
    minYRed = 0, maxYRed = 0;

    // 重置X轴和Y轴范围
    QValueAxis *axisX = qobject_cast<QValueAxis*>(ui->charts->chart()->axes(Qt::Horizontal).first());
    if (axisX) {
        axisX->setRange(0, 1); // 重置X轴范围
    }

    QValueAxis *axisY = qobject_cast<QValueAxis*>(ui->charts->chart()->axes(Qt::Vertical).first());
    if (axisY) {
        axisY->setRange(0, 1); // 重置Y轴范围
    }

    // 重置X轴和Y轴范围
    axisX = qobject_cast<QValueAxis*>(ui->chartsForce->chart()->axes(Qt::Horizontal).first());
    if (axisX) {
        axisX->setRange(0, 1); // 重置X轴范围
    }

    axisY = qobject_cast<QValueAxis*>(ui->chartsForce->chart()->axes(Qt::Vertical).first());
    if (axisY) {
        axisY->setRange(0, 1); // 重置Y轴范围
    }
}

void MainWindow::on_Connect_clicked(bool checked)
{
    if(checked){
        Platform1->ConnectToBaseMotion();
        ui->Connect->setText("Platform Disconnect");
    }
    else{
        Platform1->Disconnect();
        ui->Connect->setText("Platform Connect");
    }
}


void MainWindow::on_But_Back_clicked()
{
    bool ok;
    unsigned int channel = ui->comboBox_CHx->currentIndex();
    signed int distance = -1 * ui->lineEdit_Distance->text().toInt(&ok);

    if (ok) {
        Platform1->GotoPositionRelative(channel, distance);
        //QMessageBox::information(this, "Success", QString("Distance: %1").arg(distance));
    } else {
        // 转换失败
        QMessageBox::warning(this, "Error", "Please enter a valid signed integer.");
    }
}


void MainWindow::on_But_Forward_clicked()
{
    bool ok;
    signed int channel = ui->comboBox_CHx->currentIndex();
    unsigned int distance = ui->lineEdit_Distance->text().toInt(&ok);

    if (ok) {
        Platform1->GotoPositionRelative(channel, distance);
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid signed integer.");
    }
}


void MainWindow::on_But_Stop_clicked()
{
    Platform1->Stop(CH1);
    Platform1->Stop(CH2);
    Platform1->Stop(CH3);
}


void MainWindow::on_But_Forward_V_pressed()
{
    bool ok;
    signed int channel = ui->comboBox_CHx->currentIndex();
    signed int velocity = ui->lineEdit_Velocity->text().toInt(&ok);

    if (ok) {
        Platform1->setVelocity(channel, velocity, 5000000000);
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid signed integer.");
    }
}


void MainWindow::on_But_Forward_V_released()
{
    signed int channel = ui->comboBox_CHx->currentIndex();
    Platform1->closeVelocityMode(channel);
}


void MainWindow::on_But_Back_V_pressed()
{
    bool ok;
    signed int channel = ui->comboBox_CHx->currentIndex();
    signed int velocity = -1 * ui->lineEdit_Velocity->text().toInt(&ok);

    if (ok) {
        Platform1->setVelocity(channel, velocity, 5000000000);
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid signed integer.");
    }
}


void MainWindow::on_But_Back_V_released()
{
    signed int channel = ui->comboBox_CHx->currentIndex();
    Platform1->closeVelocityMode(channel);
}


void MainWindow::on_But_SetVoltage_clicked()
{
    bool ok;
    signed int channel = ui->comboBox_CHx->currentIndex();
    unsigned int target = ui->lineEdit_ScanA->text().toUInt(&ok);

    if (ok) {
        Platform1->ScanMoveAbsolute(channel, target, 100);
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid signed integer.");
    }
}


void MainWindow::on_But_Forward_Scan_clicked()
{
    bool ok;
    signed int channel = ui->comboBox_CHx->currentIndex();
    signed int target = ui->lineEdit_ScanR->text().toUInt(&ok);

    if (ok) {
        Platform1->ScanMoveRelative(channel, target, 100);
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid signed integer.");
    }
}


void MainWindow::on_But_Back_Scan_clicked()
{
    bool ok;
    signed int channel = ui->comboBox_CHx->currentIndex();
    signed int target = -1 * ui->lineEdit_ScanR->text().toUInt(&ok);

    if (ok) {
        Platform1->ScanMoveRelative(channel, target, 100);
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid signed integer.");
    }
}



void MainWindow::on_But_ConnectToForce_clicked(bool checked)
{
    long long force;
    if(checked)
    {
        ui->But_ConnectToForce->setText("Force Disconnect ");
        forceSensor->Connect(L"COM5", 921600, NOPARITY, 8, ONESTOPBIT);
        force = forceSensor->ReadCurrentForce(1);
        forceSensor->SetReferenceZero(force);
    }
    else
    {
        ui->But_ConnectToForce->setText("Force Connect ");
        forceSensor->DisConnect();
    }
}


void MainWindow::on_But_Zero_clicked()
{
    signed int channel = ui->comboBox_CHx->currentIndex();
    Platform1->setPosition(channel);
}


void MainWindow::on_But_Goto_clicked()
{
    bool ok;
    signed int channel = ui->comboBox_CHx->currentIndex();
    unsigned int distance = ui->lineEdit_Distance->text().toInt(&ok);

    if (ok) {
        Platform1->GotoPositionAbsolute(channel, distance);
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid signed integer.");
    }
}


void MainWindow::on_But_Save_clicked()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString fileName = currentTime.toString("yyyyMMddhhmmss") + ".xlsx";
    bool success = Saver->saveExcelDocument(fileName);
    if(success){
        QMessageBox::warning(this, "Success", "Success");
    }else{
        QMessageBox::warning(this, "Error", "Error");
    }
}

