#include "DataSaver.h"

DataSaver::DataSaver(QObject *parent)
    : QObject(parent)
{
}

DataSaver::~DataSaver()
{
    // 析构函数
}

void DataSaver::addDataPoint(unsigned int timestamp, long long force, long long displacement)
{
    DataPoint point{timestamp, force, displacement};
    m_dataPoints.append(point);
}

bool DataSaver::saveExcelDocument(const QString &filePath)
{
    Document m_xlsx;
    // 写入表头
    m_xlsx.write(1, 1, QStringLiteral("Timestamp"));
    m_xlsx.write(1, 2, QStringLiteral("Force (N)"));
    m_xlsx.write(1, 3, QStringLiteral("Displacement (mm)"));

    // 写入数据
    for (int i = 0; i < m_dataPoints.size(); ++i) {
        const auto& point = m_dataPoints[i];
        m_xlsx.write(i + 2, 1, point.timestamp); // 时间格式化为字符串
        m_xlsx.write(i + 2, 2, point.force); // 将unsigned int转换为double写入
        m_xlsx.write(i + 2, 3, point.displacement); // 将long long转换为double写入
    }
    return m_xlsx.saveAs(filePath);
}



void DataSaver::clearCache()
{
    // 清空数据点容器，以便为新的Excel文件准备
    m_dataPoints.clear();
}
