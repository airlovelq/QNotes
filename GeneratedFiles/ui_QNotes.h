/********************************************************************************
** Form generated from reading UI file 'QNotes.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QNOTES_H
#define UI_QNOTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QNotesClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_more;
    QPushButton *pushButton_redo;
    QPushButton *pushButton_add;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_undo;
    QPushButton *pushButton_del;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_maximize;
    QPushButton *pushButton_minimize;
    QPushButton *pushButton_close;
    QLineEdit *lineEdit;
    QListWidget *listWidget_Names;

    void setupUi(QMainWindow *QNotesClass)
    {
        if (QNotesClass->objectName().isEmpty())
            QNotesClass->setObjectName(QStringLiteral("QNotesClass"));
        QNotesClass->resize(866, 544);
        centralWidget = new QWidget(QNotesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 7, 1, 1);

        pushButton_more = new QPushButton(centralWidget);
        pushButton_more->setObjectName(QStringLiteral("pushButton_more"));

        gridLayout->addWidget(pushButton_more, 0, 11, 1, 1);

        pushButton_redo = new QPushButton(centralWidget);
        pushButton_redo->setObjectName(QStringLiteral("pushButton_redo"));

        gridLayout->addWidget(pushButton_redo, 0, 6, 1, 1);

        pushButton_add = new QPushButton(centralWidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        gridLayout->addWidget(pushButton_add, 0, 3, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 1, 3, 1, 9);

        pushButton_undo = new QPushButton(centralWidget);
        pushButton_undo->setObjectName(QStringLiteral("pushButton_undo"));

        gridLayout->addWidget(pushButton_undo, 0, 5, 1, 1);

        pushButton_del = new QPushButton(centralWidget);
        pushButton_del->setObjectName(QStringLiteral("pushButton_del"));

        gridLayout->addWidget(pushButton_del, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        pushButton_maximize = new QPushButton(centralWidget);
        pushButton_maximize->setObjectName(QStringLiteral("pushButton_maximize"));

        gridLayout->addWidget(pushButton_maximize, 0, 9, 1, 1);

        pushButton_minimize = new QPushButton(centralWidget);
        pushButton_minimize->setObjectName(QStringLiteral("pushButton_minimize"));

        gridLayout->addWidget(pushButton_minimize, 0, 8, 1, 1);

        pushButton_close = new QPushButton(centralWidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

        gridLayout->addWidget(pushButton_close, 0, 10, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMaximumSize(QSize(250, 16777215));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 2);

        listWidget_Names = new QListWidget(centralWidget);
        listWidget_Names->setObjectName(QStringLiteral("listWidget_Names"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listWidget_Names->sizePolicy().hasHeightForWidth());
        listWidget_Names->setSizePolicy(sizePolicy1);
        listWidget_Names->setMaximumSize(QSize(250, 16777215));

        gridLayout->addWidget(listWidget_Names, 1, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        QNotesClass->setCentralWidget(centralWidget);

        retranslateUi(QNotesClass);

        QMetaObject::connectSlotsByName(QNotesClass);
    } // setupUi

    void retranslateUi(QMainWindow *QNotesClass)
    {
        QNotesClass->setWindowTitle(QApplication::translate("QNotesClass", "QNotes", Q_NULLPTR));
        pushButton_more->setText(QApplication::translate("QNotesClass", "...", Q_NULLPTR));
        pushButton_redo->setText(QString());
        pushButton_add->setText(QString());
        pushButton_undo->setText(QString());
        pushButton_del->setText(QString());
        pushButton_maximize->setText(QString());
        pushButton_minimize->setText(QString());
        pushButton_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QNotesClass: public Ui_QNotesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QNOTES_H
