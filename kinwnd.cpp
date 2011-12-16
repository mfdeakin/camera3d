#include "kinwnd.h"
#include "ui_kinwnd.h"

kinwnd::kinwnd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kinwnd)
{
    ui->setupUi(this);

}

kinwnd::~kinwnd()
{
    delete ui;
}
