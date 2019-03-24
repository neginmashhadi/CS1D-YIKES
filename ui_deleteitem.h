/********************************************************************************
** Form generated from reading UI file 'deleteitem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEITEM_H
#define UI_DELETEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DeleteItem
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *next_button;
    QPushButton *submit_button;

    void setupUi(QDialog *DeleteItem)
    {
        if (DeleteItem->objectName().isEmpty())
            DeleteItem->setObjectName(QStringLiteral("DeleteItem"));
        DeleteItem->resize(529, 376);
        buttonBox = new QDialogButtonBox(DeleteItem);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(170, 340, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(DeleteItem);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 20, 251, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        next_button = new QPushButton(DeleteItem);
        next_button->setObjectName(QStringLiteral("next_button"));
        next_button->setGeometry(QRect(140, 300, 75, 23));
        submit_button = new QPushButton(DeleteItem);
        submit_button->setObjectName(QStringLiteral("submit_button"));
        submit_button->setGeometry(QRect(250, 300, 75, 23));

        retranslateUi(DeleteItem);
        QObject::connect(buttonBox, SIGNAL(accepted()), DeleteItem, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DeleteItem, SLOT(reject()));

        QMetaObject::connectSlotsByName(DeleteItem);
    } // setupUi

    void retranslateUi(QDialog *DeleteItem)
    {
        DeleteItem->setWindowTitle(QApplication::translate("DeleteItem", "Dialog", nullptr));
        next_button->setText(QApplication::translate("DeleteItem", "Next", nullptr));
        submit_button->setText(QApplication::translate("DeleteItem", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeleteItem: public Ui_DeleteItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEITEM_H
