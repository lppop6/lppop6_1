/********************************************************************************
** Form generated from reading UI file 'SUB_IQA_1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUB_IQA_1_H
#define UI_SUB_IQA_1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow1
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLabel *lbl_Title;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *lbl_Pic1;
    QLabel *lbl_Pic2;
    QLabel *lbl_Pic3;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QPushButton *btn_Rechose;
    QPushButton *btn_chose;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow1)
    {
        if (MainWindow1->objectName().isEmpty())
            MainWindow1->setObjectName(QString::fromUtf8("MainWindow1"));
        MainWindow1->resize(800, 600);
        centralwidget = new QWidget(MainWindow1);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbl_Title = new QLabel(frame_2);
        lbl_Title->setObjectName(QString::fromUtf8("lbl_Title"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        lbl_Title->setFont(font);
        lbl_Title->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(lbl_Title, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame_2, 0, 0, 1, 1);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(10);
        groupBox->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lbl_Pic1 = new QLabel(groupBox);
        lbl_Pic1->setObjectName(QString::fromUtf8("lbl_Pic1"));

        gridLayout_2->addWidget(lbl_Pic1, 0, 0, 1, 1);

        lbl_Pic2 = new QLabel(groupBox);
        lbl_Pic2->setObjectName(QString::fromUtf8("lbl_Pic2"));

        gridLayout_2->addWidget(lbl_Pic2, 0, 1, 1, 1);

        lbl_Pic3 = new QLabel(groupBox);
        lbl_Pic3->setObjectName(QString::fromUtf8("lbl_Pic3"));

        gridLayout_2->addWidget(lbl_Pic3, 0, 2, 1, 1);

        btn_1 = new QPushButton(groupBox);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));

        gridLayout_2->addWidget(btn_1, 1, 0, 1, 1);

        btn_2 = new QPushButton(groupBox);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));

        gridLayout_2->addWidget(btn_2, 1, 1, 1, 1);

        btn_3 = new QPushButton(groupBox);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));

        gridLayout_2->addWidget(btn_3, 1, 2, 1, 1);

        splitter->addWidget(groupBox);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btn_Rechose = new QPushButton(frame);
        btn_Rechose->setObjectName(QString::fromUtf8("btn_Rechose"));

        gridLayout_3->addWidget(btn_Rechose, 0, 0, 1, 1);

        btn_chose = new QPushButton(frame);
        btn_chose->setObjectName(QString::fromUtf8("btn_chose"));

        gridLayout_3->addWidget(btn_chose, 0, 1, 1, 1);

        splitter->addWidget(frame);

        gridLayout_4->addWidget(splitter, 1, 0, 1, 1);

        MainWindow1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow1);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow1->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow1);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow1->setStatusBar(statusbar);

        retranslateUi(MainWindow1);

        QMetaObject::connectSlotsByName(MainWindow1);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow1)
    {
        MainWindow1->setWindowTitle(QApplication::translate("MainWindow1", "MainWindow", nullptr));
        lbl_Title->setText(QApplication::translate("MainWindow1", "\350\257\267\351\200\211\346\213\251\345\233\276\347\211\207\350\264\250\351\207\217\347\233\270\345\220\214\347\232\204\345\233\276\347\211\207\357\274\214\345\217\257\344\273\245\344\270\215\351\200\211\346\210\226\350\200\205\345\205\250\351\200\211", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow1", "Pic_Group", nullptr));
        lbl_Pic1->setText(QApplication::translate("MainWindow1", "1", nullptr));
        lbl_Pic2->setText(QApplication::translate("MainWindow1", "2", nullptr));
        lbl_Pic3->setText(QApplication::translate("MainWindow1", "3", nullptr));
        btn_1->setText(QApplication::translate("MainWindow1", "1", nullptr));
        btn_2->setText(QApplication::translate("MainWindow1", "2", nullptr));
        btn_3->setText(QApplication::translate("MainWindow1", "3", nullptr));
        btn_Rechose->setText(QApplication::translate("MainWindow1", "\351\207\215\351\200\211", nullptr));
        btn_chose->setText(QApplication::translate("MainWindow1", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow1: public Ui_MainWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUB_IQA_1_H
