#ifndef ADDRELATIVEWINDOW_H
#define ADDRELATIVEWINDOW_H

#include <QWidget>

class personwindow;
class MainWindow;
class Person;

namespace Ui {
class addrelativewindow;
}

class addrelativewindow : public QWidget
{
    Q_OBJECT

public:
    explicit addrelativewindow(QWidget *parent = 0);
    ~addrelativewindow();

    void setFatherWindow(MainWindow *father);
    void setAwPersonOfSignal(Person *value);
    Person *getAwPersonOfSignal() const;

private:
    Ui::addrelativewindow *ui;
    MainWindow *parent;
    Person *awPersonOfSignal;

private slots:
    void on_pushButtonAddPa_clicked();
    void on_pushButtonAddMa_clicked();
    void on_pushButtonAddPartner_clicked();
    void on_pushButtonAddChild_clicked();
};

#endif // ADDRELATIVEWINDOW_H
