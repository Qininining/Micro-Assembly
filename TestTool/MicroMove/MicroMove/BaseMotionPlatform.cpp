#include "BaseMotionPlatform.h"

BaseMotionPlatform::BaseMotionPlatform(const char* location)
{
    loc = location;
    motionSta = 0;

}

BaseMotionPlatform::~BaseMotionPlatform()
{
    if(motionSta)
        NT_CloseSystem(ntHandle);
}




void BaseMotionPlatform::ConnectToBaseMotion()
{
    unsigned int numOfChannels;
    error = NT_OpenSystem(&ntHandle, loc, "sync");
    if (error)
        qDebug() << "Open NT system: Error: " << error << "ntHandle:" << ntHandle;
    else{
        motionSta = 1;
        qDebug() << "Open NT system  successfully!" << "ntHandle:" << ntHandle;
        error = NT_GetNumberOfChannels(ntHandle, &numOfChannels);
        qDebug() << "Number of Channels:" << numOfChannels;
    }

}

void BaseMotionPlatform::Disconnect()
{
    if(motionSta)
    {
        error = NT_CloseSystem(ntHandle);
        if (error)
            qDebug() << "Close NT system: Error: " << error << "ntHandle:" << ntHandle;
        else{
            qDebug() << "Close NT system  successfully!" << "ntHandle:" << ntHandle;
            motionSta = 0;
        }
    }
    else
        qDebug() << "Close NT system: Error: " << "Platform not Connected";
}

void BaseMotionPlatform::GotoPositionAbsolute(NT_INDEX channelIndex, signed int position)
{
    error = NT_GotoPositionAbsolute_S(ntHandle,
    channelIndex,
    position);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::GotoPositionAbsolute ERROR:" << error;
}

void BaseMotionPlatform::GotoPositionRelative(NT_INDEX channelIndex, signed int diff)
{
    error = NT_GotoPositionRelative_S(ntHandle,channelIndex,diff);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::GotoPositionRelative ERROR:" << error;
}

signed int BaseMotionPlatform::GetPosition(NT_INDEX channelIndex)
{
    int pos;
    error = NT_GetPosition_S(ntHandle,
    channelIndex,
    &pos);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::GetPosition ERROR:" << error;
    return pos;
}

void BaseMotionPlatform::StepMove(NT_INDEX channelIndex, signed int steps,unsigned int amplitude,unsigned int frequency)
{
    error = NT_StepMove_S(ntHandle,channelIndex,steps,amplitude,frequency);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::StepMove ERROR:" << error;
}

void BaseMotionPlatform::ContinueMove(NT_INDEX channelIndex, bool dir, unsigned int amplitude,unsigned int frequency)
{
    signed int steps = 30000;
    steps = steps * dir;
    error = NT_StepMove_S(ntHandle,channelIndex,steps,amplitude,frequency);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::StepMove ERROR:" << error;
}
//● target (unsigned 32bit)，输入 – 绝对目标位置。有效输入范围为 0...4,095，0 对应
//0V，4,095 对于 100V。
//● scanSpeed (unsigned 32bit), 输入 - 扫描速度。有效输入范围是 1 ... 4,095,000。
//将 0-100V 等分成 4096 份，扫描速度表示每秒扫描电压变化的份数。比如，值为 1
//时，在从 0 扫描到 4,095 需要 4,095 秒，而全速扫描（值为 4,095,000）只需一毫秒。
void BaseMotionPlatform::ScanMoveAbsolute(NT_INDEX channelIndex, unsigned int target, unsigned int time)
{
    error = NT_ScanMoveAbsolute_S(ntHandle, channelIndex,target, 4095000/time);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::ScanMoveAbsolute ERROR:" << error;
}

void BaseMotionPlatform::ScanMoveRelative(NT_INDEX channelIndex, signed int target, unsigned int time)
{
    error = NT_ScanMoveRelative_S(ntHandle, channelIndex,target, 4095000/time);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::ScanMoveRelative ERROR:" << error;
}
//● speed (unsigned 32bit)，输入 - 设置定位台匀速运动的速度值,线性定位台的单位是
//nm/s,旋转定位台的单位是 u°/s。有效值范围是 0...5,000,000。0 默认禁用速度控制。
void BaseMotionPlatform::setVelocity(NT_INDEX channelIndex, signed int velocity, long long target)
{
    int dir = 0;
    unsigned int speed = 0;
    if(velocity >= 0)
    {
        dir = 1;
        speed = velocity;
    }

    else
    {
        dir = -1;
        speed = -1 * velocity;
    }
    error = NT_SetClosedLoopMoveSpeed_S(ntHandle, channelIndex, NT_SPEED_ENABLED, speed);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::setVelocity ERROR(1):" << error;
    error = NT_GotoPositionRelative_S(ntHandle, channelIndex, target * dir);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::setVelocity ERROR(2):" << error;
}

void BaseMotionPlatform::closeVelocityMode(NT_INDEX channelIndex)
{
    error = NT_Stop_S(ntHandle, channelIndex);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::closeVelocityMode ERROR(1):" << error;
    error = NT_SetClosedLoopMoveSpeed_S(ntHandle, channelIndex, NT_SPEED_DISABLED, 0);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::closeVelocityMode ERROR(2):" << error;
    NT_SetClosedLoopHoldEnabled_S(ntHandle,channelIndex,NT_CLOSELOOP_ENABLED);
}

void BaseMotionPlatform::setPosition(NT_INDEX channelIndex)
{
    error = NT_SetPosition_S(ntHandle, channelIndex, 0);
    if (error != NT_OK)
        qDebug() << "BaseMotionPlatform::setPosition ERROR:" << error;
}

void BaseMotionPlatform::Stop(NT_INDEX channelIndex)
{
    error = NT_Stop_S(ntHandle, channelIndex);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::Stop ERROR:" << error;
}

unsigned int BaseMotionPlatform::GetVoltage(NT_INDEX channelIndex)
{
    unsigned int Vol;
    error = NT_GetVoltageLevel_S(ntHandle,channelIndex,&Vol);
    if(error != NT_OK)
        qDebug() << "BaseMotionPlatform::GetVoltage ERROR:" << error;
    return Vol;
}


void BaseMotionPlatform::getMotionInfo()
{
    unsigned int numOfChannels;
    char info[200];
    unsigned int size = sizeof(info);
    unsigned int known;
    unsigned int speed;

    if(motionSta)
    {
        error = NT_GetNumberOfChannels(ntHandle, &numOfChannels);
        if(error != NT_OK)
            qDebug() << "BaseMotionPlatform::getMotionInfo ERROR(1):" << error;
        else
            qDebug() << "Number of Channels:" << numOfChannels;

        error = NT_GetVersionInfo(ntHandle, info, &size);
        if(error != NT_OK)
            qDebug() << "BaseMotionPlatform::getMotionInfo ERROR(2):" << error;
        else
            qDebug() << "VersionInfo:" << info;

        error = NT_GetPhysicalPositionKnown_S(ntHandle,0,&known);
        if(error != NT_OK)
            qDebug() << "BaseMotionPlatform::getMotionInfo ERROR(3):" << error;
        else
            qDebug() << "CH1 PhysicalPositionKnown:" << known;
        error = NT_GetPhysicalPositionKnown_S(ntHandle,1,&known);
        if(error != NT_OK)
            qDebug() << "BaseMotionPlatform::getMotionInfo ERROR(3):" << error;
        else
            qDebug() << "CH2 PhysicalPositionKnown:" << known;
        error = NT_GetPhysicalPositionKnown_S(ntHandle,2,&known);
        if(error != NT_OK)
            qDebug() << "BaseMotionPlatform::getMotionInfo ERROR(3):" << error;
        else
            qDebug() << "CH3 PhysicalPositionKnown:" << known;

        NT_GetClosedLoopMoveSpeed_S(ntHandle,0,&speed);
        if(error != NT_OK)
            qDebug() << "BaseMotionPlatform::getMotionInfo ERROR(4):" << error;
        else
            qDebug() << "CH1 ClosedLoopMoveSpeed:" << speed;
        NT_GetClosedLoopMoveSpeed_S(ntHandle,1,&speed);
        if(error != NT_OK)
            qDebug() << "BaseMotionPlatform::getMotionInfo ERROR(4):" << error;
        else
            qDebug() << "CH2 ClosedLoopMoveSpeed:" << speed;
        NT_GetClosedLoopMoveSpeed_S(ntHandle,2,&speed);
        if(error != NT_OK)
            qDebug() << "BaseMotionPlatform::getMotionInfo ERROR(4):" << error;
        else
            qDebug() << "CH3 ClosedLoopMoveSpeed:" << speed;
    }
    else
        qDebug() << "Platform not Connected";

}
