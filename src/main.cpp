#include "ui/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication spellingBeeQt(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
