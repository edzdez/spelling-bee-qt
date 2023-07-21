#ifndef SPELLING_BEE_QT_MAINWINDOW_H
#define SPELLING_BEE_QT_MAINWINDOW_H

#include <QDebug>
#include <QFile>
#include <QJsonObject>
#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>

#include "lib/trie.h"
#include "lib/utils.h"

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

  signals:
    void gameLoaded();
    void pointsEarned();
    void resetUi();

  private slots:
    void onRequestReply(QNetworkReply *reply);
    void onGameLoad();
    void onPointsEarned();
    void onResetUi();

    void on_l0_clicked();
    void on_l1_clicked();
    void on_l2_clicked();
    void on_l3_clicked();
    void on_l4_clicked();
    void on_l5_clicked();
    void on_l6_clicked();

    void onNewGameClicked();
    void on_submitButton_clicked();

  protected:
    void keyPressEvent(QKeyEvent *event) override;

  private:
    void fetchData();
    void parseResponse(const QString &response);
    void submit();

    Ui::MainWindow *ui;

    QNetworkAccessManager *m_manager;

    QJsonDocument m_gameData;
    QString m_validLetters;
    QSet<QString> m_guessed;
    lib::Trie m_wordlist;
    int m_points;
    int m_totalPoints;
};

#endif // SPELLING_BEE_QT_MAINWINDOW_H
