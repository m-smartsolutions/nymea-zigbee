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

#include "zigbeeinterfacedeconzreply.h"

Deconz::Command ZigbeeInterfaceDeconzReply::command() const
{
    return m_command;
}

quint8 ZigbeeInterfaceDeconzReply::sequenceNumber() const
{
    return m_sequenceNumber;
}

QByteArray ZigbeeInterfaceDeconzReply::responseData() const
{
    return m_responseData;
}

Deconz::StatusCode ZigbeeInterfaceDeconzReply::statusCode() const
{
    return m_statusCode;
}

bool ZigbeeInterfaceDeconzReply::aborted() const
{
    return m_aborted;
}

void ZigbeeInterfaceDeconzReply::abort()
{
    m_aborted = true;
    emit finished();
}

ZigbeeInterfaceDeconzReply::ZigbeeInterfaceDeconzReply(Deconz::Command command, quint8 sequenceNumber, QObject *parent) :
    QObject(parent),
    m_timer(new QTimer(this)),
    m_command(command),
    m_sequenceNumber(sequenceNumber)
{
    m_timer->setInterval(2000);
    m_timer->setSingleShot(true);
    connect(m_timer, &QTimer::timeout, this, &ZigbeeInterfaceDeconzReply::onTimeout);
}

void ZigbeeInterfaceDeconzReply::onTimeout()
{
    m_timeout = true;
    emit timeout();
    emit finished();
}
