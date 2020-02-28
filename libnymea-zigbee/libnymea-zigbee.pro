include(../config.pri)

TARGET = nymea-zigbee1
TEMPLATE = lib

SOURCES += \
    nxp/interface/zigbeeinterface.cpp \
    nxp/interface/zigbeeinterfacemessage.cpp \
    nxp/interface/zigbeeinterfacerequest.cpp \
    nxp/interface/zigbeeinterfacereply.cpp \
    nxp/zigbeenetworknxp.cpp \
    nxp/zigbeebridgecontrollernxp.cpp \
    nxp/zigbeenodenxp.cpp \
    zigbeecluster.cpp \
    zigbeeclusterattribute.cpp \
    zigbeenetwork.cpp \
    zigbeenetworkmanager.cpp \
    zigbee.cpp \
    loggingcategory.cpp \
    zigbeenodeendpoint.cpp \
    zigbeesecurityconfiguration.cpp \
    zigbeeutils.cpp \
    zigbeenode.cpp \
    zigbeeaddress.cpp \

HEADERS += \
    nxp/interface/zigbeeinterface.h \
    nxp/interface/zigbeeinterfacemessage.h \
    nxp/interface/zigbeeinterfacerequest.h \
    nxp/interface/zigbeeinterfacereply.h \
    nxp/zigbeenetworknxp.h \
    nxp/zigbeebridgecontrollernxp.h \
    nxp/zigbeenodenxp.h \
    zigbeecluster.h \
    zigbeeclusterattribute.h \
    zigbeenetwork.h \
    zigbeenetworkmanager.h \
    zigbee.h \
    loggingcategory.h \
    zigbeenodeendpoint.h \
    zigbeesecurityconfiguration.h \
    zigbeeutils.h \
    zigbeenode.h \
    zigbeeaddress.h \

# install header file with relative subdirectory
for (header, HEADERS) {
    path = $$[QT_INSTALL_PREFIX]/include/nymea-zigbee/$${dirname(header)}
    eval(headers_$${path}.files += $${header})
    eval(headers_$${path}.path = $${path})
    eval(INSTALLS *= headers_$${path})
}

# define install target
target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target

# Create pkgconfig file
CONFIG += create_pc create_prl no_install_prl
QMAKE_PKGCONFIG_NAME = libnymea-zigbee
QMAKE_PKGCONFIG_DESCRIPTION = nymea-zigbee development library
QMAKE_PKGCONFIG_PREFIX = $$[QT_INSTALL_PREFIX]
QMAKE_PKGCONFIG_INCDIR = $$[QT_INSTALL_PREFIX]/include/nymea-zigbee/
QMAKE_PKGCONFIG_LIBDIR = $$target.path
QMAKE_PKGCONFIG_VERSION = 1.0.0
QMAKE_PKGCONFIG_FILE = nymea-zigbee
QMAKE_PKGCONFIG_DESTDIR = pkgconfig

