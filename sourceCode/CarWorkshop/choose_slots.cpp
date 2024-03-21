#include "choose_slots.h"
#include "qmessagebox.h"
#include "ui_choose_slots.h"

choose_slots::choose_slots(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::choose_slots)
{
    ui->setupUi(this);
    connect(ui->confirmbtn,SIGNAL(clicked()),this,SLOT(confirmBtnClicked()));
}

choose_slots::~choose_slots()
{
    delete ui;
}

void choose_slots::confirmBtnClicked(){
    QString s1 = ui->slot1line->text();
    QString s2 = ui->slot2line->text();
    QString s3 = ui->slot3line->text();
    if(s1.isEmpty()&&s2.isEmpty()&&s3.isEmpty()){
        QMessageBox::about(this,"Error","Can't input nothing!");
    }else{
        if(id_limit(s1)&&id_limit(s2)&&id_limit(s3)){
            emit input_slots(s1,s2,s3);
        }else{
            QMessageBox::about(this,"Error","Please input slot id from 1-8!");
        }
    }
    this->hide();
}

bool choose_slots::id_limit(QString s){
    if(s!="1"&&s!="2"&&s!="3"&&s!="4"&&s!="5"&&s!="6"&&s!="7"&&s!="8"&&s!=""){
        qDebug()<<"Please enter 1-8 number!";
        return false;
    }
    return true;
}
