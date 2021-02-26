#! /bin/sh
#
# Xcode run script for macOS to change PvAPI dylib loader paths and
# install top .app bundle when building
#
# usage: APP
# ie. APP is path/to/OFApp.app
#
# if run outside of Xcode, the OF_PATH variable must be set:
# OF_PATH=../../ macos_install_libs.sh bin/MyApp.app 
# forked from https://github.com/zkmkarlsruhe/ofxTensorFlow2
# which is made by Dan Wilcox ZKM | Hertz-Lab 2021
# adapted for ofxProsilica by Stephan Schulz

# stop on error
set -e

if [ "$1" = "" ] ; then
	echo "usage: path/to/Project.app"
	exit 1
fi

APP_PATH="$1"
APP_NAME="$(basename ${APP_PATH%.*})"

#/Applications/of_v0.11.0_osx_release/addons/ofxProsilica/libs/PvAPI/lib/osx/x64
SRC="$OF_PATH/addons/ofxProsilica/libs/PvAPI/lib/osx/x64"
#DEST="$APP_PATH/Contents/Frameworks"
DEST="$APP_PATH/Contents/macOS"
echo "ofxProsilica: install PvAPI lib to $APP_PATH $APP_NAME"

# detect tf version from dylib naming: libtensorflow.2.4.0.dylib -> 2.4.0
#VER=$(ls "$SRC" | egrep "libtensorflow\.[0-9]\.[0-9]\.[0-9]" | sed "s/[^0-9]*//")
#VER="$(basename ${VER%.*})"

# copy dylibs to app bundle
rsync -aved "$SRC"/*.dylib "$DEST"

## change dylib loader path to Frameworks dir in executable
#install_name_tool -change @rpath/libtensorflow.2.dylib @executable_path/../Frameworks/libtensorflow.2.dylib "$APP_PATH/Contents/MacOS/$APP_NAME"
#install_name_tool -change @rpath/libtensorflow_framework.2.dylib @executable_path/../Frameworks/libtensorflow_framework.2.dylib "$APP_PATH/Contents/MacOS/$APP_NAME"
#
## change dylib loader path to Frameworks dir in dylibs
#install_name_tool -id @executable_path/../Frameworks/libtensorflow.2.dylib -change @rpath/libtensorflow_framework.2.dylib @executable_path/../Frameworks/libtensorflow_framework.2.dylib "$DEST"/libtensorflow.${VER}.dylib
#install_name_tool -id @executable_path/../Frameworks/libtensorflow.2_framework.dylib "$DEST"/libtensorflow_framework.${VER}.dylib
