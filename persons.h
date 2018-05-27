#ifndef PERSONS_H
#define PERSONS_H

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QFileInfo>

class Person;
class PersonView;
class MainWindow;

class Persons
{
public:
    static const int MaxPersons = 500;
    Persons(MainWindow *father);

    void addNewPerson(Person* person);
    void saveAll();
    void readAll();
    void clear();

    //void addLine(int x1, int y1, int x2, int y2);

private:
    int numOfPersons;
    Person **all;
    Person *readPerson(QTextStream in);
    MainWindow *father;

    //QList<QPair<QPair<int, int>, QPair<int, int>>> list;
    //QString getLineString();

};

#endif // PERSONS_H
