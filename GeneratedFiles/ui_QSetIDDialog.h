/********************************************************************************
** Form generated from reading UI file 'QSetIDDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QSETIDDIALOG_H
#define UI_QSETIDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QSetIDDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_accept;
    QPushButton *pushButton_cancel;

    void setupUi(QWidget *QSetIDDialog)
    {
        if (QSetIDDialog->objectName().isEmpty())
            QSetIDDialog->setObjectName(QStringLiteral("QSetIDDialog"));
        QSetIDDialog->resize(321, 41);
        horizontalLayout = new QHBoxLayout(QSetIDDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit = new QLineEdit(QSetIDDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_accept = new QPushButton(QSetIDDialog);
        pushButton_accept->setObjectName(QStringLiteral("pushButton_accept"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_accept->sizePolicy().hasHeightForWidth());
        pushButton_accept->setSizePolicy(sizePolicy);
        pushButton_accept->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(pushButton_accept);

        pushButton_cancel = new QPushButton(QSetIDDialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        sizePolicy.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy);
        pushButton_cancel->setMaximumSize(QSize(30, 16777215));

        horizontalLayout->addWidget(pushButton_cancel);


        retranslateUi(QSetIDDialog);

        QMetaObject::connectSlotsByName(QSetIDDialog);
    } // setupUi

    void retranslateUi(QWidget *QSetIDDialog)
    {
        QSetIDDialog->setWindowTitle(QApplication::translate("QSetIDDialog", "QSetIDDialog", Q_NULLPTR));
        pushButton_accept->setText(QString());
        pushButton_cancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QSetIDDialog: public Ui_QSetIDDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QSETIDDIALOG_H
