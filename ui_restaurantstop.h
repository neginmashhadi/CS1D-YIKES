/********************************************************************************
** Form generated from reading UI file 'restaurantstop.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTAURANTSTOP_H
#define UI_RESTAURANTSTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_restaurantStop
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Next_Button;
    QPushButton *Submit_Button;
    QLabel *label;

    void setupUi(QDialog *restaurantStop)
    {
        if (restaurantStop->objectName().isEmpty())
            restaurantStop->setObjectName(QStringLiteral("restaurantStop"));
        restaurantStop->resize(442, 328);
        buttonBox = new QDialogButtonBox(restaurantStop);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(80, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(restaurantStop);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 50, 271, 201));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Next_Button = new QPushButton(restaurantStop);
        Next_Button->setObjectName(QStringLiteral("Next_Button"));
        Next_Button->setGeometry(QRect(70, 260, 75, 23));
        Submit_Button = new QPushButton(restaurantStop);
        Submit_Button->setObjectName(QStringLiteral("Submit_Button"));
        Submit_Button->setGeometry(QRect(150, 260, 75, 23));
        label = new QLabel(restaurantStop);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 20, 181, 21));

        retranslateUi(restaurantStop);
        QObject::connect(buttonBox, SIGNAL(accepted()), restaurantStop, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), restaurantStop, SLOT(reject()));

        QMetaObject::connectSlotsByName(restaurantStop);
    } // setupUi

    void retranslateUi(QDialog *restaurantStop)
    {
        restaurantStop->setWindowTitle(QApplication::translate("restaurantStop", "Dialog", nullptr));
        Next_Button->setText(QApplication::translate("restaurantStop", "Next", nullptr));
        Submit_Button->setText(QApplication::translate("restaurantStop", "Submit", nullptr));
        label->setText(QApplication::translate("restaurantStop", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class restaurantStop: public Ui_restaurantStop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTAURANTSTOP_H
