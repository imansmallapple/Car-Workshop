#ifndef TICKET_H
#define TICKET_H

#include <QWidget>


namespace Ui {
class ticket;
}

class ticket : public QWidget
{
    Q_OBJECT

public:
    explicit ticket(QWidget *parent = nullptr);
    ~ticket();
signals:
    void finishBtnClick();
private slots:
    void finishBtnClicked();
private:
    Ui::ticket *ui;

};

#endif // TICKET_H
