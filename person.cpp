#include "person.h"

int Person::id = 0;

QString Person::getName() const
{
    return name;
}

void Person::setName(const QString &value)
{
    name = value;
}

QString Person::getSurname() const
{
    return surname;
}

void Person::setSurname(const QString &value)
{
    surname = value;
}

QString Person::getPatronymic() const
{
    return patronymic;
}

void Person::setPatronymic(const QString &value)
{
    patronymic = value;
}

QString Person::getSex() const
{
    return sex;
}

void Person::setSex(const QString &value)
{
    sex = value;
}

bool Person::getDead() const
{
    return dead;
}

void Person::setDead(bool value)
{
    dead = value;
}

int Person::getDayB() const
{
    return dayB;
}

void Person::setDayB(int value)
{
    dayB = value;
}

QString Person::getMonthB() const
{
    return monthB;
}

void Person::setMonthB(const QString &value)
{
    monthB = value;
}

int Person::getYearB() const
{
    return yearB;
}

void Person::setYearB(int value)
{
    yearB = value;
}

int Person::getDayD() const
{
    return dayD;
}

void Person::setDayD(int value)
{
    dayD = value;
}

QString Person::getMonthD() const
{
    return monthD;
}

void Person::setMonthD(const QString &value)
{
    monthD = value;
}

int Person::getYearD() const
{
    return yearD;
}

void Person::setYearD(int value)
{
    yearD = value;
}

QString Person::getMaidenSurname() const
{
    return maidenSurname;
}

void Person::setMaidenSurname(const QString &value)
{
    maidenSurname = value;
}

QString Person::getPlace() const
{
    return place;
}

void Person::setPlace(const QString &value)
{
    place = value;
}

QString Person::getEducation() const
{
    return education;
}

void Person::setEducation(const QString &value)
{
    education = value;
}

QString Person::getWork() const
{
    return work;
}

void Person::setWork(const QString &value)
{
    work = value;
}

QString Person::getPhotoURL() const
{
    return photoURL;
}

void Person::setPhotoURL(const QString &value)
{
    photoURL = value;
}

float Person::getX() const
{
    return x;
}

void Person::setX(float value)
{
    x = value;
}

float Person::getY() const
{
    return y;
}

void Person::setY(float value)
{
    y = value;
}

int Person::getId()
{
    return id;
}

void Person::setId(int value)
{
    id = value;
}

int* Person::getMother() const
{
    return mother;
}

void Person::setMother(int *value)
{
    mother = value;
}

int* Person::getFather() const
{
    return father;
}

void Person::setFather(int *value)
{
    father = value;
}

int **Person::getSon() const
{
    return son;
}

void Person::setSon(int **value)
{
    son = value;
}

int **Person::getPartner() const
{
    return partner;
}

void Person::setPartner(int **value)
{
    partner = value;
}

QString Person::getYearBStr() const
{
    return yearBStr;
}

void Person::setYearBStr(const QString &value)
{
    yearBStr = value;
}

QString Person::getYearDStr() const
{
    return yearDStr;
}

void Person::setYearDStr(const QString &value)
{
    yearDStr = value;
}

Person::Person(){
    id++;
    name = "";
    surname = "";
    patronymic = "";
    sex = "";
    dead = false;
    dayB = 0;
    monthB = "";
    yearB = 0;
    dayD = 0;
    monthD = "";
    yearD = 0;
    maidenSurname = "";
    place = "";
    education = "";
    work = "";
    photoURL = "";
}
