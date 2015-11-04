#!/bin/sh
SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
ROOT_DIR=$SCRIPT_DIR/../
SRC_DIR=$ROOT_DIR/src
VENDOR_DIR=$SRC_DIR/ios/vendor
TMP_DIR=$ROOT_DIR/tmp
rm -rf $TMP_DIR
rm -rf $VENDOR_DIR

mkdir -p $TMP_DIR
mkdir -p $VENDOR_DIR
mkdir -p $VENDOR_DIR/Headers
mkdir -p $VENDOR_DIR/Resources
cd $TMP_DIR
curl https://testfire-downloads.s3.amazonaws.com/ios/Testfire.zip --output Testfire.zip
unzip Testfire.zip
cp -R Testfire/Resources/* $VENDOR_DIR/Resources/
cp -R Testfire/Testfire.framework/Headers/* $VENDOR_DIR/Headers/
cp Testfire/Testfire.framework/Testfire $VENDOR_DIR/libTestfire.a
