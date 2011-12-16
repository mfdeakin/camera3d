SOURCES += \
    kinc.cpp \
    libusbemu.cpp \
    kinwnd.cpp

LIBS += -lfreenect \
        -lusb

HEADERS += \
    kinwnd.h

FORMS += \
    kinwnd.ui





