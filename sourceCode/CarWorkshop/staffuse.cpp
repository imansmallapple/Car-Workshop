#include "staffuse.h"
#include "ui_staffuse.h"

staffuse::staffuse(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::staffuse)
{
    ui->setupUi(this);
}

staffuse::~staffuse()
{
    delete ui;
}
