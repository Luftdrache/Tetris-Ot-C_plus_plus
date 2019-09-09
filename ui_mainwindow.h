/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glass.h"
#include "nextfigure.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Start_New_Game;
    QAction *actionExit;
    QAction *action_How_to_play;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    nextFigure *widget;
    QSpacerItem *verticalSpacer_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_2;
    Glass *glass;
    QMenuBar *menuBar;
    QMenu *menu_Game;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1043, 639);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(240, 136, 9, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        action_Start_New_Game = new QAction(MainWindow);
        action_Start_New_Game->setObjectName(QStringLiteral("action_Start_New_Game"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        action_How_to_play = new QAction(MainWindow);
        action_How_to_play->setObjectName(QStringLiteral("action_How_to_play"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 30, 261, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        widget = new nextFigure(verticalLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(200, 250));

        verticalLayout->addWidget(widget);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(700, 30, 311, 521));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        pushButton_2->setFont(font1);

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font1);

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 30));
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        lcdNumber = new QLCDNumber(verticalLayoutWidget_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(50, 70));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(16);
        lcdNumber->setFont(font2);

        verticalLayout_2->addWidget(lcdNumber);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        glass = new Glass(centralWidget);
        glass->setObjectName(QStringLiteral("glass"));
        glass->setGeometry(QRect(300, 30, 381, 521));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        glass->setPalette(palette1);
        glass->setFocusPolicy(Qt::StrongFocus);
        glass->setProperty("rows", QVariant(11u));
        glass->setProperty("cols", QVariant(18u));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1043, 26));
        menu_Game = new QMenu(menuBar);
        menu_Game->setObjectName(QStringLiteral("menu_Game"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_Game->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_Game->addAction(action_Start_New_Game);
        menu_Game->addAction(actionExit);
        menu_Help->addAction(action_How_to_play);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), actionExit, SLOT(trigger()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), action_Start_New_Game, SLOT(trigger()));
        QObject::connect(action_Start_New_Game, SIGNAL(triggered()), glass, SLOT(slotNewGame()));
        QObject::connect(glass, SIGNAL(signalDrawNextFigure(Figure*)), widget, SLOT(slotShowNewFigure(Figure*)));
        QObject::connect(glass, SIGNAL(signalSetScore(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tetris", nullptr));
        action_Start_New_Game->setText(QApplication::translate("MainWindow", "&Start", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Start_New_Game->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_NO_SHORTCUT
        action_How_to_play->setText(QApplication::translate("MainWindow", "&How to play", nullptr));
#ifndef QT_NO_SHORTCUT
        action_How_to_play->setShortcut(QApplication::translate("MainWindow", "F3", nullptr));
#endif // QT_NO_SHORTCUT
        label_2->setText(QApplication::translate("MainWindow", "Next Figure", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "New Game", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QApplication::translate("MainWindow", "Count", nullptr));
        menu_Game->setTitle(QApplication::translate("MainWindow", "&Game", nullptr));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
