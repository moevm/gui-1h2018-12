#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "personwindow.h"
#include "personview.h"
#include "person.h"
#include <QPainter>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Family Tree");
    m_Pixmap = QPixmap(1500, 800);
    m_Pixmap.fill(Qt::white);
    //all = new Person*[MaxPersons];      //массив, хранящий всю семью
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLabel(Person *person) {
    person->getPersonView()->UpdateLabel();
}

Person *MainWindow::getMwPersonOfSignal() const
{
    return mwPersonOfSignal;
}

void MainWindow::addPerson(Person* person, QString whoRelativeAdd, Person* personOfSignal){
    personView = new PersonView(person, this);
    if(person->getId() == 1){

        ui->personButton->close();

        personView->setX(this->width()/2 - personView->labelWidth/2);
        personView->setY(this->height()/2 - personView->labelHeight/2);
    }else{
        isVert = true;
        viewOfSignal = personOfSignal->getPersonView();
        if (whoRelativeAdd == "father") {
            personView->setX(viewOfSignal->getX() - (personView->labelWidth)/2 - personView->spaceToParentX);
            personView->setY(viewOfSignal->getY() - personView->labelHeight - personView->spaceToParentY);
        }
        if (whoRelativeAdd == "mother") {
            personView->setX(viewOfSignal->getX() + 3*(personView->labelWidth)/2 + personView->spaceToParentX);
            personView->setY(viewOfSignal->getY() - personView->labelHeight - personView->spaceToParentY);
        }
        if (whoRelativeAdd == "partner") {
            personView->setX(viewOfSignal->getX() + personView->labelWidth + 2*personView->spaceToParentX);
            personView->setY(viewOfSignal->getY());
        }
        if (whoRelativeAdd == "child") {
            personView->setX(viewOfSignal->getX()+viewOfSignal->labelWidth + viewOfSignal->spaceToParentX -
                             (personOfSignal->getNumOfChild()*(viewOfSignal->labelWidth +
                             (personOfSignal->getNumOfChild()-1)*viewOfSignal->spaceToParentX))/2 +
                             personOfSignal->getCurrentNumOfChild()*(personView->labelWidth + personView->spaceToParentX));
            //personView->setX(viewOfSignal->getX() - (personOfSignal->getNumOfChild()*(personView->labelWidth + personView->spaceToParentX) - personView->spaceToParentX)/2 + personView->labelWidth/2 + personOfSignal->getCurrentNumOfChild()*(personView->labelWidth + personView->spaceToParentX));
            personView->setY(viewOfSignal->getY() + personView->labelHeight + personView->spaceToParentY);
        }
    }

    personView->addButton();
    person->setPersonView(personView);
    //repaint();
}

MainWindow::on_personButton_clicked(){  //когда нажимаем, чтобы добавить персону
    personwindow *pw = new personwindow();
    pw->setFatherWindow(this);
    pw->show();
}

void MainWindow::paintEvent(QPaintEvent *){
    if(isVert){
        //QPixmap m_Pixmap(600, 400);
        QPainter pnt(&m_Pixmap);
       // QPainter painter(this);
        //painter.setPen(QPen(Qt::black,3,Qt::SolidLine));
        //painter.drawLine(personView->getX()+personView->labelWidth/2, personView->getY()+personView->labelHeight/2,
                                //viewOfSignal->getX()+personView->labelWidth/2, viewOfSignal->getY()+personView->labelHeight/2);
        //pnt.setPen(QPen(Qt::black,3,Qt::SolidLine));
        pnt.drawLine(personView->getX()+personView->labelWidth/2, personView->getY()+personView->labelHeight/2,
                                viewOfSignal->getX()+personView->labelWidth/2, viewOfSignal->getY()+personView->labelHeight/2);

        QPainter p(this);
        p.drawPixmap(0, 0,m_Pixmap);

    }
}
