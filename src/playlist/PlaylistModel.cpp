/****************************************************************************
* Tano - An Open IP TV Player
* Copyright (C) 2011 Tadej Novak <tadej@tano.si>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "container/Channel.h"
#include "playlist/M3UHandler.h"

#include "PlaylistModel.h"

PlaylistModel::PlaylistModel(QObject *parent)
    : ListModel(new Channel, parent)
{
    _name = QObject::tr("Channel list");
}

PlaylistModel::~PlaylistModel() { }

Channel *PlaylistModel::find(const QString &id) const
{
    return qobject_cast<Channel *>(ListModel::find(id));
}

Channel *PlaylistModel::row(const int &row)
{
    return qobject_cast<Channel *>(ListModel::row(row));
}

Channel *PlaylistModel::takeRow(const int &row)
{
    return qobject_cast<Channel *>(ListModel::takeRow(row));
}

void PlaylistModel::openM3UFile(const QString &file)
{
    M3UHandler *open = new M3UHandler();
    open->processFile(file);

    for(int i = 0; i < open->channelList().size(); i++) {
        processChannel(open->channelList()[i]);
    }

    _name = open->name();

    delete open;
}

void PlaylistModel::processChannel(Channel *channel)
{
    bool exists = find(channel->id());
    if(!exists) {
        for(int i = 0; i < rowCount(); i++) {
            if(row(i)->name() == channel->name()) {
                row(i)->setUrl(channel->url());
                return;
            }
        }
    } else {
        return;
    }

    if(channel->number() == 0) {
        channel->setNumber(1);
    }

    if(_channelNumbers.contains(channel->number())) {
        for(int i = channel->number(); i < 1000; i++) {
            if(!_channelNumbers.contains(i)) {
                channel->setNumber(i);
                break;
            }
        }
    }
    _channelNumbers << channel->number();

    for(int i = 0; i < channel->categories().size(); i++) {
        if(!_categoryList.contains(channel->categories()[i]))
            _categoryList << channel->categories()[i];
    }
    if(!_languageList.contains(channel->language()))
        _languageList << channel->language();
    if(!_epgList.contains(channel->epg()) && !channel->epg().isEmpty())
        _epgList << channel->epg();

    _numbers.insert(channel->number(), channel);
    appendRow(channel);
}

bool PlaylistModel::validate() const
{
    for(int i = 1; i < _channelNumbers.size(); i++) {
        if(_channelNumbers[i-1] == _channelNumbers[i]) {
            return false;
        }
    }

    return true;
}