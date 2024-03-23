#include "staff_calender.h"
#include "ui_staff_calender.h"

staff_calender::staff_calender(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::staff_calender)
{
    ui->setupUi(this);

    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this, SLOT(onCalenderClicked(QDate)));

    connect(ui->savebtn,SIGNAL(clicked()),this,SLOT(saveBtnClicked()));
    //------------------------------------------------------------------------------------





    //------------------------------------------------------------------------------------
    //Define database Qsqlite
    calenderdb = QSqlDatabase::addDatabase("QSQLITE","sqlite2");
    calenderdb.setDatabaseName("calenderinfo.db");
    calenderdb.open();
    if(calenderdb.open()){
        //qDebug is similar with std::cout
        qDebug()<<"Connected to SQL Calender Server!";
    }else{
        //Output connect fail reason
        qDebug()<<"Failed to connect to SQL Sever: "<< calenderdb.lastError().text();//Need include QSqlError header here
    }
    QSqlQuery query(calenderdb);
    query.exec("create table calenderinfo(name, date, status)");//create only once
    //query.exec("insert into calenderinfo(name, date, status) values('Jiaxu', '2000-12-6', 'busy')");
    //query->exec("select database();");
    QSqlQuery queryForModel("select * from calenderinfo",calenderdb);
    qmodel = new QSqlQueryModel(this);//we use this model to fullfill the table
    qmodel->setQuery(std::move(queryForModel));

    ui->tableView->setModel(qmodel);//include QSqlQueryModel


}

staff_calender::~staff_calender()
{
    delete ui;
}

void staff_calender::get_name_from_query(QString name){

    ui->staffnamebtn->setText(name);
    //We can store name in a member varivale!!!
    this->currentName = name;

}

void staff_calender::onCalenderClicked(const QDate& date){
 //write the to be edited date code
 //  qDebug()<<date;
 //qDebug()<<"current name: "<<this->currentName;
 QString dateString = date.toString();
 //Goes to status selection widget
    setPage = new set_status();
    setPage->show();
    //now we entered, if we touch button we can set status
    //Just set the date as our first parameter into database
    QSqlQuery query(calenderdb);
    QString sqlInsert = "insert into calenderinfo(name, date) values('"+this->currentName+"','"+dateString+"')";
    query.exec(sqlInsert);
    QSqlQuery queryForDisplayModel("select * from calenderinfo",calenderdb);
    qmodel->setQuery(std::move(queryForDisplayModel));

    //Do button here
    connect(setPage,&set_status::clickFree,this,[=](){
        getFreeBtnClicked(dateString);
    });
    connect(setPage,&set_status::clickBusy,this,[=](){
        getBusyBtnClicked(dateString);
    });


}

void staff_calender::getBusyBtnClicked(QString date){
    //qDebug()<<"Clicked busy";
    QSqlQuery query(calenderdb);
    //QString sqlInsert = "insert into calenderinfo(status) values('busy')";
    QString sqlUpdate = "update calenderinfo set status = 'busy' where name = '"+this->currentName+"' and date = '"+date+"'";
    //query.exec(sqlInsert);
    query.exec(sqlUpdate);
    QSqlQuery queryForDisplayModel("select * from calenderinfo",calenderdb);
    qmodel->setQuery(std::move(queryForDisplayModel));
}

void staff_calender::getFreeBtnClicked(QString date){
    //qDebug()<<"Clicked free";
    QSqlQuery query(calenderdb);
    //QString sqlInsert = "insert into calenderinfo(status) values('free')";
    QString sqlUpdate = "update calenderinfo set status = 'free' where name = '"+this->currentName+"' and date = '"+date+"'";
    //query.exec(sqlInsert);
    query.exec(sqlUpdate);
    QSqlQuery queryForDisplayModel("select * from calenderinfo",calenderdb);
    qmodel->setQuery(std::move(queryForDisplayModel));
}

void staff_calender::exportToPdf(){
    QPdfWriter pdfWriter("staff calender.pdf");//set output path

    QPainter painter(&pdfWriter);//link painter with pdfWriter

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial",10));
    //painter.drawText(rect(),Qt::AlignCenter,"HAHA");
    QSqlQuery query(calenderdb);
    QString sql = "select * from calenderinfo";
    if (!query.exec(sql)) {
        qDebug() << "Error executing SQL query:" << query.lastError().text();
        return;
    }/*
    int row=0;
    while(query.next()){
        qDebug()<<"insidewhile";
        for(int col=0;col < query.record().count(); ++col){

            qDebug()<<"query value: "<<query.value(col).toString();
        }
        ++row;
    }*/
    int row = 0;
    int cellWidth = 1500;
    int cellHeight = 200;
    int startX = 50; // 起始 x 坐标
    int startY = 100; // 起始 y 坐标
    while(query.next()){
        //QSqlRecord类封装了数据库记录的功能和特征，通常代表数据库中表或视图中的一行
        for (int col = 0; col < query.record().count(); ++col) {
            QString data = query.value(col).toString();
            painter.drawText(startX + col * cellWidth, startY + row * cellHeight, data);
        }
        ++row;
    }
    painter.end();
     QMessageBox::about(this,"Notice","PDF file saved!");
}

void staff_calender::saveBtnClicked(){
    qDebug()<<"Save clicked!";
    this->exportToPdf();
}
