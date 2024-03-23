#ifndef TICKET_BASIC_QUERY_H
#define TICKET_BASIC_QUERY_H

#include <QWidget>
#include <QString>
namespace Ui {
class ticket_basic_query;
}

class ticket_basic_query : public QWidget
{
    Q_OBJECT

public:
    explicit ticket_basic_query(QWidget *parent = nullptr);
    ~ticket_basic_query();
signals:
    void query_data(QString, QString, QString, QString, QString, QString,QString);
    void staff_name(QString);
private slots:
    void set_query();
    void confirmBtnClicked();

private:
    Ui::ticket_basic_query *ui;

    void clear_query();
};

#endif // TICKET_BASIC_QUERY_H
