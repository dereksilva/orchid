#!/bin/bash
set -e

rm -rf app-flutter
mkdir app-flutter
cd app-flutter

ln -s ../app-shared shared
ln -s ../app-flutter.mk makefile
ln -s ../gui-"$1" gui

ln -s gui/pubspec.yaml
ln -s gui/lib
ln -s gui/assets

flutter=shared/flutter/bin/flutter

"${flutter}" create -i objc -a java --no-pub --project-name orchid .

make
