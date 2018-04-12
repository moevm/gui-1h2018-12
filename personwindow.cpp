#include "personwindow.h"
#include "ui_personwindow.h"
#include "person.h"
#include "mainwindow.h"

personwindow::personwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personwindow)
{
    ui->setupUi(this);

    ui->comboBoxDayD->setVisible(false);
    ui->comboBoxMonthD->setVisible(false);
    ui->textEditYearD->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_15->setVisible(false);
    ui->label_16->setVisible(false);
    ui->label_17->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_21->setVisible(false);

}

personwindow::~personwindow()
{
    delete ui;
}

void personwindow::setFatherWindow(MainWindow *father)
{
    parent = father;
}

void personwindow::on_pushButton_clicked()
{
    if(ui->textEditName->toPlainText() == "" && ui->textEditSurname->toPlainText() == ""){
        ui->label_3->setStyleSheet("QLabel {"
                                   "color: red;"
                                   "}");
        ui->label_3->setVisible(true);
    } else if(ui->textEditNumOfChild->toPlainText() == "" || ui->textEditNumOfPartners->toPlainText() == "") {
        ui->label_21->setStyleSheet("QLabel {"
                                   "color: red;"
                                   "}");
        ui->label_21->setVisible(true);
    } else {
        person = new Person();

        person->setNumOfChild(ui->textEditNumOfChild->toPlainText().toInt());
        person->setNumOfPartner(ui->textEditNumOfPartners->toPlainText().toInt());

        if(whoRelativeAdd == "father"){
            person->setChild(personOfSignal->getId());
            personOfSignal->setFather(person->getId());
        }
        if(whoRelativeAdd == "mother"){
            person->setChild(personOfSignal->getId());
            personOfSignal->setMother(person->getId());
        }
        if(whoRelativeAdd == "partner"){
            person->setPartner(personOfSignal->getId());
            personOfSignal->setPartner(person->getId());
        }
        if(whoRelativeAdd == "child"){
            if(personOfSignal->getSex() == "Мужской"){
                person->setFather(personOfSignal->getId());
            }
            if(personOfSignal->getSex() == "Женский"){
                person->setMother(personOfSignal->getId());
            }
            personOfSignal->setChild(person->getId());
        }
        person->setName(ui->textEditName->toPlainText());
        person->setSurname(ui->textEditSurname->toPlainText());
        person->setPatronymic(ui->textEditPatronymic->toPlainText());
        person->setSex(ui->comboBoxSex->currentText());
        person->setDayB(ui->comboBoxDayB->currentText().toInt());
        person->setMonthB(ui->comboBoxMonthB->currentText());
        person->setYearB(ui->textEditYearB->toPlainText().toInt());
        person->setDead(ui->comboBoxLiveOrDie->currentIndex());
        person->setDayD(ui->comboBoxDayD->currentText().toInt());
        person->setMonthD(ui->comboBoxMonthD->currentText());
        person->setYearD(ui->textEditYearD->toPlainText().toInt());
        person->setMaidenSurname(ui->textEditMaidenSurname->toPlainText());
        person->setEducation(ui->textEditEducation->toPlainText());
        person->setPlace(ui->textEditPlace->toPlainText());
        person->setWork(ui->textEditWork->toPlainText());
        person->setYearBStr(ui->textEditYearB->toPlainText());
        person->setYearDStr(ui->textEditYearD->toPlainText());
        person->setOtherInf(ui->textEditElse->toPlainText());
        if(person->getId() == 1){
            person->setX(parent->width()/2);
            person->setY(parent->height()/2);
        }else{
            if (whoRelativeAdd == "father") {
                person->setX(personOfSignal->getX() - (person->labelWidth)/2 - spaceToParentX);
                person->setY(personOfSignal->getY() - person->labelHeight - spaceToParentY);
            }
            if (whoRelativeAdd == "mother") {
                person->setX(personOfSignal->getX() + 3*(person->labelWidth)/2 + spaceToParentX);
                person->setY(personOfSignal->getY() - person->labelHeight - spaceToParentY);
            }
            if (whoRelativeAdd == "partner") {
                person->setX(personOfSignal->getX() + person->labelWidth + 2*spaceToParentX);
                person->setY(personOfSignal->getY());
            }
            if (whoRelativeAdd == "child") {
                person->setX(personOfSignal->getX() - (personOfSignal->getNumOfChild()*(person->labelWidth + spaceToParentX) - spaceToParentX)/2 + person->labelWidth/2 + personOfSignal->getCurrentNumOfChild()*(person->labelWidth + spaceToParentX));
                person->setY(personOfSignal->getY() + person->labelHeight + spaceToParentY);
            }
        }
        parent->addPerson(person);
        this->close();
    }
}

void personwindow::on_comboBoxLiveOrDie_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Умер"){
        ui->comboBoxDayD->setVisible(true);
        ui->comboBoxMonthD->setVisible(true);
        ui->textEditYearD->setVisible(true);
        ui->label_2->setVisible(true);
        ui->label_15->setVisible(true);
        ui->label_16->setVisible(true);
        ui->label_17->setVisible(true);
    }else{
        ui->comboBoxDayD->setVisible(false);
        ui->comboBoxMonthD->setVisible(false);
        ui->textEditYearD->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_15->setVisible(false);
        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
}

void personwindow::setPersonOfSignal(Person *val1,  QString val2)
{
    personOfSignal = val1;
    whoRelativeAdd = val2;
}
