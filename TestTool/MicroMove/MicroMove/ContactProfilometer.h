#ifndef CONTACTPROFILOMETER_H
#define CONTACTPROFILOMETER_H

#include <iostream>
#include <thread>

#include "ForceSensor.h"
#include "BaseMotionPlatform.h"

using namespace std;

class ContactProfilometer:public BaseMotionPlatform
{
public:
    ContactProfilometer(const char* location,
                        wstring serial_name);
    virtual ~ContactProfilometer();

public:
    void Connect();

private:
    ForceSensor *forceSensor;
    wstring forceSerial;
    int force;


};

#endif // CONTACTPROFILOMETER_H
