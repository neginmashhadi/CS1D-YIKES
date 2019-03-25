/********************************************************************************
** Form generated from reading UI file 'customtripmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMTRIPMENU_H
#define UI_CUSTOMTRIPMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomTripMenu
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;

    void setupUi(QDialog *CustomTripMenu)
    {
        if (CustomTripMenu->objectName().isEmpty())
            CustomTripMenu->setObjectName(QStringLiteral("CustomTripMenu"));
        CustomTripMenu->resize(429, 380);
        buttonBox = new QDialogButtonBox(CustomTripMenu);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(70, 330, 331, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(CustomTripMenu);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(130, 20, 171, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(CustomTripMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 170, 75, 23));

        retranslateUi(CustomTripMenu);
        QObject::connect(buttonBox, SIGNAL(accepted()), CustomTripMenu, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CustomTripMenu, SLOT(reject()));

        QMetaObject::connectSlotsByName(CustomTripMenu);
    } // setupUi

    void retranslateUi(QDialog *CustomTripMenu)
    {
        CustomTripMenu->setWindowTitle(QApplication::translate("CustomTripMenu", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("CustomTripMenu", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomTripMenu: public Ui_CustomTripMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMTRIPMENU_H
