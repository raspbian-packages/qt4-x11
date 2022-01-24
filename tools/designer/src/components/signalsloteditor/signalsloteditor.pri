
INCLUDEPATH += $$PWD

HEADERS += $$PWD/signalslot_utils_p.h \
    $$PWD/connectdialog_p.h \
    $$PWD/signalsloteditor.h \
    $$PWD/signalsloteditor_tool.h \
    $$PWD/signalsloteditor_plugin.h \
    $$PWD/signalsloteditor_global.h \
    $$PWD/signalsloteditor_p.h \
    $$PWD/signalsloteditorwindow.h

SOURCES += $$PWD/signalslot_utils.cpp \
    $$PWD/connectdialog.cpp \
    $$PWD/signalsloteditor.cpp \
    $$PWD/signalsloteditor_tool.cpp \
    $$PWD/signalsloteditor_plugin.cpp \
    $$PWD/signalsloteditor_instance.cpp \
    $$PWD/signalsloteditorwindow.cpp

FORMS += $$PWD/connectdialog.ui

equals(QT_ARCH, powerpc) {
    message("powerpc/gcc 4.6 ICE workaround for designer: build with -gstabs rather than -g")
    QMAKE_CXXFLAGS -= -g
    QMAKE_CXXFLAGS += -gstabs
}

