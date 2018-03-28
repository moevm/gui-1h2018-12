#include "addrelativewindow.h"
#include "ui_addrelativewindow.h"

addrelativewindow::addrelativewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addrelativewindow)
{
    ui->setupUi(this);

}

addrelativewindow::~addrelativewindow()
{
    delete ui;
}
