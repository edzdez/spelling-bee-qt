#ifndef SPELLING_BEE_QT_TESTWORDVALIDATOR_H
#define SPELLING_BEE_QT_TESTWORDVALIDATOR_H

#include <QObject>
#include <QTest>

#include "wordvalidator.h"

class TestWordValidator : public QObject
{
    Q_OBJECT
  private slots:
    void isValid();
};

#endif // SPELLING_BEE_QT_TESTWORDVALIDATOR_H
