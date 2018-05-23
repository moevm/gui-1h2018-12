#include "personview.h"

#include "person.h"
#include "mainwindow.h"
#include "addrelativewindow.h"
#include "personwindow.h"

QLabel *PersonView::getPersonCardLabel() const
{
    return personCardLabel;
}

void PersonView::setPersonCardLabel(QLabel *value)
{
    personCardLabel = value;
}

QPushButton *PersonView::getAddRelativeButton() const
{
    return addRelativeButton;
}

void PersonView::setAddRelativeButton(QPushButton *value)
{
    addRelativeButton = value;
}

QPushButton *PersonView::getInfoButton() const
{
    return infoButton;
}

void PersonView::setInfoButton(QPushButton *value)
{
    infoButton = value;
}

PersonView::PersonView(Person* person, MainWindow *mwFather)
{
    this->mwFather = mwFather;
    this->person = person;
}

void PersonView::UpdateLabel() {
    personCardLabel->setText(person->generatePersonString());
    personCardLabel->update();
}

void PersonView::addButton() {
    personCardLabel = new QLabel(mwFather/*->scroll*/);
    //mwFather->scroll->setWidget(personCardLabel);
    personCardLabel->setText(person->generatePersonString());
    personCardLabel->setStyleSheet("QLabel {"
                                              "border-style: solid;"
                                              "border-width: 1px;"
                                              "border-color: black; "
                                              "font-size: 12pt;"
                                              "background-color: white;"
                                              "}");
    personCardLabel->setGeometry(getX(), getY(), labelWidth, labelHeight);


    addRelativeButton = new QPushButton(mwFather/*->scroll*/);
    //mwFather->scroll->setWidget(addRelativeButton);
    addRelativeButton->setText("+");
    addRelativeButton->setGeometry(getX() + labelWidth - plusButtonWidth, getY() + labelHeight - plusButtonHeight, plusButtonWidth, plusButtonHeight);

    infoButton = new QPushButton(mwFather);
    infoButton->setText("Info");
    infoButton->setGeometry(getX() , getY() + labelHeight - infoButtonHeight, infoButtonWidth, infoButtonHeight);

    personCardLabel->setVisible(true);
    addRelativeButton->setVisible(true);
    infoButton->setVisible(true);

    //mwFather->getMwPersonOfSignal()->getPersonView()
    //mwFather->getMwPersonOfSignal()

    connect(addRelativeButton, SIGNAL(clicked()), this, SLOT(on_addRelativeButton_clicked()));
    connect(infoButton, SIGNAL(clicked()), this, SLOT(on_infoButton_clicked()));
}

void PersonView::on_infoButton_clicked() {
    personwindow *pw = new personwindow();
    pw->setFatherWindow(mwFather);
    pw->addInfo(person);
    pw->show();
}

void PersonView::on_addRelativeButton_clicked(){
    addrelativewindow *aw = new addrelativewindow();
    aw->setFatherWindow(mwFather);
    aw->setAwPersonOfSignal(person);
    aw->show();
}

float PersonView::getX() const
{
    return x;
}

void PersonView::setX(float value)
{
    x = value;
}

float PersonView::getY() const
{
    return y;
}

void PersonView::setY(float value)
{
    y = value;
}
