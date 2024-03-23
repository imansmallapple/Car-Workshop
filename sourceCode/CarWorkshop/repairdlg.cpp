#include "repairdlg.h"
#include "ui_repairdlg.h"

repairDlg::repairDlg(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::repairDlg)
{
    ui->setupUi(this);
    //change widget from boss page to mainwindow page

    connect(ui->applybtn,SIGNAL(clicked()),this,SLOT(applyBtnClicked()));
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(calendarWidget_clicked(QDate)));
    //connect(ui->editbtn,SIGNAL(clicked()),this, SLOT(editBtnClicked()));


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
    query.exec("create table workshopinfo(id, date, availability, ticket)");//create only once
    QSqlQuery queryForModel("select * from workshopinfo",workshopdb);
    qmodel = new QSqlQueryModel(this);//we use this model to fullfill the table
    qmodel->setQuery(std::move(queryForModel));

    ui->tableView->setModel(qmodel);//include QSqlQueryModel

}

repairDlg::~repairDlg()
{
    query->finish();
    delete query;
    QSqlDatabase::removeDatabase("sqlite3");
    delete ui;
}

void repairDlg::applyBtnClicked(){
    this->choose_page=new choose_slots();
    this->choose_page->show();
    connect(this->choose_page,SIGNAL(input_slots(QString,QString,QString)),this,SLOT(checkSlotValid(QString,QString,QString)));
}

void repairDlg::update_ticket_state(QStringList ids){
    QSqlQuery query(workshopdb);
    QStringListIterator iterator(ids);
    QSqlQuery queryUpdate("select date, availability, ticket from workshopinfo where date ='"+this->current_date+"'",workshopdb);

    this->current_ids=ids;
    while(iterator.hasNext()){
        QString sqlUpdate = "update workshopinfo set ticket = 'created' where id="+iterator.next()+" and date='"+this->current_date+"'";
        query.exec(sqlUpdate);
    }
    qmodel->setQuery(std::move(queryUpdate));
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
            if (!ticket_page) {  // 只有当ticket_page还没有被创建时，才创建和显示它
                ticket_query = new ticket_basic_query();
                ticket_page = new ticket(ticket_query);//将ticket_query对象传递给ticket
                connect(this,SIGNAL(id_valid(QStringList)),this->ticket_page,SLOT(setTicket(QStringList)),Qt::UniqueConnection);
                connect(this,SIGNAL(query_ok()),this->ticket_query,SLOT(set_query()),Qt::UniqueConnection);
                connect(this,SIGNAL(id_valid(QStringList)),this,SLOT(update_ticket_state(QStringList)));
                connect(this->ticket_page,SIGNAL(ticket_in_process()),this,SLOT(change_ticket_in_process()));
                connect(this->ticket_query,SIGNAL(staff_name(QString)),this,SLOT(send_staff_name(QString)));
            }
            emit id_valid(ids);
            emit query_ok();


        }else{
            qDebug()<<"One or more non-empty IDs are not available!";
            QMessageBox::about(this,"Warning","One or more slots are occupied or invalid input!");
        }
    }else{
        qDebug()<<"No ID input!";
    }

}

void repairDlg::send_staff_name(QString staffname){
    //qDebug()<<"Inside send name!"<<staffname;
    emit staff_name(staffname);
}

void repairDlg::change_ticket_in_process(){
    //qDebug()<<"In process!";
    QSqlQuery query(workshopdb);
    QStringListIterator iterator(this->current_ids);
    while(iterator.hasNext()){
        QString sqlUpdate = "update workshopinfo set ticket = 'in process', availability = 'busy' where id="+iterator.next()+" and date='"+this->current_date+"'";
        query.exec(sqlUpdate);
    }
    QSqlQuery queryUpdate("select date, availability, ticket from workshopinfo where date ='"+this->current_date+"'",workshopdb);
    qmodel->setQuery(std::move(queryUpdate));
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
            QString sqlInsert = "insert into workshopinfo(id, date, availability, ticket) values("+QString::number(i)+", '"+dateString+"','available','closed')";
            query.exec(sqlInsert);
        }
    }

        //display table
    //select name from staffinfo where name = '"+name+"'
    //update table
    QSqlQuery queryForDisplayModel("select date, availability, ticket from workshopinfo where date ='"+dateString+"'",workshopdb);
    qmodel->setQuery(std::move(queryForDisplayModel));

}

//When slot is in Busy state, only after staff finish repairment can change the busy state back to available
void repairDlg::getChosenSlotId(QString id){
    this->current_id=id;
    qDebug()<<"current_id: "<<this->current_id<<" current date: "<<this->current_date;
    QSqlQuery query(workshopdb);
    QString sqlUpdate = "update workshopinfo set availability = 'busy' where id="+this->current_id+" and date='"+this->current_date+"'";
    query.exec(sqlUpdate);
    //update database table
    QSqlQuery queryUpdate("select date, availability, ticket from workshopinfo where date ='"+this->current_date+"'",workshopdb);
    qmodel->setQuery(std::move(queryUpdate));
}

