#include "repairdlg.h"
#include "ui_repairdlg.h"

repairDlg::repairDlg(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::repairDlg)
{
    ui->setupUi(this);
    //change widget from boss page to mainwindow page
    connect(ui->cancelbtn, SIGNAL(clicked()),this,SLOT(cancelBtnClicked()));
    connect(ui->applybtn,SIGNAL(clicked()),this,SLOT(applyBtnClicked()));
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(calendarWidget_clicked(QDate)));
    connect(ui->editbtn,SIGNAL(clicked()),this, SLOT(editBtnClicked()));


    //------------------------------------------------------------------------------------
    //Define database Qsqlite
    workshopdb = QSqlDatabase::addDatabase("QSQLITE","sqlite3");
    workshopdb.setDatabaseName("workshopinfo.db");
    workshopdb.open();
    if(workshopdb.open()){
        //qDebug is similar with std::cout
        qDebug()<<"Connected to SQL Workshop Server!";
    }else{
        //Output connect fail reason
        qDebug()<<"Failed to connect to SQL Workshop Sever: "<< workshopdb.lastError().text();//Need include QSqlError header here
    }
    QSqlQuery query(workshopdb);
    query.exec("create table workshopinfo(id, date, availability, ticket number)");//create only once
    QSqlQuery queryForModel("select * from workshopinfo",workshopdb);
    qmodel = new QSqlQueryModel(this);//we use this model to fullfill the table
    qmodel->setQuery(std::move(queryForModel));

    ui->tableView->setModel(qmodel);//include QSqlQueryModel

}

repairDlg::~repairDlg()
{
    delete ui;
}

void repairDlg::cancelBtnClicked(){
    this->hide();
}

void repairDlg::applyBtnClicked(){
    this->choose_page=new choose_slots();
    this->choose_page->show();
    connect(this->choose_page,SIGNAL(input_slots(QString,QString,QString)),this,SLOT(checkSlotValid(QString,QString,QString)));


}


//Remember to create today's workshop data first, if it's empty then not working
void repairDlg::checkSlotValid(QString s1,QString s2,QString s3){
    qDebug()<<"Slot1: "<<s1<<"Slot2: "<<s2<<"Slot3: "<<s3;
    //so we just check today's slots case
    this->current_date=QDate::currentDate().toString();
    qDebug()<<"Today date: "<<this->current_date;
    QSqlQuery query(workshopdb);
    QString sql_select_date = "select date from workshopinfo where date='"+this->current_date+"'";
    query.exec(sql_select_date);
    //display today's table
    QSqlQuery queryForDisplayModel("select date, availability from workshopinfo where date ='"+this->current_date+"'",workshopdb);
    qmodel->setQuery(std::move(queryForDisplayModel));
    //If there are at least one available slot, we can enter exist
    // Create a list of all non-empty ids
    QStringList ids;
    if(!s1.isEmpty()) ids << s1;
    if(!s2.isEmpty()) ids << s2;
    if(!s3.isEmpty()) ids << s3;

    // Check if all non-empty ids are available
    if(!ids.isEmpty()){
        QString sql_check_availability = "select id from workshopinfo where id in ("+ids.join(",")+") and date ='"+this->current_date+"' and availability='available'";
        query.exec(sql_check_availability);
        if(query.next()){
            qDebug()<<"All non-empty IDs are available!";
            //if ids are good then we go to ticket window
            //Always first connect second emit signal
            connect(this,SIGNAL(id_valid()),this,SLOT(setTicket()));
            emit id_valid();

        }else{
            qDebug()<<"One or more non-empty IDs are not available!";
            QMessageBox::about(this,"Warning","One or more slots are occupied or invalid input!");
        }
    }else{
        qDebug()<<"No ID input!";
    }

}

void repairDlg::setTicket(){
    qDebug()<<"Into set ticket!";
    ticket_page = new ticket();
    this->ticket_page->show();
}


void repairDlg::getFinishBtnClicked(){
    this->show();
}

//We set availability "available" as our default parameter
void repairDlg::calendarWidget_clicked(const QDate &date)
{
    QString dateString = date.toString();
    //save current date
    this->current_date=dateString;
    qDebug()<<"current date: "<<this->current_date;

    //now we entered, if we touch button we can set status
    QSqlQuery query(workshopdb);

    //set stable 8 rows of data for each date
    //But all data must be saved into database

    QString sql_select_date = "select date from workshopinfo where date='"+dateString+"'";
    query.exec(sql_select_date);
    if(query.next()){
        qDebug()<<"Data exists!";
    }else{
        for(int i=1; i<=8; i++){
            //check if we have can find the date exits then skip
            QString sqlInsert = "insert into workshopinfo(id, date, availability) values("+QString::number(i)+", '"+dateString+"','available')";
            query.exec(sqlInsert);
        }
    }

        //display table
    //select name from staffinfo where name = '"+name+"'
    //update table
    QSqlQuery queryForDisplayModel("select date, availability from workshopinfo where date ='"+dateString+"'",workshopdb);
    qmodel->setQuery(std::move(queryForDisplayModel));

}

void repairDlg::editBtnClicked(){
    this->update_page = new update_slots();
    this->update_page->show();
    connect(this->update_page,SIGNAL(choose_id(QString)),this,SLOT(getChosenSlotId(QString)));
}

//When slot is in Busy state, only after staff finish repairment can change the busy state back to available
void repairDlg::getChosenSlotId(QString id){
    this->current_id=id;
    qDebug()<<"current_id: "<<this->current_id<<" current date: "<<this->current_date;
    QSqlQuery query(workshopdb);
    QString sqlUpdate = "update workshopinfo set availability = 'busy' where id="+this->current_id+" and date='"+this->current_date+"'";
    query.exec(sqlUpdate);
    //update database table
    QSqlQuery queryUpdate("select date, availability from workshopinfo where date ='"+this->current_date+"'",workshopdb);
    qmodel->setQuery(std::move(queryUpdate));
}

