#ifndef PERson_H
#define PERson_H

#include <QString>
#include <QObject>
#include <QLabel>
#include <QPushButton>

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
    QString otherInf;
    int numOfPartner;
    int numOfChild;
    int currentNumOfChild;
    int currentNumOfPartner;

    float x;    //координаты центра "карточки" для отрисовки
    float y;

    int mother;
    int father;
    int *child;
    int *partner;

    QLabel *personCardLabel;
    QPushButton *addRelativeButton;

public:
    Person();
    ~Person(){}

    static const int labelHeight = 91;
    static const int labelWidth = 171;


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

    QString getYearBStr() const;
    void setYearBStr(const QString &value);

    QString getYearDStr() const;
    void setYearDStr(const QString &value);

    QString getOtherInf() const;
    void setOtherInf(const QString &value);

    QLabel *getPersonCardLabel() const;
    void setPersonCardLabel(QLabel *value, float _x, float _y);

    QPushButton *getAddRelativeButton() const;
    void setAddRelativeButton(QPushButton *value);

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

private slots:
};

#endif // PERson_H
