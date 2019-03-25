/********************************************************************************
** Form generated from reading UI file 'deleterestaurant.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETERESTAURANT_H
#define UI_DELETERESTAURANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteRestaurant
{
public:
    QDialogButtonBox *buttonBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *deleteRestaurant)
    {
        if (deleteRestaurant->objectName().isEmpty())
            deleteRestaurant->setObjectName(QStringLiteral("deleteRestaurant"));
        deleteRestaurant->resize(494, 337);
        buttonBox = new QDialogButtonBox(deleteRestaurant);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(140, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        scrollArea = new QScrollArea(deleteRestaurant);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(250, 50, 221, 201));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 199));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(deleteRestaurant);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 120, 171, 21));
        lineEdit = new QLineEdit(deleteRestaurant);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 150, 61, 20));
        pushButton = new QPushButton(deleteRestaurant);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 190, 81, 23));

        retranslateUi(deleteRestaurant);
        QObject::connect(buttonBox, SIGNAL(accepted()), deleteRestaurant, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), deleteRestaurant, SLOT(reject()));

        QMetaObject::connectSlotsByName(deleteRestaurant);
    } // setupUi

    void retranslateUi(QDialog *deleteRestaurant)
    {
        deleteRestaurant->setWindowTitle(QApplication::translate("deleteRestaurant", "Dialog", nullptr));
        label->setText(QApplication::translate("deleteRestaurant", "ID number of deleted Restaurant:", nullptr));
        pushButton->setText(QApplication::translate("deleteRestaurant", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteRestaurant: public Ui_deleteRestaurant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETERESTAURANT_H
