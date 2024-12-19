/**********************************************************************
* Copyright (C) 2024  NATORS£¬All Rights Reserved
*
* File name: NTControl.h
* Author   : Nators
*
* This is the software interface to the Nano Positioning System.
* Please refer to the Programmer's Guide for a detailed documentation.
*
* THIS  SOFTWARE, DOCUMENTS, FILES AND INFORMATION ARE PROVIDED 'AS IS'
* WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
* BUT  NOT  LIMITED  TO,  THE  IMPLIED  WARRANTIES  OF MERCHANTABILITY,
* FITNESS FOR A PURPOSE, OR THE WARRANTY OF NON-INFRINGEMENT.
* THE  ENTIRE  RISK  ARISING OUT OF USE OR PERFORMANCE OF THIS SOFTWARE
* REMAINS WITH YOU.
* IN  NO  EVENT  SHALL  THE  NATORS  GMBH  BE  LIABLE  FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL, CONSEQUENTIAL OR OTHER DAMAGES ARISING
* OUT OF THE USE OR INABILITY TO USE THIS SOFTWARE.
**********************************************************************/
#pragma warning(disable : 4996)
#ifndef NPSCONTROL_H
#define NPSCONTROL_H

#ifdef NPSCONTROL_EXPORTS
	#define NPSCONTROL_API __declspec(dllexport)
#else
	#define NPSCONTROL_API __declspec(dllimport)
#endif

#define NPSCONTROL_CC  __cdecl


typedef unsigned int NT_STATUS;
typedef unsigned int NT_INDEX;
typedef unsigned int NT_PACKET_TYPE;


typedef struct NT_packet {
	NT_PACKET_TYPE packetType; // type of packet
	NT_INDEX channelIndex; // source channel
	unsigned int data1; // data field
	signed int data2; // data field
	signed int data3; // data field
	unsigned int data4; // data field
} NT_PACKET;


// function status return values
#define NT_OK                                       0
#define NT_INITIALIZATION_ERROR                     1
#define NT_NOT_INITIALIZED_ERROR                    2
#define NT_NO_SYSTEMS_FOUND_ERROR                   3
#define NT_TOO_MANY_SYSTEMS_ERROR                   4
#define NT_INVALID_SYSTEM_INDEX_ERROR               5
#define NT_INVALID_CHANNEL_INDEX_ERROR              6
#define NT_TRANSMIT_ERROR                           7
#define NT_WRITE_ERROR                              8
#define NT_INVALID_PARAMETER_ERROR                  9
#define NT_READ_ERROR                               10
#define NT_INTERNAL_ERROR                           12
#define NT_WRONG_MODE_ERROR                         13
#define NT_PROTOCOL_ERROR                           14
#define NT_TIMEOUT_ERROR                            15
#define NT_ID_LIST_TOO_SMALL_ERROR                  17
#define NT_SYSTEM_ALREADY_ADDED_ERROR               18
#define NT_WRONG_CHANNEL_TYPE_ERROR                 19
#define NT_CANCELED_ERROR                           20
#define NT_INVALID_SYSTEM_LOCATOR_ERROR             21
#define NT_INPUT_BUFFER_OVERFLOW_ERROR              22
#define NT_QUERYBUFFER_SIZE_ERROR                   23
#define NT_DRIVER_ERROR                             24
#define NT_NO_SENSOR_PRESENT_ERROR                  129
#define NT_AMPLITUDE_TOO_LOW_ERROR                  130
#define NT_AMPLITUDE_TOO_HIGH_ERROR                 131
#define NT_FREQUENCY_TOO_LOW_ERROR                  132
#define NT_FREQUENCY_TOO_HIGH_ERROR                 133
#define NT_SCAN_TARGET_TOO_HIGH_ERROR               135
#define NT_SCAN_SPEED_TOO_LOW_ERROR                 136
#define NT_SCAN_SPEED_TOO_HIGH_ERROR                137
#define NT_SENSOR_DISABLED_ERROR                    140
#define NT_COMMAND_OVERRIDDEN_ERROR                 141
#define NT_END_STOP_REACHED_ERROR                   142
#define NT_WRONG_SENSOR_TYPE_ERROR                  143
#define NT_COULD_NOT_FIND_REF_ERROR                 144
#define NT_WRONG_END_EFFECTOR_TYPE_ERROR            145
#define NT_MOVEMENT_LOCKED_ERROR                    146
#define NT_RANGE_LIMIT_REACHED_ERROR                147
#define NT_PHYSICAL_POSITION_UNKNOWN_ERROR          148
#define NT_OUTPUT_BUFFER_OVERFLOW_ERROR             149
#define NT_COMMAND_NOT_PROCESSABLE_ERROR            150
#define NT_WAITING_FOR_TRIGGER_ERROR                151
#define NT_COMMAND_NOT_TRIGGERABLE_ERROR            152
#define NT_COMMAND_QUEUE_FULL_ERROR                 153
#define NT_INVALID_COMPONENT_ERROR                  154
#define NT_INVALID_SUB_COMPONENT_ERROR              155
#define NT_INVALID_PROPERTY_ERROR                   156
#define NT_PERMISSION_DENIED_ERROR                  157
#define NT_CALIBRATION_FAILED_ERROR                 160
#define NT_INCOMPLETE_PACKET_ERROR                  161
#define NT_PIDTYPE_ERROR                            170
#define NT_UNKNOWN_COMMAND_ERROR                    240
#define NT_OTHER_ERROR                              255

// general definitions
#define NT_UNDEFINED                                0
#define NT_FALSE                                    0
#define NT_TRUE                                     1
#define NT_DISABLED                                 0
#define NT_ENABLED                                  1
#define NT_FALLING_EDGE                             0
#define NT_RISING_EDGE                              1
#define NT_FORWARD                                  0
#define NT_BACKWARD                                 1


// configuration flags for NT_InitDevices
#define NT_SYNCHRONOUS_COMMUNICATION                0
#define NT_ASYNCHRONOUS_COMMUNICATION               1
#define NT_HARDWARE_RESET                           2

// return values from NT_GetInitState
#define NT_INIT_STATE_NONE                          0
#define NT_INIT_STATE_SYNC                          1
#define NT_INIT_STATE_ASYNC                         2

// Hand Control Module modes for NT_SetHCMEnabled
#define NT_HCM_DISABLED                             0
#define NT_HCM_ENABLED                              1
#define NT_HCM_CONTROLS_DISABLED                    2

// configuration values for NT_SetBufferedOutput_A
#define NT_UNBUFFERED_OUTPUT                        0
#define NT_BUFFERED_OUTPUT                          1

// configuration values for NT_SetAccumulateRelativePositions_X
#define NT_NO_ACCUMULATE_RELATIVE_POSITIONS         0
#define NT_ACCUMULATE_RELATIVE_POSITIONS            1

// configuration values for NT_SetSensorEnabled_X
#define NT_SENSOR_DISABLED                          0
#define NT_SENSOR_ENABLED                           1

// set pid for NT_SetPIDParameter_S
#define NT_PID1_P                                   0
#define NT_PID1_I                                   1
#define NT_PID1_D                                   2
//#define NT_PID2_P                                   3
//#define NT_PID2_I                                   4
//#define NT_PID2_D                                   5

//set closedloopmovespeed for NT_SetClosedLoopMoveSpeed_S
#define NT_SPEED_DISABLED                           0
#define NT_SPEED_ENABLED                            16

//set enabled for NT_SetClosedLoopMoveAcceleration_S
#define NT_ASPEED_DISABLED                          0
#define NT_ASPEED_ENABLED                           1

// set enable for NT_SetClosedLoopHoldEnabled_S
#define NT_CLOSELOOP_DISABLED                        0
#define NT_CLOSELOOP_ENABLED                         1

// set direction for NT_FindReferenceMark_S
#define NT_FIND_FORWARD                             1
#define NT_FIND_BACKWARD                            2

// set Auto reset for NT_FindReferenceMark_S
#define NT_AUTO_ZERO_DISABLED                       0
#define NT_AUTO_ZERO_ENABLED                        1

//set limit enabled for NT_LimitEnable_S
#define NT_LIMIT_DISABLED                           0
#define NT_LIMIT_ENABLED                            1

//set sensor type for NT_SetSensorType_S
#define LINEAR                                      1
#define GON59                                       2
#define GON78                                       3
#define RS80                                        4
#define RS60                                        5
#define RS50                                        9
#define RS40                                        8
#define RS20                                        7
// infinite timeout for functions that wait
#define NT_TIMEOUT_INFINITE                         0xFFFFFFFF

// packet types for asynchronous mode
#define NT_NO_PACKET_TYPE                           0
#define NT_ERROR_PACKET_TYPE                        1
#define NT_POSITION_PACKET_TYPE                     2
#define NT_COMPLETED_PACKET_TYPE                    3
#define NT_STATUS_PACKET_TYPE                       4
#define NT_ANGLE_PACKET_TYPE                        5
#define NT_VOLTAGE_LEVEL_PACKET_TYPE                6
#define NT_SENSOR_TYPE_PACKET_TYPE                  7
#define NT_SENSOR_ENABLED_PACKET_TYPE               8
#define NT_END_EFFECTOR_TYPE_PACKET_TYPE            9
#define NT_GRIPPER_OPENING_PACKET_TYPE              10
#define NT_FORCE_PACKET_TYPE                        11
#define NT_MOVE_SPEED_PACKET_TYPE                   12
#define NT_PHYSICAL_POSITION_KNOWN_PACKET_TYPE      13
#define NT_POSITION_LIMIT_PACKET_TYPE               14
#define NT_ANGLE_LIMIT_PACKET_TYPE                  15
#define NT_SAFE_DIRECTION_PACKET_TYPE               16
#define NT_SCALE_PACKET_TYPE                        17
#define NT_MOVE_ACCELERATION_PACKET_TYPE            18
#define NT_CHANNEL_PROPERTY_PACKET_TYPE             19
#define NT_CAPTURE_BUFFER_PACKET_TYPE               20
#define NT_TRIGGERED_PACKET_TYPE                    21
#define NT_ANGLE_LIMIT_R_PACKET_TYPE                23
#define NT_ANGLE_LIMIT_A_PACKET_TYPE                24

#define NT_CHECKPOWER_PACKET_TYPE                   41
#define NT_GETINFOMATIONSIZE_PACKET_TYPE            42

#define NT_INVALID_PACKET_TYPE                      255

// channel status codes
#define NT_STOPPED_STATUS                           0
#define NT_STEPPING_STATUS                          1
#define NT_SCANNING_STATUS                          2
#define NT_HOLDING_STATUS                           3
#define NT_TARGET_STATUS                            4
#define NT_SENSOR_CLOSED_STATUS                     5
#define NT_NO_HOLDING_STATUS                        6
#define NT_REFERENCING_STATUS                       7
#define NT_CALIBRATING_STATUS                       8
#define NT_PHY_LIMIT_STATUS                         10
#define NT_SOFT_LIMIT_STATUS                        11
#define NT_SHORT_CIRCUIT_STATUS                     13


#ifdef __cplusplus
extern "C" {
#endif
	/***********************************************************************
	General note:
	All functions have a return value of NT_STATUS
	indicating success (NT_OK) or failure of execution. See the above
	definitions for a list of error codes.
	***********************************************************************/

	/************************************************************************
	*************************************************************************
	**                 Section I: Initialization Functions                 **
	*************************************************************************
	************************************************************************/


	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_OpenSystem(NT_INDEX* systemIndex, const char* systemLocator, const char* options);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_CloseSystem(NT_INDEX systemIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_FindSystems(const char* options, char* outBuffer, unsigned int* ioBufferSize);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetSystemLocator(NT_INDEX systemIndex, char* outBuffer, unsigned int* ioBufferSize);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetHCMEnabled(NT_INDEX systemIndex, unsigned int enabled);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetNumberOfChannels(NT_INDEX systemIndex, unsigned int* channels);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetConnectionStatus(NT_INDEX systemIndex, unsigned int* xstatus, unsigned int* ystatus, unsigned int* zstatus);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetVersionInfo(NT_INDEX systemIndex, char* infomation, unsigned int* size);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetSystemLocator(NT_INDEX systemIndex, char* inBuffer);

	/************************************************************************
	*************************************************************************
	**        Section IIa:  Functions for SYNCHRONOUS communication        **
	*************************************************************************
	************************************************************************/
	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_StepMove_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int steps, unsigned int amplitude, unsigned int frequency);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GotoPositionAbsolute_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int position);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GotoPositionRelative_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int diff);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetPosition_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int position);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetStatus_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int* status);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetPosition_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int* position);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetSensorEnabled_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int enabled);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetSensorEnabled_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int* enabled);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetVoltageLevel_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int* level);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetClosedLoopMoveSpeed_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int* speed);
	
	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetClosedLoopMoveAcceleration_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int* acceleration);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_ScanMoveAbsolute_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int target, unsigned int scanSpeed);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_ScanMoveRelative_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int diff, unsigned int scanSpeed);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetAccumulateRelativePositions_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int accumulate);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_Stop_S(NT_INDEX systemIndex, NT_INDEX channelIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetClosedLoopMoveSpeed_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int enadled, unsigned int speed);
	
	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetClosedLoopMoveAcceleration_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int enadled, unsigned int acceleration);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetClosedLoopMaxFrequency_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int frequency);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_EmergencyStop_S(NT_INDEX systemIndex, NT_INDEX channelIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_CalibrateSensor_S(NT_INDEX systemIndex, NT_INDEX channelIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC  NT_SetPIDParameter_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int type, float temp);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetClosedLoopHoldEnabled_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int enabled);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_FindReferenceMark_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int direction, unsigned int enabled);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetPhysicalPositionKnown_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int* known);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_LimitEnable_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int enabled);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_DisPlacementClear_S(NT_INDEX systemIndex, NT_INDEX channelIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetAngle_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int* angle, signed int* revolution);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetSensorType_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int type);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetSensorType_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int* type);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GotoAngleRelative_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int  angleDiff, signed int revolutionDiff);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GotoAngleAbsolute_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int  angle, signed int revolution);
	
	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetClosedLoopMaxFrequency_S(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int* frequency);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetCheckPower_S(NT_INDEX systemIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetCheckPower_S(NT_INDEX systemIndex, unsigned int* power);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetPositionLimit_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int minPosition, signed int maxPosition);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetPositionLimit_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int* minPosition, signed int* maxPosition);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetAngleLimit_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int minRevolution, signed int maxRevolution, signed int minAngle, signed int maxAngle);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetAngleLimit_S(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int* minRevolution, signed int* maxRevolution, signed int* minAngle, signed int* maxAngle);
	/************************************************************************
	*************************************************************************
	**       Section IIb:  Functions for ASYNCHRONOUS communication        **
	*************************************************************************
	************************************************************************/
	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_StepMove_A(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int steps, unsigned int amplitude, unsigned int frequency);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_Stop_A(NT_INDEX systemIndex, NT_INDEX channelIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetStatus_A(NT_INDEX systemIndex, NT_INDEX channelIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GotoPositionRelative_A(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int diff, unsigned int holdTime);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GotoPositionAbsolute_A(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int position, unsigned int holdTime);
		
	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetPosition_A(NT_INDEX systemIndex, NT_INDEX channelIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetPosition_A(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int position);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetSensorEnabled_A(NT_INDEX systemIndex, unsigned int enabled);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetSensorEnabled_A(NT_INDEX systemIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_GetVoltageLevel_A(NT_INDEX systemIndex, NT_INDEX channelIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_ScanMoveRelative_A(NT_INDEX systemIndex, NT_INDEX channelIndex, signed int diff, unsigned int scanSpeed);
		
	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_ScanMoveAbsolute_A(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int target, unsigned int scanSpeed);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetAccumulateRelativePositions_A(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int accumulate);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetBufferedOutput_A(NT_INDEX systemIndex, unsigned int mode);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_FlushOutput_A(NT_INDEX systemIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_ReceiveNextPacket_A(NT_INDEX systemIndex, unsigned int timeout, NT_PACKET* packet);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_LookAtNextPacket_A(NT_INDEX systemIndex, unsigned int timeout, NT_PACKET* packet);
	
	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_CancelWaitForPacket_A(NT_INDEX systemIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_DiscardPacket_A(NT_INDEX systemIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_CalibrateSensor_A(NT_INDEX systemIndex, NT_INDEX channelIndex);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetPIDParameter_A(NT_INDEX systemIndex, NT_INDEX channelIndex,  int Proportion,  int Integration,  int Differential);

	NPSCONTROL_API
		NT_STATUS NPSCONTROL_CC NT_SetClosedLoopHoldEnabled_A(NT_INDEX systemIndex, NT_INDEX channelIndex, unsigned int enabled);
#ifdef __cplusplus
}
#endif 

#endif   /* NTCONTROL_H */ 