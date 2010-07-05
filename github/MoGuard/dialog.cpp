#include "dialog.h"
#include "ui_dialog.h"
#include <Qt>
#include <context.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_Maemo5StackedWindow);
}

Dialog::~Dialog()
{
    delete ui;

}

void Dialog::on_pushButton_3_clicked()
{
    this->hide();
    Context::GetContext()->qo1->show();
}
