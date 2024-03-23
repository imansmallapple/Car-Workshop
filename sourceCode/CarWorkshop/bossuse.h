#ifndef BOSSUSE_H
#define BOSSUSE_H

#include <QWidget>
#include <QSqlDatabase>//get sqlite header file
#include<QSqlError>
#include<QSqlQuery>//implement sql sentences
#include <QMessageBox>
#include <QSqlTableModel>
#include <QString>
#include<QSqlQueryModel>
#include<add_staff.h>
#include<delete_staff.h>

#include<calender_query.h>
namespace Ui {
class bossUse;
}

class bossUse : public QWidget
{
    Q_OBJECT

public:
    explicit bossUse(QWidget *parent = nullptr);
    ~bossUse();

    //Save add_staff installation address
    add_staff *addPage = NULL;
    delete_staff *deletePage = NULL;

    calender_query *calender_query_page = NULL;

signals:
    void backFromBossUse();
    void haveName(QString);
    void dontHaveName();
    void sendStaffList(QStringList names);

private slots:
    void getFromAddStaffData(QString receivedData);//receive string infomation from add page

    void addbtn_clicked();

    void getFromDeleteStaffData(QString);
    void firebtn_clicked();

    void calenderbtn_clicked();
    void getFromCalenderQueryData(QString);

    void haveEmptyInput();
    void deleteInvalidStaff();

    void send_name_list();


private:
    Ui::bossUse *ui;
    QSqlDatabase staffdb;
    QSqlQuery *query1;
    QSqlQueryModel *qmodel;
};

#endif // BOSSUSE_H
