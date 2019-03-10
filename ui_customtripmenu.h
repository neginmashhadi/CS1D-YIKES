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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomTripMenu
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *CustomTripMenu)
    {
        if (CustomTripMenu->objectName().isEmpty())
            CustomTripMenu->setObjectName(QStringLiteral("CustomTripMenu"));
        CustomTripMenu->resize(400, 300);
        buttonBox = new QDialogButtonBox(CustomTripMenu);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 260, 331, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(CustomTripMenu);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 20, 141, 226));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(CustomTripMenu);
        QObject::connect(buttonBox, SIGNAL(accepted()), CustomTripMenu, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CustomTripMenu, SLOT(reject()));

        QMetaObject::connectSlotsByName(CustomTripMenu);
    } // setupUi

    void retranslateUi(QDialog *CustomTripMenu)
    {
        CustomTripMenu->setWindowTitle(QApplication::translate("CustomTripMenu", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomTripMenu: public Ui_CustomTripMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMTRIPMENU_H
