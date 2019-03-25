/********************************************************************************
** Form generated from reading UI file 'edititem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITITEM_H
#define UI_EDITITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditItem
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *name_label;
    QLineEdit *food_name;
    QSpacerItem *verticalSpacer_3;
    QLabel *price_label;
    QDoubleSpinBox *food_price;
    QSpacerItem *verticalSpacer_2;
    QPushButton *next_button;
    QPushButton *submit_button;

    void setupUi(QDialog *EditItem)
    {
        if (EditItem->objectName().isEmpty())
            EditItem->setObjectName(QStringLiteral("EditItem"));
        EditItem->resize(445, 399);
        buttonBox = new QDialogButtonBox(EditItem);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 360, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(EditItem);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 20, 281, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        name_label = new QLabel(verticalLayoutWidget);
        name_label->setObjectName(QStringLiteral("name_label"));

        verticalLayout->addWidget(name_label);

        food_name = new QLineEdit(verticalLayoutWidget);
        food_name->setObjectName(QStringLiteral("food_name"));

        verticalLayout->addWidget(food_name);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        price_label = new QLabel(verticalLayoutWidget);
        price_label->setObjectName(QStringLiteral("price_label"));

        verticalLayout->addWidget(price_label);

        food_price = new QDoubleSpinBox(verticalLayoutWidget);
        food_price->setObjectName(QStringLiteral("food_price"));

        verticalLayout->addWidget(food_price);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        next_button = new QPushButton(EditItem);
        next_button->setObjectName(QStringLiteral("next_button"));
        next_button->setGeometry(QRect(130, 310, 75, 23));
        submit_button = new QPushButton(EditItem);
        submit_button->setObjectName(QStringLiteral("submit_button"));
        submit_button->setGeometry(QRect(230, 310, 75, 23));

        retranslateUi(EditItem);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditItem, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditItem, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditItem);
    } // setupUi

    void retranslateUi(QDialog *EditItem)
    {
        EditItem->setWindowTitle(QApplication::translate("EditItem", "Dialog", nullptr));
        name_label->setText(QApplication::translate("EditItem", "TextLabel", nullptr));
        price_label->setText(QApplication::translate("EditItem", "TextLabel", nullptr));
        next_button->setText(QApplication::translate("EditItem", "Next", nullptr));
        submit_button->setText(QApplication::translate("EditItem", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditItem: public Ui_EditItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITITEM_H
