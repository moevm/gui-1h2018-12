#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QScrollArea>
#include <QPushButton>

class PersonView;
class Person;
class Persons;
class personwindow;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addPerson(Person *person, QString whoRelativeAdd, Person *personOfSignal);
    void updateLabel(Person *person);

    void paintEvent(QPaintEvent *);

    Person *getMwPersonOfSignal() const;

    QScrollArea *scroll;
    //void drowLines(QList<QPair<QPair<int, int>, QPair<int, int>>> list);

    QPixmap  m_Pixmap;
    QString fileName;
    bool isSave;
    bool isVert = false;

    QPushButton *personButton;

private:
    Ui::MainWindow *ui;

    Person *mwPersonOfSignal;

    Persons *allPersons;

    QString whoAddRelative;
    Person *personOfSignal;
    Person *person;

    int buttonHeight = 50;
    int buttonWidth = 113;
    float windowHeight = 1055;
    float windowWidth = 1924;

    QString generatePersonString(Person *person);
    void init();

private slots:
    void on_personButton_clicked();
    void on_saveButton_clicked();
    void on_openButton_clicked();
    void on_clearButton_clicked();
};

#endif // MAINWINDOW_H
