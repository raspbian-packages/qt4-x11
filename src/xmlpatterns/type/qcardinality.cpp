/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
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
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qpatternistlocale_p.h"

#include "qcardinality_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

QString Cardinality::displayName(const CustomizeDisplayName explain) const
{
    if(explain == IncludeExplanation)
    {
        if(isEmpty())
            return QString(QtXmlPatterns::tr("empty") + QLatin1String("(\"empty-sequence()\")"));
        else if(isZeroOrOne())
            return QString(QtXmlPatterns::tr("zero or one") + QLatin1String("(\"?\")"));
        else if(isExactlyOne())
            return QString(QtXmlPatterns::tr("exactly one"));
        else if(isOneOrMore())
            return QString(QtXmlPatterns::tr("one or more") + QLatin1String("(\"+\")"));
        else
            return QString(QtXmlPatterns::tr("zero or more") + QLatin1String("(\"*\")"));
    }
    else
    {
        Q_ASSERT(explain == ExcludeExplanation);

        if(isEmpty() || isZeroOrOne())
            return QLatin1String("?");
        else if(isExactlyOne())
            return QString();
        else if(isExact())
        {
            return QString(QLatin1Char('{'))    +
                   QString::number(maximum())   +
                   QLatin1Char('}');
        }
        else
        {
            if(m_max == -1)
            {
                if(isOneOrMore())
                    return QChar::fromLatin1('+');
                else
                    return QChar::fromLatin1('*');
            }
            else
            {
                /* We have a range. We use a RegExp-like syntax. */
                return QString(QLatin1Char('{'))    +
                       QString::number(minimum())   +
                       QLatin1String(", ")          +
                       QString::number(maximum())   +
                       QLatin1Char('}');

            }
        }
    }
}

QT_END_NAMESPACE
