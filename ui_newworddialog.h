/********************************************************************************
** Form generated from reading UI file 'newworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWORDDIALOG_H
#define UI_NEWWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewWordDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *txtWord;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *txtPartOfSpeech;
    QLineEdit *txtTranslation;
    QTextEdit *txtEExamples;
    QTextEdit *txtENotes;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnAddWord;
    QPushButton *btnAddAdditional;

    void setupUi(QDialog *NewWordDialog)
    {
        if (NewWordDialog->objectName().isEmpty())
            NewWordDialog->setObjectName("NewWordDialog");
        NewWordDialog->resize(377, 458);
        verticalLayout = new QVBoxLayout(NewWordDialog);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        txtWord = new QLineEdit(NewWordDialog);
        txtWord->setObjectName("txtWord");

        gridLayout->addWidget(txtWord, 0, 1, 1, 1);

        label = new QLabel(NewWordDialog);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 1, 1, 1);

        label_2 = new QLabel(NewWordDialog);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        txtPartOfSpeech = new QLineEdit(NewWordDialog);
        txtPartOfSpeech->setObjectName("txtPartOfSpeech");

        gridLayout->addWidget(txtPartOfSpeech, 2, 1, 1, 1);

        txtTranslation = new QLineEdit(NewWordDialog);
        txtTranslation->setObjectName("txtTranslation");

        gridLayout->addWidget(txtTranslation, 1, 1, 1, 1);

        txtEExamples = new QTextEdit(NewWordDialog);
        txtEExamples->setObjectName("txtEExamples");

        gridLayout->addWidget(txtEExamples, 3, 1, 1, 1);

        txtENotes = new QTextEdit(NewWordDialog);
        txtENotes->setObjectName("txtENotes");

        gridLayout->addWidget(txtENotes, 4, 1, 1, 1);

        label_3 = new QLabel(NewWordDialog);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(NewWordDialog);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(NewWordDialog);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        btnAddWord = new QPushButton(NewWordDialog);
        btnAddWord->setObjectName("btnAddWord");

        horizontalLayout_3->addWidget(btnAddWord);

        btnAddAdditional = new QPushButton(NewWordDialog);
        btnAddAdditional->setObjectName("btnAddAdditional");

        horizontalLayout_3->addWidget(btnAddAdditional);


        gridLayout->addLayout(horizontalLayout_3, 6, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);

        QWidget::setTabOrder(txtWord, txtTranslation);
        QWidget::setTabOrder(txtTranslation, txtPartOfSpeech);
        QWidget::setTabOrder(txtPartOfSpeech, txtEExamples);
        QWidget::setTabOrder(txtEExamples, txtENotes);
        QWidget::setTabOrder(txtENotes, btnAddWord);
        QWidget::setTabOrder(btnAddWord, btnAddAdditional);

        retranslateUi(NewWordDialog);

        QMetaObject::connectSlotsByName(NewWordDialog);
    } // setupUi

    void retranslateUi(QDialog *NewWordDialog)
    {
        NewWordDialog->setWindowTitle(QCoreApplication::translate("NewWordDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NewWordDialog", "Word", nullptr));
        label_2->setText(QCoreApplication::translate("NewWordDialog", "Translation", nullptr));
        label_3->setText(QCoreApplication::translate("NewWordDialog", "Part of Speech", nullptr));
        label_4->setText(QCoreApplication::translate("NewWordDialog", "Examples", nullptr));
        label_5->setText(QCoreApplication::translate("NewWordDialog", "Notes", nullptr));
        btnAddWord->setText(QCoreApplication::translate("NewWordDialog", "Add Word", nullptr));
        btnAddAdditional->setText(QCoreApplication::translate("NewWordDialog", "Add and Add Another", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewWordDialog: public Ui_NewWordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWORDDIALOG_H
