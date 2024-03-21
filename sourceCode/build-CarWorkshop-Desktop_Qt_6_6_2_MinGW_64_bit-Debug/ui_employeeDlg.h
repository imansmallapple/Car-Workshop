/********************************************************************************
** Form generated from reading UI file 'employeeDlg.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEDLG_H
#define UI_EMPLOYEEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(901, 522);
        tableWidget = new QTableWidget(Form);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 90, 821, 401));
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 0, 691, 20));
        widget = new QWidget(Form);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 30, 821, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "\350\277\231\351\207\214\345\272\224\350\257\245\346\234\211\344\270\252\350\241\250\357\274\214\347\202\271\345\221\230\345\267\245\344\274\232\350\277\233\345\210\260detail\357\274\214\350\277\231\351\207\214\345\260\261\345\217\252\346\234\211\345\247\223\345\220\215\357\274\214\345\271\264\351\276\204\357\274\214\346\200\247\345\210\253\357\274\214\345\267\245\344\275\234\346\227\266\351\225\277", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Find Employee", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form", "Hire Employee", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Form", "Fire Employee", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEDLG_H
