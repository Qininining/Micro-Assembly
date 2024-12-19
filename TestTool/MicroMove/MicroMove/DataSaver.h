#ifndef DATASAVER_H
#define DATASAVER_H

#include <QObject>
#include <QDateTime>
#include <QVector>
#include "xlsxdocument.h" // 确保包含QXlsx的头文件
using namespace QXlsx;

class DataSaver : public QObject
{
    Q_OBJECT
public:
    explicit DataSaver(QObject *parent = nullptr);
    ~DataSaver();

    // 添加数据点的方法
    void addDataPoint(unsigned int timestamp, long long force, long long displacement);

    // 创建Excel文档并写入数据，但不保存
    bool saveExcelDocument(const QString &filePath);

    // 清除所有数据点，以便为新的Excel文件准备
    void clearCache();

private:
    struct DataPoint {
        unsigned int timestamp;
        long long force;
        long long displacement;
    };

    QVector<DataPoint> m_dataPoints; // 存储数据点的容器
};

#endif // DATASAVER_H

//// 假设dataSaver是DataSaver的一个实例
//dataSaver.createExcelDocument();
//if (dataSaver.saveExcelDocument("path/to/first/excel/file.xlsx")) {
//    dataSaver.clearCache(); // 清除缓存，为下一次使用做准备
//}

//// 现在你可以再次添加数据点，并为另一个文件创建Excel文档
//dataSaver.addDataPoint(QDateTime::currentDateTime(), 500, 123456789LL);
//dataSaver.createExcelDocument();
//dataSaver.saveExcelDocument("path/to/second/excel/file.xlsx");
