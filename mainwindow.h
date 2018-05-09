#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class PersonView;
class Person;
class personwindow;

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
    void addPerson(Person *person, QString whoRelativeAdd, Person *personOfSignal);
    void updateLabel(Person *person);

    void paintEvent(QPaintEvent *);

    Person *getMwPersonOfSignal() const;

private:
    Ui::MainWindow *ui;

    Person *mwPersonOfSignal;

    //Person** all;

    QString generatePersonString(Person *person);

    bool isVert = false;
    PersonView *personView;
    PersonView *viewOfSignal;
    QPixmap   m_Pixmap;

private slots:
    on_personButton_clicked();
};

#endif // MAINWINDOW_H
