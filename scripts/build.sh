#!/bin/sh
SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
$SCRIPT_DIR/build-ios.sh
$SCRIPT_DIR/build-android.sh
