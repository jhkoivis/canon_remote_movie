/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : TakePictureCommand.h	                                          *
*                                                                             *
*   Description: This is the Sample code to show the usage of EDSDK.          *
*                                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*   Written and developed by Camera Design Dept.53                            *
*   Copyright Canon Inc. 2006 All Rights Reserved                             *
*                                                                             *
*******************************************************************************/

#pragma once

#include "Command.h"
#include "CameraEvent.h"
#include "EDSDK.h"
#include <stdlib.h> //char *_itoa(int value, char *string, int radix);

class TakePictureCommand : public Command
{

public:
	TakePictureCommand(CameraModel *model) : Command(model){}


	// Execute command	
	virtual bool execute()
	{
		EdsError err = EDS_ERR_OK;
		bool	 locked = false;
		
		char buffer1[35];
		char *p1;
		char buffer2[35];
		char *p2;
		char buffer3[35];
		char *p3;


		//Taking a picture

		// https://stackoverflow.com/questions/4037929/how-to-start-stop-video-recording-on-canon-camera-via-sdk

		EdsUInt32 saveTo = kEdsSaveTo_Camera;
		err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_SaveTo, 0, sizeof(saveTo), &saveTo);

		p1 = _itoa(err, buffer1, 16);

		if (err != EDS_ERR_OK) {
			int msgboxID1 = MessageBox(
				NULL,
				(LPCTSTR)p1,
				(LPCTSTR)L"Account Details",
				MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
			);
		}

		EdsUInt32 record_start = 4; // Begin movie shooting 
		err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_Record, 0, sizeof(record_start), &record_start);

		p2 = _itoa(err, buffer2, 16);

		if (err != EDS_ERR_OK) {

			int msgboxID2 = MessageBox(
				NULL,
				(LPCTSTR)p2,
				(LPCTSTR)L"Account Details",
				MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
			);

		}

		//EdsUInt32 record_stop = 0; // End movie shooting 
		//err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_Record, 0, sizeof(record_stop), &record_stop);

		p3 = _itoa(err, buffer3, 16);

		if (err != EDS_ERR_OK) {

			int msgboxID3 = MessageBox(
				NULL,
				(LPCTSTR)p3,
				(LPCTSTR)L"Account Details",
				MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
			);

		}


		//err = EdsSendCommand(_model->getCameraObject(), kEdsCameraCommand_PressShutterButton, kEdsCameraCommand_ShutterButton_Completely);
		//      EdsSendCommand(_model->getCameraObject(), kEdsCameraCommand_PressShutterButton, kEdsCameraCommand_ShutterButton_OFF);
		

		//Notification of error
		if(err != EDS_ERR_OK)
		{
			// It retries it at device busy
			if(err == EDS_ERR_DEVICE_BUSY)
			{
				CameraEvent e("DeviceBusy");
				_model->notifyObservers(&e);
				return true;
			}
			
			CameraEvent e("error", &err); 
			_model->notifyObservers(&e);
		}

		return true;
	}


};