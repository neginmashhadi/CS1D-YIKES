/********************************************************************************
** Form generated from reading UI file 'receipt.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIPT_H
#define UI_RECEIPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_receipt
{
public:
    QDialogButtonBox *buttonBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QDialog *receipt)
    {
        if (receipt->objectName().isEmpty())
            receipt->setObjectName(QStringLiteral("receipt"));
        receipt->resize(692, 396);
        buttonBox = new QDialogButtonBox(receipt);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(580, 350, 81, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        scrollArea = new QScrollArea(receipt);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 30, 431, 271));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 269));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(receipt);
        QObject::connect(buttonBox, SIGNAL(accepted()), receipt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), receipt, SLOT(reject()));

        QMetaObject::connectSlotsByName(receipt);
    } // setupUi

    void retranslateUi(QDialog *receipt)
    {
        receipt->setWindowTitle(QApplication::translate("receipt", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class receipt: public Ui_receipt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIPT_H
