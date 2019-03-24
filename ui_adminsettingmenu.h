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
#include <QtWidgets/QPushButton>
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
    QPushButton *RestaurantButton;
    QVBoxLayout *Restaurant_Layout;
    QRadioButton *RestaurantAdd;
    QRadioButton *RestaurantDelete;
    QRadioButton *Reinitialize;
    QPushButton *ItemButton;
    QVBoxLayout *Item_layout;
    QRadioButton *ItemAdd;
    QRadioButton *ItemDelete;
    QRadioButton *ItemEdit;

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
        verticalLayoutWidget->setGeometry(QRect(100, 30, 191, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        RestaurantButton = new QPushButton(verticalLayoutWidget);
        RestaurantButton->setObjectName(QStringLiteral("RestaurantButton"));

        verticalLayout->addWidget(RestaurantButton);

        Restaurant_Layout = new QVBoxLayout();
        Restaurant_Layout->setObjectName(QStringLiteral("Restaurant_Layout"));
        RestaurantAdd = new QRadioButton(verticalLayoutWidget);
        RestaurantAdd->setObjectName(QStringLiteral("RestaurantAdd"));

        Restaurant_Layout->addWidget(RestaurantAdd);

        RestaurantDelete = new QRadioButton(verticalLayoutWidget);
        RestaurantDelete->setObjectName(QStringLiteral("RestaurantDelete"));

        Restaurant_Layout->addWidget(RestaurantDelete);

        Reinitialize = new QRadioButton(verticalLayoutWidget);
        Reinitialize->setObjectName(QStringLiteral("Reinitialize"));

        Restaurant_Layout->addWidget(Reinitialize);


        verticalLayout->addLayout(Restaurant_Layout);

        ItemButton = new QPushButton(verticalLayoutWidget);
        ItemButton->setObjectName(QStringLiteral("ItemButton"));

        verticalLayout->addWidget(ItemButton);

        Item_layout = new QVBoxLayout();
        Item_layout->setObjectName(QStringLiteral("Item_layout"));
        ItemAdd = new QRadioButton(verticalLayoutWidget);
        ItemAdd->setObjectName(QStringLiteral("ItemAdd"));

        Item_layout->addWidget(ItemAdd);

        ItemDelete = new QRadioButton(verticalLayoutWidget);
        ItemDelete->setObjectName(QStringLiteral("ItemDelete"));

        Item_layout->addWidget(ItemDelete);

        ItemEdit = new QRadioButton(verticalLayoutWidget);
        ItemEdit->setObjectName(QStringLiteral("ItemEdit"));

        Item_layout->addWidget(ItemEdit);


        verticalLayout->addLayout(Item_layout);


        retranslateUi(AdminSettingMenu);
        QObject::connect(buttonBox, SIGNAL(accepted()), AdminSettingMenu, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AdminSettingMenu, SLOT(reject()));

        QMetaObject::connectSlotsByName(AdminSettingMenu);
    } // setupUi

    void retranslateUi(QDialog *AdminSettingMenu)
    {
        AdminSettingMenu->setWindowTitle(QApplication::translate("AdminSettingMenu", "Dialog", nullptr));
        RestaurantButton->setText(QApplication::translate("AdminSettingMenu", "Restaurant Add/Delete/Reinitialize", nullptr));
        RestaurantAdd->setText(QApplication::translate("AdminSettingMenu", "Add Restaurant", nullptr));
        RestaurantDelete->setText(QApplication::translate("AdminSettingMenu", "Delete Restaurant", nullptr));
        Reinitialize->setText(QApplication::translate("AdminSettingMenu", "Reinitialize First 10", nullptr));
        ItemButton->setText(QApplication::translate("AdminSettingMenu", "Item Add/Delete/Edit", nullptr));
        ItemAdd->setText(QApplication::translate("AdminSettingMenu", "Add Item", nullptr));
        ItemDelete->setText(QApplication::translate("AdminSettingMenu", "Delete Item", nullptr));
        ItemEdit->setText(QApplication::translate("AdminSettingMenu", "Edit Item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminSettingMenu: public Ui_AdminSettingMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINSETTINGMENU_H
