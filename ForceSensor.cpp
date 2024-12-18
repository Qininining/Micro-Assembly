#include "ForceSensor.h"

ForceSensor::ForceSensor()
{
    referenceZero = 0;
    force = 0;
}

ForceSensor::~ForceSensor()
{
}
/*******************************************************************
* 名称： openSyn
* 功能： 同步方式打开串口,并配置默认信息
* 参数：
    serial_name：串口名称
    baud_rate  ：波特率，取值如下
        ......
        CBR_9600    9600bps
        CBR_14400   14400bps
        ......
    parity     ：校验方式
        EVENPARITY  偶校验
        MARKPARITY  标号校验
        NOPARITY    无校验
        ODDPARITY   奇校验
        SPACEPARITY 空格校验
    byte_size  ：数据位大小
        4，5，6，7，8
    stop_bits  ：停止位
        ONESTOPBIT      1个停止位
        ONE5STOPBITS    1.5个停止位
        TWOSTOPBITS     2个停止位
* 返回： 正确返回为ture，错误返回为false
*******************************************************************/
bool ForceSensor::Connect(wstring serial_name, unsigned int baud_rate, unsigned char parity, unsigned char byte_size, unsigned char stop_bits)
{
    if (!com.openSyn(serial_name, baud_rate, parity, byte_size, stop_bits))
    {
        cout << "ForceSensor Conect Failed!!!" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

long long ForceSensor::ReadCurrentForce(bool relative)
{
    string strbuf;
    long long num = 0;

    com.readCurrentData(buffer, sizeof(buffer) - 1);
    strbuf = buffer;
    num = GetForceFromBuffer(strbuf);
    force = num;
    if(relative)
        num = num - referenceZero;

    return num;
}

long long ForceSensor::ReadCurrentForce(bool relative, long long &absForce)
{
    string strbuf;
    long long num = 0;

    com.readCurrentData(buffer, sizeof(buffer) - 1);
    strbuf = buffer;
    num = GetForceFromBuffer(strbuf);
    absForce = num;
    if(relative)
        num = num - referenceZero;

    return num;
}

bool ForceSensor::SetReferenceZero(long long num)
{
    referenceZero = num;
    // cout<<"Set referenceZero:\t"<<referenceZero<<endl;
    return 1;
}

bool ForceSensor::DisConnect()
{
    com.closeComm();
    return 1;
}

long long ForceSensor::GetForceFromBuffer(string buffer)
{
    string result = "\0";
    long long num = 0;

    if (buffer.length() == 10)
    {
        if (buffer[6] == '0' && buffer[7] == 'd' && buffer[8] == '\r' && buffer[9] == '\n')
        {
            result = buffer.substr(0, 6);
            // cout << "result: " << result << endl;
            try
            {
                num = stoi(result, nullptr, 16);
            }
            catch (const invalid_argument &e)
            {
                cout << "Invalid argument: " << e.what() << '\n';
            }
            catch (const out_of_range &e)
            {
                cout << "Out of range: " << e.what() << '\n';
            }
            return num;
        }
        else
        {
            cout << "error data format:" << sizeof(buffer)<< buffer << endl;
            return -1;
        }
    }
    else
    {
        cout << "error data length:" << sizeof(buffer) << endl;
        return -1;
    }
}
