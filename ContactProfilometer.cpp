#include "ContactProfilometer.h"

#include <cmath>

ContactProfilometer::ContactProfilometer(const char* location, wstring serial_name)
    :BaseMotionPlatform(location)
{
    forceSensor = new ForceSensor;
    forceSerial = serial_name;
}

ContactProfilometer::~ContactProfilometer()
{

}


void ContactProfilometer::Connect()
{
//    forceSensor->Connect(forceSerial, 921600, NOPARITY, 8, ONESTOPBIT);
    ConnectToBaseMotion();
}
