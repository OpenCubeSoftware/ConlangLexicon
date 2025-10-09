/********************************************************************************
** Form generated from reading UI file 'landingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANDINGWINDOW_H
#define UI_LANDINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LandingWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnNewLexicon;
    QPushButton *btnOpenLexicon;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *listRecentLexicons;

    void setupUi(QDialog *LandingWindow)
    {
        if (LandingWindow->objectName().isEmpty())
            LandingWindow->setObjectName("LandingWindow");
        LandingWindow->resize(388, 346);
        horizontalLayout = new QHBoxLayout(LandingWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        btnNewLexicon = new QPushButton(LandingWindow);
        btnNewLexicon->setObjectName("btnNewLexicon");

        verticalLayout->addWidget(btnNewLexicon);

        btnOpenLexicon = new QPushButton(LandingWindow);
        btnOpenLexicon->setObjectName("btnOpenLexicon");

        verticalLayout->addWidget(btnOpenLexicon);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(LandingWindow);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        listRecentLexicons = new QListWidget(LandingWindow);
        listRecentLexicons->setObjectName("listRecentLexicons");

        verticalLayout_2->addWidget(listRecentLexicons);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(LandingWindow);

        QMetaObject::connectSlotsByName(LandingWindow);
    } // setupUi

    void retranslateUi(QDialog *LandingWindow)
    {
        LandingWindow->setWindowTitle(QCoreApplication::translate("LandingWindow", "Dialog", nullptr));
        btnNewLexicon->setText(QCoreApplication::translate("LandingWindow", "Create New Lexicon", nullptr));
        btnOpenLexicon->setText(QCoreApplication::translate("LandingWindow", "Open Existing Lexicon", nullptr));
        label->setText(QCoreApplication::translate("LandingWindow", "Recent Lexicons:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LandingWindow: public Ui_LandingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANDINGWINDOW_H
