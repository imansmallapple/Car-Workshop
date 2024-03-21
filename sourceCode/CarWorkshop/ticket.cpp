#include "ticket.h"
#include "ui_ticket.h"

ticket::ticket(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ticket)
{
    ui->setupUi(this);
    connect(ui->finishbtn,SIGNAL(clicked()),this,SLOT(finishBtnClicked()));
}

ticket::~ticket()
{
    delete ui;
}

void ticket::finishBtnClicked(){
    emit finishBtnClick();
    this->hide();
}

