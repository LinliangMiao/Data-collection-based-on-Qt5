#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>

#include "QTimerEvent"
#include "QTimer"
#include "QTime"
#include "QSystemTrayIcon"
#include "QCheckBox"
#include "QDebug"
#include "QMessageBox"
#include "qmath.h"
#include "QPointF"
#include "QList"
#include "QKeyEvent"
#include "QFileDialog"
#include "QDesktopServices"
#include "QFile"
#include "QtCharts/QChart"
#include "QLineSeries"
#include "QValueAxis"
#include "QChartView"
#include "fstream"
#include <QUdpSocket>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "dataprocess.h"
#include "filetrans.h"

#include <stdio.h>
#include <fstream>

#define chartx_maxSize 600

QT_CHARTS_USE_NAMESPACE
using namespace std;

static QChart *m_chart;
static QLineSeries *m_series_pump1;
static QLineSeries *m_series_magnetism1x;
static QLineSeries *m_series_magnetism1y;
static QLineSeries *m_series_magnetism1z;
static QLineSeries *m_series_magnetism1all;
static QLineSeries *m_series_magnetism2x;
static QLineSeries *m_series_magnetism2y;
static QLineSeries *m_series_magnetism2z;
static QLineSeries *m_series_magnetism2all;
static int serial_draw_step;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    FILE* fp;

    filetrans filetrans_thread1;
    dataprocess dataprocess1;

    bool isSelectFile = 0;
    bool isChooseSavePath = 0;

    int count_com;
    int timeId;
    QString sysrecordfilename_csv;
    QString sysrecordfilename_bin;

    QTimer *time1 ;


private:
    Ui::MainWindow *ui;
    QUdpSocket mSocket;
    QSerialPort *serial;


private slots:
    void openSerial();
    void closeSerial();
    void UDPconnect();
    void UDPshutdown();
    void closeWindow();
    void filetrans_start();
    void SelectTransFile();
    void SelectTransDir();
    void ProgressBar_Setvalue();
    void read_UDPdata();
    void Serialdata_Disply();

public:
    void InitialSerial();
    void InitialUI();
    void closeEvent(QCloseEvent* e);
    void timerEvent(QTimerEvent *event) Q_DECL_OVERRIDE;
    void readMyCom();
    QStringList GetEnableCommPort();

    bool UDPsendReady = 0;
};

#endif // MAINWINDOW_H
