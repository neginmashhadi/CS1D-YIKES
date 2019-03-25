/********************************************************************************
** Form generated from reading UI file 'shortesttrip.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHORTESTTRIP_H
#define UI_SHORTESTTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_shortesttrip
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QLabel *label;

    void setupUi(QDialog *shortesttrip)
    {
        if (shortesttrip->objectName().isEmpty())
            shortesttrip->setObjectName(QStringLiteral("shortesttrip"));
        shortesttrip->resize(400, 300);
        buttonBox = new QDialogButtonBox(shortesttrip);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox = new QSpinBox(shortesttrip);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(140, 150, 121, 21));
        label = new QLabel(shortesttrip);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 110, 201, 21));

        retranslateUi(shortesttrip);
        QObject::connect(buttonBox, SIGNAL(accepted()), shortesttrip, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), shortesttrip, SLOT(reject()));

        QMetaObject::connectSlotsByName(shortesttrip);
    } // setupUi

    void retranslateUi(QDialog *shortesttrip)
    {
        shortesttrip->setWindowTitle(QApplication::translate("shortesttrip", "Dialog", nullptr));
        label->setText(QApplication::translate("shortesttrip", "Number of stops (exclusing Domino's)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shortesttrip: public Ui_shortesttrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHORTESTTRIP_H
