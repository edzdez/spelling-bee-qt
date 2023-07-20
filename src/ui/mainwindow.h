#ifndef SPELLING_BEE_QT_MAINWINDOW_H
#define SPELLING_BEE_QT_MAINWINDOW_H

#include <QDebug>
#include <QFile>
#include <QMainWindow>

#include "lib/trie.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

  private:
    void readWordlist();

    Ui::MainWindow *ui;
    QMap<int, QString> m_points;
    lib::Trie m_wordlist{};
};

#endif // SPELLING_BEE_QT_MAINWINDOW_H
