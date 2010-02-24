/****************************************************************************
* QVlc - Qt and libVLC connector library
* VlcVolumeSlider.h: Volume manager and slider
*****************************************************************************
* Copyright (C) 2008-2010 Tadej Novak
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* This file may be used under the terms of the
* GNU General Public License version 3.0 as published by the
* Free Software Foundation and appearing in the file LICENSE.GPL
* included in the packaging of this file.
*****************************************************************************/

#ifndef QVLC_VLCVOLUMESLIDER_H_
#define QVLC_VLCVOLUMESLIDER_H_

#include <QtCore/QTimer>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

class VlcVolumeSlider : public QWidget
{
Q_OBJECT
public:
	VlcVolumeSlider(QWidget *parent = 0);
	~VlcVolumeSlider();

	void setVolume(const int &volume);
	int volume() const {return _slider->value();};

public slots:
	void mute();
	void vup();
	void vdown();
	void volumeControl(const bool &direction);

private slots:
	void changeVolume(const int &newVolume);
	void updateVolume();

private:
	QSlider *_slider;
	QLabel *_label;
	QTimer *_timer;
};

#endif // QVLC_VLCVOLUMESLIDER_H_