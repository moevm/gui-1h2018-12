#ifndef PERsonWINDOW_H
#define PERsonWINDOW_H

#include <QWidget>
#include <QFileDialog>

class MainWindow;
class Person;


namespace Ui {
class personwindow;
}

class personwindow : public QWidget
{
    Q_OBJECT

public:
    explicit personwindow(QWidget *parent = 0);
    ~personwindow();

    void setFatherWindow(MainWindow *father);
    void setPersonOfSignal(Person *val1, QString val2);
    void addInfo(Person *person);

private:
    MainWindow *parent;
    Person *person;
    Person *personOfSignal;
    QString whoRelativeAdd;
    bool isChange;
    QString img;

    void addNewPerson();
    void changePerson();
    void fromFormToPerson();
    void init();

    Ui::personwindow *ui;

private slots:
    void on_pushButton_clicked();
    void on_comboBoxLiveOrDie_currentIndexChanged(const QString &arg1);
    void on_choosePhoto_clicked();
};

#endif // PERsonWINDOW_H
