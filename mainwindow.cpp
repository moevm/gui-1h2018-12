#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personwindow.h"
#include "addrelativewindow.h"
#include "person.h"
//#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
mapper = new QSignalMapper(this);
    //all = new Person*[MaxPersons];      //массив, хранящий всю семью
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addPerson(Person* person){
    ui->personButton->setVisible(false);

    QLabel *card = new QLabel(this);
    QPushButton *relBut = new QPushButton(this);

    card->setText(generatePersonString(person));
    person->setPersonCardLabel(card, person->getX(), person->getY());

    relBut->setGeometry(person->getX() + person->labelWidth - 31, person->getY() + person->labelHeight - 28, 31, 28);
    person->setAddRelativeButton(relBut);

    person->getPersonCardLabel()->setVisible(true);
    person->getAddRelativeButton()->setVisible(true);



    /*connect(person->getAddRelativeButton(), SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(person->getAddRelativeButton(), person); // по клику кнопки будем передавать текст из этой кнопки
    // передаём текст с кнопки из маппера в слот, где будет установлен текст
    connect(mapper, SIGNAL(mapped(Person*)), this, SLOT(on_AddRelativeButton_clicked(Person*)));*/

    //firstPerson = person;

    setMwPersonOfSignal(person);
    //connect(person->getAddRelativeButton(), SIGNAL(clicked(bool)),  this, SLOT(setMwPersonOfSignal()));
    connect(person->getAddRelativeButton(), SIGNAL(clicked()), this, SLOT(on_AddRelativeButton_clicked()));
}

/*void MainWindow::clicked(Person *val)
{
    mwPersonOfSignal = val;
}*/

QString MainWindow::generatePersonString(Person* person){
   QString str = person->getName() + " " + person->getSurname() + " " + "\n";
   if(person->getYearBStr() != "" || person->getYearDStr() != ""){
       str += "(" + person->getYearBStr() + "-";
       if (person->getDead())
          str += person->getYearDStr();
       else
           str += "now";
       str += ")";
   }
   return str;
}

Person *MainWindow::getMwPersonOfSignal() const
{
    return mwPersonOfSignal;
}

MainWindow::on_personButton_clicked(){  //когда нажимаем, чтобы добавить персону
    personwindow *pw = new personwindow();
    pw->setFatherWindow(this);
    pw->show();
}

void MainWindow::on_AddRelativeButton_clicked(){
    addrelativewindow *aw = new addrelativewindow();
    aw->setFatherWindow(this);
    aw->setAwPersonOfSignal(mwPersonOfSignal);
    aw->show();
}

void MainWindow::setMwPersonOfSignal(Person *val)
{
    mwPersonOfSignal = val;
}
