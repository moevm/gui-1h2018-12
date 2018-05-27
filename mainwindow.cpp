#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "personwindow.h"
#include "personview.h"
#include "person.h"
#include "persons.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Family Tree");

    m_Pixmap = QPixmap(":/dd1.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/dd1.png")));
    setPalette(palette);

    /*scroll = new QScrollArea(this);
    QRect pos = ui->centralWidget->geometry();
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scroll->setWidget(ui->centralWidget);
    scroll->setGeometry(0,0,2000,2000);*/

    //scroll->setWidget(personButton);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    isSave = false;

    allPersons = new Persons(this);

    personButton = new QPushButton(this);
    personButton->setGeometry((windowWidth - buttonWidth) / 2, (windowHeight - buttonHeight) / 2, buttonWidth + 55, buttonHeight + 10);
    personButton->setText("Добавить \r\n"
                          "первого человека");
    personButton->setStyleSheet("font: 75 10pt \"MS Shell Dlg 2\";"
                                "font: bold;");
    personButton->show();
    connect(personButton, SIGNAL(clicked()), this, SLOT(on_personButton_clicked()));

    QPushButton *openButton = new QPushButton(this);
    openButton->setGeometry(20, 15, buttonWidth, buttonHeight);
    openButton->setText("Открыть \r\n"
                          "файл");
    openButton->setStyleSheet("font: 75 10pt \"MS Shell Dlg 2\";"
                                );
    openButton->show();
    connect(openButton, SIGNAL(clicked()), this, SLOT(on_openButton_clicked()));

    QPushButton *saveButton = new QPushButton(this);
    saveButton->setGeometry(140, 15, buttonWidth, buttonHeight);
    saveButton->setText("Сохранить \r\n"
                          "дерево");
    saveButton->setStyleSheet("font: 75 10pt \"MS Shell Dlg 2\";"
                                );
    saveButton->show();
    connect(saveButton, SIGNAL(clicked()), this, SLOT(on_saveButton_clicked()));

    QPushButton *clearButton = new QPushButton(this);
    clearButton->setGeometry(260, 15, buttonWidth, buttonHeight);
    clearButton->setText("Удалить \r\n"
                          "дерево");
    clearButton->setStyleSheet("font: 75 10pt \"MS Shell Dlg 2\";"
                               );
    /*"background: rgba(255, 255, 255, 0.0);"
                               "border-radius: 8px;"
                               "color: green;"
                               ""
                               */
    clearButton->show();
    connect(clearButton, SIGNAL(clicked()), this, SLOT(on_clearButton_clicked()));

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

        personButton->close();

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
            float lenOfChilds_div_2 = (personOfSignal->getNumOfChild()*(viewOfSignal->labelWidth +
                                      (personOfSignal->getNumOfChild() - 1)*2*viewOfSignal->spaceToParentX))/2;
            if(personOfSignal->getCurrentNumOfChild() == 1 && personOfSignal->getSex() == "Мужской"){
                personView->setX(viewOfSignal->getX()+viewOfSignal->labelWidth + viewOfSignal->spaceToParentX - lenOfChilds_div_2);
            }
            else if(personOfSignal->getCurrentNumOfChild() == 1 && personOfSignal->getSex() == "Женский"){
                personView->setX(viewOfSignal->getX() - viewOfSignal->spaceToParentX - lenOfChilds_div_2);
            }
            else{
                personView->setX(personOfSignal->getChild()[0]->getPersonView()->getX() + (personOfSignal->getCurrentNumOfChild() - 1) * (2 * personView->spaceToParentX + personView->labelWidth));
                            /*viewOfSignal->getX()+viewOfSignal->labelWidth + viewOfSignal->spaceToParentX -
                                 (personOfSignal->getNumOfChild()*(viewOfSignal->labelWidth +
                                 (personOfSignal->getNumOfChild()-1)*viewOfSignal->spaceToParentX))/2 +
                                 personOfSignal->getCurrentNumOfChild()*(personView->labelWidth + personView->spaceToParentX)*/
            }


            //personView->setX(viewOfSignal->getX() - (personOfSignal->getNumOfChild()*(personView->labelWidth + personView->spaceToParentX) - personView->spaceToParentX)/2 + personView->labelWidth/2 + personOfSignal->getCurrentNumOfChild()*(personView->labelWidth + personView->spaceToParentX));
            personView->setY(viewOfSignal->getY() + personView->labelHeight + personView->spaceToParentY);
        }
    }

    personView->addButton();
    person->setPersonView(personView);
}

void MainWindow::paintEvent(QPaintEvent *){
    if(isSave){
        m_Pixmap = QPixmap(fileName);
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(QPixmap(fileName)));
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


        if( (whoAddRelative == "father" && person->getSex() == "Мужской" && personOfSignal->getMother() != NULL)
                || (whoAddRelative == "partner" && person->getSex() == "Мужской") ){
            QLine line(personView->getX()+personView->labelWidth, personView->getY()+personView->labelHeight/2,
                        personView->getX()+personView->labelWidth + 2*personView->spaceToParentX, personView->getY()+personView->labelHeight/2);
            pnt.drawLine(line);
        }

        if( (whoAddRelative == "mother" && person->getSex() == "Женский" && personOfSignal->getFather() != NULL)
                || (whoAddRelative == "partner" && person->getSex() == "Женский") ){
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

        if( (whoAddRelative == "mother" && personOfSignal->getFather() == NULL)
                || (whoAddRelative == "father" && personOfSignal->getMother() == NULL) ){
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

void MainWindow::on_personButton_clicked(){  //когда нажимаем, чтобы добавить персону
    personwindow *pw = new personwindow();
    pw->setFatherWindow(this);
    /*float t1, t2;
    t1 = width();   //1924
    t2 = height();  //1055
    */
    pw->show();
}

void MainWindow::on_saveButton_clicked(){
    allPersons->saveAll();
}

void MainWindow::on_openButton_clicked(){
    allPersons->readAll();
}

void MainWindow::on_clearButton_clicked()
{
   QPalette palette;
   palette.setBrush(QPalette::Window, QBrush(QPixmap(":/dd2.png")));
   setPalette(palette);
   update();
   allPersons->clear();
   init();
}
