#ifndef STAFFUSE_H
#define STAFFUSE_H

#include <QWidget>

namespace Ui {
class staffuse;
}

class staffuse : public QWidget
{
    Q_OBJECT

public:
    explicit staffuse(QWidget *parent = nullptr);
    ~staffuse();

private:
    Ui::staffuse *ui;
};

#endif // STAFFUSE_H
