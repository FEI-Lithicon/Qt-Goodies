/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QDOUBLESLIDER_H
#define QDOUBLESLIDER_H

#include <QtGui/QSlider>
#include "qabstractslider2.h"

QT_BEGIN_HEADER

//QT_BEGIN_NAMESPACE

QT_MODULE(Gui)

class QDoubleSliderPrivate;
class QStyleOptionSlider;
class Q_GUI_EXPORT QDoubleSlider : public QAbstractSlider
{
    Q_OBJECT

    typedef QPair<int,int> range_t;

      //    Q_ENUMS(TickPosition)
      Q_PROPERTY(range_t range READ range WRITE setValue);
      Q_PROPERTY(QSlider::TickPosition tickPosition READ tickPosition WRITE setTickPosition)
    Q_PROPERTY(int tickInterval READ tickInterval WRITE setTickInterval)

public:
    enum TickPosition {
        NoTicks = 0,
        TicksAbove = 1,
        TicksLeft = TicksAbove,
        TicksBelow = 2,
        TicksRight = TicksBelow,
        TicksBothSides = 3

    };

    explicit QDoubleSlider(QWidget *parent = 0);
    explicit QDoubleSlider(Qt::Orientation orientation, QWidget *parent = 0);

    ~QDoubleSlider();

    QSize sizeHint() const;
    QSize minimumSizeHint() const;

    void setTickPosition(QSlider::TickPosition position);
    QSlider::TickPosition tickPosition() const;

    void setTickInterval(int ti);
    int tickInterval() const;

    bool event(QEvent *event);

    const range_t & range() {
      return _range;
    }
    
    void changeEvent(QEvent *ev);

 signals:
    void valueChanged(QPair<int,int> range);

 public slots:
    void setValue(const QPair<int,int> & value);
     
protected:
    void paintEvent(QPaintEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void initStyleOption(QStyleOptionSlider *option) const;

private:
    friend Q_GUI_EXPORT QStyleOptionSlider qt_qsliderStyleOption(QDoubleSlider *slider);
    
    Q_DISABLE_COPY(QDoubleSlider);
    Q_DECLARE_PRIVATE(QDoubleSlider);

    friend class SliderProperties;

    range_t _range;
    
    enum ELEMENT { NONE=0x0, FIRST=0x1, SECOND=0x2};
    
    ELEMENT tracking;
};

//QT_END_NAMESPACE

QT_END_HEADER

#endif // QDOUBLESLIDER_H
