#ifndef PERson_H
#define PERson_H

#include <QString>
#include <QObject>

//#include "personview.h"

class PersonView;

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
    QString dayBStr;
    QString monthB;
    int yearB;
    QString yearBStr;
    int dayD;
    QString dayDStr;
    QString monthD;
    int yearD;
    QString yearDStr;
    QString maidenSurname;
    QString place;
    QString education;
    QString work;
    QString photoURL;
    QString otherInf;
    int numOfPartner;
    int numOfChild;
    int currentNumOfChild;
    int currentNumOfPartner;
    QString numOfPartnerStr;
    QString numOfChildStr;


    int mother;
    int father;
    int *child;
    int *partner;

    PersonView *personView;

public:
    Person();
    ~Person(){}

    QString generatePersonString();

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

    static int getId();
    static void setId(int value);

    QString getYearBStr() const;
    void setYearBStr(const QString &value);

    QString getYearDStr() const;
    void setYearDStr(const QString &value);

    QString getOtherInf() const;
    void setOtherInf(const QString &value);

    int getNumOfPartner() const;
    void setNumOfPartner(int value);

    int getNumOfChild() const;
    void setNumOfChild(int value);

    int *getPartner() const;
    void setPartner(int value);

    int *getChild() const;
    void setChild(int value);

    int getFather() const;
    void setFather(int value);

    int getMother() const;
    void setMother(int value);

    int getCurrentNumOfChild() const;
    void setCurrentNumOfChild(int value);

    PersonView *getPersonView() const;
    void setPersonView(PersonView *value);
    QString getDayBStr() const;
    void setDayBStr(const QString &value);
    QString getDayDStr() const;
    void setDayDStr(const QString &value);
    QString getNumOfPartnerStr() const;
    void setNumOfPartnerStr(const QString &value);
    QString getNumOfChildStr() const;
    void setNumOfChildStr(const QString &value);
};

#endif // PERson_H
