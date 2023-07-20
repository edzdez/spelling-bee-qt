#ifndef SPELLING_BEE_QT_TESTTRIE_H
#define SPELLING_BEE_QT_TESTTRIE_H

#include <QObject>
#include <QTest>

class TestTrie : public QObject
{
    Q_OBJECT
  private slots:
    void addAndContains();
};

#endif // SPELLING_BEE_QT_TESTTRIE_H
