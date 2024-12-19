#ifndef FORCESENSOR_H
#define FORCESENSOR_H

#include <iostream>
#include "SerialInterface.h"

using namespace std;

class ForceSensor
{
public:
    // 构造函数，初始化 ForceSensor 对象
    ForceSensor();
    ForceSensor(wstring serial_name);
    // 析构函数，清理 ForceSensor 对象所占用的资源
    ~ForceSensor();

public:
    // 连接到指定的串行端口
    bool Connect(wstring serial_name, unsigned int baud_rate,
                 unsigned char parity, unsigned char byte_size,
                 unsigned char stop_bits);
    // 从传感器读取当前力值
    long long ReadCurrentForce(bool relative);
    long long ReadCurrentForce(bool relative, long long &absForce);
    // 设置参考零点
    bool SetReferenceZero(long long num);
    // 断开与传感器的连接
    bool DisConnect();

    bool SetDsensitivity(double dsensitivity);

private:
    // 保存参考零点的值
    long long referenceZero;
    long long force;
    // 缓冲区，用于临时存储从传感器读取的数据
    char buffer[11];
    // 串行接口对象，用于处理与传感器的通信
    SerialInterface com;
    // 从缓冲区中解析出力值
    long long GetForceFromBuffer(string buffer);
};

#endif

// @code
// #include <iostream>

// #include "ForceSensor.h"

// using namespace std;

// int main()
// {
//    int force;
//    ForceSensor forceSensor;

//    forceSensor.Connect(L"COM4", 921600, NOPARITY, 8, ONESTOPBIT);

//    force = forceSensor.ReadCurrentForce();

//    forceSensor.SetReferenceZero(force);

//    while (1)
//    {

//       force = forceSensor.ReadCurrentForce();

//       cout << force << endl;

//       getchar();
//    }

//    return 0;
// }
