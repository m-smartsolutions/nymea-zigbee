#ifndef NXP_H
#define NXP_H

#include <QObject>

class Nxp
{
    Q_GADGET
public:
    enum Command {
        CommandGetVersion = 0x00,
        CommandGetControllerState = 0x01,
        CommandSoftReset = 0x02,
        CommandFactoryReset = 0x03,

        CommandSetPanId = 0x04,
        CommandSetChannelMask = 0x05,
        CommandSetSecurityKey = 0x06,

        CommandStartNetwork = 0x07,
        CommandGetNetworkState = 0x08,
        CommandSetPermitJoinCoordinator = 0x09
    };
    Q_ENUM(Command)

    enum Notification {
        NotificationDeviceStatusChanged = 0x7D,
        NotificationNetworkStarted = 0x7E,
        NotificationDebugMessage = 0xFE
    };
    Q_ENUM(Notification)

    enum Status {
        StatusSuccess = 0x00,
        StatusProtocolError = 0x01,
        StatusUnknownCommand = 0x02,
        StatusInvalidCrc = 0x03,
        StatusStackError = 0x04
    };
    Q_ENUM(Status)

    enum LogLevel {
        LogLevelEmergency = 0x00,
        LogLevelAlert = 0x01,
        LogLevelCritical = 0x02,
        LogLevelError = 0x03,
        LogLevelWarning = 0x04,
        LogLevelNotice = 0x05,
        LogLevelInfo = 0x06,
        LogLevelDebug = 0x07
    };
    Q_ENUM(LogLevel)


    enum KeyType {
        KeyTypeGlobalLinkKey = 0x00,
        KeyTypeUniqueLinkKey = 0x01
    };
    Q_ENUM(KeyType)
};

#endif // NXP_H
