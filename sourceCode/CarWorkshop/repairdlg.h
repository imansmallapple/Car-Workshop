#ifndef REPAIRDLG_H
#define REPAIRDLG_H

#include <ticket_basic_query.h>
#include <QWidget>
#include<ticket.h>
#include <QSqlDatabase>//get sqlite header file
#include <QSqlError>
#include <QSqlQuery>//implement sql sentences
#include <QSqlQueryModel>
#include <choose_slots.h>
#include <QDate>

namespace Ui {
class repairDlg;
}

class repairDlg : public QWidget
{
    Q_OBJECT

public:
    explicit repairDlg(QWidget *parent = nullptr);
    ~repairDlg();
    //Save ticket installation address
    ticket *ticket_page = NULL;
    choose_slots *choose_page =NULL;
    ticket_basic_query *ticket_query=NULL;

signals:
    void backFromRepairDlg();
    void id_valid(QStringList);//check if id valid
    void query_ok();
    void staff_name(QString);
private slots:

    void applyBtnClicked();
    void getFinishBtnClicked();
    void calendarWidget_clicked(const QDate &date);
    //void editBtnClicked();
    void getChosenSlotId(QString);
    void checkSlotValid(QString,QString,QString);
    void update_ticket_state(QStringList);
    void change_ticket_in_process();
    void send_staff_name(QString);

private:
    Ui::repairDlg *ui;
    QSqlDatabase workshopdb;
    QSqlQuery *query;
    QSqlQueryModel *qmodel;
    QString current_id;
    QString current_date;
    QStringList current_ids;
};

#endif // REPAIRDLG_H
