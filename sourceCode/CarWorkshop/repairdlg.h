#ifndef REPAIRDLG_H
#define REPAIRDLG_H

#include <QWidget>
#include<ticket.h>
#include <QSqlDatabase>//get sqlite header file
#include <QSqlError>
#include <QSqlQuery>//implement sql sentences
#include <QSqlQueryModel>
#include <update_slots.h>
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
    update_slots *update_page = NULL;
    choose_slots *choose_page =NULL;

signals:
    void backFromRepairDlg();
    void id_valid();
private slots:
    void cancelBtnClicked();
    void applyBtnClicked();
    void getFinishBtnClicked();
    void calendarWidget_clicked(const QDate &date);
    void editBtnClicked();
    void getChosenSlotId(QString);
    void checkSlotValid(QString,QString,QString);
    void setTicket();

private:
    Ui::repairDlg *ui;
    QSqlDatabase workshopdb;
    QSqlQuery *query;
    QSqlQueryModel *qmodel;
    QString current_id;
    QString current_date;
};

#endif // REPAIRDLG_H
