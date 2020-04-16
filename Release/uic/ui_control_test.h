/********************************************************************************
** Form generated from reading UI file 'control_test.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_TEST_H
#define UI_CONTROL_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "labelmap.h"

QT_BEGIN_NAMESPACE

class Ui_control_test
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QSplitter *splitter;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QSlider *sld_Y;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    LabelMap *lbl_Map_Show;
    QSlider *sld_X;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *lbl_Displacement;
    QSpinBox *spb_X;
    QLabel *lbl_Displacement_Relative;
    QSpacerItem *horizontalSpacer_7;
    QDoubleSpinBox *dspn_V;
    QPushButton *btn_Change_V;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lbl_V;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_Reset;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_start;
    QLabel *lbl_Relative_V;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbl_X;
    QLabel *label;
    QLabel *lbl_Y;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spb_Y;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *control_test)
    {
        if (control_test->objectName().isEmpty())
            control_test->setObjectName(QString::fromUtf8("control_test"));
        control_test->resize(810, 759);
        centralwidget = new QWidget(control_test);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(6);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sld_Y = new QSlider(frame_2);
        sld_Y->setObjectName(QString::fromUtf8("sld_Y"));
        sld_Y->setMaximum(100);
        sld_Y->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(sld_Y, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 3, 2);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(27, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 4, 4, 1, 1);

        lbl_Map_Show = new LabelMap(frame_2);
        lbl_Map_Show->setObjectName(QString::fromUtf8("lbl_Map_Show"));
        lbl_Map_Show->setEnabled(true);

        gridLayout_2->addWidget(lbl_Map_Show, 0, 2, 4, 3);

        sld_X = new QSlider(frame_2);
        sld_X->setObjectName(QString::fromUtf8("sld_X"));
        sld_X->setMaximum(100);
        sld_X->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sld_X, 4, 3, 1, 1);

        splitter->addWidget(frame_2);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lbl_Displacement = new QLabel(frame);
        lbl_Displacement->setObjectName(QString::fromUtf8("lbl_Displacement"));

        gridLayout->addWidget(lbl_Displacement, 2, 10, 1, 1);

        spb_X = new QSpinBox(frame);
        spb_X->setObjectName(QString::fromUtf8("spb_X"));
        spb_X->setMaximum(100);

        gridLayout->addWidget(spb_X, 1, 3, 1, 1);

        lbl_Displacement_Relative = new QLabel(frame);
        lbl_Displacement_Relative->setObjectName(QString::fromUtf8("lbl_Displacement_Relative"));

        gridLayout->addWidget(lbl_Displacement_Relative, 2, 11, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 8, 1, 1);

        dspn_V = new QDoubleSpinBox(frame);
        dspn_V->setObjectName(QString::fromUtf8("dspn_V"));

        gridLayout->addWidget(dspn_V, 2, 6, 1, 1);

        btn_Change_V = new QPushButton(frame);
        btn_Change_V->setObjectName(QString::fromUtf8("btn_Change_V"));

        gridLayout->addWidget(btn_Change_V, 1, 5, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 1, 1, 1);

        lbl_V = new QLabel(frame);
        lbl_V->setObjectName(QString::fromUtf8("lbl_V"));

        gridLayout->addWidget(lbl_V, 2, 5, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 4, 1, 1);

        btn_Reset = new QPushButton(frame);
        btn_Reset->setObjectName(QString::fromUtf8("btn_Reset"));

        gridLayout->addWidget(btn_Reset, 2, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 8, 1, 1);

        btn_start = new QPushButton(frame);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));

        gridLayout->addWidget(btn_start, 1, 0, 1, 1);

        lbl_Relative_V = new QLabel(frame);
        lbl_Relative_V->setObjectName(QString::fromUtf8("lbl_Relative_V"));

        gridLayout->addWidget(lbl_Relative_V, 1, 11, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        lbl_X = new QLabel(frame);
        lbl_X->setObjectName(QString::fromUtf8("lbl_X"));

        gridLayout->addWidget(lbl_X, 1, 2, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 10, 1, 1);

        lbl_Y = new QLabel(frame);
        lbl_Y->setObjectName(QString::fromUtf8("lbl_Y"));

        gridLayout->addWidget(lbl_Y, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(171, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 4, 1, 1);

        spb_Y = new QSpinBox(frame);
        spb_Y->setObjectName(QString::fromUtf8("spb_Y"));
        spb_Y->setMaximum(100);

        gridLayout->addWidget(spb_Y, 2, 3, 1, 1);

        splitter->addWidget(frame);

        gridLayout_3->addWidget(splitter, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        control_test->setCentralWidget(centralwidget);
        menubar = new QMenuBar(control_test);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 810, 26));
        control_test->setMenuBar(menubar);
        statusbar = new QStatusBar(control_test);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        control_test->setStatusBar(statusbar);

        retranslateUi(control_test);

        QMetaObject::connectSlotsByName(control_test);
    } // setupUi

    void retranslateUi(QMainWindow *control_test)
    {
        control_test->setWindowTitle(QApplication::translate("control_test", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("control_test", "\350\277\220\345\212\250\346\216\247\345\210\266", nullptr));
        label_2->setText(QString());
        lbl_Map_Show->setText(QApplication::translate("control_test", "TextLabel", nullptr));
        lbl_Displacement->setText(QApplication::translate("control_test", "\347\233\270\345\257\271\344\275\215\347\247\273\357\274\232", nullptr));
        lbl_Displacement_Relative->setText(QApplication::translate("control_test", "0", nullptr));
        btn_Change_V->setText(QApplication::translate("control_test", "\345\234\250\347\272\277\345\217\230\351\200\237", nullptr));
        lbl_V->setText(QApplication::translate("control_test", "  \351\200\237\345\272\246\357\274\232", nullptr));
        btn_Reset->setText(QApplication::translate("control_test", "\345\244\215\344\275\215", nullptr));
        btn_start->setText(QApplication::translate("control_test", "\345\274\200\345\247\213\350\277\220\345\212\250", nullptr));
        lbl_Relative_V->setText(QApplication::translate("control_test", "0", nullptr));
        lbl_X->setText(QApplication::translate("control_test", "X\350\275\264", nullptr));
        label->setText(QApplication::translate("control_test", "\347\233\270\345\257\271\351\200\237\345\272\246\357\274\232", nullptr));
        lbl_Y->setText(QApplication::translate("control_test", "Y\350\275\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class control_test: public Ui_control_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_TEST_H
