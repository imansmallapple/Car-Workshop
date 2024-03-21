#ifndef DELETE_STAFF_H
#define DELETE_STAFF_H

#include <QWidget>

namespace Ui {
class delete_staff;
}

class delete_staff : public QWidget
{
    Q_OBJECT

public:
    explicit delete_staff(QWidget *parent = nullptr);
    ~delete_staff();
signals:
    void sendDeleteData(QString);
    void deleteWrongInput();
private slots:
    void finishbtn_clicked();

    void on_cancelbtn_clicked();

private:
    Ui::delete_staff *ui;
};

#endif // DELETE_STAFF_H
