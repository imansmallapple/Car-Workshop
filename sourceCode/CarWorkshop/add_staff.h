#ifndef ADD_STAFF_H
#define ADD_STAFF_H
#include <QWidget>

namespace Ui {
class add_staff;
}

class add_staff : public QWidget
{
    Q_OBJECT

public:
    explicit add_staff(QWidget *parent = nullptr);
    ~add_staff();

signals:
    void sendToBossData(QString);//return type of signal must be void
    void existEmptyInput();

private slots:
    void on_finishbtn_clicked();

private:
    Ui::add_staff *ui;
};

#endif // ADD_STAFF_H
