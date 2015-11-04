#!/bin/sh
SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
SRC_DIR=$SCRIPT_DIR/../src
VENDOR_DIR=$SRC_DIR/android/vendor
rm -rf $VENDOR_DIR
mkdir -p $VENDOR_DIR
cp $SCRIPT_DIR/build-extras.gradle $VENDOR_DIR
curl https://testfire-downloads.s3.amazonaws.com/android/Testfire.aar --output $VENDOR_DIR/Testfire.aar
