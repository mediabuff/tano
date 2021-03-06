/****************************************************************************
* Tano - An Open IP TV Player
* Copyright (C) 2013 Tadej Novak <tadej@tano.si>
*
* This file is part of Qt Creator.
* Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
* Contact: http://www.qt-project.org/legal
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

#ifndef TANO_MINISPLITTER_H_
#define TANO_MINISPLITTER_H_

#include <QSplitter>

class QSplitterHandle;

class MiniSplitter : public QSplitter
{
public:
    MiniSplitter(QWidget *parent = 0);
    MiniSplitter(Qt::Orientation orientation);

protected:
    QSplitterHandle *createHandle();
};

#endif // TANO_MINISPLITTER_H_
