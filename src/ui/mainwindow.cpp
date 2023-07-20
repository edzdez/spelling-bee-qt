// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_wordlist()
{
    ui->setupUi(this);
    readWordlist();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readWordlist()
{
}
