/********************************************************************************
** Form generated from reading UI file 'ProfileWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEWIDGET_H
#define UI_PROFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *usernameLabel;
    QLabel *fullNameLabel;
    QLabel *roleLabel;
    QPushButton *changePasswordButton;
    QGroupBox *passwordGroup;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLineEdit *newPassword;
    QLabel *label_5;
    QLineEdit *confirmPassword;
    QPushButton *savePasswordButton;
    QSpacerItem *verticalSpacer;
    QPushButton *logoutButton;

    void setupUi(QWidget *ProfileWidget)
    {
        if (ProfileWidget->objectName().isEmpty())
            ProfileWidget->setObjectName("ProfileWidget");
        verticalLayout = new QVBoxLayout(ProfileWidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(ProfileWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet(QString::fromUtf8("font-size: 16pt; font-weight: bold;"));

        verticalLayout->addWidget(label);

        usernameLabel = new QLabel(ProfileWidget);
        usernameLabel->setObjectName("usernameLabel");

        verticalLayout->addWidget(usernameLabel);

        fullNameLabel = new QLabel(ProfileWidget);
        fullNameLabel->setObjectName("fullNameLabel");

        verticalLayout->addWidget(fullNameLabel);

        roleLabel = new QLabel(ProfileWidget);
        roleLabel->setObjectName("roleLabel");

        verticalLayout->addWidget(roleLabel);

        changePasswordButton = new QPushButton(ProfileWidget);
        changePasswordButton->setObjectName("changePasswordButton");

        verticalLayout->addWidget(changePasswordButton);

        passwordGroup = new QGroupBox(ProfileWidget);
        passwordGroup->setObjectName("passwordGroup");
        formLayout = new QFormLayout(passwordGroup);
        formLayout->setObjectName("formLayout");
        label_4 = new QLabel(passwordGroup);
        label_4->setObjectName("label_4");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        newPassword = new QLineEdit(passwordGroup);
        newPassword->setObjectName("newPassword");
        newPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(0, QFormLayout::FieldRole, newPassword);

        label_5 = new QLabel(passwordGroup);
        label_5->setObjectName("label_5");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        confirmPassword = new QLineEdit(passwordGroup);
        confirmPassword->setObjectName("confirmPassword");
        confirmPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, confirmPassword);

        savePasswordButton = new QPushButton(passwordGroup);
        savePasswordButton->setObjectName("savePasswordButton");

        formLayout->setWidget(2, QFormLayout::SpanningRole, savePasswordButton);


        verticalLayout->addWidget(passwordGroup);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        logoutButton = new QPushButton(ProfileWidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setStyleSheet(QString::fromUtf8("background-color: #f44336; color: white; font-weight: bold;"));

        verticalLayout->addWidget(logoutButton);


        retranslateUi(ProfileWidget);

        QMetaObject::connectSlotsByName(ProfileWidget);
    } // setupUi

    void retranslateUi(QWidget *ProfileWidget)
    {
        label->setText(QCoreApplication::translate("ProfileWidget", "User Profile", nullptr));
        usernameLabel->setText(QCoreApplication::translate("ProfileWidget", "Username: ", nullptr));
        fullNameLabel->setText(QCoreApplication::translate("ProfileWidget", "Full Name: ", nullptr));
        roleLabel->setText(QCoreApplication::translate("ProfileWidget", "Role: ", nullptr));
        changePasswordButton->setText(QCoreApplication::translate("ProfileWidget", "Change Password", nullptr));
        passwordGroup->setTitle(QCoreApplication::translate("ProfileWidget", "Change Password", nullptr));
        label_4->setText(QCoreApplication::translate("ProfileWidget", "New Password:", nullptr));
        label_5->setText(QCoreApplication::translate("ProfileWidget", "Confirm Password:", nullptr));
        savePasswordButton->setText(QCoreApplication::translate("ProfileWidget", "Save Password", nullptr));
        logoutButton->setText(QCoreApplication::translate("ProfileWidget", "Logout", nullptr));
        (void)ProfileWidget;
    } // retranslateUi

};

namespace Ui {
    class ProfileWidget: public Ui_ProfileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWIDGET_H
