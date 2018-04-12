#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>
#include "person.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    static const int MaxPersons = 500;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addPerson(Person *person);
    Person *getMwPersonOfSignal() const;

private:
    Ui::MainWindow *ui;

    //Person** all;
    QString generatePersonString(Person *person);
    void setMwPersonOfSignal(Person *val);

    Person *mwPersonOfSignal;
    Person *firstPerson;

    QSignalMapper *mapper;

signals:


private slots:
    on_personButton_clicked();
    void on_AddRelativeButton_clicked();

    //void clicked(Person *val);
};

#endif // MAINWINDOW_H
