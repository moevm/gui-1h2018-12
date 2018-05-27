#include "persons.h"
#include "person.h"
#include "mainwindow.h"
#include "personview.h"

Persons::Persons(MainWindow *father)
{
    all = new Person*[MaxPersons];      //массив, хранящий всю семью
    numOfPersons = 0;
    this->father = father;

    //list = *(new QList<QPair<QPair<int, int>, QPair<int, int>>> ());
}

/*void Persons::addLine(int x1, int y1, int x2, int y2) {
    //list.push_back(*(new QPair(*(new QPair(x1, y1)), *(new QPair(x2, y2)) )) );
}*/

void Persons::addNewPerson(Person* person) {
    all[numOfPersons] = person;
    person->setId(numOfPersons);

    numOfPersons++;
}

void Persons::saveAll() {
    QString fileName = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    QFile *file = new QFile(fileName);
    QFileInfo qfi(file->fileName());
    QFile file2(qfi.dir().path() + "/pix_" + qfi.baseName() + ".png");
    file2.open(QIODevice::WriteOnly);
    father->m_Pixmap.save(&file2, "PNG");
    file2.close();

    if (file->open(QIODevice::WriteOnly)) {
        QTextStream out(file);
        out << QString::number(numOfPersons);
        out << "\r\n";
        for (int i = 0; i < numOfPersons; i++) {
            out << QString::number(all[i]->getId()) + " ";
            out << QString(all[i]->generateAllDataPersonString());
            out << "\r\n";
        }
        //out << getLineString();
        file->close();

    }
}

/*QString Persons::getLineString() {
    QListIterator<QPair<QPair<int, int>, QPair<int, int>>> i(list);
    QString lineData = QString::number(list.size());
    QPair<QPair<int, int>, QPair<int, int>> tmp;
    while (i.hasNext()) {
        tmp = i.next();
        lineData += " " + QString::number(tmp.first.first) + " " + QString::number(tmp.first.second) +
                    " " + QString::number(tmp.second.first) + " " + QString::number(tmp.second.second);
    }
    return lineData;
}*/

void Persons::readAll() {
    QString fileName = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QFileInfo qfi(file.fileName());
        father->fileName = qfi.dir().path() + "/pix_" + qfi.baseName() + ".png";
        clear();
        father->update();
        QTextStream in(&file);
        in >> numOfPersons;
        int k;
        QString str;
        Person* newPerson;
        PersonView* newPersonView;
        for (int i = 0; i < numOfPersons; ++i) {
            newPerson = new Person();
            in >> k;
            newPerson->setId(k);
            all[k] = newPerson;
            in >> str;
            if(str == "null"){
                newPerson->setName("");
            }else{
                newPerson->setName(str);
            }
            in >> str;
            if(str == "null"){
                newPerson->setSurname("");
            }else{
                newPerson->setSurname(str);
            }
            in >> str;
            if(str == "null"){
                newPerson->setPatronymic("");
            }else{
                newPerson->setPatronymic(str);
            }
            in >> str;
            newPerson->setSex(str);
            in >> str;
            if(str == "0"){
                newPerson->setDead(false);
            }else{
                newPerson->setDead(true);
            }
            in >> str;
            if(str == "null"){
                newPerson->setDayBStr("");
                newPerson->setDayB(0);
            }else{
                newPerson->setDayBStr(str);
                newPerson->setDayB(str.toInt());
            }
            in >> str;
            if(str == "null"){
                newPerson->setMonthB("");
            }else{
                newPerson->setMonthB(str);
            }
            in >> str;
            if(str == "null"){
                newPerson->setYearBStr("");
                newPerson->setYearB(0);
            }else{
                newPerson->setYearBStr(str);
                newPerson->setYearB(str.toInt());
            }
            in >> str;
            if(str == "null"){
                newPerson->setDayDStr("");
                newPerson->setDayD(0);
            }else{
                newPerson->setDayDStr(str);
                newPerson->setDayD(str.toInt());
            }
            in >> str;
            if(str == "null"){
                newPerson->setMonthD("");
            }else{
                newPerson->setMonthD(str);
            }
            in >> str;
            if(str == "null"){
                newPerson->setYearDStr("");
                newPerson->setYearD(0);
            }else{
                newPerson->setYearDStr(str);
                newPerson->setYearD(str.toInt());
            }
            in >> str;
            if(str == "null"){
                newPerson->setMaidenSurname("");
            }else{
                newPerson->setMaidenSurname(str);
            }
            in >> str;
            if(str == "null"){
                newPerson->setWork("");
            }else{
                newPerson->setWork(str);
            }
            in >> str;
            if(str == "null"){
                newPerson->setEducation("");
            }else{
                newPerson->setEducation(str);
            }
            in >> str;
            if(str == "null"){
                newPerson->setPhotoURL("");
            }else{
                newPerson->setPhotoURL(str);
            }
            in >> str;
            if(str == "null"){
                newPerson->setOtherInf("");
            }else{
                newPerson->setOtherInf(str);
            }
            in >> str;
            newPerson->setNumOfChildStr(str);
            in >> k;
            newPerson->setCurrentNumOfChild(k);

            in >> str;
            if(str != "null"){
                newPerson->setMotherId(str.toInt());
            }
            in >> str;
            if(str != "null"){
                newPerson->setFatherId(str.toInt());
            }
            in >> str;
            if(str != "null"){
                newPerson->setPartnerId(str.toInt());
            }
            for(int j = 0; j < newPerson->getCurrentNumOfChild(); ++j){
                in >> k;
                newPerson->setChildId(k, j);
            }

            newPersonView = new PersonView(newPerson, father);
            in >> k;
            newPersonView->setX(k);
            in >> k;
            newPersonView->setY(k);
            newPersonView->addButton();
            newPerson->setPersonView(newPersonView);
        }
        /*int x2, y2;
        list = *(new QList<QPair<QPair<int, int>, QPair<int, int>>> ());
        for (int i = 0; i < k; i++) {
            in >> x >> y >> x2 >> y2;
            list.push_back(new QPair (new QPair(x, y), new QPair(x2, y2)));
        }
        //father->drowLines(list);*/
        father->isSave = true;
        father->personButton->close();

        for (int i = 0; i < numOfPersons; ++i) {
            if(all[i]->getMotherId() >= 0){
                all[i]->setMother(all[all[i]->getMotherId()]);
            }
            if(all[i]->getFatherId() >= 0){
                all[i]->setFather(all[all[i]->getFatherId()]);
            }
            if(all[i]->getPartnerId() >= 0){
                all[i]->setPartner(all[all[i]->getPartnerId()]);
            }
            int numOfChildsThere = all[i]->getCurrentNumOfChild();
            all[i]->setCurrentNumOfChild(0);
            for(int j = 0; j < numOfChildsThere; ++j){
                all[i]->setChild(all[all[i]->getChildId()[j]]);
            }
        }

        file.close();
    }
}
   // all[i]->setMother( all[ all[i]->getMotherId()] )

void Persons::clear(){
    for(int i = 0; i < numOfPersons ; ++i){
        all[i]->getPersonView()->getPersonCardLabel()->setStyleSheet("opacity: 1.0;");
        all[i]->getPersonView()->getPersonCardLabel()->clear();
        all[i]->getPersonView()->getAddRelativeButton()->close();
        all[i]->getPersonView()->getInfoButton()->close();
        delete all[i];
    }
}

/*Person* Persons::readPerson(QTextStream in) {
    Person* newPerson = new Person();
    QString str;
    in >> str;
    newPerson->setName(str);
    in >> str;
    newPerson->setSurname(str);

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
    in >> numOfPartnerStr;
    in >> currentNumOfChild;
    in >> currentNumOfPartner;
    in >> k;
    mother->setId(k.toInt());
    in >> k;
    father->setId(k.toInt());

    return newPerson;
}*/
