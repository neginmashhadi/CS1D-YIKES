/********************************************************************************
** Form generated from reading UI file 'reinitializefirstten.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REINITIALIZEFIRSTTEN_H
#define UI_REINITIALIZEFIRSTTEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ReinitializeFirstTen
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;

    void setupUi(QDialog *ReinitializeFirstTen)
    {
        if (ReinitializeFirstTen->objectName().isEmpty())
            ReinitializeFirstTen->setObjectName(QStringLiteral("ReinitializeFirstTen"));
        ReinitializeFirstTen->resize(400, 300);
        buttonBox = new QDialogButtonBox(ReinitializeFirstTen);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pushButton = new QPushButton(ReinitializeFirstTen);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 120, 191, 31));

        retranslateUi(ReinitializeFirstTen);
        QObject::connect(buttonBox, SIGNAL(accepted()), ReinitializeFirstTen, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ReinitializeFirstTen, SLOT(reject()));

        QMetaObject::connectSlotsByName(ReinitializeFirstTen);
    } // setupUi

    void retranslateUi(QDialog *ReinitializeFirstTen)
    {
        ReinitializeFirstTen->setWindowTitle(QApplication::translate("ReinitializeFirstTen", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("ReinitializeFirstTen", "Reinitialize The First Ten Restaurants", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReinitializeFirstTen: public Ui_ReinitializeFirstTen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REINITIALIZEFIRSTTEN_H
