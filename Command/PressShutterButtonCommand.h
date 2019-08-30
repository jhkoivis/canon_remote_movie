/******************************************************************************
*                                                                             *
*   PROJECT : EOS Digital Software Development Kit EDSDK                      *
*      NAME : PressShutterButtonCommand.h	                                  *
*                                                                             *
*   Description: This is the Sample code to show the usage of EDSDK.          *
*                                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*   Written and developed by Camera Design Dept.53                            *
*   Copyright Canon Inc. 2006-2008 All Rights Reserved                        *
*                                                                             *
*******************************************************************************/

#pragma once

#include "Command.h"
#include "CameraEvent.h"
#include "EDSDK.h"

class PressShutterButtonCommand : public Command
{
private:
	EdsUInt32 _status;

public:
	PressShutterButtonCommand(CameraModel *model, EdsUInt32 status) : _status(status), Command(model){}


	// Execute command	
	virtual bool execute()
	{
		EdsError err = EDS_ERR_OK;
		bool	 locked = false;
		
		char buffer4[35];
		char *p4;
		//char buffer2[35];
		//char *p2;
		//char buffer3[35];
		//char *p3;


		//Taking a picture

		// https://stackoverflow.com/questions/4037929/how-to-start-stop-video-recording-on-canon-camera-via-sdk

		//EdsUInt32 saveTo = kEdsSaveTo_Camera;
		//err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_SaveTo, 0, sizeof(saveTo), &saveTo);

		//p1 = _itoa(err, buffer1, 16);

		//int msgboxID1 = MessageBox(
		//	NULL,
		//	(LPCTSTR)p1,
		//	(LPCTSTR)L"Account Details",
		//	MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
		//);


		//EdsUInt32 record_start = 4; // Begin movie shooting 
		//err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_Record, 0, sizeof(record_start), &record_start);

		//p2 = _itoa(err, buffer2, 16);

		//int msgboxID2 = MessageBox(
		//	NULL,
		//	(LPCTSTR)p2,
		//	(LPCTSTR)L"Account Details",
		//	MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
		//);


		if (_status == kEdsCameraCommand_ShutterButton_Halfway)
		{

			EdsUInt32 record_stop = 0; // End movie shooting 
			err = EdsSetPropertyData(_model->getCameraObject(), kEdsPropID_Record, 0, sizeof(record_stop), &record_stop);

			p4 = _itoa(err, buffer4, 16);

			if (err != EDS_ERR_OK) {

				int msgboxID4 = MessageBox(
					NULL,
					(LPCTSTR)p4,
					(LPCTSTR)L"Account Details",
					MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
				);
			}
		}

		//PressShutterButton
		else if(err == EDS_ERR_OK)
		{
			err = EdsSendCommand(_model->getCameraObject(), kEdsCameraCommand_PressShutterButton, _status);
		}






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