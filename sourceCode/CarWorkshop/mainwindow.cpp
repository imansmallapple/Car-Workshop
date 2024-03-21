#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    this->setWindowTitle("Car Workshop Management System");

    this->boss_use_page = new bossUse;//construct bossUse page class

    this->staff_use_page = new repairDlg;//construct repair dlalog page class

    //change widget from mainwindow to boss window
    connect(ui->bossbtn,&QPushButton::clicked, [=](){
        //hide mainwindow
        this->hide();
        //show boss window
        this->boss_use_page->show();
    });

    //change widget from boss window to mainwindow
    connect(this->boss_use_page, &bossUse::backFromBossUse,[=](){
        this->boss_use_page->hide();
        this->show();
    });

    //change widget from mainwindow to repair dialog window
    connect(ui->employeebtn, &QPushButton::clicked,[=](){
       //hide mainwindow
        this->hide();
       //show repair dialog window
        this->staff_use_page->show();
    });

    //change widget from repair dialog window to mainwindow
    connect(this->staff_use_page, &repairDlg::backFromRepairDlg,[=](){
        this->staff_use_page->hide();
        this->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bossbtn_clicked()
{

}
