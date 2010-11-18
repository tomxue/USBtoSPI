/********************************************************************************
** Form generated from reading UI file 'usb2spiwindow.ui'
**
** Created: Thu Nov 18 10:04:20 2010
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
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
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
    QPushButton *testButton;
    QSpinBox *spinBox;
    QPushButton *aboutButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *USB2SPIWindow)
    {
        if (USB2SPIWindow->objectName().isEmpty())
            USB2SPIWindow->setObjectName(QString::fromUtf8("USB2SPIWindow"));
        USB2SPIWindow->resize(596, 752);
        centralWidget = new QWidget(USB2SPIWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 77, 141));
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
        infoEdit->setGeometry(QRect(110, 90, 471, 611));
        testButton = new QPushButton(centralWidget);
        testButton->setObjectName(QString::fromUtf8("testButton"));
        testButton->setGeometry(QRect(20, 190, 75, 23));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 220, 71, 22));
        spinBox->setMaximum(1000);
        spinBox->setSingleStep(2);
        spinBox->setValue(58);
        aboutButton = new QPushButton(centralWidget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setGeometry(QRect(20, 270, 75, 23));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(170, 20, 122, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(170, 50, 188, 22));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBox_2 = new QComboBox(widget1);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        horizontalLayout_2->addWidget(comboBox_2);

        USB2SPIWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(USB2SPIWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 596, 18));
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
        testButton->setText(QApplication::translate("USB2SPIWindow", "Test", 0, QApplication::UnicodeUTF8));
        aboutButton->setText(QApplication::translate("USB2SPIWindow", "About", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("USB2SPIWindow", "SPI SCK:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("USB2SPIWindow", "1000kHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("USB2SPIWindow", "100kHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("USB2SPIWindow", "200kHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("USB2SPIWindow", "500kHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("USB2SPIWindow", "2000kHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("USB2SPIWindow", "6000kHz", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("USB2SPIWindow", "SPI Mode:", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("USB2SPIWindow", "CKPHA=1, CKPOL=1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("USB2SPIWindow", "CKPHA=0, CKPOL=0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("USB2SPIWindow", "CKPHA=0, CKPOL=1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("USB2SPIWindow", "CKPHA=1, CKPOL=0", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class USB2SPIWindow: public Ui_USB2SPIWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USB2SPIWINDOW_H
