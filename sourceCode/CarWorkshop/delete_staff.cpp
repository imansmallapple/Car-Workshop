#include "delete_staff.h"
#include "ui_delete_staff.h"

delete_staff::delete_staff(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::delete_staff)
{
    ui->setupUi(this);
    this->setWindowTitle("Fire Window");
    //Was a problem: over connect to same slot. solution: use uniqueConnection parameter
    connect(ui->finishbtn,SIGNAL(clicked(bool)),this,SLOT(finishbtn_clicked()),Qt::UniqueConnection);
}

delete_staff::~delete_staff()
{
    delete ui;
}

void delete_staff::finishbtn_clicked()
{
    //First check if this name is exists or not

    QString name = ui->nameline->text();
    //QString sql = "delete from staffinfo where name='"+name+"'";

    emit sendDeleteData(name);
    this->hide();
}


void delete_staff::on_cancelbtn_clicked()
{
    this->hide();
}

