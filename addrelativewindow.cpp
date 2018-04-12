#include "addrelativewindow.h"
#include "ui_addrelativewindow.h"
#include "personwindow.h"
#include "mainwindow.h"

addrelativewindow::addrelativewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addrelativewindow)
{
    ui->setupUi(this);
}

addrelativewindow::~addrelativewindow()
{
    delete ui;
}

void addrelativewindow::setFatherWindow(MainWindow *father)
{
    parent = father;
}

void addrelativewindow::on_pushButtonAddPa_clicked()
{
    personwindow *pw = new personwindow();
    pw->setFatherWindow(parent);
    pw->setPersonOfSignal(getAwPersonOfSignal(), "father");
    pw->show();
    this->close();
}

Person *addrelativewindow::getAwPersonOfSignal() const
{
    return awPersonOfSignal;
}

void addrelativewindow::setAwPersonOfSignal(Person *value)
{
    awPersonOfSignal = value;
}

void addrelativewindow::on_pushButtonAddMa_clicked()
{
    personwindow *pw = new personwindow();
    pw->setFatherWindow(parent);
    pw->setPersonOfSignal(getAwPersonOfSignal(), "mother");
    pw->show();
    this->close();
}

void addrelativewindow::on_pushButtonAddPartner_clicked()
{
    personwindow *pw = new personwindow();
    pw->setFatherWindow(parent);
    pw->setPersonOfSignal(getAwPersonOfSignal(), "partner");
    pw->show();
    this->close();
}

void addrelativewindow::on_pushButtonAddChild_clicked()
{
    personwindow *pw = new personwindow();
    pw->setFatherWindow(parent);
    pw->setPersonOfSignal(getAwPersonOfSignal(), "child");
    pw->show();
    this->close();
}
