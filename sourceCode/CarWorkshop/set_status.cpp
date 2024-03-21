#include "set_status.h"
#include "ui_set_status.h"

set_status::set_status(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::set_status)
{
    ui->setupUi(this);

    connect(ui->busybtn,SIGNAL(clicked()),this,SLOT(busyBtnClicked()));
    connect(ui->freebtn,SIGNAL(clicked()),this,SLOT(freeBtnClicked()));
}

set_status::~set_status()
{
    delete ui;
}

void set_status::busyBtnClicked(){
    emit clickBusy();
    this->hide();
}

void set_status::freeBtnClicked(){
    emit clickFree();
    this->hide();
}


