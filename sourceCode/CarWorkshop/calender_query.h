#ifndef CALENDER_QUERY_H
#define CALENDER_QUERY_H
#include<staff_calender.h>
#include <QWidget>
#include <QMessageBox>
#include <QThread>


namespace Ui {
class calender_query;
}

class calender_query : public QWidget
{
    Q_OBJECT

public:
    explicit calender_query(QWidget *parent = nullptr);
    ~calender_query();

    staff_calender *staffCalenderPage = NULL;

signals:
    void name_data(QString);
    void send_name_to_calender(QString);
private slots:
    void confirmbtn_clicked();
    void getName(QString);
    void dontGetName();

private:
    Ui::calender_query *ui;
};

#endif // CALENDER_QUERY_H
