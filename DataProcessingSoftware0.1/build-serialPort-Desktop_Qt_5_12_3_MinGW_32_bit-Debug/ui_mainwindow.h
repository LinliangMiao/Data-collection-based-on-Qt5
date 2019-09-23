/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_3;
    QPushButton *closeSerial;
    QPushButton *openSerial;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *portName;
    QLabel *label_4;
    QComboBox *baudRate;
    QLabel *label_5;
    QComboBox *dataBits;
    QLabel *label_6;
    QComboBox *parityCom;
    QLabel *label_7;
    QComboBox *stopBit;
    QLabel *label_8;
    QComboBox *flowType;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *filetrans_select;
    QLineEdit *filetrans_select_display;
    QPushButton *dir_datasave_select;
    QLineEdit *dir_datasave_select_display;
    QPushButton *filetrans_start;
    QProgressBar *filetrans_progressBar;
    QGroupBox *groupBox_5;
    QLineEdit *magnetism2all_display;
    QLineEdit *acc_y_display;
    QLineEdit *magnetism2x_display;
    QLineEdit *magnetism1all_display;
    QLabel *acc_z;
    QLabel *timerec;
    QLabel *pump01;
    QLineEdit *height_display;
    QLineEdit *acc_z_display;
    QLabel *magnetism2all;
    QLabel *latitude;
    QLineEdit *roll_display;
    QLabel *acc_x;
    QLineEdit *magnetism1z_display;
    QLabel *magnetism1y;
    QLabel *pos_status;
    QLabel *magnetism1all;
    QLabel *magnetism2x;
    QLabel *yaw;
    QLabel *magnetism2y;
    QLabel *acc_y;
    QLineEdit *magnetism2z_display;
    QLabel *pitch;
    QLabel *longitude;
    QLineEdit *pitch_display;
    QLineEdit *acc_x_display;
    QLabel *height;
    QLineEdit *pos_status_display;
    QLineEdit *pump_display;
    QLineEdit *timerec_display;
    QLabel *roll;
    QLineEdit *longti_display;
    QLabel *magnetism1z;
    QLabel *ins_status;
    QLineEdit *magnetism1y_display;
    QLineEdit *magnetism2y_display;
    QLineEdit *ins_status_display;
    QLabel *magnetism2z;
    QLineEdit *yaw_display;
    QLineEdit *lati_display;
    QLineEdit *magnetism1x_display;
    QLabel *magnetism1x;
    QLabel *acc_status;
    QLineEdit *acc_status_display;
    QLineEdit *risefall_display;
    QLabel *risefall;
    QLabel *MCU_status;
    QLineEdit *MCUsave_status_display;
    QGroupBox *groupBox_6;
    QPushButton *UDPshutdown;
    QPushButton *UDPconnect;
    QRadioButton *UDPsendButton;
    QRadioButton *UDPrecvButton;
    QLabel *multicastIP;
    QLineEdit *multicastIPlineedit;
    QLabel *localport;
    QLineEdit *localportlineedit;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QCheckBox *fluxgate1y;
    QCheckBox *fluxgate2z;
    QCheckBox *pump1;
    QCheckBox *fluxgate2all;
    QCheckBox *fluxgate1x;
    QCheckBox *fluxgate2x;
    QCheckBox *fluxgate2y;
    QCheckBox *fluxgate1z;
    QCheckBox *pump2;
    QCheckBox *fluxgate1all;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 700);
        MainWindow->setMinimumSize(QSize(718, 450));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png/soft.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAnimated(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 3, 151, 211));
        closeSerial = new QPushButton(groupBox_3);
        closeSerial->setObjectName(QString::fromUtf8("closeSerial"));
        closeSerial->setGeometry(QRect(80, 180, 61, 23));
        openSerial = new QPushButton(groupBox_3);
        openSerial->setObjectName(QString::fromUtf8("openSerial"));
        openSerial->setGeometry(QRect(10, 180, 61, 23));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 125, 152));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        portName = new QComboBox(layoutWidget);
        portName->setObjectName(QString::fromUtf8("portName"));

        gridLayout->addWidget(portName, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        baudRate = new QComboBox(layoutWidget);
        baudRate->setObjectName(QString::fromUtf8("baudRate"));

        gridLayout->addWidget(baudRate, 1, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        dataBits = new QComboBox(layoutWidget);
        dataBits->setObjectName(QString::fromUtf8("dataBits"));

        gridLayout->addWidget(dataBits, 2, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        parityCom = new QComboBox(layoutWidget);
        parityCom->setObjectName(QString::fromUtf8("parityCom"));

        gridLayout->addWidget(parityCom, 3, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        stopBit = new QComboBox(layoutWidget);
        stopBit->setObjectName(QString::fromUtf8("stopBit"));

        gridLayout->addWidget(stopBit, 4, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        flowType = new QComboBox(layoutWidget);
        flowType->setObjectName(QString::fromUtf8("flowType"));

        gridLayout->addWidget(flowType, 5, 1, 1, 1);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(180, 0, 1011, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 496, 171, 185));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        filetrans_select = new QPushButton(groupBox_4);
        filetrans_select->setObjectName(QString::fromUtf8("filetrans_select"));

        verticalLayout_2->addWidget(filetrans_select);

        filetrans_select_display = new QLineEdit(groupBox_4);
        filetrans_select_display->setObjectName(QString::fromUtf8("filetrans_select_display"));

        verticalLayout_2->addWidget(filetrans_select_display);

        dir_datasave_select = new QPushButton(groupBox_4);
        dir_datasave_select->setObjectName(QString::fromUtf8("dir_datasave_select"));

        verticalLayout_2->addWidget(dir_datasave_select);

        dir_datasave_select_display = new QLineEdit(groupBox_4);
        dir_datasave_select_display->setObjectName(QString::fromUtf8("dir_datasave_select_display"));

        verticalLayout_2->addWidget(dir_datasave_select_display);

        filetrans_start = new QPushButton(groupBox_4);
        filetrans_start->setObjectName(QString::fromUtf8("filetrans_start"));

        verticalLayout_2->addWidget(filetrans_start);

        filetrans_progressBar = new QProgressBar(groupBox_4);
        filetrans_progressBar->setObjectName(QString::fromUtf8("filetrans_progressBar"));
        filetrans_progressBar->setAcceptDrops(false);
        filetrans_progressBar->setToolTipDuration(-1);
        filetrans_progressBar->setValue(0);
        filetrans_progressBar->setOrientation(Qt::Horizontal);
        filetrans_progressBar->setInvertedAppearance(false);

        verticalLayout_2->addWidget(filetrans_progressBar);


        verticalLayout_3->addLayout(verticalLayout_2);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(180, 570, 1001, 111));
        magnetism2all_display = new QLineEdit(groupBox_5);
        magnetism2all_display->setObjectName(QString::fromUtf8("magnetism2all_display"));
        magnetism2all_display->setGeometry(QRect(700, 80, 71, 20));
        acc_y_display = new QLineEdit(groupBox_5);
        acc_y_display->setObjectName(QString::fromUtf8("acc_y_display"));
        acc_y_display->setGeometry(QRect(830, 40, 101, 20));
        magnetism2x_display = new QLineEdit(groupBox_5);
        magnetism2x_display->setObjectName(QString::fromUtf8("magnetism2x_display"));
        magnetism2x_display->setGeometry(QRect(700, 20, 71, 20));
        magnetism1all_display = new QLineEdit(groupBox_5);
        magnetism1all_display->setObjectName(QString::fromUtf8("magnetism1all_display"));
        magnetism1all_display->setGeometry(QRect(550, 80, 71, 20));
        acc_z = new QLabel(groupBox_5);
        acc_z->setObjectName(QString::fromUtf8("acc_z"));
        acc_z->setGeometry(QRect(782, 61, 36, 16));
        timerec = new QLabel(groupBox_5);
        timerec->setObjectName(QString::fromUtf8("timerec"));
        timerec->setGeometry(QRect(16, 21, 36, 16));
        pump01 = new QLabel(groupBox_5);
        pump01->setObjectName(QString::fromUtf8("pump01"));
        pump01->setGeometry(QRect(340, 81, 42, 16));
        height_display = new QLineEdit(groupBox_5);
        height_display->setObjectName(QString::fromUtf8("height_display"));
        height_display->setGeometry(QRect(230, 60, 100, 20));
        acc_z_display = new QLineEdit(groupBox_5);
        acc_z_display->setObjectName(QString::fromUtf8("acc_z_display"));
        acc_z_display->setGeometry(QRect(830, 60, 101, 20));
        magnetism2all = new QLabel(groupBox_5);
        magnetism2all->setObjectName(QString::fromUtf8("magnetism2all"));
        magnetism2all->setGeometry(QRect(632, 81, 61, 16));
        latitude = new QLabel(groupBox_5);
        latitude->setObjectName(QString::fromUtf8("latitude"));
        latitude->setGeometry(QRect(190, 42, 36, 16));
        roll_display = new QLineEdit(groupBox_5);
        roll_display->setObjectName(QString::fromUtf8("roll_display"));
        roll_display->setGeometry(QRect(380, 40, 91, 20));
        acc_x = new QLabel(groupBox_5);
        acc_x->setObjectName(QString::fromUtf8("acc_x"));
        acc_x->setGeometry(QRect(782, 22, 36, 16));
        magnetism1z_display = new QLineEdit(groupBox_5);
        magnetism1z_display->setObjectName(QString::fromUtf8("magnetism1z_display"));
        magnetism1z_display->setGeometry(QRect(550, 60, 71, 20));
        magnetism1y = new QLabel(groupBox_5);
        magnetism1y->setObjectName(QString::fromUtf8("magnetism1y"));
        magnetism1y->setGeometry(QRect(482, 42, 60, 16));
        pos_status = new QLabel(groupBox_5);
        pos_status->setObjectName(QString::fromUtf8("pos_status"));
        pos_status->setGeometry(QRect(14, 61, 60, 16));
        magnetism1all = new QLabel(groupBox_5);
        magnetism1all->setObjectName(QString::fromUtf8("magnetism1all"));
        magnetism1all->setGeometry(QRect(482, 81, 61, 16));
        magnetism2x = new QLabel(groupBox_5);
        magnetism2x->setObjectName(QString::fromUtf8("magnetism2x"));
        magnetism2x->setGeometry(QRect(632, 22, 60, 16));
        yaw = new QLabel(groupBox_5);
        yaw->setObjectName(QString::fromUtf8("yaw"));
        yaw->setGeometry(QRect(340, 61, 36, 16));
        magnetism2y = new QLabel(groupBox_5);
        magnetism2y->setObjectName(QString::fromUtf8("magnetism2y"));
        magnetism2y->setGeometry(QRect(632, 43, 60, 16));
        acc_y = new QLabel(groupBox_5);
        acc_y->setObjectName(QString::fromUtf8("acc_y"));
        acc_y->setGeometry(QRect(782, 42, 36, 16));
        magnetism2z_display = new QLineEdit(groupBox_5);
        magnetism2z_display->setObjectName(QString::fromUtf8("magnetism2z_display"));
        magnetism2z_display->setGeometry(QRect(700, 60, 71, 20));
        pitch = new QLabel(groupBox_5);
        pitch->setObjectName(QString::fromUtf8("pitch"));
        pitch->setGeometry(QRect(340, 22, 36, 16));
        longitude = new QLabel(groupBox_5);
        longitude->setObjectName(QString::fromUtf8("longitude"));
        longitude->setGeometry(QRect(190, 22, 36, 16));
        pitch_display = new QLineEdit(groupBox_5);
        pitch_display->setObjectName(QString::fromUtf8("pitch_display"));
        pitch_display->setGeometry(QRect(380, 20, 91, 20));
        acc_x_display = new QLineEdit(groupBox_5);
        acc_x_display->setObjectName(QString::fromUtf8("acc_x_display"));
        acc_x_display->setGeometry(QRect(830, 20, 101, 20));
        height = new QLabel(groupBox_5);
        height->setObjectName(QString::fromUtf8("height"));
        height->setGeometry(QRect(190, 61, 36, 16));
        pos_status_display = new QLineEdit(groupBox_5);
        pos_status_display->setObjectName(QString::fromUtf8("pos_status_display"));
        pos_status_display->setGeometry(QRect(70, 60, 108, 20));
        pump_display = new QLineEdit(groupBox_5);
        pump_display->setObjectName(QString::fromUtf8("pump_display"));
        pump_display->setGeometry(QRect(380, 80, 91, 20));
        timerec_display = new QLineEdit(groupBox_5);
        timerec_display->setObjectName(QString::fromUtf8("timerec_display"));
        timerec_display->setGeometry(QRect(70, 20, 108, 20));
        roll = new QLabel(groupBox_5);
        roll->setObjectName(QString::fromUtf8("roll"));
        roll->setGeometry(QRect(340, 42, 36, 16));
        longti_display = new QLineEdit(groupBox_5);
        longti_display->setObjectName(QString::fromUtf8("longti_display"));
        longti_display->setGeometry(QRect(230, 20, 100, 20));
        magnetism1z = new QLabel(groupBox_5);
        magnetism1z->setObjectName(QString::fromUtf8("magnetism1z"));
        magnetism1z->setGeometry(QRect(482, 61, 60, 16));
        ins_status = new QLabel(groupBox_5);
        ins_status->setObjectName(QString::fromUtf8("ins_status"));
        ins_status->setGeometry(QRect(14, 40, 60, 16));
        magnetism1y_display = new QLineEdit(groupBox_5);
        magnetism1y_display->setObjectName(QString::fromUtf8("magnetism1y_display"));
        magnetism1y_display->setGeometry(QRect(550, 40, 71, 20));
        magnetism2y_display = new QLineEdit(groupBox_5);
        magnetism2y_display->setObjectName(QString::fromUtf8("magnetism2y_display"));
        magnetism2y_display->setGeometry(QRect(700, 40, 71, 20));
        ins_status_display = new QLineEdit(groupBox_5);
        ins_status_display->setObjectName(QString::fromUtf8("ins_status_display"));
        ins_status_display->setGeometry(QRect(70, 40, 108, 20));
        magnetism2z = new QLabel(groupBox_5);
        magnetism2z->setObjectName(QString::fromUtf8("magnetism2z"));
        magnetism2z->setGeometry(QRect(632, 62, 60, 16));
        yaw_display = new QLineEdit(groupBox_5);
        yaw_display->setObjectName(QString::fromUtf8("yaw_display"));
        yaw_display->setGeometry(QRect(380, 60, 91, 20));
        lati_display = new QLineEdit(groupBox_5);
        lati_display->setObjectName(QString::fromUtf8("lati_display"));
        lati_display->setGeometry(QRect(230, 40, 100, 20));
        magnetism1x_display = new QLineEdit(groupBox_5);
        magnetism1x_display->setObjectName(QString::fromUtf8("magnetism1x_display"));
        magnetism1x_display->setGeometry(QRect(550, 20, 71, 20));
        magnetism1x = new QLabel(groupBox_5);
        magnetism1x->setObjectName(QString::fromUtf8("magnetism1x"));
        magnetism1x->setGeometry(QRect(482, 22, 60, 16));
        acc_status = new QLabel(groupBox_5);
        acc_status->setObjectName(QString::fromUtf8("acc_status"));
        acc_status->setGeometry(QRect(13, 81, 61, 16));
        acc_status_display = new QLineEdit(groupBox_5);
        acc_status_display->setObjectName(QString::fromUtf8("acc_status_display"));
        acc_status_display->setGeometry(QRect(70, 80, 108, 20));
        risefall_display = new QLineEdit(groupBox_5);
        risefall_display->setObjectName(QString::fromUtf8("risefall_display"));
        risefall_display->setGeometry(QRect(230, 80, 100, 20));
        risefall = new QLabel(groupBox_5);
        risefall->setObjectName(QString::fromUtf8("risefall"));
        risefall->setGeometry(QRect(190, 80, 36, 16));
        MCU_status = new QLabel(groupBox_5);
        MCU_status->setObjectName(QString::fromUtf8("MCU_status"));
        MCU_status->setGeometry(QRect(783, 81, 36, 16));
        MCUsave_status_display = new QLineEdit(groupBox_5);
        MCUsave_status_display->setObjectName(QString::fromUtf8("MCUsave_status_display"));
        MCUsave_status_display->setGeometry(QRect(830, 80, 101, 20));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 215, 171, 121));
        UDPshutdown = new QPushButton(groupBox_6);
        UDPshutdown->setObjectName(QString::fromUtf8("UDPshutdown"));
        UDPshutdown->setGeometry(QRect(82, 95, 61, 23));
        UDPconnect = new QPushButton(groupBox_6);
        UDPconnect->setObjectName(QString::fromUtf8("UDPconnect"));
        UDPconnect->setGeometry(QRect(10, 95, 61, 23));
        UDPsendButton = new QRadioButton(groupBox_6);
        UDPsendButton->setObjectName(QString::fromUtf8("UDPsendButton"));
        UDPsendButton->setGeometry(QRect(10, 20, 51, 16));
        UDPrecvButton = new QRadioButton(groupBox_6);
        UDPrecvButton->setObjectName(QString::fromUtf8("UDPrecvButton"));
        UDPrecvButton->setGeometry(QRect(80, 20, 51, 16));
        UDPrecvButton->setChecked(true);
        multicastIP = new QLabel(groupBox_6);
        multicastIP->setObjectName(QString::fromUtf8("multicastIP"));
        multicastIP->setGeometry(QRect(10, 43, 48, 16));
        multicastIPlineedit = new QLineEdit(groupBox_6);
        multicastIPlineedit->setObjectName(QString::fromUtf8("multicastIPlineedit"));
        multicastIPlineedit->setGeometry(QRect(67, 43, 95, 20));
        localport = new QLabel(groupBox_6);
        localport->setObjectName(QString::fromUtf8("localport"));
        localport->setGeometry(QRect(10, 70, 60, 16));
        localportlineedit = new QLineEdit(groupBox_6);
        localportlineedit->setObjectName(QString::fromUtf8("localportlineedit"));
        localportlineedit->setGeometry(QRect(67, 70, 95, 20));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 342, 181, 151));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 171, 128));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        fluxgate1y = new QCheckBox(layoutWidget1);
        fluxgate1y->setObjectName(QString::fromUtf8("fluxgate1y"));

        gridLayout_2->addWidget(fluxgate1y, 0, 1, 1, 1);

        fluxgate2z = new QCheckBox(layoutWidget1);
        fluxgate2z->setObjectName(QString::fromUtf8("fluxgate2z"));

        gridLayout_2->addWidget(fluxgate2z, 3, 0, 1, 1);

        pump1 = new QCheckBox(layoutWidget1);
        pump1->setObjectName(QString::fromUtf8("pump1"));

        gridLayout_2->addWidget(pump1, 4, 0, 1, 1);

        fluxgate2all = new QCheckBox(layoutWidget1);
        fluxgate2all->setObjectName(QString::fromUtf8("fluxgate2all"));

        gridLayout_2->addWidget(fluxgate2all, 3, 1, 1, 1);

        fluxgate1x = new QCheckBox(layoutWidget1);
        fluxgate1x->setObjectName(QString::fromUtf8("fluxgate1x"));

        gridLayout_2->addWidget(fluxgate1x, 0, 0, 1, 1);

        fluxgate2x = new QCheckBox(layoutWidget1);
        fluxgate2x->setObjectName(QString::fromUtf8("fluxgate2x"));

        gridLayout_2->addWidget(fluxgate2x, 2, 0, 1, 1);

        fluxgate2y = new QCheckBox(layoutWidget1);
        fluxgate2y->setObjectName(QString::fromUtf8("fluxgate2y"));

        gridLayout_2->addWidget(fluxgate2y, 2, 1, 1, 1);

        fluxgate1z = new QCheckBox(layoutWidget1);
        fluxgate1z->setObjectName(QString::fromUtf8("fluxgate1z"));

        gridLayout_2->addWidget(fluxgate1z, 1, 0, 1, 1);

        pump2 = new QCheckBox(layoutWidget1);
        pump2->setObjectName(QString::fromUtf8("pump2"));

        gridLayout_2->addWidget(pump2, 4, 1, 1, 1);

        fluxgate1all = new QCheckBox(layoutWidget1);
        fluxgate1all->setObjectName(QString::fromUtf8("fluxgate1all"));

        gridLayout_2->addWidget(fluxgate1all, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        groupBox->raise();
        groupBox_3->raise();
        verticalLayoutWidget->raise();
        groupBox_4->raise();
        groupBox_5->raise();
        groupBox_6->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        closeSerial->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\344\270\262\345\217\243", nullptr));
        openSerial->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\344\270\262\350\241\214\345\217\243\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\265\201\357\274\232", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\217\220\345\217\226", nullptr));
        filetrans_select->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\225\260\346\215\256\350\256\260\345\275\225\346\226\207\344\273\266", nullptr));
        dir_datasave_select->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\225\260\346\215\256\345\257\274\345\207\272\347\233\256\345\275\225", nullptr));
        filetrans_start->setText(QApplication::translate("MainWindow", "\346\217\220\345\217\226\346\225\260\346\215\256", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\345\256\236\346\227\266\346\225\260\346\215\256", nullptr));
        magnetism2x_display->setText(QString());
        acc_z->setText(QApplication::translate("MainWindow", "\345\212\240\350\256\241Z\357\274\232", nullptr));
        timerec->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", nullptr));
        pump01->setText(QApplication::translate("MainWindow", "\345\205\211\346\263\265\357\274\232", nullptr));
        magnetism2all->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2502A\357\274\232", nullptr));
        latitude->setText(QApplication::translate("MainWindow", "\347\272\254\345\272\246\357\274\232", nullptr));
        acc_x->setText(QApplication::translate("MainWindow", "\345\212\240\350\256\241X\357\274\232", nullptr));
        magnetism1y->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2501Y\357\274\232", nullptr));
        pos_status->setText(QApplication::translate("MainWindow", "\345\256\232\344\275\215\347\212\266\346\200\201\357\274\232", nullptr));
        magnetism1all->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2501A\357\274\232", nullptr));
        magnetism2x->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2502X\357\274\232", nullptr));
        yaw->setText(QApplication::translate("MainWindow", "\350\210\252\345\220\221\357\274\232", nullptr));
        magnetism2y->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2502Y\357\274\232", nullptr));
        acc_y->setText(QApplication::translate("MainWindow", "\345\212\240\350\256\241Y\357\274\232", nullptr));
        magnetism2z_display->setText(QString());
        pitch->setText(QApplication::translate("MainWindow", "\344\277\257\344\273\260\357\274\232", nullptr));
        longitude->setText(QApplication::translate("MainWindow", "\347\273\217\345\272\246\357\274\232", nullptr));
        height->setText(QApplication::translate("MainWindow", "\351\253\230\347\250\213\357\274\232", nullptr));
        pos_status_display->setText(QString());
        roll->setText(QApplication::translate("MainWindow", "\346\250\252\346\273\232\357\274\232", nullptr));
        magnetism1z->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2501Z\357\274\232", nullptr));
        ins_status->setText(QApplication::translate("MainWindow", "\347\273\204\345\257\274\347\212\266\346\200\201\357\274\232", nullptr));
        magnetism2y_display->setText(QString());
        ins_status_display->setText(QString());
        magnetism2z->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2502Z\357\274\232", nullptr));
        magnetism1x->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2501X\357\274\232", nullptr));
        acc_status->setText(QApplication::translate("MainWindow", "\345\212\240\350\256\241\347\212\266\346\200\201\357\274\232", nullptr));
        acc_status_display->setText(QString());
        risefall->setText(QApplication::translate("MainWindow", "\350\265\267\344\274\217\357\274\232", nullptr));
        MCU_status->setText(QApplication::translate("MainWindow", "\346\225\260\351\207\207\357\274\232", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "UDP\347\273\204\346\222\255\350\256\276\347\275\256", nullptr));
        UDPshutdown->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        UDPconnect->setText(QApplication::translate("MainWindow", "\345\212\240\345\205\245", nullptr));
        UDPsendButton->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        UDPrecvButton->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266", nullptr));
        multicastIP->setText(QApplication::translate("MainWindow", "\347\273\204\346\222\255IP\357\274\232", nullptr));
        multicastIPlineedit->setText(QApplication::translate("MainWindow", "227.0.81.22", nullptr));
        localport->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\253\257\345\217\243\357\274\232", nullptr));
        localportlineedit->setText(QApplication::translate("MainWindow", "37001", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\347\273\230\345\233\276\346\216\247\345\210\266", nullptr));
        fluxgate1y->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\250Y1", nullptr));
        fluxgate2z->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\250Z2", nullptr));
        pump1->setText(QApplication::translate("MainWindow", "\345\205\211\346\263\2651", nullptr));
        fluxgate2all->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2502\346\200\273\345\234\272", nullptr));
        fluxgate1x->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\250X1", nullptr));
        fluxgate2x->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\250X2", nullptr));
        fluxgate2y->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\250Y2", nullptr));
        fluxgate1z->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\250Z1", nullptr));
        pump2->setText(QApplication::translate("MainWindow", "\345\205\211\346\263\2652", nullptr));
        fluxgate1all->setText(QApplication::translate("MainWindow", "\347\243\201\351\200\232\351\227\2501\346\200\273\345\234\272", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
