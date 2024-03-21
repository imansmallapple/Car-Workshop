#include "slots_table.h"
#include "ui_slots_table.h"

slots_table::slots_table(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::slots_table)
{
    ui->setupUi(this);
}

slots_table::~slots_table()
{
    delete ui;
}
