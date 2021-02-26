ofxProsilica
==============
!!! Please tell me if you know who originally made ofxProsilica !!!

Description
-----------
openframeworks addon for use with Allied Vision Prosilica cameras.


Cameras 
-----------

## Allied AVT GigE
* Mako G125C PoE (color)
* Prosilica GC750 (monochrome)



Installation and Build
----------------------

### macOS

After generating project files using the OF Project Generator, add the following to one of the Run Script build phases in the Xcode project to invoke the `macos_install_libs.sh` script:

1. Select the project in the left-hand Xcode project tree
2. Select the project build target under TARGETS
3. Under the Build Phases tab, find the 2nd Run Script, and add the following before the final `echo` line:

```shell
$OF_PATH/addons/ofxProsilica/scripts/macos_install_libs.sh "$TARGET_BUILD_DIR/$PRODUCT_NAME.app";
```

Thanks to
---------------
* Who ever made the original ofxProsilica. 
* https://github.com/zkmkarlsruhe/ofxTensorFlow2


Old notes
---------------

For compatibility with OSX it is based on the legacy GigE SDK from Allied Vision Technology PvAPI.

* The files from /inc-pc/ (ImageLib.h, PvApi.h, PvRegIo.h) go into /ofxProsilica/libs/PvAPI/include
* The files from /lib-pc/x86/4.2/ (libImagelib.a, libPvAPI.a) go into  /ofxProsilica/libs/PvAPI/lib/osx/

for Windows: Install the SDK (appears in C:/Program Files/Allied Vision Technologies) and move the files:

*  The files from /inc-pc/ (ImageLib.h, PvApi.h, PvRegIo.h) go into /ofxProsilica/libs/PvAPI/include
* The files from /lib-pc/ (Imagelib.lib, PvAPI.lib) go into  /ofxProsilica/libs/PvAPI/lib/win32/

For Visual Studio copy PvAPI.dll to the Project Directory:

* In you can use Project + Properties-> Build events-> Post-Build Event to xcopy it
* xcopy /e /i /y "$(ProjectDir)..\..\..\addons\ofxProsilica\libs\PvAPI\lib\win32\PvAPI.dll" "$(ProjectDir)bin"


The SampleViewer in /bin-pc/ can be very useful for troubleshooting
