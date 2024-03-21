/********************************************************************************
** Form generated from reading UI file 'employeePersonalInfo.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEPERSONALINFO_H
#define UI_EMPLOYEEPERSONALINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QCalendarWidget *calendarWidget;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(799, 478);
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 30, 471, 19));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(540, 420, 121, 28));
        textEdit = new QTextEdit(Form);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(670, 420, 101, 31));
        calendarWidget = new QCalendarWidget(Form);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(100, 60, 551, 291));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "\350\277\231\351\207\214\346\234\211\344\270\252\345\244\247\346\227\245\345\216\206\357\274\214\346\230\276\347\244\272\345\221\230\345\267\245\345\277\231\347\242\214\346\210\226\351\227\262\344\275\231\347\212\266\346\200\201\343\200\202\350\200\201\346\235\277\345\217\257\344\273\245\345\210\266\345\256\232\345\221\230\345\267\245\346\227\266\350\226\252", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Edit Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEPERSONALINFO_H
