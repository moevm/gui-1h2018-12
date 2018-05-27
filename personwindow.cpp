#include "personwindow.h"
#include "ui_personwindow.h"

#include "mainwindow.h"
#include "person.h"


personwindow::personwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::personwindow)
{
    ui->setupUi(this);
    init();
}

personwindow::~personwindow()
{
    delete ui;
}

void personwindow::init(){
    on_comboBoxLiveOrDie_currentIndexChanged("Жив");
    ui->label_3->setVisible(false);
    ui->label_21->setVisible(false);
    ui->textEditNumOfChild->setText("0");
    isChange = false;
    ui->textEditPhoto->setVisible(false);
}

void personwindow::setFatherWindow(MainWindow *father)
{
    parent = father;
}

void personwindow::fromFormToPerson() {
    person->setName(ui->textEditName->toPlainText());
    person->setSurname(ui->textEditSurname->toPlainText());
    person->setPatronymic(ui->textEditPatronymic->toPlainText());
    person->setSex(ui->comboBoxSex->currentText());
    person->setDayB(ui->comboBoxDayB->currentText().toInt());
    person->setMonthB(ui->comboBoxMonthB->currentText());
    person->setYearB(ui->textEditYearB->toPlainText().toInt());
    person->setDead(ui->comboBoxLiveOrDie->currentIndex());
    if(person->getDead() == true){
        person->setDayD(ui->comboBoxDayD->currentText().toInt());
        person->setMonthD(ui->comboBoxMonthD->currentText());
        person->setYearD(ui->textEditYearD->toPlainText().toInt());
    }
    person->setMaidenSurname(ui->textEditMaidenSurname->toPlainText());
    person->setEducation(ui->textEditEducation->toPlainText());
    person->setPlace(ui->textEditPlace->toPlainText());
    person->setWork(ui->textEditWork->toPlainText());
    person->setYearBStr(ui->textEditYearB->toPlainText());
    person->setYearDStr(ui->textEditYearD->toPlainText());
    person->setOtherInf(ui->textEditElse->toPlainText());
    person->setDayBStr(ui->comboBoxDayB->currentText());
    person->setDayDStr(ui->comboBoxDayD->currentText());
    //person->setNumOfPartnerStr(ui->textEditNumOfPartners->toPlainText());
    person->setNumOfChildStr(ui->textEditNumOfChild->toPlainText());
    person->setNumOfChild(ui->textEditNumOfChild->toPlainText().toInt());
    person->setPhotoURL(img);
}

void personwindow::addNewPerson() {
    if(ui->textEditName->toPlainText() == "" && ui->textEditSurname->toPlainText() == ""){
        ui->label_3->setStyleSheet("QLabel {"
                                   "color: red;"
                                   "}");
        ui->label_3->setVisible(true);
    } else if(ui->textEditNumOfChild->toPlainText() == "") {
        ui->label_21->setStyleSheet("QLabel {"
                                   "color: red;"
                                   "}");
        ui->label_21->setVisible(true);
    } else {
        person = new Person();
        person->setNumOfChild(ui->textEditNumOfChild->toPlainText().toInt());
        //person->setNumOfPartner(ui->textEditNumOfPartners->toPlainText().toInt());

        if(whoRelativeAdd == "father"){
            person->setChild(personOfSignal);
            personOfSignal->setFather(person);
            person->setPartner(personOfSignal->getMother());
        }
        if(whoRelativeAdd == "mother"){
            person->setChild(personOfSignal);
            personOfSignal->setMother(person);
            person->setPartner(personOfSignal->getFather());
        }
        if(whoRelativeAdd == "partner"){
            person->setPartner(personOfSignal);
            personOfSignal->setPartner(person);
        }
        if(whoRelativeAdd == "child"){
            if(personOfSignal->getSex() == "Мужской"){
                person->setMother(personOfSignal->getMyPartner());
                person->setFather(personOfSignal);
            }
            if(personOfSignal->getSex() == "Женский"){
                person->setMother(personOfSignal);
                person->setFather(personOfSignal->getMyPartner());
            }
            personOfSignal->setChild(person);
            if (personOfSignal->getMyPartner() != NULL) {
                personOfSignal->getMyPartner()->setChild(person);
            }
        }
        fromFormToPerson();
        parent->addPerson(person, whoRelativeAdd, personOfSignal);
        this->close();
    }
}

void personwindow::changePerson() {
    fromFormToPerson();
    isChange = false;
    parent->updateLabel(person);
    this->close();
}

void personwindow::on_pushButton_clicked() {
    if (isChange) {
        changePerson();
    } else {
        addNewPerson();
    }
}

void personwindow::addInfo(Person *person) {
    ui->textEditSurname->setText(person->getSurname());
    ui->textEditName->setText(person->getName());
    ui->textEditPatronymic->setText(person->getPatronymic());
    ui->comboBoxSex->setCurrentText(person->getSex());
    ui->comboBoxDayB->setCurrentText(person->getDayBStr());
    ui->comboBoxMonthB->setCurrentText(person->getMonthB());
    ui->textEditYearB->setText(person->getYearBStr());
    ui->comboBoxLiveOrDie->setCurrentIndex(person->getDead());
    ui->comboBoxDayD->setCurrentText((QString)person->getDayDStr());
    ui->comboBoxMonthD->setCurrentText(person->getMonthD());
    ui->textEditYearD->setText(person->getYearDStr());
    ui->textEditMaidenSurname->setText(person->getMaidenSurname());
    ui->textEditEducation->setText(person->getEducation());
    ui->textEditPlace->setText(person->getPlace());
    ui->textEditWork->setText(person->getWork());
    ui->textEditElse->setText(person->getOtherInf());
    ui->textEditNumOfChild->setText(person->getNumOfChildStr());
    //ui->textEditNumOfPartners->setText(person->getNumOfPartnerStr());
    QPixmap pixmap(person->getPhotoURL());
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));

    this->person = person;
    isChange = true;
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

void personwindow::on_choosePhoto_clicked()
{
    QString img = "";
    ui->textEditPhoto->setVisible(true);
    img = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/photo", tr("Image Files (*.png *.jpg *.bmp"));
    if(img != ""){
        ui->textEditPhoto->setText(img);
    }
    QPixmap pixmap(ui->textEditPhoto->toPlainText());
    int w = ui->photo->width();
    int h = ui->photo->height();
    ui->photo->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));
    this->img = ui->textEditPhoto->toPlainText();
}
