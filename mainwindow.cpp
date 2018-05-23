#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "personwindow.h"
#include "personview.h"
#include "person.h"
#include "persons.h"
#include <QList>
#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Family Tree");

    isSave = false;

    //m_Pixmap = QPixmap(width(), height());
    //m_Pixmap.fill(Qt::transparent);
    m_Pixmap = QPixmap(":\dd2.png");

    /*scroll = new QScrollArea(this);
    QRect pos = ui->centralWidget->geometry();
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setWidget(ui->centralWidget);
    scroll->setGeometry(0,0,2000,2000);*/

    //scroll->setWidget(personButton);
    allPersons = new Persons(this);

   //centralWidget()->setStyleSheet("background: green;");

    /*centralWidget()->setStyleSheet(
                " background-image: url(\":/Tree.png\");"
                " background-position: center;"
                "}");

    QPalette pal;
    pal.setBrush(centralWidget()->backgroundRole(), QBrush(QPixmap("/Tree.png")));
    centralWidget()->setPalette(pal);*/

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":\dd2.png")));
    setPalette(palette);

    //personButton = new QPushButton(this);
    //personButton->setGeometry(width() - 30/2, height() - 100/2, 100, 30);
    //personButton->setText("add first person");
    //personButton->show();
    //personButton->setVisible(true);
    connect(personButton, SIGNAL(clicked()), this, SLOT(on_personButton_clicked()));
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
    allPersons->addNewPerson(person);
    PersonView *personView = new PersonView(person, this);
    this->person = person;
    if(person->getId() == 0){

        //ui->personButton->close();

        personView->setX(this->width()/2 - personView->labelWidth/2);
        personView->setY(this->height()/2 - personView->labelHeight/2);
    }else{
        isVert = true;
        whoAddRelative = whoRelativeAdd;
        this->personOfSignal = personOfSignal;
        PersonView *viewOfSignal = personOfSignal->getPersonView();
        if (whoRelativeAdd == "father") {
            if(personOfSignal->getMother() == NULL){
                personView->setX(viewOfSignal->getX() + (person->getNumOfChild()*viewOfSignal->labelWidth
                                + (person->getNumOfChild() - 1)*viewOfSignal->spaceToParentX)/2 - personView->spaceToParentX
                                - personView->labelWidth);
                personView->setY(viewOfSignal->getY() - personView->labelHeight - personView->spaceToParentY);
            }else{
                personView->setX(personOfSignal->getMother()->getPersonView()->getX() - personView->labelWidth - 2*personView->spaceToParentX);
                personView->setY(personOfSignal->getMother()->getPersonView()->getY());
            }
        }
        if (whoRelativeAdd == "mother") {
            if(personOfSignal->getFather() == NULL){
                personView->setX(viewOfSignal->getX() + (person->getNumOfChild()*viewOfSignal->labelWidth
                                + (person->getNumOfChild() - 1)*viewOfSignal->spaceToParentX)/2 + personView->spaceToParentX);
                personView->setY(viewOfSignal->getY() - personView->labelHeight - personView->spaceToParentY);
            }else{
                personView->setX(personOfSignal->getFather()->getPersonView()->getX() + personView->labelWidth
                                 + 2*personView->spaceToParentX);
                personView->setY(personOfSignal->getFather()->getPersonView()->getY());
            }
        }
        if (whoRelativeAdd == "partner") {
            if(person->getSex() == "Мужской"){
                personView->setX(viewOfSignal->getX() - personView->labelWidth - 2*personView->spaceToParentX);
            }else{
                personView->setX(viewOfSignal->getX() + personView->labelWidth + 2*personView->spaceToParentX);
            }
            personView->setY(viewOfSignal->getY());
        }
        if (whoRelativeAdd == "child") {
            if(personOfSignal->getCurrentNumOfChild() == 1 && personOfSignal->getSex() == "Мужской"){
                personView->setX(viewOfSignal->getX()+viewOfSignal->labelWidth - viewOfSignal->spaceToParentX);
            }
            else if(personOfSignal->getCurrentNumOfChild() == 1 && personOfSignal->getSex() == "Женский"){
                personView->setX(viewOfSignal->getX()-viewOfSignal->labelWidth + viewOfSignal->spaceToParentX);
            }
            else{
                personView->setX(viewOfSignal->getX()+viewOfSignal->labelWidth + viewOfSignal->spaceToParentX -
                                 (personOfSignal->getNumOfChild()*(viewOfSignal->labelWidth +
                                 (personOfSignal->getNumOfChild()-1)*viewOfSignal->spaceToParentX))/2 +
                                 personOfSignal->getCurrentNumOfChild()*(personView->labelWidth + personView->spaceToParentX));
            }


            //personView->setX(viewOfSignal->getX() - (personOfSignal->getNumOfChild()*(personView->labelWidth + personView->spaceToParentX) - personView->spaceToParentX)/2 + personView->labelWidth/2 + personOfSignal->getCurrentNumOfChild()*(personView->labelWidth + personView->spaceToParentX));
            personView->setY(viewOfSignal->getY() + personView->labelHeight + personView->spaceToParentY);
        }
    }

    personView->addButton();
    person->setPersonView(personView);
}

MainWindow::on_personButton_clicked(){  //когда нажимаем, чтобы добавить персону
    personwindow *pw = new personwindow();
    pw->setFatherWindow(this);
    float t1, t2;
    t1 = width();   //1924
    t2 = height();  //1055
    pw->show();
}

void MainWindow::paintEvent(QPaintEvent *){
    if(isSave){
        //m_Pixmap.load(":\test.png");
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(QPixmap(":\test.png")));
        setPalette(palette);
        isSave = false;
    }
    if(isVert){
        PersonView *viewOfSignal = personOfSignal->getPersonView();
        PersonView *personView = person->getPersonView();

        QPainter pnt(&m_Pixmap);
        pnt.setPen(QPen(Qt::white,6,Qt::SolidLine));

        /*allPersons->addLine(personView->getX()+personView->labelWidth/2, personView->getY()+personView->labelHeight/2,
                            viewOfSignal->getX()+personView->labelWidth/2, viewOfSignal->getY()+personView->labelHeight/2);*/


        if(whoAddRelative == "father" && person->getSex() == "Мужской" && personOfSignal->getMother() != NULL
                || whoAddRelative == "partner" && person->getSex() == "Мужской"){
            QLine line(personView->getX()+personView->labelWidth, personView->getY()+personView->labelHeight/2,
                        personView->getX()+personView->labelWidth + 2*personView->spaceToParentX, personView->getY()+personView->labelHeight/2);
            pnt.drawLine(line);
        }

        if(whoAddRelative == "mother" && person->getSex() == "Женский" && personOfSignal->getFather() != NULL
                || whoAddRelative == "partner" && person->getSex() == "Женский"){
            QLine line(personView->getX(), personView->getY()+personView->labelHeight/2,
                        personView->getX() - 2*personView->spaceToParentX, personView->getY()+personView->labelHeight/2);
            pnt.drawLine(line);
        }

        if(whoAddRelative == "child"){
            if(personOfSignal->getSex() == "Женский"){
                QLine line(viewOfSignal->getX(), viewOfSignal->getY()+personView->labelHeight/2,
                           viewOfSignal->getX() - viewOfSignal->spaceToParentX, viewOfSignal->getY() + personView->labelHeight/2);
                QLine line2(viewOfSignal->getX() - viewOfSignal->spaceToParentX, viewOfSignal->getY() + personView->labelHeight/2,
                            viewOfSignal->getX() - viewOfSignal->spaceToParentX, viewOfSignal->getY() + personView->labelHeight);
                QLine line3(viewOfSignal->getX() - viewOfSignal->spaceToParentX, viewOfSignal->getY() + personView->labelHeight,
                            personView->getX() + personView->labelWidth/2, personView->getY() + personView->labelHeight/2);
                pnt.drawLine(line);
                pnt.drawLine(line2);
                pnt.drawLine(line3);
            }else{
                QLine line(viewOfSignal->getX() + viewOfSignal->labelWidth, viewOfSignal->getY()+personView->labelHeight/2,
                           viewOfSignal->getX() + viewOfSignal->labelWidth + viewOfSignal->spaceToParentX, viewOfSignal->getY()
                           + personView->labelHeight/2);
                QLine line2(viewOfSignal->getX() + viewOfSignal->labelWidth + viewOfSignal->spaceToParentX, viewOfSignal->getY()
                            + personView->labelHeight/2, viewOfSignal->getX() + viewOfSignal->labelWidth + viewOfSignal->spaceToParentX,
                            viewOfSignal->getY() + personView->labelHeight);
                QLine line3(viewOfSignal->getX() + viewOfSignal->labelWidth + viewOfSignal->spaceToParentX, viewOfSignal->getY()
                            + personView->labelHeight, personView->getX() + personView->labelWidth/2, personView->getY()
                            + personView->labelHeight/2);
                pnt.drawLine(line);
                pnt.drawLine(line2);
                pnt.drawLine(line3);
            }
        }

        if(whoAddRelative == "mother" && personOfSignal->getFather() == NULL
                || whoAddRelative == "father" && personOfSignal->getMother() == NULL){
            if(whoAddRelative == "mother"){
                QLine line3(viewOfSignal->getX() + (person->getNumOfChild()*viewOfSignal->labelWidth
                            + (person->getNumOfChild() - 1)*viewOfSignal->spaceToParentX)/2, viewOfSignal->getY()
                            - personView->spaceToParentY - personView->labelHeight/2,
                            viewOfSignal->getX() + (person->getNumOfChild()*viewOfSignal->labelWidth
                            + (person->getNumOfChild() - 1)*viewOfSignal->spaceToParentX)/2 + personView->spaceToParentX, viewOfSignal->getY()
                            - personView->spaceToParentY - personView->labelHeight/2);
                pnt.drawLine(line3);
            }else{
                QLine line3(viewOfSignal->getX() + (person->getNumOfChild()*viewOfSignal->labelWidth
                            + (person->getNumOfChild() - 1)*viewOfSignal->spaceToParentX)/2, viewOfSignal->getY()
                            - personView->spaceToParentY - personView->labelHeight/2,
                            viewOfSignal->getX() + (person->getNumOfChild()*viewOfSignal->labelWidth
                            + (person->getNumOfChild() - 1)*viewOfSignal->spaceToParentX)/2 - personView->spaceToParentX, viewOfSignal->getY()
                            - personView->spaceToParentY - personView->labelHeight/2);
                pnt.drawLine(line3);
            }
            QLine line(viewOfSignal->getX() + personView->labelWidth/2, viewOfSignal->getY()+personView->labelHeight/2,
                       viewOfSignal->getX() + (person->getNumOfChild()*viewOfSignal->labelWidth
                       + (person->getNumOfChild() - 1)*viewOfSignal->spaceToParentX)/2, viewOfSignal->getY() - personView->spaceToParentY);
            QLine line2(viewOfSignal->getX() + (person->getNumOfChild()*viewOfSignal->labelWidth
                        + (person->getNumOfChild() - 1)*viewOfSignal->spaceToParentX)/2, viewOfSignal->getY() - personView->spaceToParentY,
                        viewOfSignal->getX() + (person->getNumOfChild()*viewOfSignal->labelWidth
                        + (person->getNumOfChild() - 1)*viewOfSignal->spaceToParentX)/2, viewOfSignal->getY() - personView->spaceToParentY
                        - personView->labelHeight/2);

            pnt.drawLine(line);
            pnt.drawLine(line2);
        }

        QPainter p(this);
        p.drawPixmap(0, 0, m_Pixmap);
    }
}

/*void MainWindow::drowLines(QList<QPair<QPair<int, int>, QPair<int, int>>> list) {
    QPainter pnt(&m_Pixmap);

    QListIterator<QPair<QPair<int, int>, QPair<int, int>>> i(list);
    QPair<QPair<int, int>, QPair<int, int>> tmp;
    while (i.hasNext()) {
        tmp = i.next();
        pnt.drawLine(tmp.first.first, tmp.first.second, tmp.second.first, tmp.second.second);
    }
    QPainter p(this);
    p.drawPixmap(0, 0,m_Pixmap);


}*/

MainWindow::on_saveButton_clicked(){
    allPersons->saveAll();
}

MainWindow::on_openButton_clicked(){
    //ui->personButton->close();
    allPersons->readAll();

    update();
}

void MainWindow::on_clearButton_clicked()
{
   allPersons->clear();

   allPersons = new Persons(this);

   //ui->personButton->setVisible(true);

   QPalette palette;
   palette.setBrush(QPalette::Window, QBrush(QPixmap(":\dd2.png")));
   setPalette(palette);

   //connect(personButton, SIGNAL(clicked()), this, SLOT(on_personButton_clicked()));

}
