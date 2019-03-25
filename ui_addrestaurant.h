/********************************************************************************
** Form generated from reading UI file 'addrestaurant.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESTAURANT_H
#define UI_ADDRESTAURANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addRestaurant
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *path;
    QPushButton *pushButton_2;

    void setupUi(QDialog *addRestaurant)
    {
        if (addRestaurant->objectName().isEmpty())
            addRestaurant->setObjectName(QStringLiteral("addRestaurant"));
        addRestaurant->resize(437, 340);
        buttonBox = new QDialogButtonBox(addRestaurant);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(340, 270, 81, 51));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Close);
        pushButton = new QPushButton(addRestaurant);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 80, 205, 31));
        label = new QLabel(addRestaurant);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 120, 411, 41));
        horizontalLayoutWidget = new QWidget(addRestaurant);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 170, 351, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        path = new QLineEdit(horizontalLayoutWidget);
        path->setObjectName(QStringLiteral("path"));

        horizontalLayout->addWidget(path);

        pushButton_2 = new QPushButton(addRestaurant);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 230, 75, 23));

        retranslateUi(addRestaurant);
        QObject::connect(buttonBox, SIGNAL(accepted()), addRestaurant, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), addRestaurant, SLOT(reject()));

        QMetaObject::connectSlotsByName(addRestaurant);
    } // setupUi

    void retranslateUi(QDialog *addRestaurant)
    {
        addRestaurant->setWindowTitle(QApplication::translate("addRestaurant", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("addRestaurant", "Add 2 New Restaurants from NewFile.txt", nullptr));
        label->setText(QApplication::translate("addRestaurant", "Press the button above, or enter the path of the new file bellow and press Submit:", nullptr));
        label_2->setText(QApplication::translate("addRestaurant", "Path:", nullptr));
        pushButton_2->setText(QApplication::translate("addRestaurant", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addRestaurant: public Ui_addRestaurant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESTAURANT_H
