#ifndef PERSONWINDOW_H
#define PERSONWINDOW_H

#include <QWidget>
#include "mainwindow.h"


namespace Ui {
class personwindow;
}

class personwindow : public QWidget
{
    Q_OBJECT

public:
    explicit personwindow(QWidget *parent = 0);
    ~personwindow();
    void setFatherWindow(MainWindow *father);

private slots:

    void on_pushButton_clicked();

private:
    MainWindow *parent;
    Person* person;
    Ui::personwindow *ui;
};

#endif // PERSONWINDOW_H
