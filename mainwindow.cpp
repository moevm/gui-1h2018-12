#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personwindow.h"
#include "addrelativewindow.h"
#include "person.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->AddRelativeButton->setVisible(false);
    ui->textEditCard->setVisible(false);

    all = new Person*[MaxPersons];      //массив, хранящий всю семью
}

MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::getH() const
{
    return MainWindow::height();
}

float MainWindow::getW() const
{
    return MainWindow::width();
}

void MainWindow::addPerson(Person* person){
    ui->personButton->setVisible(false);
    ui->AddRelativeButton->setVisible(true);
    ui->textEditCard->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: black; "
                                 "font-size: 12pt;"
                                 "}");
    ui->AddRelativeButton->setStyleSheet("QLabel {"
                                         "border-style: solid;"
                                         "border-width: 1px;"
                                         "border-color: black; "
                                         "}");
    all[person->getId() - 1] = person;
    ui->textEditCard->setText(generatePersonString(person));
    ui->textEditCard->setVisible(true);
}

QString MainWindow::generatePersonString(Person* person){
   QString str = person->getName() + " " + person->getSurname() + " " + "\n" + "(" + person->getYearBStr() + "-";
   if (person->getDead())
      str += person->getYearDStr();
   else
       str += "now";
   str += ")";
   return str;
}

MainWindow::on_personButton_clicked(){  //когда нажимаем, чтобы добавить персону
    personwindow *pw = new personwindow();
    pw->setFatherWindow(this);
    pw->show();
}

MainWindow::on_AddRelativeButton_clicked(){
    addrelativewindow *aw = new addrelativewindow();
    aw->show();
}

