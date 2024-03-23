#include "add_parts.h"
#include "ui_add_parts.h"

add_parts::add_parts(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_parts)
{
    ui->setupUi(this);
    connect(ui->confirmbtn,SIGNAL(clicked()),this,SLOT(confirmBtnClicked()));
}

add_parts::~add_parts()
{
    delete ui;
}

void add_parts::confirmBtnClicked(){
    qDebug()<<"Confirm btn clicked!";
    QString name = ui->nameline->text();
    float amount = ui->amountline->text().toFloat();
    float unitPrice = ui->unitline->text().toFloat();
    emit parts_data(name, amount, unitPrice);
    this->hide();
}
