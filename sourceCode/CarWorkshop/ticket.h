#ifndef TICKET_H
#define TICKET_H

#include <QWidget>
#include <QSqlDatabase>//get sqlite header file
#include <QSqlError>
#include <QSqlQuery>//implement sql sentences
#include <QSqlQueryModel>
#include <ticket_basic_query.h>
#include <add_parts.h>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QSqlRecord>
#include <QFont>

namespace Ui {
class ticket;
}

class ticket : public QWidget
{
    Q_OBJECT

public:
    explicit ticket(ticket_basic_query *ticket_query, QWidget *parent = nullptr);// 在构造函数中接收一个ticket_basic_query对象的指针
    ~ticket();
    add_parts *add_page = NULL;

signals:
    void finishBtnClick();
    void ticket_in_process();
private slots:
    void finishBtnClicked();
    void setTicket(QStringList);
    void changeBtnClicked();
    void set_ticket_basic_data(QString,QString,QString,QString,QString,QString,QString);
    void addBtnClicked();
    void save_parts_data(QString,float,float);
    void editBtnClicked();
    void pdfBtnClicked();
    void finalCostBtnClicked();

private:
    Ui::ticket *ui;
    QStringList slot_list;
    int current_slot_index = 0;
    QSqlDatabase ticketdb;
    QSqlDatabase partdb;
    QSqlDatabase estimatedb;
    QSqlQuery *query;
    QSqlQueryModel *qmodel;
    ticket_basic_query *ticket_query;// 添加一个新的成员变量来存储ticket_basic_query对象的指针
    int ticket_id=1;
    void clear_table();
    void estimateExportToPdf();
    void finalCostExportToPdf();
};

#endif // TICKET_H
