#ifndef CHOOSE_SLOTS_H
#define CHOOSE_SLOTS_H

#include <QWidget>

namespace Ui {
class choose_slots;
}

class choose_slots : public QWidget
{
    Q_OBJECT

public:
    explicit choose_slots(QWidget *parent = nullptr);
    ~choose_slots();
signals:
    void input_slots(QString,QString,QString);
private slots:
    void confirmBtnClicked();
private:
    Ui::choose_slots *ui;

    bool id_limit(QString);
};

#endif // CHOOSE_SLOTS_H
