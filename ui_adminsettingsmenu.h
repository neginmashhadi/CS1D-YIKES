/********************************************************************************
** Form generated from reading UI file 'adminsettingsmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINSETTINGSMENU_H
#define UI_ADMINSETTINGSMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminSettingsMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AdminSettingsMenu)
    {
        if (AdminSettingsMenu->objectName().isEmpty())
            AdminSettingsMenu->setObjectName(QStringLiteral("AdminSettingsMenu"));
        AdminSettingsMenu->resize(400, 300);
        verticalLayoutWidget = new QWidget(AdminSettingsMenu);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(130, 50, 136, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_2 = new QRadioButton(verticalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(verticalLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);

        radioButton_3 = new QRadioButton(verticalLayoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        buttonBox = new QDialogButtonBox(AdminSettingsMenu);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(220, 260, 156, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(AdminSettingsMenu);

        QMetaObject::connectSlotsByName(AdminSettingsMenu);
    } // setupUi

    void retranslateUi(QDialog *AdminSettingsMenu)
    {
        AdminSettingsMenu->setWindowTitle(QApplication::translate("AdminSettingsMenu", "Dialog", nullptr));
        radioButton_2->setText(QApplication::translate("AdminSettingsMenu", "Add/Delete Restaurant", nullptr));
        radioButton->setText(QApplication::translate("AdminSettingsMenu", "Add/Delete Item", nullptr));
        radioButton_3->setText(QApplication::translate("AdminSettingsMenu", "Change Item Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminSettingsMenu: public Ui_AdminSettingsMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSETTINGSMENU_H
