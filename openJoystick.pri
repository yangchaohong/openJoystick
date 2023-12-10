SOURCES += \
    $$PWD/openJoystick-Linux.c \
    $$PWD/openJoystick-Win.c
HEADERS += \
    $$PWD/openJoystick-Linux.h \
    $$PWD/openJoystick-Win.h \
    $$PWD/openJoystick.h

INCLUDEPATH += $$PWD
win32: LIBS += -lXinput
