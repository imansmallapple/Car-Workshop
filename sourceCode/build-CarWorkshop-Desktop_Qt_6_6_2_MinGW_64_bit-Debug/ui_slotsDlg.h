/********************************************************************************
** Form generated from reading UI file 'slotsDlg.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLOTSDLG_H
#define UI_SLOTSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableWidget *tableWidget;
    QLabel *label;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(802, 495);
        tableWidget = new QTableWidget(Form);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(40, 120, 551, 281));
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 60, 641, 19));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "Here shows available and occupied slots, \347\202\271\345\217\257\344\277\256\347\273\264\344\277\256\346\247\275\347\232\204\346\227\266\345\200\231\344\274\232\345\274\271\345\207\272\346\235\245\347\224\263\350\257\267\347\252\227\345\217\243\345\270\246\345\217\226\346\266\210\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLOTSDLG_H
