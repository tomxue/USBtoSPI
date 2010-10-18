/********************************************************************************
** Form generated from reading UI file 'usb2spiwindow.ui'
**
** Created: Mon Oct 18 14:09:08 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USB2SPIWINDOW_H
#define UI_USB2SPIWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_USB2SPIWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *CloseAllButton;
    QPushButton *openButton;
    QPushButton *fileButton;
    QPushButton *closeButton;
    QTextEdit *infoEdit;
    QTextEdit *dataEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *USB2SPIWindow)
    {
        if (USB2SPIWindow->objectName().isEmpty())
            USB2SPIWindow->setObjectName(QString::fromUtf8("USB2SPIWindow"));
        USB2SPIWindow->resize(599, 554);
        centralWidget = new QWidget(USB2SPIWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 20, 77, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        CloseAllButton = new QPushButton(layoutWidget);
        CloseAllButton->setObjectName(QString::fromUtf8("CloseAllButton"));

        verticalLayout->addWidget(CloseAllButton);

        openButton = new QPushButton(layoutWidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        verticalLayout->addWidget(openButton);

        fileButton = new QPushButton(layoutWidget);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));

        verticalLayout->addWidget(fileButton);

        closeButton = new QPushButton(layoutWidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        verticalLayout->addWidget(closeButton);

        infoEdit = new QTextEdit(centralWidget);
        infoEdit->setObjectName(QString::fromUtf8("infoEdit"));
        infoEdit->setGeometry(QRect(206, 21, 351, 192));
        dataEdit = new QTextEdit(centralWidget);
        dataEdit->setObjectName(QString::fromUtf8("dataEdit"));
        dataEdit->setGeometry(QRect(206, 219, 351, 281));
        USB2SPIWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(USB2SPIWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 599, 18));
        USB2SPIWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(USB2SPIWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        USB2SPIWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(USB2SPIWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        USB2SPIWindow->setStatusBar(statusBar);

        retranslateUi(USB2SPIWindow);

        QMetaObject::connectSlotsByName(USB2SPIWindow);
    } // setupUi

    void retranslateUi(QMainWindow *USB2SPIWindow)
    {
        USB2SPIWindow->setWindowTitle(QApplication::translate("USB2SPIWindow", "USB2SPIWindow", 0, QApplication::UnicodeUTF8));
        CloseAllButton->setText(QApplication::translate("USB2SPIWindow", "Close", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("USB2SPIWindow", "Open Device", 0, QApplication::UnicodeUTF8));
        fileButton->setText(QApplication::translate("USB2SPIWindow", "Write File", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("USB2SPIWindow", "Close Device", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class USB2SPIWindow: public Ui_USB2SPIWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USB2SPIWINDOW_H
