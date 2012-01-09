SOURCES += \
    kinc.cpp \
    kinwnd.cpp

LIBS += -lfreenect \
        -lusb \
        -lpthread

HEADERS += \
    kinwnd.h

QT += opengl

win32 {
    SOURCES += libusbemu.cpp \
        libfreenect_sync.cpp
    HEADERS += libfreenect_sync.h
    INCLUDEPATH += C:\Kinect\OpenKinect-libfreenect-dbfd4ce\wrappers\c_sync
}
else {
    INCLUDEPATH += /usr/include/libfreenect
}







