#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "person.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //QTextEdit textEditCard;

    static const int MaxPersons=500;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    float getH() const;

    float getW() const;
    void addPerson(Person* person);

private:
    Ui::MainWindow *ui;
    float h;
    float w;

    Person** all;
    QString generatePersonString(Person* person);

private slots:
    on_personButton_clicked();
    on_AddRelativeButton_clicked();
};

#endif // MAINWINDOW_H
