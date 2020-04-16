/********************************************************************************
** Form generated from reading UI file 'SUB_IQA_2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUB_IQA_2_H
#define UI_SUB_IQA_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QLabel *lbl_Pic;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *lbl_Analy;
    QRadioButton *rdb_5;
    QRadioButton *rdb_4;
    QRadioButton *rdb_3;
    QRadioButton *rdb_2;
    QRadioButton *rdb_1;
    QPushButton *btn_Submit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 599);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lbl_Pic = new QLabel(frame);
        lbl_Pic->setObjectName(QString::fromUtf8("lbl_Pic"));
        lbl_Pic->setFrameShape(QFrame::Box);

        gridLayout_3->addWidget(lbl_Pic, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lbl_Analy = new QLabel(groupBox);
        lbl_Analy->setObjectName(QString::fromUtf8("lbl_Analy"));
        lbl_Analy->setFocusPolicy(Qt::NoFocus);
        lbl_Analy->setFrameShape(QFrame::NoFrame);

        gridLayout_2->addWidget(lbl_Analy, 0, 0, 1, 1);

        rdb_5 = new QRadioButton(groupBox);
        rdb_5->setObjectName(QString::fromUtf8("rdb_5"));

        gridLayout_2->addWidget(rdb_5, 1, 0, 1, 1);

        rdb_4 = new QRadioButton(groupBox);
        rdb_4->setObjectName(QString::fromUtf8("rdb_4"));

        gridLayout_2->addWidget(rdb_4, 2, 0, 1, 1);

        rdb_3 = new QRadioButton(groupBox);
        rdb_3->setObjectName(QString::fromUtf8("rdb_3"));

        gridLayout_2->addWidget(rdb_3, 3, 0, 1, 1);

        rdb_2 = new QRadioButton(groupBox);
        rdb_2->setObjectName(QString::fromUtf8("rdb_2"));

        gridLayout_2->addWidget(rdb_2, 4, 0, 1, 1);

        rdb_1 = new QRadioButton(groupBox);
        rdb_1->setObjectName(QString::fromUtf8("rdb_1"));

        gridLayout_2->addWidget(rdb_1, 5, 0, 1, 1);

        btn_Submit = new QPushButton(groupBox);
        btn_Submit->setObjectName(QString::fromUtf8("btn_Submit"));

        gridLayout_2->addWidget(btn_Submit, 6, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        lbl_Pic->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\345\233\276\345\203\217\350\264\250\351\207\217\346\265\213\350\257\204", nullptr));
        lbl_Analy->setText(QApplication::translate("MainWindow", "\350\257\267\345\257\271\345\267\246\345\233\276\350\277\233\350\241\214\345\233\276\345\203\217\350\264\250\351\207\217\347\232\204\344\270\273\350\247\202\345\210\206\346\236\220", nullptr));
        rdb_5->setText(QApplication::translate("MainWindow", "\344\270\235\346\257\253\347\234\213\344\270\215\345\207\272\345\233\276\345\203\217\350\264\250\351\207\217\345\217\230\345\235\217", nullptr));
        rdb_4->setText(QApplication::translate("MainWindow", "\350\203\275\347\234\213\345\207\272\350\264\250\351\207\217\346\234\211\351\227\256\351\242\230\357\274\214\344\275\206\344\270\215\345\246\250\347\242\215\350\247\202\347\234\213", nullptr));
        rdb_3->setText(QApplication::translate("MainWindow", "\346\270\205\346\245\232\347\232\204\347\234\213\345\207\272\350\264\250\351\207\217\346\234\211\351\227\256\351\242\230\357\274\214\345\257\271\350\247\202\347\234\213\347\250\215\346\234\211\345\246\250\347\242\215", nullptr));
        rdb_2->setText(QApplication::translate("MainWindow", "\345\257\271\350\247\202\347\234\213\346\234\211\345\246\250\347\242\215", nullptr));
        rdb_1->setText(QApplication::translate("MainWindow", "\351\235\236\345\270\270\344\270\245\351\207\215\347\232\204\345\246\250\347\242\215\350\247\202\347\234\213", nullptr));
        btn_Submit->setText(QApplication::translate("MainWindow", "\346\217\220\344\272\244\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUB_IQA_2_H
