/********************************************************************************
** Form generated from reading UI file 'adminsettingmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSETTINGMENU_H
#define UI_ADMINSETTINGMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminSettingMenu
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *AD_Restaurant_Button;
    QRadioButton *AD_Item_Button;
    QRadioButton *Change_Price_Button;

    void setupUi(QDialog *AdminSettingMenu)
    {
        if (AdminSettingMenu->objectName().isEmpty())
            AdminSettingMenu->setObjectName(QStringLiteral("AdminSettingMenu"));
        AdminSettingMenu->resize(400, 300);
        buttonBox = new QDialogButtonBox(AdminSettingMenu);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(AdminSettingMenu);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 40, 160, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        AD_Restaurant_Button = new QRadioButton(verticalLayoutWidget);
        AD_Restaurant_Button->setObjectName(QStringLiteral("AD_Restaurant_Button"));

        verticalLayout->addWidget(AD_Restaurant_Button);

        AD_Item_Button = new QRadioButton(verticalLayoutWidget);
        AD_Item_Button->setObjectName(QStringLiteral("AD_Item_Button"));

        verticalLayout->addWidget(AD_Item_Button);

        Change_Price_Button = new QRadioButton(verticalLayoutWidget);
        Change_Price_Button->setObjectName(QStringLiteral("Change_Price_Button"));

        verticalLayout->addWidget(Change_Price_Button);


        retranslateUi(AdminSettingMenu);
        QObject::connect(buttonBox, SIGNAL(accepted()), AdminSettingMenu, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AdminSettingMenu, SLOT(reject()));

        QMetaObject::connectSlotsByName(AdminSettingMenu);
    } // setupUi

    void retranslateUi(QDialog *AdminSettingMenu)
    {
        AdminSettingMenu->setWindowTitle(QApplication::translate("AdminSettingMenu", "Dialog", nullptr));
        AD_Restaurant_Button->setText(QApplication::translate("AdminSettingMenu", "Add/Delete Restaurant", nullptr));
        AD_Item_Button->setText(QApplication::translate("AdminSettingMenu", "Add/Delete Item", nullptr));
        Change_Price_Button->setText(QApplication::translate("AdminSettingMenu", "Change Item Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminSettingMenu: public Ui_AdminSettingMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSETTINGMENU_H
