# canon_remote_movie
minimal changes to get sample program to take movies

## Quick start

0. put camera in movie mode (see 2.) and connect USB cable, test with "EOS utility" that "remote movie" and everything else works , CLOSE eos utility
1. .exe is in Debug/CameraControl.exe
2. click "Start EVF" (you should now see liveView == "movie shoot mode for EOS 80D")
3. click "Take Movie" to start
4. click "Stop Movie" to stop

## Known "Features"

- error dialogs go behind the main window (if any errors)
- error shows just a number, see EDSDKErros.h for human readdable version

## Modifications

- PressShutterButtonCommand.h
- TakePictureCommand.h
- CameraControl.rc
- stdafx.h (here override VINVER definition and the NT-ver definition, later I found out that they are first defined in project -> properties)
- In visual studio 2017: project->properties-> C/C++ -> Genreal -> headers -> add correct path to canon sdk headers
- In visual studio 2017: project->properties-> C/C++ -> Genreal -> linker -> add correct path to canon.dll
- also, the windows kit 10 includes have to be added to headers... installing windows kit 10 and rebooting dit the trick, I think ... (complains about new.h if not correct)
  
## Depedencies etc

- Windows 10 (latest at 30.8.2019)
- win sdk kit 10 (also 8.1 is installed)
- tested with Canon eos 80D with memory card
- canon ESDK (latest at 30.8.2019)
- CC0 unless otherwise stated in the files

## Canon license (pdf included) states that Canon has all rights (copyleft) but I have permission to distribute (with the canon copyleft)

1.LICENCE GRANT AND RESTRICTIONS.
Subject to Your compliance with the terms of this 
Agreement, Canon grants You a non-exclusive, non-transferable, royalty-free licence in theTerritory:
(a) to use and copy the SDK only for the purpose of developing the Software Solutions;
(b) to modify the modifiable files of the SDK to create derivative of such modifiable files only  for  the  purpose  of  developing  the  Software  Solutions  and  only  to  the  extent  that such modifiable files and the Software Solutions are not distributed in a way that affect Canon’s  or  its  licensors  intellectual  property  ownership  including  without  limitation distribution or use under a copyleft open source licence; For the avoidance of doubt, modifiable files include any code other than a binary or byte code or a library portion of the SDK.

and then more legal jargon...



