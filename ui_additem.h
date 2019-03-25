/********************************************************************************
** Form generated from reading UI file 'additem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEM_H
#define UI_ADDITEM_H

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

class Ui_AddItem
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLineEdit *food_name;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QDoubleSpinBox *food_price;
    QSpacerItem *verticalSpacer;
    QPushButton *Next_Button;
    QPushButton *Submit;

    void setupUi(QDialog *AddItem)
    {
        if (AddItem->objectName().isEmpty())
            AddItem->setObjectName(QStringLiteral("AddItem"));
        AddItem->resize(455, 434);
        buttonBox = new QDialogButtonBox(AddItem);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 390, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(AddItem);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 30, 211, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        food_name = new QLineEdit(verticalLayoutWidget);
        food_name->setObjectName(QStringLiteral("food_name"));

        verticalLayout->addWidget(food_name);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        food_price = new QDoubleSpinBox(verticalLayoutWidget);
        food_price->setObjectName(QStringLiteral("food_price"));

        verticalLayout->addWidget(food_price);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        Next_Button = new QPushButton(AddItem);
        Next_Button->setObjectName(QStringLiteral("Next_Button"));
        Next_Button->setGeometry(QRect(140, 330, 75, 23));
        Submit = new QPushButton(AddItem);
        Submit->setObjectName(QStringLiteral("Submit"));
        Submit->setGeometry(QRect(240, 330, 75, 23));

        retranslateUi(AddItem);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddItem, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddItem, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddItem);
    } // setupUi

    void retranslateUi(QDialog *AddItem)
    {
        AddItem->setWindowTitle(QApplication::translate("AddItem", "Dialog", nullptr));
        label->setText(QApplication::translate("AddItem", "New Food Name:", nullptr));
        label_2->setText(QApplication::translate("AddItem", "New Food Price:", nullptr));
        Next_Button->setText(QApplication::translate("AddItem", "Next", nullptr));
        Submit->setText(QApplication::translate("AddItem", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddItem: public Ui_AddItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEM_H
