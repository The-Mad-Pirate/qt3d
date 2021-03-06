/****************************************************************************
**
** Copyright (C) 2015 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qpicktriangleevent.h"
#include "qpickevent_p.h"
#include <private/qobject_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DRender {

class QPickTriangleEventPrivate : public QPickEventPrivate
{
public:
    QPickTriangleEventPrivate()
        : QPickEventPrivate()
        , m_triangleIndex(0)
        , m_vertex1Index(0)
        , m_vertex2Index(0)
        , m_vertex3Index(0)
    {
    }

    uint m_triangleIndex;
    uint m_vertex1Index;
    uint m_vertex2Index;
    uint m_vertex3Index;
};

QPickTriangleEvent::QPickTriangleEvent()
    : QPickEvent(*new QPickTriangleEventPrivate())
{
}

QPickTriangleEvent::QPickTriangleEvent(const QPointF &position, const QVector3D &intersection, const QVector3D &localIntersection, float distance,
                                       uint triangleIndex, uint vertex1Index, uint vertex2Index, uint vertex3Index)
    : QPickEvent(*new QPickTriangleEventPrivate())
{
    Q_D(QPickTriangleEvent);
    d->m_position = position;
    d->m_distance = distance;
    d->m_worldIntersection = intersection;
    d->m_localIntersection = localIntersection;
    d->m_triangleIndex = triangleIndex;
    d->m_vertex1Index = vertex1Index;
    d->m_vertex2Index = vertex2Index;
    d->m_vertex3Index = vertex3Index;
}

QPickTriangleEvent::~QPickTriangleEvent()
{
}

uint QPickTriangleEvent::triangleIndex() const
{
    Q_D(const QPickTriangleEvent);
    return d->m_triangleIndex;
}

uint QPickTriangleEvent::vertex1Index() const
{
    Q_D(const QPickTriangleEvent);
    return d->m_vertex1Index;
}

uint QPickTriangleEvent::vertex2Index() const
{
    Q_D(const QPickTriangleEvent);
    return d->m_vertex2Index;
}

uint QPickTriangleEvent::vertex3Index() const
{
    Q_D(const QPickTriangleEvent);
    return d->m_vertex3Index;
}

} // Qt3DRender

QT_END_NAMESPACE

