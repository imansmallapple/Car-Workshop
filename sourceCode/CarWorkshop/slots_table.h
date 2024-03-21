#ifndef SLOTS_TABLE_H
#define SLOTS_TABLE_H

#include <QWidget>

namespace Ui {
class slots_table;
}

class slots_table : public QWidget
{
    Q_OBJECT

public:
    explicit slots_table(QWidget *parent = nullptr);
    ~slots_table();

private:
    Ui::slots_table *ui;
};

#endif // SLOTS_TABLE_H
