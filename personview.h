#ifndef PERSONVIEW_H
#define PERSONVIEW_H

#include <QObject>
#include <QLabel>
#include <QPushButton>

class MainWindow;
class Person;
class AddRelativeWindow;

namespace Ui {
class personView;
}

class PersonView:public QObject
{
    Q_OBJECT
private:
    float x;    //координаты центра "карточки" для отрисовки
    float y;

    QLabel *personCardLabel;
    QPushButton *addRelativeButton;
    QPushButton *infoButton;
    Person *person;
    MainWindow *mwFather;

public:
    static const int labelHeight = 120;
    static const int labelWidth = 171;
    static const int plusButtonHeight = 28;
    static const int plusButtonWidth = 31;
    static const int infoButtonHeight = 28;
    static const int infoButtonWidth = 75;

    static const int spaceToParentX = 40;
    static const int spaceToParentY = 60;

    PersonView(Person *person, MainWindow *mwfather);

    void addButton();


    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);
    void UpdateLabel();

    QLabel *getPersonCardLabel() const;
    void setPersonCardLabel(QLabel *value);

    QPushButton *getAddRelativeButton() const;
    void setAddRelativeButton(QPushButton *value);

    QPushButton *getInfoButton() const;
    void setInfoButton(QPushButton *value);

public slots:
    void on_addRelativeButton_clicked();
    void on_infoButton_clicked();
};

#endif // PERSONVIEW_H
