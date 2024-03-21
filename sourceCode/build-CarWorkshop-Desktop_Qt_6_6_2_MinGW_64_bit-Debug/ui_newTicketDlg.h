/********************************************************************************
** Form generated from reading UI file 'newTicketDlg.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTICKETDLG_H
#define UI_NEWTICKETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableWidget *tableWidget;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_9;
    QListWidget *listWidget_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_11;
    QLineEdit *lineEdit_2;
    QLabel *label_12;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QWidget *widget4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QTextEdit *textEdit_6;
    QWidget *widget5;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QWidget *widget6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_13;
    QLineEdit *lineEdit_3;
    QWidget *widget7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_14;
    QLineEdit *lineEdit_8;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1248, 486);
        tableWidget = new QTableWidget(Form);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(140, 170, 541, 221));
        label_5 = new QLabel(Form);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 170, 131, 19));
        label_8 = new QLabel(Form);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(570, 10, 181, 19));
        label_9 = new QLabel(Form);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(490, 100, 271, 19));
        listWidget_2 = new QListWidget(Form);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(930, 190, 291, 91));
        widget = new QWidget(Form);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(730, 50, 201, 27));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");

        horizontalLayout_5->addWidget(label_10);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_5->addWidget(lineEdit);

        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(760, 190, 171, 27));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName("label_11");

        horizontalLayout_6->addWidget(label_11);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout_6->addWidget(lineEdit_2);

        label_12 = new QLabel(Form);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(700, 110, 161, 19));
        widget1 = new QWidget(Form);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(1010, 430, 221, 31));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        textEdit = new QTextEdit(widget1);
        textEdit->setObjectName("textEdit");

        horizontalLayout->addWidget(textEdit);

        widget2 = new QWidget(Form);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(20, 30, 431, 101));
        horizontalLayout_2 = new QHBoxLayout(widget2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(widget2);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget2);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget2);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_7 = new QLineEdit(widget2);
        lineEdit_7->setObjectName("lineEdit_7");

        verticalLayout->addWidget(lineEdit_7);

        lineEdit_6 = new QLineEdit(widget2);
        lineEdit_6->setObjectName("lineEdit_6");

        verticalLayout->addWidget(lineEdit_6);

        lineEdit_5 = new QLineEdit(widget2);
        lineEdit_5->setObjectName("lineEdit_5");

        verticalLayout->addWidget(lineEdit_5);


        horizontalLayout_2->addLayout(verticalLayout);

        widget3 = new QWidget(Form);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(0, 420, 381, 31));
        horizontalLayout_3 = new QHBoxLayout(widget3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget3);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        lineEdit_4 = new QLineEdit(widget3);
        lineEdit_4->setObjectName("lineEdit_4");

        horizontalLayout_3->addWidget(lineEdit_4);

        widget4 = new QWidget(Form);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(930, 10, 291, 31));
        horizontalLayout_4 = new QHBoxLayout(widget4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget4);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        textEdit_6 = new QTextEdit(widget4);
        textEdit_6->setObjectName("textEdit_6");

        horizontalLayout_4->addWidget(textEdit_6);

        widget5 = new QWidget(Form);
        widget5->setObjectName("widget5");
        widget5->setGeometry(QRect(930, 50, 291, 125));
        verticalLayout_3 = new QVBoxLayout(widget5);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(widget5);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");

        verticalLayout_3->addWidget(listWidget);

        widget6 = new QWidget(Form);
        widget6->setObjectName("widget6");
        widget6->setGeometry(QRect(847, 300, 381, 27));
        horizontalLayout_7 = new QHBoxLayout(widget6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(widget6);
        label_13->setObjectName("label_13");

        horizontalLayout_7->addWidget(label_13);

        lineEdit_3 = new QLineEdit(widget6);
        lineEdit_3->setObjectName("lineEdit_3");

        horizontalLayout_7->addWidget(lineEdit_3);

        widget7 = new QWidget(Form);
        widget7->setObjectName("widget7");
        widget7->setGeometry(QRect(910, 340, 321, 27));
        horizontalLayout_8 = new QHBoxLayout(widget7);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(widget7);
        label_14->setObjectName("label_14");

        horizontalLayout_8->addWidget(label_14);

        lineEdit_8 = new QLineEdit(widget7);
        lineEdit_8->setObjectName("lineEdit_8");

        horizontalLayout_8->addWidget(lineEdit_8);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label_5->setText(QCoreApplication::translate("Form", "Issue Description", nullptr));
        label_8->setText(QCoreApplication::translate("Form", "MAINTENANCE TICKET", nullptr));
        label_9->setText(QCoreApplication::translate("Form", "\350\277\231\344\272\233\351\203\275\346\230\257\350\207\252\345\212\250\347\224\237\346\210\220\347\232\204", nullptr));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("Form", "Name", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("Form", "Amount", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_2->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("Form", "Price", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_2->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("Form", "Total", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        label_10->setText(QCoreApplication::translate("Form", "Estimated Cost:", nullptr));
        label_11->setText(QCoreApplication::translate("Form", "Parts Cost:", nullptr));
        label_12->setText(QCoreApplication::translate("Form", "\345\217\263\350\276\271\346\230\257\345\217\257\347\274\226\350\276\221\347\232\204", nullptr));
        label->setText(QCoreApplication::translate("Form", "Ticket status:", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "       Brand", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "         Type", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Registration ID", nullptr));
        label_6->setText(QCoreApplication::translate("Form", "Estimated Repair Date:", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "Maintenance staff:", nullptr));

        const bool __sortingEnabled1 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(0);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("Form", "description", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(1);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("Form", "service cost", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(2);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("Form", "client attitude", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled1);

        label_13->setText(QCoreApplication::translate("Form", "Actual working time period:", nullptr));
        label_14->setText(QCoreApplication::translate("Form", "Actual working staff:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTICKETDLG_H
