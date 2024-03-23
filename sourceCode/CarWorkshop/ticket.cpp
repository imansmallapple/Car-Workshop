#include "ticket.h"
#include "ui_ticket.h"

ticket::ticket(ticket_basic_query *ticket_query, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ticket),
    ticket_query(ticket_query)// 初始化ticket_query成员变量
{
    ui->setupUi(this);
    connect(ui->finishbtn,SIGNAL(clicked()),this,SLOT(finishBtnClicked()));
    connect(ui->changebtn,SIGNAL(clicked()),this,SLOT(changeBtnClicked()));
    connect(ui->addbtn,SIGNAL(clicked()),this,SLOT(addBtnClicked()),Qt::UniqueConnection);
    connect(ui->editbtn,SIGNAL(clicked()),this,SLOT(editBtnClicked()),Qt::UniqueConnection);
    connect(ui->pdfbtn,SIGNAL(clicked()),this,SLOT(pdfBtnClicked()),Qt::UniqueConnection);
    connect(ui->finalcostbtn,SIGNAL(clicked()),this,SLOT(finalCostBtnClicked()),Qt::UniqueConnection);

    qmodel = new QSqlQueryModel(this);



    //------------------------------------------------------------------------------------
    //Define database Qsqlite
    ticketdb = QSqlDatabase::addDatabase("QSQLITE","sqlite4");
    ticketdb.setDatabaseName("ticketinfo.db");
    if(ticketdb.open()){
        qDebug()<<"Connected to SQL Ticket Server!";
    }else{
        //Output connect fail reason
        qDebug()<<"Failed to connect to SQL Sever: "<< ticketdb.lastError().text();//Need include QSqlError header here
    }
    QSqlQuery query(ticketdb);
    query.exec("create table ticketinfo(id INTEGER, brand TEXT, model TEXT, registrationId TEXT, problem TEXT, staff TEXT, timeSlots TEXT,ticketState TEXT)");

    //------------------------------------------------------------------------------------
    //Define database Qsqlite
    partdb = QSqlDatabase::addDatabase("QSQLITE","sqlite5");
    partdb.setDatabaseName(" partinfo.db");
    if( partdb.open()){
        qDebug()<<"Connected to SQL Part Server!";
    }else{
        //Output connect fail reason
        qDebug()<<"Failed to connect to SQL Sever: "<<partdb.lastError().text();//Need include QSqlError header here
    }
    QSqlQuery query_part_db(partdb);
    query_part_db.exec("create table partinfo(id INTEGER, name TEXT, amount FLOAT, unit_price FLOAT, total_price FLOAT)");

    //------------------------------------------------------------------------------------
    //Define database Qsqlite
    estimatedb = QSqlDatabase::addDatabase("QSQLITE","sqlite6");
    estimatedb.setDatabaseName("estimateinfo.db");
    if(estimatedb.open()){
        qDebug()<<"Connected to SQL Estimate Server!";
    }else{
        //Output connect fail reason
        qDebug()<<"Failed to connect to SQL Sever: "<<estimatedb.lastError().text();//Need include QSqlError header here
    }
    QSqlQuery query_estimate_db(estimatedb);
    query_estimate_db.exec("create table estimateinfo(id INTEGER, description TEXT, service_cost FLOAT, client_attitude TEXT)");
}

ticket::~ticket()
{
    delete ui;
}

void ticket::finishBtnClicked(){
    emit finishBtnClick();
    this->hide();
    clear_table();

    //finish button clicked will alter ticket status into "In process"
    emit ticket_in_process();
}

void ticket::setTicket(QStringList ids){
    this->slot_list=ids;
    qDebug()<<"Valid ids: "<<ids;
    ui->currentslotline->setText(ids.first());
    this->show();
    connect(this->ticket_query,SIGNAL(query_data(QString,QString,QString,QString,QString,QString,QString)),this,SLOT(set_ticket_basic_data(QString,QString,QString,QString,QString,QString,QString)),Qt::UniqueConnection);
}

void ticket::changeBtnClicked(){
    QString current_slot = slot_list.at(current_slot_index);
    qDebug() << current_slot;
    ui->currentslotline->setText(current_slot);

    // 更新迭代器位置，如果已经到达列表的末尾，就重新开始
    current_slot_index = (current_slot_index + 1) % slot_list.size();

}
void ticket::set_ticket_basic_data(QString brand,QString model,QString regid,QString staff,QString timeSlot,QString issue,QString state){
    qDebug()<<"Inside set txt!"<<brand;
    QSqlQuery query(ticketdb);
    query.exec("SELECT MAX(id) FROM ticketinfo");
    if (query.next()) {
        //qDebug()<<"MAX: "<< query.value(0).toInt() + 1;
        this->ticket_id = query.value(0).toInt()+1;
        qDebug()<<"Ticket id: "<<this->ticket_id;
    } else {
        this->ticket_id = 1;
    }
    //we need check staff name if it's inside staffdb, otherwise can't insert



    QString sqlInsert = QString("insert into ticketinfo(id, brand, model,registrationId, problem,staff,timeSlots, ticketState) values(%1,'%2','%3','%4','%5','%6','%7','%8')")
                            .arg(this->ticket_id).arg(brand).arg(model).arg(regid).arg(staff).arg(timeSlot).arg(issue).arg(state);
    query.exec(sqlInsert);

    ui->brandline->setText(brand);
    ui->modelline->setText(model);
    ui->idline->setText(regid);
    ui->staffline->setText(staff);
    ui->timeline->setText(timeSlot);
    ui->issuetxt->setPlainText(issue);
    ui->stateline->setText(state);
    ui->ticketidline->setText(QString::number(this->ticket_id));
    //this->ticket_id+=1;
}

void ticket::clear_table(){
    ui->brandline->clear();
    ui->modelline->clear();
    ui->idline->clear();
    ui->staffline->clear();
    ui->timeline->clear();
    ui->issuetxt->clear();
    ui->ticketidline->clear();
}

void ticket::addBtnClicked(){
    qDebug()<<"Inside add button!";
    this->add_page=new add_parts();
    this->add_page->show();
    connect(this->add_page,SIGNAL(parts_data(QString,float,float)),this,SLOT(save_parts_data(QString,float,float)));
}

void ticket::save_parts_data(QString name,float amount,float unitPrice){
   // qDebug()<<"Inside save parts data!";
   // qDebug()<<"name: "<<name<<"amount: "<<amount<<"unitPrice: "<<unitPrice;
   QSqlQuery query_part_db(partdb);
    float total_price = amount*unitPrice;
    //We can use %arg to add different types of data in database
    QString sql =QString("insert into partinfo(id, name, amount, unit_price, total_price) values(%1,'%2',%3,%4,%5)").arg(this->ticket_id).arg(name).arg(amount).arg(unitPrice).arg(total_price);
   //query_part_db.exec(sql);
    if(!query_part_db.exec(sql)) {
       qDebug() << "Error inserting into partinfo: " << query_part_db.lastError();
    }
    //display parts infomation in ticket
    ui->partstb->setModel(qmodel);
    QSqlQuery query_display("select name, amount, unit_price, total_price from partinfo",partdb);
     qmodel->setQuery(std::move(query_display));
}

void ticket::editBtnClicked(){
    qDebug()<<"enter edit btn!";
    QSqlQuery query_estimate_db(estimatedb);
    QString description = ui->desctb->toPlainText();
    float service_cost = ui->serviceline->text().toFloat();
    QString attitude = ui->clientline->text();
    QString sql =QString("insert into estimateinfo(id, description, service_cost, client_attitude) values(%1,'%2',%3,'%4')").arg(this->ticket_id).arg(description).arg(service_cost).arg(attitude);
    if(!query_estimate_db.exec(sql)) {
        qDebug() << "Error inserting into estimateinfo: " << query_estimate_db.lastError();
    }
    QMessageBox::about(this,"Notice","All changes saved successfully!");
}

void ticket::pdfBtnClicked(){
    estimateExportToPdf();
}

void ticket::estimateExportToPdf(){
    QPdfWriter pdfWriter("estimate.pdf");//set output path

    QPainter painter(&pdfWriter);//link painter with pdfWriter

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial",10));
    QSqlQuery query(estimatedb);
    QString sql = "select * from estimateinfo";
    if (!query.exec(sql)) {
        qDebug() << "Error executing SQL query:" << query.lastError().text();
        return;
    }
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

void ticket::finalCostBtnClicked(){
    finalCostExportToPdf();
}

void ticket::finalCostExportToPdf(){
    QPdfWriter pdfWriter("final cost.pdf");//set output path

    QPainter painter(&pdfWriter);//link painter with pdfWriter

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial",10));
    QSqlQuery query(partdb);
    QString sql = "select * from partinfo";
    if (!query.exec(sql)) {
        qDebug() << "Error executing SQL query:" << query.lastError().text();
        return;
    }
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
