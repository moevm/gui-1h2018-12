#ifndef ADDRELATIVEWINDOW_H
#define ADDRELATIVEWINDOW_H

#include <QWidget>

namespace Ui {
class addrelativewindow;
}

class addrelativewindow : public QWidget
{
    Q_OBJECT

public:
    explicit addrelativewindow(QWidget *parent = 0);
    ~addrelativewindow();

private:
    Ui::addrelativewindow *ui;
};

#endif // ADDRELATIVEWINDOW_H
