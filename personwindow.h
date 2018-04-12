#ifndef PERsonWINDOW_H
#define PERsonWINDOW_H

#include <QWidget>
#include "mainwindow.h"

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

    static const int spaceToParentX = 40;
    static const int spaceToParentY = 30;

private slots:
    void on_pushButton_clicked();
    void on_comboBoxLiveOrDie_currentIndexChanged(const QString &arg1);

private:
    MainWindow *parent;
    Person *person;
    Person *personOfSignal;
    QString whoRelativeAdd;

    Ui::personwindow *ui;
};

#endif // PERsonWINDOW_H
