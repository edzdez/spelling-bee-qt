// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    ui->l6->setStyleSheet("background-color: #FFFF00; color: #000000; border: none;");

    connect(m_manager, &QNetworkAccessManager::finished, this, &MainWindow::onRequestReply);
    connect(ui->actionNew_Game, &QAction::triggered, this, &MainWindow::onNewGameClicked);
    connect(this, &MainWindow::gameLoaded, this, &MainWindow::onGameLoad);
    connect(this, &MainWindow::pointsEarned, this, &MainWindow::onPointsEarned);
    connect(this, &MainWindow::resetUi, this, &MainWindow::onResetUi);

    fetchData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fetchData()
{
    m_manager->get(QNetworkRequest(QUrl("https://freebee.fun/cgi-bin/random")));
    qInfo("fetching data...");
}

void MainWindow::onRequestReply(QNetworkReply *reply)
{
    if (!reply->error())
    {
        QString response = reply->readAll();
        qInfo() << "received a response";
        parseResponse(response);
    }
    else
        qCritical() << reply->errorString();

    reply->deleteLater();
}

void MainWindow::parseResponse(const QString &response)
{
    QJsonParseError err{};
    m_gameData = QJsonDocument::fromJson(response.toUtf8(), &err);
    if (m_gameData.isNull())
    {
        qCritical() << "failed to parse response:" << err.errorString();
        return;
    }

    qInfo("parsed response");
    emit gameLoaded();
}

void MainWindow::onGameLoad()
{
    const auto gameData = m_gameData.object();
    m_validLetters = gameData.value("letters").toString().toUpper();
    m_validLetters += gameData.value("center").toString().toUpper();
    ui->l0->setText(static_cast<QChar>(m_validLetters[0]));
    ui->l1->setText(static_cast<QChar>(m_validLetters[1]));
    ui->l2->setText(static_cast<QChar>(m_validLetters[2]));
    ui->l3->setText(static_cast<QChar>(m_validLetters[3]));
    ui->l4->setText(static_cast<QChar>(m_validLetters[4]));
    ui->l5->setText(static_cast<QChar>(m_validLetters[5]));
    ui->l6->setText(static_cast<QChar>(m_validLetters[6]));

    const auto words = gameData.value("wordlist").toArray();
    for (const auto &word : words)
        m_wordlist.addWord(word.toString());
    qInfo("built wordlist");

    m_points = 0;
    m_totalPoints = gameData.value("total").toInt();
    emit resetUi();
}

void MainWindow::on_l0_clicked()
{
    ui->wordEntry->setText(ui->wordEntry->text() + ui->l0->text());
}

void MainWindow::on_l1_clicked()
{
    ui->wordEntry->setText(ui->wordEntry->text() + ui->l1->text());
}

void MainWindow::on_l2_clicked()
{
    ui->wordEntry->setText(ui->wordEntry->text() + ui->l2->text());
}

void MainWindow::on_l3_clicked()
{
    ui->wordEntry->setText(ui->wordEntry->text() + ui->l3->text());
}

void MainWindow::on_l4_clicked()
{
    ui->wordEntry->setText(ui->wordEntry->text() + ui->l4->text());
}

void MainWindow::on_l5_clicked()
{
    ui->wordEntry->setText(ui->wordEntry->text() + ui->l5->text());
}

void MainWindow::on_l6_clicked()
{
    ui->wordEntry->setText(ui->wordEntry->text() + ui->l6->text());
}

void MainWindow::on_submitButton_clicked()
{
    submit();
}

void MainWindow::onPointsEarned()
{
    ui->pointsLabel->setText(QString("Points: %1").arg(m_points));
    ui->rankLabel->setText(QString("Rank: %1").arg(lib::calculateRank(m_points, m_totalPoints)));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    ui->label->clear();
    for (auto &&m_validLetter : m_validLetters)
    {
        if (event->text().toUpper() == m_validLetter)
        {
            ui->wordEntry->setText(ui->wordEntry->text() + m_validLetter);
            return;
        }
    }

    if (event->key() == Qt::Key::Key_Backspace)
        ui->wordEntry->backspace();
    else if (event->key() == Qt::Key_Return)
        submit();
}

void MainWindow::submit()
{
    QString guess = ui->wordEntry->text();
    if (guess.isEmpty())
        return;
    if (!guess.contains(m_validLetters[6]))
    {
        ui->label->setText("must use center letter");
        return;
    }
    if (m_guessed.contains(guess))
    {
        ui->label->setText("you already guessed that");
        return;
    }

    ui->wordEntry->clear();

    if (m_wordlist.contains(guess.toLower()))
    {
        m_guessed.insert(guess);
        m_points += lib::calculatePoints(guess);
        ui->foundWords->appendPlainText(guess);
        emit pointsEarned();
    }
    else
        ui->label->setText("not in wordlist");
}

void MainWindow::onResetUi()
{
    m_guessed.clear();
    ui->pointsLabel->setText("Points: 0");
    ui->rankLabel->setText("Rank: 0");
    ui->label->clear();
    ui->foundWords->clear();
}

void MainWindow::onNewGameClicked()
{
    fetchData();
}
