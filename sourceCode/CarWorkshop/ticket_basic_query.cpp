#include "ticket_basic_query.h"
#include "ui_ticket_basic_query.h"

ticket_basic_query::ticket_basic_query(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ticket_basic_query)
{
    ui->setupUi(this);
    connect(ui->confirmbtn,SIGNAL(clicked()),this,SLOT(confirmBtnClicked()));
}

ticket_basic_query::~ticket_basic_query()
{
    delete ui;
}


void ticket_basic_query::set_query(){
    this->show();
}

void ticket_basic_query::confirmBtnClicked(){
    QString brand = ui->brandline->text();
    QString model = ui->modelline->text();
    QString regid = ui->idline->text();
    QString staff = ui->staffline->text();
    QString timeSlot = ui->timeline->text();
    QString issue = ui->problemtxt->toPlainText();
    QString state="created";
    emit staff_name(staff);
    emit query_data(brand,model,regid,staff,timeSlot,issue,state);
    clear_query();
    this->hide();
}

void ticket_basic_query::clear_query(){
    ui->brandline->clear();
    ui->modelline->clear();
    ui->idline->clear();
    ui->staffline->clear();
    ui->timeline->clear();
    ui->problemtxt->clear();
}
