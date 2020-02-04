TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Observer/Observer.c \
    Observer/Subject.c \
    example/main.c \
    example/models/cat.c \
    example/models/dog.c

HEADERS += \
    Observer/Observer.h \
    Observer/Subject.h \
    Observer/common.h \
    example/models/cat.h \
    example/models/dog.h
