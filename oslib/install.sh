#!/bin/sh

PSPSDK=$(psp-config --pspsdk-path)
if [ -z "$PSPSDK" ]; then
    echo
    echo "ERROR: Env variable PSPSDK not set."
    echo
    exit 1
fi

echo
echo "---------------"
echo "OSLib installer"
echo "---------------"
echo "Creating directories...."
mkdir -p $PSPSDK/include/oslib
mkdir -p $PSPSDK/include/oslib/intraFont
mkdir -p $PSPSDK/include/oslib/libpspmath
mkdir -p $PSPSDK/include/oslib/adhoc

echo "Copying lib...."
cp -f libosl.a $PSPSDK/lib/

echo "Copying header files...."
cp -f src/intraFont/intraFont.h $PSPSDK/include/oslib/intraFont/
cp -f src/intraFont/libccc.h $PSPSDK/include/oslib/intraFont/
cp -f src/libpspmath/pspmath.h $PSPSDK/include/oslib/libpspmath/
cp -f src/adhoc/pspadhoc.h $PSPSDK/include/oslib/adhoc/
cp -f src/oslmath.h $PSPSDK/include/oslib/
cp -f src/net.h $PSPSDK/include/oslib/
cp -f src/browser.h $PSPSDK/include/oslib/
cp -f src/audio.h $PSPSDK/include/oslib/
cp -f src/bgm.h $PSPSDK/include/oslib/
cp -f src/dialog.h $PSPSDK/include/oslib/
cp -f src/drawing.h $PSPSDK/include/oslib/
cp -f src/keys.h $PSPSDK/include/oslib/
cp -f src/map.h $PSPSDK/include/oslib/
cp -f src/messagebox.h $PSPSDK/include/oslib/
cp -f src/osk.h $PSPSDK/include/oslib/
cp -f src/saveload.h $PSPSDK/include/oslib/
cp -f src/oslib.h $PSPSDK/include/oslib/
cp -f src/text.h $PSPSDK/include/oslib/
cp -f src/usb.h $PSPSDK/include/oslib/
cp -f src/vfpu_ops.h $PSPSDK/include/oslib/
cp -f src/VirtualFile.h $PSPSDK/include/oslib/
cp -f src/vram_mgr.h $PSPSDK/include/oslib/
cp -f src/ccc.h $PSPSDK/include/oslib/
cp -f src/sfont.h $PSPSDK/include/oslib/

echo "Done!"
echo
