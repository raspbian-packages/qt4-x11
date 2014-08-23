/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the test suite of the Qt Toolkit.
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


#include <QtTest/QtTest>
#include <qsslerror.h>

#include <QtNetwork/qhostaddress.h>
#include <QtNetwork/qnetworkproxy.h>

class tst_QSslError : public QObject
{
    Q_OBJECT

public:
    tst_QSslError();
    virtual ~tst_QSslError();

    static void enterLoop(int secs)
    {
        ++loopLevel;
        QTestEventLoop::instance().enterLoop(secs);
        --loopLevel;
    }
    static void exitLoop()
    {
        // Safe exit - if we aren't in an event loop, don't
        // exit one.
        if (loopLevel > 0)
            QTestEventLoop::instance().exitLoop();
    }
    static bool timeout()
    {
        return QTestEventLoop::instance().timeout();
    }

public slots:
    void initTestCase_data();
    void init();
    void cleanup();

#ifndef QT_NO_OPENSSL
private slots:
    void constructing();
#endif
    
private:
    static int loopLevel;
};

int tst_QSslError::loopLevel = 0;

tst_QSslError::tst_QSslError()
{
}

tst_QSslError::~tst_QSslError()
{

}

void tst_QSslError::initTestCase_data()
{
}

void tst_QSslError::init()
{
}

void tst_QSslError::cleanup()
{
}

#ifndef QT_NO_OPENSSL

void tst_QSslError::constructing()
{
    QSslError error;
}

#endif // QT_NO_OPENSSL

QTEST_MAIN(tst_QSslError)
#include "tst_qsslerror.moc"
