#ifndef __SerialInterface_H_
#define __SerialInterface_H_
#include <Windows.h>
#include <iostream>
using namespace std;

class SerialInterface
{
private:
    /* data */
    HANDLE hCom;
    string last_error;
public:
    SerialInterface();
    ~SerialInterface();
public:
    //同步方式打开串口,并配置默认信息
    bool openSyn(wstring serial_name,unsigned int baud_rate,unsigned char parity, unsigned char byte_size, unsigned char stop_bits);
    //同步方式打开串口(需自己配置串口参数)
    bool openSyn(wstring serial_name);

    //设置推荐的缓冲大小
    bool setBufferSize(DWORD inputBuff,DWORD outBuffer);
    //设置超时
    bool setTimeouts(COMMTIMEOUTS &timeouts);
    //设置串口信息
    bool setDCB(DCB& dcb);

    //刷新缓冲区
    bool purgeBuff(DWORD flags);
    //刷新缓冲区
    bool flushBuff();
    //写数据
    DWORD writeData(char *buffer,int length);
    //读数据
    DWORD readData(char *buffer,int length);
    //读当前数据
    DWORD readCurrentData(char *buffer,int length);
    //写字符串
    DWORD writeStr(string str);
    //关闭串口
    void closeComm();
    //判断串口是否打开
    bool isOpened();
    //得到最后一次失败的错误信息
    string getSerialLastError();
private:
    //设置最后一次的错误信息
    void setSerialLastError(string error_msg);
    //清chu最后一次的错误信息
    void clearSerialLastError();
};

#endif /*__SerialInterface_H_*/



// @code

// #include <iostream>

// #include "ForceSensor.h"
// #include "SerialInterface.h"

// using namespace std;

// #define bufferLength 11

// #define BAUD_RATE 921600

// int main()
// {
//    char buffer[11] = "894E770b\r\n";
//    string strbuf = buffer;
//    SerialInterface com;

//    if (!com.openSyn(L"COM4", BAUD_RATE, NOPARITY, 8, ONESTOPBIT))
//    {
//       cout << com.getSerialLastError() << endl;
//       getchar();
//       return 0;
//    }
//    while (1)
//    {

//       com.readCurrentData(buffer, sizeof(buffer) - 1);

//       strbuf = buffer;
//       cout << "GetForceFromBuffer: " << GetForceFromBuffer(strbuf) << endl;

//       getchar();

//    }


//    com.closeComm();

//    return 0;
// }
