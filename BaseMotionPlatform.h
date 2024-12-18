#ifndef BASEMOTIONPLATFORM_H
#define BASEMOTIONPLATFORM_H


#include <iostream>
#include <thread>
#include <QDebug>
#include "NanoDrive2.8.11/04_SDK/include/NTControl.h"

using namespace std;

#define CH1 0
#define CH2 1
#define CH3 2

class BaseMotionPlatform
{
public:
    BaseMotionPlatform(const char* location);
    virtual ~BaseMotionPlatform();

public:
    void ConnectToBaseMotion();
    void Disconnect();
    void GotoPositionAbsolute(NT_INDEX channelIndex, signed int position);
    void GotoPositionRelative(NT_INDEX channelIndex, signed int diff);
    void StepMove(NT_INDEX channelIndex, signed int steps,
                  unsigned int amplitude, unsigned int frequency);
    void ContinueMove(NT_INDEX channelIndex, bool dir,
                      unsigned int amplitude, unsigned int frequency);
    void ScanMoveAbsolute(NT_INDEX channelIndex, unsigned int target, unsigned int time);
    void ScanMoveRelative(NT_INDEX channelIndex, signed int target, unsigned int time);

    void setVelocity(NT_INDEX channelIndex, signed int velocity,  long long  target);
    void closeVelocityMode(NT_INDEX channelIndex);
    void setPosition(NT_INDEX channelIndex);
    unsigned int GetVoltage(NT_INDEX channelIndex);
    signed int GetPosition(NT_INDEX channelIndex);
    void getMotionInfo();

    void Stop(NT_INDEX channelIndex);

private:
    NT_STATUS error = NT_OK;
    NT_INDEX ntHandle;
    const char* loc;
    int motionSta;

};

#endif // BASEMOTIONPLATFORM_H
