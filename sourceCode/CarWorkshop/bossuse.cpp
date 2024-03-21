#include "bossuse.h"
#include "ui_bossuse.h"
#include "QPushButton"
bossUse::bossUse(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::bossUse)
{
    ui->setupUi(this);
    this->setWindowTitle("Staff Infomation");

    //change widget from boss page to mainwindow page
    //this->addPage = new add_staff;//construct add staff page class



    //------------------------------------------------------------------------------------
    connect(ui->backbtn, &QPushButton::clicked,[=](){
    //send a signal to mainwindow
        emit this->backFromBossUse();
    });

    //change widget from boss window to add page
  //  connect(ui->addbtn,&QPushButton::clicked, [=](){
        //show add page
  //     this->addPage->show();
  //  });

     //receive string data from add page
    connect(ui->addbtn, SIGNAL(clicked()), this, SLOT(addbtn_clicked()),Qt::UniqueConnection);

    connect(ui->firebtn, SIGNAL(clicked()), this, SLOT(firebtn_clicked()),Qt::UniqueConnection);

    connect(ui->calenderbtn,SIGNAL(clicked()),this,SLOT(calenderbtn_clicked()),Qt::UniqueConnection);





    //------------------------------------------------------------------------------------
    //Define database Qsqlite
    staffdb = QSqlDatabase::addDatabase("QSQLITE","sqlite1");
    staffdb.setDatabaseName("staffinfo.db");
    //staffdb.open();//not necessary to open twice
    if(!staffdb.open()){
        //Output connect fail reason
        qDebug()<<"Failed to connect to SQL Sever: " << staffdb.lastError().text();//Need include QSqlError header here
    }else{
        qDebug()<<"Connected to SQL Sever";

        QSqlQuery query1(staffdb);
        //query = new QSqlQuery(QSqlDatabase::database("sqlite1"));
        query1.exec("create table staffinfo(id, name, status, price)");//create only once
        //query->exec("insert into staffinfo(id, name, status, price) values(1, 'Alex', 'busy', 200)");
        //query->exec("select database();");
        QSqlQuery queryForModel("select * from staffinfo", staffdb);
        qmodel = new QSqlQueryModel(this);//we use this model to fullfill the table
        //QSqlQuery 对象不应该被复制，因为它可能包含大量的数据
        qmodel->setQuery(std::move(queryForModel));
        ui->tableView->setModel(qmodel);//include QSqlQueryModel
        }
}

bossUse::~bossUse()
{
    QSqlQuery query1(staffdb);
    // 关闭所有的查询
    query1.finish();

    // 关闭数据库连接
    staffdb.close();

    // 移除数据库连接
    QSqlDatabase::removeDatabase("sqlite1");

    delete ui;
}

void bossUse::addbtn_clicked(){
    addPage = new add_staff();//create addpage window

    connect(addPage,SIGNAL(existEmptyInput()),this,SLOT(haveEmptyInput()),Qt::UniqueConnection);
    //remove behind linking if first connect is activated
    disconnect(addPage,SIGNAL(sendToBossData(QString)),this,SLOT(getFromAddStaffData(QString)));
    connect(addPage,SIGNAL(sendToBossData(QString)),this,SLOT(getFromAddStaffData(QString)),Qt::UniqueConnection);
    addPage->show();
}

void bossUse::getFromAddStaffData(QString data){
    QSqlQuery query1(staffdb);
    connect(addPage,SIGNAL(existEmptyInput()),this,SLOT(haveEmptyInput()));

    query1.exec(data);
    QMessageBox::about(this,"Noice","Add successful!");
     QSqlQuery queryForModel("select * from staffinfo", staffdb);
    qmodel->setQuery(std::move(queryForModel));//show again after add staff
}

void bossUse::haveEmptyInput(){
    QMessageBox::about(this,"Notice","Can't input empty parameter!");
}

void bossUse::firebtn_clicked()
{
    deletePage = new delete_staff();
    connect(deletePage,SIGNAL(deleteWrongInput()),this,SLOT(deleteInvalidStaff()));
    //remove behind linking if first connect is activated
    disconnect(deletePage, SIGNAL(sendDeleteData(QString)),this,SLOT(getFromDeleteStaffData(QString)));
    connect(deletePage, SIGNAL(sendDeleteData(QString)),this,SLOT(getFromDeleteStaffData(QString)),Qt::UniqueConnection);
    deletePage->show();
}

void bossUse::deleteInvalidStaff(){
    QMessageBox::about(this,"Notice","Delete failed!");
}

//void bossUse::getFromDeleteStaffData(QString data){
//    query->exec(data);
//   QMessageBox::about(this,"Noice","Fire successful!");
//   qmodel->setQuery("select * from staffinfo");//show again after add staff
//}

void bossUse::getFromDeleteStaffData(QString name){
    QSqlQuery query1(staffdb);
    QString sql_delete = "delete from staffinfo where name='"+name+"'";
    QString sql_select = "select name from staffinfo where name = '"+name+"'";
    query1.exec(sql_select);
    if(query1.next()){
        //Data exits, do operations
        query1.exec(sql_delete);

        QMessageBox::about(this,"Noice","Fire successful!");        
    }else{
        QMessageBox::about(this,"Notice","Fire failed!");
    }   
    QSqlQuery queryForModel("select * from staffinfo", staffdb);
    qmodel->setQuery(std::move(queryForModel));
}

void bossUse::calenderbtn_clicked()
{
    calender_query_page = new calender_query();
    calender_query_page->show();
    //main window should receive signal from calender query page name line
    connect(calender_query_page,SIGNAL(name_data(QString)),this, SLOT(getFromCalenderQueryData(QString)),Qt::UniqueConnection);

}

void bossUse::getFromCalenderQueryData(QString namedata){
    qDebug()<<namedata;
    QSqlQuery query1(staffdb);

    QString sql_select_name = "select name from staffinfo where name = '"+namedata+"'";
    query1.exec(sql_select_name);
    if(query1.next()){
        //Data exits, do operations
        qDebug()<<"Data exists!";
        //send a signal to calender_query to show have this name
        connect(this, SIGNAL(haveName(QString)),calender_query_page,SLOT(getName(QString)));
        emit haveName(namedata);

    }
    else{
        qDebug()<<"Not exist in this database!";
        //if warning exists, we should shut off the calender widget
        //but we can't go through 2 widgets so we need pass name into subwidget and compare
        //send a signal to show don't have this name
        //WE NEED CONNECT FIRST THEN EMIT THE SIGNAL

        connect(this, SIGNAL(dontHaveName()),calender_query_page,SLOT(dontGetName()),Qt::UniqueConnection);
        emit dontHaveName();
        QThread::msleep(500);
        QMessageBox::about(this,"Warning","Input staff name invalid!");
    }
}


