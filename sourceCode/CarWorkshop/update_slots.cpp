#include "update_slots.h"
#include "ui_update_slots.h"

update_slots::update_slots(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::update_slots)
{
    ui->setupUi(this);
    connect(ui->confirmbtn,SIGNAL(clicked()),this,SLOT(confirmBtnClicked()));
}

update_slots::~update_slots()
{
    delete ui;
}


void update_slots::confirmBtnClicked(){
    emit confirmBtnClick();
    //just return the id is enough
    QString id = ui->enterline->text();
    if(id!="1"&&id!="2"&&id!="3"&&id!="4"&&id!="5"&&id!="6"&&id!="7"&&id!="8"){
        QMessageBox::about(this,"Warning","Input id is invalid!");
    }else{
        emit choose_id(id);
    }
    this->hide();
}
