/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
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
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qplatformdefs.h"

#include "qbytearray.h"
#include "qstring.h"

#include "string.h"

QT_BEGIN_NAMESPACE

#ifndef QT_VSNPRINTF

/*!
    \relates QByteArray

    A portable \c vsnprintf() function. Will call \c ::vsnprintf(), \c
    ::_vsnprintf(), or \c ::vsnprintf_s depending on the system, or
    fall back to an internal version.

    \a fmt is the \c printf() format string. The result is put into
    \a str, which is a buffer of at least \a n bytes.

    The caller is responsible to call \c va_end() on \a ap.

    \warning Since vsnprintf() shows different behavior on certain
    platforms, you should not rely on the return value or on the fact
    that you will always get a 0 terminated string back.

    Ideally, you should never call this function but use QString::sprintf()
    instead.

    \sa qsnprintf(), QString::sprintf()
*/

int qvsnprintf(char *str, size_t n, const char *fmt, va_list ap)
{
    if (!str || !fmt)
        return -1;

    QString buf;
    buf.vsprintf(fmt, ap);

    QByteArray ba = buf.toLocal8Bit();

    if (n > 0) {
        size_t blen = qMin(size_t(ba.length()), size_t(n - 1));
        memcpy(str, ba.constData(), blen);
        str[blen] = '\0'; // make sure str is always 0 terminated
    }

    return ba.length();
}

#else

QT_BEGIN_INCLUDE_NAMESPACE
#include <stdio.h>
QT_END_INCLUDE_NAMESPACE

int qvsnprintf(char *str, size_t n, const char *fmt, va_list ap)
{
    return QT_VSNPRINTF(str, n, fmt, ap);
}

#endif

// va_list mangling has been changed in g++ 4.4
// Add ABI compatibility hack for g++ 4.3 and below.
#if defined __ARM_EABI__ && defined __GNUC__ && (__GNUC__ > 4 || __GNUC__ == 4 && __GNUC_MINOR__ >= 4)
__asm__(".symver _Z10qvsnprintfPcjPKcSt9__va_list, _Z10qvsnprintfPcjPKcPv@@");
#endif

/*!
    \relates QByteArray

    A portable snprintf() function, calls qvsnprintf.

    \a fmt is the \c printf() format string. The result is put into
    \a str, which is a buffer of at least \a n bytes.

    \warning Call this function only when you know what you are doing
    since it shows different behavior on certain platforms.
    Use QString::sprintf() to format a string instead.

    \sa qvsnprintf(), QString::sprintf()
*/

int qsnprintf(char *str, size_t n, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);

    int ret = qvsnprintf(str, n, fmt, ap);
    va_end(ap);

    return ret;
}

QT_END_NAMESPACE
