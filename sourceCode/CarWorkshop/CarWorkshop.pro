QT       += core gui
QT += sql
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_staff.cpp \
    bossuse.cpp \
    calender_query.cpp \
    choose_slots.cpp \
    delete_staff.cpp \
    main.cpp \
    mainwindow.cpp \
    repairdlg.cpp \
    set_status.cpp \
    slots_table.cpp \
    staff_calender.cpp \
    staffuse.cpp \
    ticket.cpp \
    update_slots.cpp

HEADERS += \
    add_staff.h \
    bossuse.h \
    calender_query.h \
    choose_slots.h \
    delete_staff.h \
    mainwindow.h \
    repairdlg.h \
    set_status.h \
    slots_table.h \
    staff_calender.h \
    staffuse.h \
    ticket.h \
    update_slots.h

FORMS += \
    add_staff.ui \
    bossuse.ui \
    calender_query.ui \
    choose_slots.ui \
    delete_staff.ui \
    mainwindow.ui \
    repairdlg.ui \
    set_status.ui \
    slots_table.ui \
    staff_calender.ui \
    staffuse.ui \
    ticket.ui \
    update_slots.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
