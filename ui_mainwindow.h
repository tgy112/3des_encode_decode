/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QTextEdit *other_sered;
    QLabel *label_3;
    QTextEdit *other_key;
    QTextEdit *other_id;
    QLabel *label_4;
    QTextEdit *other_date;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *decode;
    QPushButton *encode;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(605, 424);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 571, 111));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 20, 141, 20));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(90, 60, 471, 25));
        textEdit->setMaximumSize(QSize(16777215, 31));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 20, 75, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 20, 54, 12));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 60, 54, 12));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 140, 571, 231));
        other_sered = new QTextEdit(groupBox_2);
        other_sered->setObjectName(QStringLiteral("other_sered"));
        other_sered->setGeometry(QRect(90, 30, 471, 25));
        other_sered->setMaximumSize(QSize(16777215, 31));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 30, 71, 16));
        other_key = new QTextEdit(groupBox_2);
        other_key->setObjectName(QStringLiteral("other_key"));
        other_key->setGeometry(QRect(90, 180, 471, 25));
        other_key->setMaximumSize(QSize(16777215, 31));
        other_id = new QTextEdit(groupBox_2);
        other_id->setObjectName(QStringLiteral("other_id"));
        other_id->setGeometry(QRect(90, 100, 471, 25));
        other_id->setMaximumSize(QSize(16777215, 31));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 100, 81, 20));
        other_date = new QTextEdit(groupBox_2);
        other_date->setObjectName(QStringLiteral("other_date"));
        other_date->setGeometry(QRect(110, 140, 121, 25));
        other_date->setMaximumSize(QSize(16777215, 31));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 140, 91, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 180, 81, 20));
        decode = new QPushButton(groupBox_2);
        decode->setObjectName(QStringLiteral("decode"));
        decode->setGeometry(QRect(340, 60, 75, 23));
        encode = new QPushButton(groupBox_2);
        encode->setObjectName(QStringLiteral("encode"));
        encode->setGeometry(QRect(340, 140, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 605, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "keygen", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\234\254\346\234\272", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "generate", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\275\277\347\224\250\346\234\237\351\231\220\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\272\217\345\210\227\345\217\267\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\233\256\346\240\207\346\234\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\345\267\262\346\234\211\345\272\217\345\210\227\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\346\234\272\346\234\272\345\231\250\347\240\201\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\346\234\272\344\275\277\347\224\250\346\234\237\351\231\220\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\347\233\256\346\240\207\346\234\272\345\272\217\345\210\227\345\217\267\357\274\232", Q_NULLPTR));
        decode->setText(QApplication::translate("MainWindow", "\345\217\215\350\247\243\345\257\206", Q_NULLPTR));
        encode->setText(QApplication::translate("MainWindow", "generate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
