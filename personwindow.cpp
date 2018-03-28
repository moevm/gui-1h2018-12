#include "personwindow.h"
#include "ui_personwindow.h"
#include "person.h"
#include "mainwindow.h"

personwindow::personwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personwindow)
{
    ui->setupUi(this);

    /*person = new Person();
    person->setMother(0);
    person->setFather(0);
    person->setPartner(0);
    person->setSon(0);*/
}

personwindow::~personwindow()
{
    delete ui;
}

void personwindow::setFatherWindow(MainWindow *father) {
    parent = father;
}

void personwindow::on_pushButton_clicked()
{
    person = new Person();
    person->setMother(0);
    person->setFather(0);
    person->setPartner(0);
    person->setSon(0);
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

    parent->addPerson(person);

    personwindow::close();

}
