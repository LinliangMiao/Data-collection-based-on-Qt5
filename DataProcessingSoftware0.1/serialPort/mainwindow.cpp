#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "process.h"

using namespace std;

#define READ_DATA false
#define DISPLAY_DATA true

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitialSerial();//初始化串口
    InitialUI();


    serial_draw_step = 50;
    time1 = new QTimer();
    timeId = startTimer(serial_draw_step);

    //File Operation
    systime = QDateTime::currentDateTime();
    str_systime = systime.toString("yyyy-MM-dd-hh-mm-ss");
    sysrecordfilename_csv = TransFileSavePath +"ReceivedDataRecord" +str_systime + ".csv";
    sysrecordfilename_bin = TransFileSavePath +"ReceivedDataRecord" +str_systime + ".bin";

    oFile.open(sysrecordfilename_csv.toStdString(), ios::out | ios::trunc);
    oFile << "Type" << "," <<"Acc Status"<< "," <<"INS Status"<< ","<<"POS Status"<< ","
          << "FluxGate1X" << "," << "FluxGate1Y" << "," << "FluxGate1Z"<< ","
          << "FluxGate2X" << "," << "FluxGate2Y" << "," << "FluxGate2Z"<< ","
          << "AccX" << "," << "AccY" << ","<< "AccZ"<< ","
          << "GPS reference week"<< "," << "GPS reference time ms"<< "," <<"Latitude(degree)"<< "," <<"Longtitude(degree)"<< ","<<"Height(m)"<< ","
          <<"Risefall(m)"<< ","<<"VelocityNorth(m/s)"<< ","<<"VelocityEast(m/s)"<< ","<<"VelocityUp(m/s)"<< ","
          <<"Roll(degree)"<< ","<<"Pitch(degree)"<< "," <<"Yaw(degree)"<< "," << "OpticalPump1" << "," << "OpticalPump2" <<endl;

    oFile_bin.open(sysrecordfilename_bin.toStdString(), ios::out | ios::trunc);
}

void MainWindow::timerEvent(QTimerEvent *event){
    if(event->timerId()==timeId){//定时器到时间,//模拟数据填充
        int size = 1;//数据个数
        if(isVisible())
        {
            /* pump 1 */
//            if(ui->pump1->isChecked()==true)
//                m_series_pump1->setVisible(true);
//            else
//                m_series_pump1->setVisible(false);
//            QVector<QPointF> oldPoints_pump1 = m_series_pump1->pointsVector();//Returns the points in the series as a vector
//            QVector<QPointF> points_pump1;

//            for(int i=size;i<oldPoints_pump1.count();++i)
//            {points_pump1.append(QPointF(i-size ,oldPoints_pump1.at(i).y()));}
//            qint64 sizePoints_pump1 = points_pump1.count();
//            for(int k=0;k<size;++k)
//            {points_pump1.append(QPointF(k+sizePoints_pump1,Pump1.Mag_allVal));}
//            //qDebug()<<result_pump1_valid;
//            m_series_pump1->replace(points_pump1);

            /* mag 1 all */
            if(ui->fluxgate1all->isChecked()==true)
            {m_series_magnetism1all->setVisible(true);}
            else
            {m_series_magnetism1all->setVisible(false);}
            QVector<QPointF> oldPoints_magnetism1all = m_series_magnetism1all->pointsVector();//Returns the points in the series as a vector
            QVector<QPointF> points_magnetism1all;

            for(int i=size;i<oldPoints_magnetism1all.count();++i)
            {points_magnetism1all.append(QPointF(i-size ,oldPoints_magnetism1all.at(i).y()));}
            qint64 sizePoints_magnetism1all = points_magnetism1all.count();
            for(int k=0;k<size;++k)
            {points_magnetism1all.append(QPointF(k+sizePoints_magnetism1all,FluxGate1.Mag_allVal));}
            m_series_magnetism1all->replace(points_magnetism1all);
            //FluxGate1.Mag_allVal = 0;

            /* mag 2 all */
            if(ui->fluxgate2all->isChecked()==true)
            {m_series_magnetism2all->setVisible(true);}
            else
            {m_series_magnetism2all->setVisible(false);}
            QVector<QPointF> oldPoints_magnetism2all = m_series_magnetism2all->pointsVector();//Returns the points in the series as a vector
            QVector<QPointF> points_magnetism2all;

            for(int i=size;i<oldPoints_magnetism2all.count();++i)
            {points_magnetism2all.append(QPointF(i-size ,oldPoints_magnetism2all.at(i).y()));}
            qint64 sizePoints_magnetism2all = points_magnetism2all.count();
            for(int k=0;k<size;++k)
            {points_magnetism2all.append(QPointF(k+sizePoints_magnetism2all,FluxGate2.Mag_allVal));}
            m_series_magnetism2all->replace(points_magnetism2all);
            //FluxGate2.Mag_allVal = 0;

            /* mag 1 x */
            if(ui->fluxgate1x->isChecked()==true)
            {m_series_magnetism1x->setVisible(true);}
            else
            {m_series_magnetism1x->setVisible(false);}
            QVector<QPointF> oldPoints_magnetism1x = m_series_magnetism1x->pointsVector();//Returns the points in the series as a vector
            QVector<QPointF> points_magnetism1x;

            for(int i=size;i<oldPoints_magnetism1x.count();++i)
            {points_magnetism1x.append(QPointF(i-size ,oldPoints_magnetism1x.at(i).y()));}
            qint64 sizePoints_magnetism1x = points_magnetism1x.count();
            for(int k=0;k<size;++k)
            {points_magnetism1x.append(QPointF(k+sizePoints_magnetism1x,FluxGate1.Mag_XVal));}
            m_series_magnetism1x->replace(points_magnetism1x);
            //FluxGate1.Mag_XVal = 0;

            /* mag 2 x */
            if(ui->fluxgate2x->isChecked()==true)
            {m_series_magnetism2x->setVisible(true);}
            else
            {m_series_magnetism2x->setVisible(false);}
            QVector<QPointF> oldPoints_magnetism2x = m_series_magnetism2x->pointsVector();//Returns the points in the series as a vector
            QVector<QPointF> points_magnetism2x;

            for(int i=size;i<oldPoints_magnetism2x.count();++i)
            {points_magnetism2x.append(QPointF(i-size ,oldPoints_magnetism2x.at(i).y()));}
            qint64 sizePoints_magnetism2x = points_magnetism2x.count();
            for(int k=0;k<size;++k)
            {points_magnetism2x.append(QPointF(k+sizePoints_magnetism2x,FluxGate2.Mag_XVal));}
            m_series_magnetism2x->replace(points_magnetism2x);
            //FluxGate2.Mag_XVal = 0;

            /* mag 1 y */
            if(ui->fluxgate1y->isChecked()==true)
            {m_series_magnetism1y->setVisible(true);}
            else
            {m_series_magnetism1y->setVisible(false);}
            QVector<QPointF> oldPoints_magnetism1y = m_series_magnetism1y->pointsVector();//Returns the points in the series as a vector
            QVector<QPointF> points_magnetism1y;

            for(int i=size;i<oldPoints_magnetism1y.count();++i)
            {points_magnetism1y.append(QPointF(i-size ,oldPoints_magnetism1y.at(i).y()));}
            qint64 sizePoints_magnetism1y = points_magnetism1y.count();
            for(int k=0;k<size;++k)
            {points_magnetism1y.append(QPointF(k+sizePoints_magnetism1y,FluxGate1.Mag_YVal));}
            m_series_magnetism1y->replace(points_magnetism1y);
            //FluxGate1.Mag_YVal = 0;

            /* mag 2 y */
            if(ui->fluxgate2y->isChecked()==true)
            {m_series_magnetism2y->setVisible(true);}
            else
            {m_series_magnetism2y->setVisible(false);}
            QVector<QPointF> oldPoints_magnetism2y = m_series_magnetism2y->pointsVector();//Returns the points in the series as a vector
            QVector<QPointF> points_magnetism2y;

            for(int i=size;i<oldPoints_magnetism2y.count();++i)
            {points_magnetism2y.append(QPointF(i-size ,oldPoints_magnetism2y.at(i).y()));}
            qint64 sizePoints_magnetism2y = points_magnetism2y.count();
            for(int k=0;k<size;++k)
            {points_magnetism2y.append(QPointF(k+sizePoints_magnetism2y,FluxGate2.Mag_YVal));}
            m_series_magnetism2y->replace(points_magnetism2y);
            //FluxGate2.Mag_YVal = 0;

            /* mag 1 z */
            if(ui->fluxgate1z->isChecked()==true)
            {m_series_magnetism1z->setVisible(true);}
            else
            {m_series_magnetism1z->setVisible(false);}
            QVector<QPointF> oldPoints_magnetism1z = m_series_magnetism1z->pointsVector();//Returns the points in the series as a vector
            QVector<QPointF> points_magnetism1z;

            for(int i=size;i<oldPoints_magnetism1z.count();++i)
            {points_magnetism1z.append(QPointF(i-size ,oldPoints_magnetism1z.at(i).y()));}
            qint64 sizePoints_magnetism1z = points_magnetism1z.count();
            for(int k=0;k<size;++k)
            {points_magnetism1z.append(QPointF(k+sizePoints_magnetism1z,FluxGate1.Mag_ZVal));}
            m_series_magnetism1z->replace(points_magnetism1z);
            //FluxGate1.Mag_ZVal = 0;

            /* mag 2 z */
            if(ui->fluxgate2z->isChecked()==true)
            {m_series_magnetism2z->setVisible(true);}
            else
            {m_series_magnetism2z->setVisible(false);}
            QVector<QPointF> oldPoints_magnetism2z = m_series_magnetism2z->pointsVector();//Returns the points in the series as a vector
            QVector<QPointF> points_magnetism2z;

            for(int i=size;i<oldPoints_magnetism2z.count();++i)
            {points_magnetism2z.append(QPointF(i-size ,oldPoints_magnetism2z.at(i).y()));}
            qint64 sizePoints_magnetism2z = points_magnetism2z.count();
            for(int k=0;k<size;++k)
            {points_magnetism2z.append(QPointF(k+sizePoints_magnetism2z,FluxGate2.Mag_ZVal));}
            m_series_magnetism2z->replace(points_magnetism2z);
            //FluxGate2.Mag_ZVal = 0;

            systime = QDateTime::currentDateTime();
            str_systime = systime.toString("hh:mm:ss");
            ui->timerec_display->setText(str_systime);
       }
    }
}

void MainWindow::InitialSerial()
{
    for(int i=0;i<GetEnableCommPort().size();i++)
        ui->portName->addItem(GetEnableCommPort()[i]);
    /*
    ui->portName->addItem("COM3");
    ui->portName->addItem("COM1");
    ui->portName->addItem("COM2"); 
    ui->portName->addItem("COM4");
    ui->portName->addItem("COM5");
    ui->portName->addItem("COM6");
    ui->portName->addItem("COM7");
    ui->portName->addItem("COM8");
    ui->portName->addItem("COM9");
    ui->portName->addItem("COM10");
    ui->portName->addItem("COM11");
    ui->portName->addItem("COM12");
    ui->portName->addItem("COM13");
    ui->portName->addItem("COM14");
    ui->portName->addItem("COM15");
    ui->portName->addItem("COM16");
    ui->portName->addItem("COM17");
    ui->portName->addItem("COM18");
    ui->portName->addItem("COM19");
    ui->portName->addItem("COM20");
    ui->portName->addItem("COM21");
    ui->portName->addItem("COM22");
    ui->portName->addItem("COM23");
    ui->portName->addItem("COM24");
    ui->portName->addItem("COM25");
    ui->portName->addItem("COM26");
    ui->portName->addItem("COM27");
    ui->portName->addItem("COM28");
    ui->portName->addItem("COM29");
    ui->portName->addItem("COM30");
    ui->portName->addItem("Silicon Labs Dual CP210x USB to UART Bridge: Standard COM Port");
    ui->portName->addItem("Silicon Labs Dual CP210x USB to UART Bridge: Enhanced COM Port");
*/
    ui->baudRate->addItem("115200");
    ui->baudRate->addItem("9600");
    ui->baudRate->addItem("1200");
    ui->baudRate->addItem("2400");
    ui->baudRate->addItem("4800");
    ui->baudRate->addItem("19200");
    ui->baudRate->addItem("38400");

    ui->dataBits->addItem("8");
    ui->dataBits->addItem("5");
    ui->dataBits->addItem("6");
    ui->dataBits->addItem("7");

    ui->parityCom->addItem("none");
    ui->parityCom->addItem("odd");//奇校验
    ui->parityCom->addItem("even");//偶校验

    ui->stopBit->addItem("1");
    ui->stopBit->addItem("2");

    ui->flowType->addItem("off");
    ui->flowType->addItem("hardware");
    ui->flowType->addItem("xonxoff");
}

void MainWindow::InitialUI()
{
    ui->closeSerial->setEnabled(false);
    ui->UDPconnect->setEnabled(true);
    ui->UDPshutdown->setEnabled(false);
    ui->filetrans_start->setEnabled(false);
    ui->fluxgate1all->setCheckState(Qt::Unchecked);
    ui->fluxgate1x->setCheckState(Qt::Unchecked);
    ui->fluxgate1y->setCheckState(Qt::Unchecked);
    ui->fluxgate2all->setCheckState(Qt::Unchecked);//ui->fluxgate2all->setEnabled(false);
    ui->fluxgate2x->setCheckState(Qt::Unchecked);//ui->fluxgate2x->setEnabled(false);
    ui->fluxgate2y->setCheckState(Qt::Unchecked);//ui->fluxgate2y->setEnabled(false);
    ui->fluxgate2z->setCheckState(Qt::Unchecked);//ui->fluxgate2z->setEnabled(false);
    ui->pump1->setCheckState(Qt::Unchecked);ui->pump1->setEnabled(false);
    ui->pump2->setCheckState(Qt::Unchecked);ui->pump2->setEnabled(false);
    ui->fluxgate1all->setStyleSheet("QCheckBox::indicator:checked {background-color:red;}");
    ui->fluxgate1x->setStyleSheet("QCheckBox::indicator:checked {background-color:blue;}");
    ui->fluxgate1y->setStyleSheet("QCheckBox::indicator:checked {background-color:gray;}");
    ui->fluxgate1z->setStyleSheet("QCheckBox::indicator:checked {background-color:black;}");
    ui->fluxgate2all->setStyleSheet("QCheckBox::indicator:checked {background-color:green;}");
    ui->fluxgate2x->setStyleSheet("QCheckBox::indicator:checked {background-color:yellow;}");
    ui->fluxgate2y->setStyleSheet("QCheckBox::indicator:checked {background-color:cyan;}");
    ui->fluxgate2z->setStyleSheet("QCheckBox::indicator:checked {background-color:purple;}");

    connect(ui->closeSerial,SIGNAL(clicked()),this,SLOT(closeSerial()));
    connect(ui->openSerial,SIGNAL(clicked()),this,SLOT(openSerial()));
    connect(ui->filetrans_select,SIGNAL(clicked()),this,SLOT(SelectTransFile()));
    connect(ui->dir_datasave_select,SIGNAL(clicked()),this,SLOT(SelectTransDir()));
    connect(ui->filetrans_start,SIGNAL(clicked()),this,SLOT(filetrans_start()));
    connect(ui->UDPconnect,SIGNAL(clicked()),this,SLOT(UDPconnect()));
    connect(ui->UDPshutdown,SIGNAL(clicked()),this,SLOT(UDPshutdown()));

    connect(&filetrans_thread1,SIGNAL(ProgressBar_Update()),this,SLOT(ProgressBar_Setvalue()));
    connect(&dataprocess1,SIGNAL(data_display()),this,SLOT(Serialdata_Disply()));

    /* 2019.3.11 */
    m_chart = new QChart;
    QChartView *chartView = new QChartView(m_chart);
    chartView->setRubberBand(QChartView::RectangleRubberBand);
    chartView->setRenderHint(QPainter::Antialiasing);

    m_series_magnetism1all = new QLineSeries;m_series_magnetism1all->setPen(QPen(Qt::red,2,Qt::SolidLine));
    m_series_magnetism1x = new QLineSeries;m_series_magnetism1x->setPen(QPen(Qt::blue,2,Qt::SolidLine));
    m_series_magnetism1y = new QLineSeries;m_series_magnetism1y->setPen(QPen(Qt::gray,2,Qt::SolidLine));
    m_series_magnetism1z = new QLineSeries;m_series_magnetism1z->setPen(QPen(Qt::black,2,Qt::SolidLine));
    m_series_magnetism2all = new QLineSeries;m_series_magnetism2all->setPen(QPen(Qt::green,2,Qt::SolidLine));
    m_series_magnetism2x = new QLineSeries;m_series_magnetism2x->setPen(QPen(Qt::yellow,2,Qt::SolidLine));
    m_series_magnetism2y = new QLineSeries;m_series_magnetism2y->setPen(QPen(Qt::cyan,2,Qt::SolidLine));
    m_series_magnetism2z = new QLineSeries;m_series_magnetism2z->setPen(QPen(Qt::magenta,2,Qt::SolidLine));
    //m_series_pump1 = new QLineSeries;m_series_pump1->setPen(QPen(Qt::green,2,Qt::SolidLine));
    m_chart->addSeries(m_series_magnetism1all);
    m_chart->addSeries(m_series_magnetism1x);
    m_chart->addSeries(m_series_magnetism1y);
    m_chart->addSeries(m_series_magnetism1z);
    m_chart->addSeries(m_series_magnetism2all);
    m_chart->addSeries(m_series_magnetism2x);
    m_chart->addSeries(m_series_magnetism2y);
    m_chart->addSeries(m_series_magnetism2z);
    //m_chart->addSeries(m_series_pump1);
    for(int i=0;i<chartx_maxSize;++i){
       m_series_magnetism1all->append(i,0);
       m_series_magnetism1x->append(i,0);
       m_series_magnetism1y->append(i,0);
       m_series_magnetism1z->append(i,0);
       m_series_magnetism2all->append(i,0);
       m_series_magnetism2x->append(i,0);
       m_series_magnetism2y->append(i,0);
       m_series_magnetism2z->append(i,0);
       //m_series_pump1->append(i,0);
    }
    m_series_magnetism1all->setUseOpenGL(true);//openGl faster
    m_series_magnetism1x->setUseOpenGL(true);//openGl faster
    m_series_magnetism1y->setUseOpenGL(true);//openGl faster
    m_series_magnetism1z->setUseOpenGL(true);//openGl faster
    m_series_magnetism2all->setUseOpenGL(true);//openGl faster
    m_series_magnetism2x->setUseOpenGL(true);//openGl faster
    m_series_magnetism2y->setUseOpenGL(true);//openGl faster
    m_series_magnetism2z->setUseOpenGL(true);//openGl faster
    //m_series_pump1->setUseOpenGL(true);//openGl faster

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,chartx_maxSize);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Time");

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-100000,100000);
    axisY->setTitleText("Magnetism Value/nT");

    m_chart->setAxisX(axisX,m_series_magnetism1all);
    m_chart->setAxisX(axisX,m_series_magnetism1x);
    m_chart->setAxisX(axisX,m_series_magnetism1y);
    m_chart->setAxisX(axisX,m_series_magnetism1z);
    m_chart->setAxisX(axisX,m_series_magnetism2all);
    m_chart->setAxisX(axisX,m_series_magnetism2x);
    m_chart->setAxisX(axisX,m_series_magnetism2y);
    m_chart->setAxisX(axisX,m_series_magnetism2z);
    //m_chart->setAxisX(axisX,m_series_pump1);
    m_chart->setAxisY(axisY,m_series_magnetism1all);
    m_chart->setAxisY(axisY,m_series_magnetism1x);
    m_chart->setAxisY(axisY,m_series_magnetism1y);
    m_chart->setAxisY(axisY,m_series_magnetism1z);
    m_chart->setAxisY(axisY,m_series_magnetism2all);
    m_chart->setAxisY(axisY,m_series_magnetism2x);
    m_chart->setAxisY(axisY,m_series_magnetism2y);
    m_chart->setAxisY(axisY,m_series_magnetism2z);
    //m_chart->setAxisY(axisY,m_series_pump1);

    m_chart->legend()->hide();
    m_chart->setTitle("Magnetism Value");

    QVBoxLayout *layout = ui->verticalLayout;
    layout->addWidget(chartView);
}

void MainWindow::readMyCom()
{
     SerialReceivedData = serial->readAll();
     if(SerialReceivedData.isEmpty())
            return ;

     dataprocess1.run();

/*    RecvDataResolution(SerialReceivedData);
     if(UDPsendReady)
     {
        mSocket.writeDatagram(SerialReceivedData,QHostAddress(ui->multicastIPlineedit->text()),ui->localportlineedit->text().toInt());
     }
*/

}

QStringList MainWindow::GetEnableCommPort()// 获取计算机可用串口
{
    QStringList CommPortList;

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if (serial.open(QIODevice::ReadWrite))
        {
            CommPortList.append(serial.portName());
            serial.close();
        }
    }

    return CommPortList;
}

void MainWindow::openSerial()
{
    QString portName=ui->portName->currentText();
    QString baudRate=ui->baudRate->currentText();
    QString dataBits=ui->dataBits->currentText();
    QString parity=ui->parityCom->currentText();
    QString stopBit=ui->stopBit->currentText();
    QString flow=ui->flowType->currentText();

    serial = new QSerialPort;
    serial->setPortName(portName);

    serial->open(QIODevice::ReadWrite);

    if(baudRate==tr("1200"))
        serial->setBaudRate(QSerialPort::Baud1200);
    else if(baudRate==tr("2400"))
        serial->setBaudRate(QSerialPort::Baud2400);
    else if(baudRate==tr("4800"))
        serial->setBaudRate(QSerialPort::Baud4800);
    else if(baudRate==tr("9600"))
        serial->setBaudRate(QSerialPort::Baud9600);
    else if(baudRate==tr("19200"))
        serial->setBaudRate(QSerialPort::Baud19200);
    else if(baudRate==tr("38400"))
        serial->setBaudRate(QSerialPort::Baud38400);
    else if(baudRate==tr("115200"))
        serial->setBaudRate(QSerialPort::Baud115200);

    if(dataBits==tr("5"))
        serial->setDataBits(QSerialPort::Data5);
    else if(dataBits==tr("6"))
        serial->setDataBits(QSerialPort::Data6);
    else if(dataBits==tr("7"))
        serial->setDataBits(QSerialPort::Data7);
    else if(dataBits==tr("8"))
        serial->setDataBits(QSerialPort::Data8);

    if(parity==tr("none"))
        serial->setParity(QSerialPort::NoParity);
    else if(parity==tr("odd"))
        serial->setParity(QSerialPort::OddParity);
    else if(parity==tr("even"))
        serial->setParity(QSerialPort::EvenParity);

    if(stopBit==tr("1"))
        serial->setStopBits(QSerialPort::OneStop);
    else if(stopBit==tr("2"))
        serial->setStopBits(QSerialPort::TwoStop);

    if(flow==tr("off"))
        serial->setFlowControl(QSerialPort::NoFlowControl);
    if(flow==tr("hardware"))
        serial->setFlowControl(QSerialPort::HardwareControl);
    if(flow==tr("xonxoff"))
        serial->setFlowControl(QSerialPort::SoftwareControl);

    ui->openSerial->setEnabled(false);
    ui->closeSerial->setEnabled(true);
    ui->portName->setEnabled(false);
    ui->baudRate->setEnabled(false);
    ui->dataBits->setEnabled(false);
    ui->parityCom->setEnabled(false);
    ui->stopBit->setEnabled(false);
    ui->flowType->setEnabled(false);
    ui->closeSerial->setEnabled(true); 

    connect(serial,&QSerialPort::readyRead,this,&MainWindow::readMyCom);
}

void MainWindow::closeSerial()
{
    serial->close();

    ui->openSerial->setEnabled(true);
    ui->closeSerial->setEnabled(false);
    ui->portName->setEnabled(true);
    ui->baudRate->setEnabled(true);
    ui->dataBits->setEnabled(true);
    ui->parityCom->setEnabled(true);
    ui->stopBit->setEnabled(true);
    ui->flowType->setEnabled(true);

    delete serial;
}

void MainWindow::UDPconnect()
{
    if(ui->UDPsendButton->isChecked())
    {
        UDPsendReady = 1;
    }
    else
    {
        if(!mSocket.bind(QHostAddress::AnyIPv4,ui->localportlineedit->text().toInt(), QUdpSocket::ReuseAddressHint))
        {
            QMessageBox::warning(this,tr("UDP Configuration Error!"),tr("Port bind failed!"),QMessageBox::Ok);
            return ;
        }

        if(!mSocket.joinMulticastGroup(QHostAddress(ui->multicastIPlineedit->text())))
        {
            QMessageBox::warning(this,tr("UDP Configuration Error!"),tr("Join multicastGroup failed!"),QMessageBox::Ok);
            return ;
        }
        connect(&mSocket,SIGNAL(readyRead()),this,SLOT(read_UDPdata()));
    }


    ui->UDPconnect->setEnabled(false);
    ui->UDPshutdown->setEnabled(true);
}

void MainWindow::UDPshutdown()
{

    UDPsendReady = 0;
    disconnect(&mSocket,SIGNAL(readyRead()),this,SLOT(read_UDPdata()));
    if(ui->UDPrecvButton->isChecked())
    {
        if(!mSocket.leaveMulticastGroup(QHostAddress(QHostAddress(ui->multicastIPlineedit->text()))))
        {
            QMessageBox::warning(this,tr("UDP Configuration Error!"),tr("Leave multicastGroup failed!"),QMessageBox::Ok);
            return ;
        }
    }

    ui->UDPconnect->setEnabled(true);
    ui->UDPshutdown->setEnabled(false);
}

void MainWindow::closeEvent(QCloseEvent* e)
{
    this->close();
}

void MainWindow::closeWindow()
{
    this->close();
}

void MainWindow::SelectTransFile()
{
    QString path="./";
    QString fileName=QFileDialog::getOpenFileName(this,tr("Select Files(*.bin)"),
                                                  path,tr("bin files(*.bin)"));
    if(fileName.isNull())
    {
        QMessageBox::warning(this,tr("File Name Error!"),tr("File name can't be null!"),QMessageBox::Ok);
        return ;
    }
    SelectFile = fileName;
    ui->filetrans_progressBar->setValue(0);
    ui->filetrans_select_display->setText(fileName);
    isSelectFile = 1;

    if(isChooseSavePath)
    {
        ui->filetrans_start->setEnabled(true);
        isSelectFile = 0;
        isChooseSavePath = 0;
    }

    return ;
}

void MainWindow::SelectTransDir()
{
    QString file_path = QFileDialog::getExistingDirectory(this,"请选择转换数据保存路径","./");
    if(file_path.isEmpty())
    {
        QMessageBox::warning(this,tr("File Directory Error!"),tr("Directory name can't be null!"),QMessageBox::Ok);
        return ;
    }
    else
    {
        ui->filetrans_progressBar->setValue(0);
        ui->dir_datasave_select_display->setText(file_path );
        TransFileSavePath = file_path;
        isChooseSavePath = 1;

        TransFileSavePath = file_path;

        if(isSelectFile)
        {
            ui->filetrans_start->setEnabled(true);
            isSelectFile = 0;
            isChooseSavePath = 0;
        }
    }
    return ;
}

void MainWindow::filetrans_start()
{
    filetrans_thread1.run();
    ui->filetrans_progressBar->setValue(100);
}

void MainWindow::ProgressBar_Setvalue()
{
    ui->filetrans_progressBar->setValue(FiletransProgress_Val);
}

void MainWindow::Serialdata_Disply()
{
    ui->acc_x_display->setText(Acc1.Acc_XStr);
    ui->acc_y_display->setText(Acc1.Acc_YStr);
    ui->acc_z_display->setText(Acc1.Acc_ZStr);
    ui->acc_status_display->setText(Acc1.Acc_status);

    ui->magnetism1x_display->setText(FluxGate1.Mag_XStr);
    ui->magnetism1y_display->setText(FluxGate1.Mag_YStr);
    ui->magnetism1z_display->setText(FluxGate1.Mag_ZStr);
    ui->magnetism1all_display->setText(FluxGate1.Mag_allStr);

    ui->magnetism2x_display->setText(FluxGate2.Mag_XStr);
    ui->magnetism2y_display->setText(FluxGate2.Mag_YStr);
    ui->magnetism2z_display->setText(FluxGate2.Mag_ZStr);
    ui->magnetism2all_display->setText(FluxGate2.Mag_allStr);

    ui->lati_display->setText(IMU_GPS1.IMUDataAll[1]);
    ui->longti_display->setText(IMU_GPS1.IMUDataAll[2]);
    ui->height_display->setText(IMU_GPS1.IMUDataAll[3]);
    ui->risefall_display->setText(IMU_GPS1.IMUDataAll[4]);
    ui->roll_display->setText(IMU_GPS1.IMUDataAll[8]);
    ui->pitch_display->setText(IMU_GPS1.IMUDataAll[9]);
    ui->yaw_display->setText(IMU_GPS1.IMUDataAll[10]);
    ui->ins_status_display->setText(IMU_GPS1.INS_status);
    ui->pos_status_display->setText(IMU_GPS1.POS_status);
}

void MainWindow::read_UDPdata()
{
    QByteArray array;
    QHostAddress address = QHostAddress(ui->multicastIPlineedit->text());
    quint16 port = ui->localportlineedit->text().toInt();
    array.resize(mSocket.bytesAvailable());//根据可读数据来设置空间大小
    mSocket.readDatagram(array.data(),array.size(),&address,&port); //读取数据

    SerialReceivedData = array;
    dataprocess1.run();
}

MainWindow::~MainWindow()
{
    delete ui;

    if(serial != nullptr)
       delete serial;
}
