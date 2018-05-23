#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPalette f;
    f.setBrush(w.centralWidget()->backgroundRole(),QBrush(QPixmap(":/Tree.pnq")));
    w.centralWidget()->setPalette(f);
    w.show();

    return a.exec();
}
