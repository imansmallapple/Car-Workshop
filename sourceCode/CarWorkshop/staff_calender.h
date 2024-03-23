#ifndef STAFF_CALENDER_H
#define STAFF_CALENDER_H

#include <QWidget>
#include <QCalendarWidget>
#include <QSqlDatabase>//get sqlite header file
#include <QSqlError>
#include <QSqlQuery>//implement sql sentences
#include <QSqlQueryModel>
#include <set_status.h>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QSqlRecord>
#include <QFont>
#include <QMessageBox>

namespace Ui {
class staff_calender;
}

class staff_calender : public QWidget
{
    Q_OBJECT

public:
    explicit staff_calender(QWidget *parent = nullptr);
    ~staff_calender();
    QCalendarWidget *calenderWidget = NULL;
    set_status *setPage= NULL;
signals:

private slots:  
    void get_name_from_query(QString);
    void onCalenderClicked(const QDate& date);
    void getBusyBtnClicked(QString);
    void getFreeBtnClicked(QString);
    void saveBtnClicked();


private:
    Ui::staff_calender *ui;
    QSqlDatabase calenderdb;
    QSqlQuery *query;
    QSqlQueryModel *qmodel;
    QString currentName;//used for store data
    void exportToPdf();

};

#endif // STAFF_CALENDER_H
