#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>//get sqlite header file
#include<QSqlError>
#include<QSqlQuery>//implement sql sentences
#include<bossuse.h>
#include<repairdlg.h>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //Save bossuse installation address
    bossUse *boss_use_page = NULL;
    //Save staffuse installation address
    repairDlg *staff_use_page = NULL;

private slots:
    void employeeBtnClicked();
    void get_staff_name(QString);
    void check_staff_name(QStringList);

private:
    Ui::MainWindow *ui;
    QString staff_name;

};
#endif // MAINWINDOW_H
