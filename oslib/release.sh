#!/bin/sh
export TARGET="./Distrib"
export SOURCE_DIR="./src"

echo
echo "-------------------"
echo "OSLib release maker"
echo "-------------------"
echo "Deleting target directory...."
rm -rf $TARGET

echo "Creating target directories...."
mkdir -p $TARGET
mkdir -p $TARGET/Install
mkdir -p $TARGET/Install/oslib
mkdir -p $TARGET/src/intraFont
mkdir -p $TARGET/src/libpspmath
mkdir -p $TARGET/src/adhoc

echo "Copying lib...."
cp -f  libosl.a $TARGET/Install

echo "Copying header files...."
cp -f $SOURCE_DIR/intraFont/intraFont.h $TARGET/src/intraFont/
cp -f $SOURCE_DIR/intraFont/libccc.h $TARGET/src/intraFont/
cp -f $SOURCE_DIR/libpspmath/pspmath.h $TARGET/src/libpspmath/
cp -f $SOURCE_DIR/adhoc/pspadhoc.h $TARGET/src/adhoc/
cp -f $SOURCE_DIR/oslmath.h $TARGET/src/
cp -f $SOURCE_DIR/net.h $TARGET/src/
cp -f $SOURCE_DIR/browser.h $TARGET/src/
cp -f $SOURCE_DIR/audio.h $TARGET/src/
cp -f $SOURCE_DIR/bgm.h $TARGET/src/
cp -f $SOURCE_DIR/dialog.h $TARGET/src/
cp -f $SOURCE_DIR/drawing.h $TARGET/src/
cp -f $SOURCE_DIR/keys.h $TARGET/src/
cp -f $SOURCE_DIR/map.h $TARGET/src/
cp -f $SOURCE_DIR/messagebox.h $TARGET/src/
cp -f $SOURCE_DIR/osk.h $TARGET/src/
cp -f $SOURCE_DIR/saveload.h $TARGET/src/
cp -f $SOURCE_DIR/oslib.h $TARGET/src/
cp -f $SOURCE_DIR/text.h $TARGET/src/
cp -f $SOURCE_DIR/usb.h $TARGET/src/
cp -f $SOURCE_DIR/vfpu_ops.h $TARGET/src/
cp -f $SOURCE_DIR/VirtualFile.h $TARGET/src/
cp -f $SOURCE_DIR/vram_mgr.h $TARGET/src/
cp -f $SOURCE_DIR/ccc.h $TARGET/src/
cp -f $SOURCE_DIR/sfont.h $TARGET/src/

echo "Copying other files...."
cp -f README.md $TARGET
cp -f CHANGELOG.TXT $TARGET
cp -f install.bat $TARGET
cp -f install.sh $TARGET

echo "Copying DOC...."
cp -rf OSLib_MODv2_Documentation $TARGET/Doc

echo "Copying Samples...."
cp -rf samples $TARGET/

echo "Copying Tools...."
cp -rf tools $TARGET/

echo "Compressing...."
zip -r OSLibmodv2.zip $TARGET/*

echo "Done!"
echo
