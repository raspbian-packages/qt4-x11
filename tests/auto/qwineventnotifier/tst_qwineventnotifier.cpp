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

#ifdef Q_OS_WIN
#include <private/qwineventnotifier_p.h>


#include <qtimer.h>

//TESTED_CLASS=
//TESTED_FILES=

class tst_QWinEventNotifier : public QObject
{
    Q_OBJECT

public:
    tst_QWinEventNotifier();
    ~tst_QWinEventNotifier();

    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

protected slots:
    void simple_activated();
    void simple_timerSet();
private slots:

    void simple();

private:
    HANDLE simpleHEvent;
    bool simpleActivated;
};

tst_QWinEventNotifier::tst_QWinEventNotifier()
{}

tst_QWinEventNotifier::~tst_QWinEventNotifier()
{ }

void tst_QWinEventNotifier::initTestCase()
{ }

void tst_QWinEventNotifier::cleanupTestCase()
{ }

void tst_QWinEventNotifier::init()
{ }

void tst_QWinEventNotifier::cleanup()
{
}


void tst_QWinEventNotifier::simple_activated()
{
    simpleActivated = true;
    ResetEvent((HANDLE)simpleHEvent);
    QTestEventLoop::instance().exitLoop();
}

void tst_QWinEventNotifier::simple_timerSet()
{
    SetEvent((HANDLE)simpleHEvent);
}

void tst_QWinEventNotifier::simple()
{
    simpleHEvent = CreateEvent(0, TRUE, FALSE, 0);
    QVERIFY(simpleHEvent);

    QWinEventNotifier n(simpleHEvent);
    QObject::connect(&n, SIGNAL(activated(HANDLE)), this, SLOT(simple_activated()));
    simpleActivated = false;

    SetEvent((HANDLE)simpleHEvent);

    QTestEventLoop::instance().enterLoop(30);
    if (QTestEventLoop::instance().timeout())
        QFAIL("Timed out");

    QVERIFY(simpleActivated);


    simpleActivated = false;

    QTimer::singleShot(3000, this, SLOT(simple_timerSet()));

    QTestEventLoop::instance().enterLoop(30);
    if (QTestEventLoop::instance().timeout())
        QFAIL("Timed out");

    QVERIFY(simpleActivated);
}

QTEST_MAIN(tst_QWinEventNotifier)

#include "tst_qwineventnotifier.moc"
#else // non-windows systems
QTEST_NOOP_MAIN
#endif
