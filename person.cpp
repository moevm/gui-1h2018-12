#include "person.h"
#include "personview.h"


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

int Person::getId()
{
    return id;
}

void Person::setId(int value)
{
    id = value;
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

QString Person::getOtherInf() const
{
    return otherInf;
}

void Person::setOtherInf(const QString &value)
{
    otherInf = value;
}

//int Person::getNumOfPartner() const
//{
//    return numOfPartner;
//}

//void Person::setNumOfPartner(int value)
//{
//    numOfPartner = value;
//    partner = new Person*[numOfPartner];
//    currentNumOfPartner = 0;
//}

int Person::getNumOfChild() const
{
    return numOfChild;
}

void Person::setNumOfChild(int value)
{
    numOfChild = value;
    child = new Person*[numOfChild];
    currentNumOfChild = 0;
}

int Person::getCurrentNumOfChild() const
{
    return currentNumOfChild;
}

void Person::setCurrentNumOfChild(int value)
{
    currentNumOfChild = value;
}

QString Person::generatePersonString(){
   QString str = name + " " + surname + " " + "\n";
   if(yearBStr != "" || yearDStr != ""){
       str += "(" + yearBStr + "-";
       if (dead)
          str += yearDStr;
       else
           str += "now";
       str += ")";
   }
   return str;
}

PersonView *Person::getPersonView() const
{
    return personView;
}

void Person::setPersonView(PersonView *value)
{
    personView = value;
}

QString Person::getDayBStr() const
{
    return dayBStr;
}

void Person::setDayBStr(const QString &value)
{
    dayBStr = value;
}

QString Person::getDayDStr() const
{
    return dayDStr;
}

void Person::setDayDStr(const QString &value)
{
    dayDStr = value;
}

//QString Person::getNumOfPartnerStr() const
//{
//    return numOfPartnerStr;
//}

//void Person::setNumOfPartnerStr(const QString &value)
//{
//    numOfPartnerStr = value;
//}

QString Person::getNumOfChildStr() const
{
    return numOfChildStr;
}

void Person::setNumOfChildStr(const QString &value)
{
    numOfChildStr = value;
}

Person *Person::getMother() const
{
    return mother;
}

void Person::setMother(Person *value)
{
    mother = value;
}

Person *Person::getFather() const
{
    return father;
}

void Person::setFather(Person *value)
{
    father = value;
}

Person **Person::getChild() const
{
    return child;
}

void Person::setChild(Person *value)
{
    child[currentNumOfChild] = value;
    currentNumOfChild++;
}

Person* Person::getPartner() const
{
    return partner;
}

Person* Person::getMyPartner()
{
    if (partner != NULL) {
        return partner;
    } else {
        return NULL;
    }
}


void Person::setPartner(Person *value)
{
    partner = value;
}

QString Person::generateAllDataPersonString() {
    QString data = "";
    if(name != ""){
        data += name;
    }else{
        data += " null";
    }
    if(surname != ""){
        data += " " + surname;
    }else{
        data += " null";
    }
    if(patronymic != ""){
        data += " " + patronymic;
    }else{
        data += " null";
    }
    data += " " + sex;
    data += " " + QString::number(dead);
    if(dayBStr != ""){
        data += " " + dayBStr;
    }else{
        data += " null";
    }
    if(monthB != ""){
        data += " " + monthB;
    }else{
        data += " null";
    }
    if(yearBStr != ""){
        data += " " + yearBStr;
    }else{
        data += " null";
    }
    if(dayDStr != ""){
        data += " " + dayDStr;
    }else{
        data += " null";
    }
    if(monthD != ""){
        data += " " + monthD;
    }else{
        data += " null";
    }
    if(yearDStr != ""){
        data += " " + yearDStr;
    }else{
        data += " null";
    }
    if(maidenSurname != ""){
        data += " " + maidenSurname;
    }else{
        data += " null";
    }
    if(work != ""){
        data += " " + work;
    }else{
        data += " null";
    }
    if(education != ""){
        data += " " + education;
    }else{
        data += " null";
    }
    if(photoURL != ""){
        data += " " + photoURL;
    }else{
        data += " null";
    }
    if(otherInf != ""){
        data += " " + otherInf;
    }else{
        data += " null";
    }
    data += " " + numOfChildStr;
    data += " " + QString::number(currentNumOfChild);

    /*if (mother != NULL) {
        data += " " + QString::number(mother->getId());
    } else {
        data += " null";
    }
    if (father != NULL) {
        data += " " + QString::number(father->getId());
    } else {
        data += " null";
    }
    for (int i = 0; i < currentNumOfChild; i++) {
        data += " " + QString::number(child[i]->getId());
    }*/
    data += " " + QString::number(getPersonView()->getX()) + " " + QString::number(getPersonView()->getY());
    return data;
}

/*void Person::readPerson(QTextStream in) {
    in >> name;
    in >> surname;
    in >> patronymic;
    in >> sex;
    QString k;
    in >> k;
    if(k == "0"){
        dead = false;
    }else{
        dead = true;
    }
    in >> dayBStr;
    in >> monthB;
    in >> yearBStr;
    in >> dayDStr;
    in >> monthD;
    in >> yearDStr;
    in >> maidenSurname;
    in >> work;
    in >> education;
    in >> photoURL;
    in >> otherInf;
    in >> numOfChildStr;
    in >> currentNumOfChild;
    in >> k;
    mother->setId(k.toInt());
    in >> k;
    father->setId(k.toInt());
}*/

Person::Person(){
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
    otherInf = "";
    mother = NULL;
    father = NULL;
    partner = NULL;
    dayBStr = "";
    yearBStr = "";
    dayDStr = "";
    yearDStr = "";
}
