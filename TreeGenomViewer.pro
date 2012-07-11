#-------------------------------------------------
#
# Project created by QtCreator 2012-06-18T14:17:46
#
#-------------------------------------------------

QT       += core gui

TARGET = TreeGenomViewer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filetextreader.cpp \
    treebuilder.cpp \
    genomnode.cpp \
    treedrawer.cpp \
    treecreatercontext.cpp \
    acidarraycreator.cpp \
    acidsetter.cpp \
    acidsetcontext.cpp

HEADERS  += mainwindow.h \
    filetextreader.h \
    treebuilder.h \
    genomnode.h \
    treedrawer.h \
    treecreatercontext.h \
    acidarraycreator.h \
    acidsetter.h \
    acidsetcontext.h \
    treeviewer.h

FORMS    += mainwindow.ui \
    openfiledialog.ui

RESOURCES += \
    res.qrc

OTHER_FILES +=
