/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Copyright 2013 - 2020, nymea GmbH
* Contact: contact@nymea.io
*
* This file is part of nymea-zigbee.
* This project including source code and documentation is protected by copyright law, and
* remains the property of nymea GmbH. All rights, including reproduction, publication,
* editing and translation, are reserved. The use of this project is subject to the terms of a
* license agreement to be concluded with nymea GmbH in accordance with the terms
* of use of nymea GmbH, available under https://nymea.io/license
*
* GNU Lesser General Public License Usage
* Alternatively, this project may be redistributed and/or modified under the terms of the GNU
* Lesser General Public License as published by the Free Software Foundation; version 3.
* this project is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License along with this project.
* If not, see <https://www.gnu.org/licenses/>.
*
* For any further details and any questions please contact us under contact@nymea.io
* or see our FAQ/Licensing Information on https://nymea.io/license/faq
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ZIGBEECLUSTER_H
#define ZIGBEECLUSTER_H

#include <QObject>

#include "zigbee.h"
#include "zigbeeclusterattribute.h"

struct ZigbeeClusterReportConfigurationRecord {
    quint8 direction;
    Zigbee::DataType dataType;
    quint16 attributeId;
    quint16 minInterval;
    quint16 maxInterval;
    quint16 timeout;
    quint8 change;
};

struct ZigbeeClusterAttributeReport {
    quint16 sourceAddress;
    quint8 endpointId;
    Zigbee::ClusterId clusterId;
    quint16 attributeId;
    Zigbee::ZigbeeStatus attributeStatus;
    Zigbee::DataType dataType;
    QByteArray data;
};


class ZigbeeCluster : public QObject
{
    Q_OBJECT

    friend class ZigbeeNode;

public:
    enum Direction {
        Input,
        Output
    };
    Q_ENUM(Direction)

    // Basic clustr 0x0000

    // Attributes from the basic cluster 0x0000
    enum BasicAttribute {
        BasicAttributeZclVersion = 0x0000, // Mandatory
        BasicAttributeAppVersion = 0x0001,
        BasicAttributeStackVersion = 0x0002,
        BasicAttributeHardwareVersion = 0x0003,
        BasicAttributeManufacturerName = 0x0004,
        BasicAttributeModelIdentifier = 0x0005,
        BasicAttributeDateCode = 0x0006, // ISO 8601 YYYYMMDD
        BasicAttributePowerSource = 0x0007, // Mandatory
        BasicAttributeLocationDescription = 0x0010,
        BasicAttributePhysicalEnvironment = 0x0011,
        BasicAttributeDeviceEnabled = 0x0012, // 0: disabled, 1: enabled
        BasicAttributeAlarmMask = 0x0013,
        BasicAttributeDisableLocalConfig = 0x0014,
        BasicAttributeSwBuildId = 0x4000
    };
    Q_ENUM(BasicAttribute)

    // From the Basic cluster attribute 0x0007 power source
    enum BasicAttributePowerSourceValue {
        BasicAttributePowerSourceValueUnknown = 0x00,
        BasicAttributePowerSourceValueMainsSinglePhase = 0x01,
        BasicAttributePowerSourceValueMainsThreePhase = 0x02,
        BasicAttributePowerSourceValueBattery = 0x03,
        BasicAttributePowerSourceValueDcSource = 0x04,
        BasicAttributePowerSourceValueEmergencyMainsConstantlyPowered = 0x05,
        BasicAttributePowerSourceValueEmergencyMainsTransferSwitch = 0x06
    };
    Q_ENUM(BasicAttributePowerSourceValue)

    // Power configuration cluster 0x0001

    enum PowerConfigurationAttribute {
        PowerConfigurationAttributeMainsInformation = 0x0000,
        PowerConfigurationAttributeMainsSettings = 0x0001,
        PowerConfigurationAttributeBatteryInformation = 0x0002,
        PowerConfigurationAttributeBatterySettings = 0x0003,
        PowerConfigurationAttributeBatterySource2Information = 0x0004,
        PowerConfigurationAttributeBattterySource2Settings = 0x0005,
        PowerConfigurationAttributeBatterySource3Information = 0x0006,
        PowerConfigurationAttributeBattterySource3Settings = 0x0007
    };
    Q_ENUM(PowerConfigurationAttribute)

    // On Off Cluster 0x0006

    enum OnOffClusterAttribute {
        OnOffClusterAttributeOnOff = 0x0000,
        OnOffClusterAttributeGlobalSceneControl = 0x4000,
        OnOffClusterAttributeOnTime = 0x4001,
        OnOffClusterAttributeOffWaitTime = 0x4002
    };
    Q_ENUM(OnOffClusterAttribute)

    enum OnOffClusterCommand {
        OnOffClusterCommandOff = 0x00,
        OnOffClusterCommandOn = 0x01,
        OnOffClusterCommandToggle = 0x02
    };
    Q_ENUM(OnOffClusterCommand)


    // Level cluster 0x0008

    enum LevelClusterAttribute {
        LevelClusterAttributeCurrentLevel = 0x0000,
        LevelClusterAttributeRemainingTime = 0x0001,
        LevelClusterAttributeOnOffTransitionTime = 0x0010,
        LevelClusterAttributeOnLevel = 0x0011,
        LevelClusterAttributeOnTransitionTime = 0x0012,
        LevelClusterAttributeOffTransitionTime = 0x0013,
        LevelClusterAttributeDefaultMoveRate = 0x0014
    };
    Q_ENUM(LevelClusterAttribute)

    enum LevelClusterCommand {
        LevelClusterCommandMoveToLevel = 0x00,
        LevelClusterCommandMove = 0x01,
        LevelClusterCommandStep = 0x02,
        LevelClusterCommandStop = 0x03,
        LevelClusterCommandMoveToLevelWithOnOff = 0x04,
        LevelClusterCommandMoveWithOnOff = 0x05,
        LevelClusterCommandStepWithOnOff = 0x06,
        LevelClusterCommandStopWithOnOff = 0x07,
    };
    Q_ENUM(LevelClusterCommand)

    // Color cluster 0x0300

    enum ColorControlClusterAttribute {
        ColorControlClusterAttributeCurrentHue = 0x0000,
        ColorControlClusterAttributeCurrentSaturation = 0x0001,
        ColorControlClusterAttributeRemainingTime = 0x0002,
        ColorControlClusterAttributeCurrentX = 0x0003,
        ColorControlClusterAttributeCurrentY = 0x0004,
        ColorControlClusterAttributeDriftCompensation = 0x0005,
        ColorControlClusterAttributeCompensationText = 0x0006,
        ColorControlClusterAttributeColorTemperatureMireds = 0x0007,
        ColorControlClusterAttributeColorMode = 0x0008,
        ColorControlClusterAttributeEnhancedCurrentHue = 0x4000,
        ColorControlClusterAttributeEnhancedColorMode = 0x4001,
        ColorControlClusterAttributeColorLoopActive = 0x4002,
        ColorControlClusterAttributeColorLoopDirection = 0x4003,
        ColorControlClusterAttributeColorLoopTime = 0x4004,
        ColorControlClusterAttributeColorLoopStartEnhancedHue = 0x4005,
        ColorControlClusterAttributeColorLoopStoredEnhancedHue = 0x4006,
        ColorControlClusterAttributeColorCapabilities = 0x400a,
        ColorControlClusterAttributeColorTempPhysicalMinMireds = 0x400b,
        ColorControlClusterAttributeColorTempPhysicalMaxMireds = 0x400c
    };
    Q_ENUM(ColorControlClusterAttribute)

    enum ColorControlClusterColorMode {
        ColorControlClusterColorModeHueSaturation = 0x00,
        ColorControlClusterColorModeXY = 0x01,
        ColorControlClusterColorModeColorTemperatureMired = 0x02
    };
    Q_ENUM(ColorControlClusterColorMode)


    explicit ZigbeeCluster(Zigbee::ClusterId clusterId, Direction direction, QObject *parent = nullptr);

    Direction direction() const;

    Zigbee::ClusterId clusterId() const;
    QString clusterName() const;

    QList<ZigbeeClusterAttribute> attributes() const;
    bool hasAttribute(quint16 attributeId) const;

    ZigbeeClusterAttribute attribute(quint16 id);

    // FIXME: this should not be public
    void setAttribute(const ZigbeeClusterAttribute &attribute);

private:
    Zigbee::ClusterId m_clusterId = Zigbee::ClusterIdUnknown;
    Direction m_direction = Input;
    QHash<quint16, ZigbeeClusterAttribute> m_attributes;

protected:

signals:
    void attributeChanged(const ZigbeeClusterAttribute &attribute);

};

QDebug operator<<(QDebug debug, ZigbeeCluster *cluster);

#endif // ZIGBEECLUSTER_H
