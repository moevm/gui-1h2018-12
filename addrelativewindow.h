#ifndef ADDRELATIVEWINDOW_H
#define ADDRELATIVEWINDOW_H

#include <QWidget>

//#include "mainwindow.h"
//#include "person.h"
//#include "personwindow.h"

class personwindow;
class MainWindow;
class Person;

namespace Ui {
class addrelativewindow;
}

class addrelativewindow : public QWidget
{
    Q_OBJECT

public:
    explicit addrelativewindow(QWidget *parent = 0);
    ~addrelativewindow();

    void setFatherWindow(MainWindow *father);

    void setAwPersonOfSignal(Person *value);

    Person *getAwPersonOfSignal() const;

private slots:
    void on_pushButtonAddPa_clicked();

    void on_pushButtonAddMa_clicked();

    void on_pushButtonAddPartner_clicked();

    void on_pushButtonAddChild_clicked();

private:
    Ui::addrelativewindow *ui;
    MainWindow *parent;
    Person *awPersonOfSignal;
};

#endif // ADDRELATIVEWINDOW_H
