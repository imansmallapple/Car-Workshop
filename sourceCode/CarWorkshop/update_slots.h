#ifndef UPDATE_SLOTS_H
#define UPDATE_SLOTS_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class update_slots;
}

class update_slots : public QWidget
{
    Q_OBJECT

public:
    explicit update_slots(QWidget *parent = nullptr);
    ~update_slots();

signals:
    void confirmBtnClick();
    void choose_id(QString);

private slots:
    void confirmBtnClicked();

private:
    Ui::update_slots *ui;
};

#endif // UPDATE_SLOTS_H
