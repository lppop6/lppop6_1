/********************************************************************************
** Form generated from reading UI file 'DP.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DP_H
#define UI_DP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DPClass
{
public:
    QAction *actionwen;
    QAction *action1;
    QAction *action3;
    QAction *action2;
    QAction *actionBMP;
    QAction *actionJPG;
    QAction *action4;
    QAction *action;
    QAction *action4_2;
    QAction *action1_2;
    QAction *action2_2;
    QAction *actionip;
    QWidget *centralWidget;
    QGridLayout *gridLayout_8;
    QSplitter *splitter;
    QFrame *frame;
    QGridLayout *gridLayout_7;
    QComboBox *cbx_device;
    QLabel *lbl_show_pic;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QPushButton *btn_open;
    QPushButton *btn_close;
    QPushButton *btn_search;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QPushButton *btn_start_grabing;
    QPushButton *btn_end_grabing;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLabel *lbl_exposure;
    QLineEdit *let_exposure;
    QLabel *lbl_gain;
    QLineEdit *let_gain;
    QPushButton *btn_set_param;
    QPushButton *btn_get_param;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QPushButton *btn_save_BMP;
    QPushButton *btn_save_JPG;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QLabel *lbl_state;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DPClass)
    {
        if (DPClass->objectName().isEmpty())
            DPClass->setObjectName(QString::fromUtf8("DPClass"));
        DPClass->resize(895, 654);
        DPClass->setMouseTracking(false);
        DPClass->setTabletTracking(true);
        actionwen = new QAction(DPClass);
        actionwen->setObjectName(QString::fromUtf8("actionwen"));
        action1 = new QAction(DPClass);
        action1->setObjectName(QString::fromUtf8("action1"));
        action3 = new QAction(DPClass);
        action3->setObjectName(QString::fromUtf8("action3"));
        action2 = new QAction(DPClass);
        action2->setObjectName(QString::fromUtf8("action2"));
        actionBMP = new QAction(DPClass);
        actionBMP->setObjectName(QString::fromUtf8("actionBMP"));
        actionJPG = new QAction(DPClass);
        actionJPG->setObjectName(QString::fromUtf8("actionJPG"));
        action4 = new QAction(DPClass);
        action4->setObjectName(QString::fromUtf8("action4"));
        action = new QAction(DPClass);
        action->setObjectName(QString::fromUtf8("action"));
        action4_2 = new QAction(DPClass);
        action4_2->setObjectName(QString::fromUtf8("action4_2"));
        action1_2 = new QAction(DPClass);
        action1_2->setObjectName(QString::fromUtf8("action1_2"));
        action2_2 = new QAction(DPClass);
        action2_2->setObjectName(QString::fromUtf8("action2_2"));
        actionip = new QAction(DPClass);
        actionip->setObjectName(QString::fromUtf8("actionip"));
        centralWidget = new QWidget(DPClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_8 = new QGridLayout(centralWidget);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMouseTracking(true);
        splitter->setTabletTracking(true);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(true);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        cbx_device = new QComboBox(frame);
        cbx_device->setObjectName(QString::fromUtf8("cbx_device"));

        gridLayout_7->addWidget(cbx_device, 0, 0, 1, 1);

        lbl_show_pic = new QLabel(frame);
        lbl_show_pic->setObjectName(QString::fromUtf8("lbl_show_pic"));

        gridLayout_7->addWidget(lbl_show_pic, 1, 0, 1, 1);

        splitter->addWidget(frame);
        frame_3 = new QFrame(splitter);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btn_open = new QPushButton(groupBox_3);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));

        gridLayout_2->addWidget(btn_open, 1, 0, 1, 1);

        btn_close = new QPushButton(groupBox_3);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));

        gridLayout_2->addWidget(btn_close, 1, 1, 1, 1);

        btn_search = new QPushButton(groupBox_3);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        gridLayout_2->addWidget(btn_search, 0, 0, 1, 2);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(frame_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btn_start_grabing = new QPushButton(groupBox_4);
        btn_start_grabing->setObjectName(QString::fromUtf8("btn_start_grabing"));

        gridLayout_3->addWidget(btn_start_grabing, 0, 0, 1, 1);

        btn_end_grabing = new QPushButton(groupBox_4);
        btn_end_grabing->setObjectName(QString::fromUtf8("btn_end_grabing"));

        gridLayout_3->addWidget(btn_end_grabing, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox_4, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        lbl_exposure = new QLabel(groupBox_2);
        lbl_exposure->setObjectName(QString::fromUtf8("lbl_exposure"));
        lbl_exposure->setLayoutDirection(Qt::LeftToRight);

        gridLayout_5->addWidget(lbl_exposure, 0, 0, 1, 1);

        let_exposure = new QLineEdit(groupBox_2);
        let_exposure->setObjectName(QString::fromUtf8("let_exposure"));

        gridLayout_5->addWidget(let_exposure, 0, 1, 1, 1);

        lbl_gain = new QLabel(groupBox_2);
        lbl_gain->setObjectName(QString::fromUtf8("lbl_gain"));

        gridLayout_5->addWidget(lbl_gain, 1, 0, 1, 1);

        let_gain = new QLineEdit(groupBox_2);
        let_gain->setObjectName(QString::fromUtf8("let_gain"));

        gridLayout_5->addWidget(let_gain, 1, 1, 1, 1);

        btn_set_param = new QPushButton(groupBox_2);
        btn_set_param->setObjectName(QString::fromUtf8("btn_set_param"));

        gridLayout_5->addWidget(btn_set_param, 2, 0, 1, 2);

        btn_get_param = new QPushButton(groupBox_2);
        btn_get_param->setObjectName(QString::fromUtf8("btn_get_param"));

        gridLayout_5->addWidget(btn_get_param, 3, 0, 1, 2);


        gridLayout->addWidget(groupBox_2, 5, 0, 1, 1);

        groupBox = new QGroupBox(frame_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        btn_save_BMP = new QPushButton(groupBox);
        btn_save_BMP->setObjectName(QString::fromUtf8("btn_save_BMP"));

        gridLayout_4->addWidget(btn_save_BMP, 0, 0, 1, 1);

        btn_save_JPG = new QPushButton(groupBox);
        btn_save_JPG->setObjectName(QString::fromUtf8("btn_save_JPG"));

        gridLayout_4->addWidget(btn_save_JPG, 0, 1, 1, 1);


        gridLayout->addWidget(groupBox, 4, 0, 1, 1);

        groupBox_5 = new QGroupBox(frame_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        lbl_state = new QLabel(groupBox_5);
        lbl_state->setObjectName(QString::fromUtf8("lbl_state"));

        gridLayout_6->addWidget(lbl_state, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_5, 1, 0, 1, 1);

        splitter->addWidget(frame_3);

        gridLayout_8->addWidget(splitter, 0, 0, 1, 1);

        DPClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DPClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 895, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        DPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DPClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DPClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DPClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DPClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addSeparator();
        menu->addAction(action1);
        menu->addAction(action2);
        menu->addAction(action3);
        menu->addAction(menu_2->menuAction());
        menu->addAction(actionip);
        menu_2->addAction(actionBMP);
        menu_2->addAction(actionJPG);

        retranslateUi(DPClass);

        QMetaObject::connectSlotsByName(DPClass);
    } // setupUi

    void retranslateUi(QMainWindow *DPClass)
    {
        DPClass->setWindowTitle(QApplication::translate("DPClass", "DP", nullptr));
        actionwen->setText(QApplication::translate("DPClass", "wen", nullptr));
        action1->setText(QApplication::translate("DPClass", "\350\277\220\345\212\250\346\216\247\345\210\266", nullptr));
        action3->setText(QApplication::translate("DPClass", "FR_IQA", nullptr));
        action2->setText(QApplication::translate("DPClass", "\344\270\273\350\247\202\350\257\204\344\273\267", nullptr));
        actionBMP->setText(QApplication::translate("DPClass", "BMP", nullptr));
        actionJPG->setText(QApplication::translate("DPClass", "JPG", nullptr));
        action4->setText(QApplication::translate("DPClass", "\350\256\276\347\275\256ip\345\234\260\345\235\200", nullptr));
        action->setText(QApplication::translate("DPClass", "\350\256\276\347\275\256\347\233\270\346\234\272IP", nullptr));
        action4_2->setText(QApplication::translate("DPClass", "4", nullptr));
        action1_2->setText(QApplication::translate("DPClass", "\347\224\265\346\234\272", nullptr));
        action2_2->setText(QApplication::translate("DPClass", "\347\233\270\346\234\272", nullptr));
        actionip->setText(QApplication::translate("DPClass", "\350\256\276\347\275\256IP", nullptr));
        lbl_show_pic->setText(QApplication::translate("DPClass", "\346\227\240", nullptr));
        groupBox_3->setTitle(QApplication::translate("DPClass", "\345\210\235\345\247\213\345\214\226", nullptr));
        btn_open->setText(QApplication::translate("DPClass", "\346\211\223\345\274\200\350\256\276\345\244\207", nullptr));
        btn_close->setText(QApplication::translate("DPClass", "\345\205\263\351\227\255\350\256\276\345\244\207", nullptr));
        btn_search->setText(QApplication::translate("DPClass", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        groupBox_4->setTitle(QApplication::translate("DPClass", "\345\233\276\345\203\217\351\207\207\351\233\206", nullptr));
        btn_start_grabing->setText(QApplication::translate("DPClass", "\345\274\200\345\247\213\351\207\207\351\233\206", nullptr));
        btn_end_grabing->setText(QApplication::translate("DPClass", "\347\273\223\346\235\237\351\207\207\351\233\206", nullptr));
        groupBox_2->setTitle(QApplication::translate("DPClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        lbl_exposure->setText(QApplication::translate("DPClass", " \346\233\235\345\205\211", nullptr));
        lbl_gain->setText(QApplication::translate("DPClass", " \345\242\236\347\233\212", nullptr));
        btn_set_param->setText(QApplication::translate("DPClass", "\350\256\276\347\275\256\345\217\202\346\225\260", nullptr));
        btn_get_param->setText(QApplication::translate("DPClass", "\350\216\267\345\217\226\345\217\202\346\225\260", nullptr));
        groupBox->setTitle(QApplication::translate("DPClass", "\345\233\276\347\211\207\344\277\235\345\255\230", nullptr));
        btn_save_BMP->setText(QApplication::translate("DPClass", "\344\277\235\345\255\230BMP", nullptr));
        btn_save_JPG->setText(QApplication::translate("DPClass", "\344\277\235\345\255\230JPG", nullptr));
        groupBox_5->setTitle(QApplication::translate("DPClass", "\347\233\270\346\234\272\347\212\266\346\200\201", nullptr));
        lbl_state->setText(QApplication::translate("DPClass", "\346\227\240", nullptr));
        menu->setTitle(QApplication::translate("DPClass", "\345\272\224\347\224\250", nullptr));
        menu_2->setTitle(QApplication::translate("DPClass", "\346\237\245\347\234\213\344\277\235\345\255\230\347\232\204\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DPClass: public Ui_DPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DP_H
