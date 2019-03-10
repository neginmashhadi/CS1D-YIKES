/********************************************************************************
** Form generated from reading UI file 'blocker.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKER_H
#define UI_BLOCKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Blocker
{
public:
    QPlainTextEdit *plainTextEdit;
    QLabel *label;

    void setupUi(QWidget *Blocker)
    {
        if (Blocker->objectName().isEmpty())
            Blocker->setObjectName(QStringLiteral("Blocker"));
        Blocker->resize(400, 300);
        plainTextEdit = new QPlainTextEdit(Blocker);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 0, 131, 301));
        label = new QLabel(Blocker);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 150, 47, 13));

        retranslateUi(Blocker);

        QMetaObject::connectSlotsByName(Blocker);
    } // setupUi

    void retranslateUi(QWidget *Blocker)
    {
        Blocker->setWindowTitle(QApplication::translate("Blocker", "Form", nullptr));
        label->setText(QApplication::translate("Blocker", "nope", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Blocker: public Ui_Blocker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKER_H
