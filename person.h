#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QObject>

class Person:public QObject
{
    Q_OBJECT
private:
    static int id;  //счетчик объектов
    QString name;
    QString surname;
    QString patronymic;
    QString sex;
    bool dead;
    int dayB;
    QString monthB;
    int yearB;
    QString yearBStr;
    int dayD;
    QString monthD;
    int yearD;
    QString yearDStr;
    QString maidenSurname;
    QString place;
    QString education;
    QString work;
    QString photoURL;

    float x;    //координаты центра "карточки" для отрисовки
    float y;

    int* mother;
    int* father;
    int** son;
    int** partner;

public:
    Person();
    ~Person(){}

    QString getName() const;
    void setName(const QString &value);

    QString getSurname() const;
    void setSurname(const QString &value);

    QString getPatronymic() const;
    void setPatronymic(const QString &value);

    QString getSex() const;
    void setSex(const QString &value);

    bool getDead() const;
    void setDead(bool value);

    int getDayB() const;
    void setDayB(int value);

    QString getMonthB() const;
    void setMonthB(const QString &value);

    int getYearB() const;
    void setYearB(int value);

    int getDayD() const;
    void setDayD(int value);

    QString getMonthD() const;
    void setMonthD(const QString &value);

    int getYearD() const;
    void setYearD(int value);

    QString getMaidenSurname() const;
    void setMaidenSurname(const QString &value);

    QString getPlace() const;
    void setPlace(const QString &value);

    QString getEducation() const;
    void setEducation(const QString &value);

    QString getWork() const;
    void setWork(const QString &value);

    QString getPhotoURL() const;
    void setPhotoURL(const QString &value);

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

    static int getId();
    static void setId(int value);

    int *getMother() const;
    void setMother(int *value);

    int *getFather() const;
    void setFather(int *value);

    int **getSon() const;
    void setSon(int **value);

    int **getPartner() const;
    void setPartner(int **value);

    QString getYearBStr() const;
    void setYearBStr(const QString &value);

    QString getYearDStr() const;
    void setYearDStr(const QString &value);

private slots:
};

#endif // PERSON_H
