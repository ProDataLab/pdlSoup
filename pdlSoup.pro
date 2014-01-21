TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    fsm.c \
    buffer.c \
    obj.c \
    obj_type.c \
    obj_var.c

HEADERS += \
    fsm.h \
    buffer.h \
    obj.h \
    obj_type.h \
    obj_var.h

