/********************************************************************************
** Form generated from reading UI file 'UVProfiler.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef FENETRE_H
#define FENETRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *fNom;
    QLabel *fPrenom;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QListView *fPostBac;
    QListView *fBranche;
    QListView *fFiliere;
    QVBoxLayout *verticalLayout_4;
    QListView *fInscription;
    QListView *listView_5;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(200, 110, 160, 222));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fNom = new QLabel(verticalLayoutWidget);
        fNom->setObjectName(QStringLiteral("fNom"));

        horizontalLayout->addWidget(fNom);

        fPrenom = new QLabel(verticalLayoutWidget);
        fPrenom->setObjectName(QStringLiteral("fPrenom"));

        horizontalLayout->addWidget(fPrenom);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        fPostBac = new QListView(verticalLayoutWidget);
        fPostBac->setObjectName(QStringLiteral("fPostBac"));

        verticalLayout_3->addWidget(fPostBac);

        fBranche = new QListView(verticalLayoutWidget);
        fBranche->setObjectName(QStringLiteral("fBranche"));

        verticalLayout_3->addWidget(fBranche);

        fFiliere = new QListView(verticalLayoutWidget);
        fFiliere->setObjectName(QStringLiteral("fFiliere"));

        verticalLayout_3->addWidget(fFiliere);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        fInscription = new QListView(verticalLayoutWidget);
        fInscription->setObjectName(QStringLiteral("fInscription"));

        verticalLayout_4->addWidget(fInscription);

        listView_5 = new QListView(verticalLayoutWidget);
        listView_5->setObjectName(QStringLiteral("listView_5"));

        verticalLayout_4->addWidget(listView_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_6->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_6->addWidget(pushButton_2);


        verticalLayout_4->addLayout(verticalLayout_6);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        fNom->setText(QApplication::translate("MainWindow", "Nom", 0));
        fPrenom->setText(QApplication::translate("MainWindow", "Prenom", 0));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FENETRE_H
