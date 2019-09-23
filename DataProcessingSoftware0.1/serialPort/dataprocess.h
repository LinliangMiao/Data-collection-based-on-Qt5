#ifndef DATAPROCESS_H
#define DATAPROCESS_H
#include <QThread>
#include "QDebug"
#include "QFile"
#include "QString"
#include "QTime"
#include <fstream>

using namespace std;

#define FilmLength 128
#define PUMP1_LEN 8
#define Acc1_LEN 15
#define FLUXGATE2_LEN 14
#define FLUXGATE1_LEN 14
#define IMU1_LEN 176

class dataprocess : public QThread
{
    Q_OBJECT
public:
    explicit dataprocess(QObject *parent = 0);
    void RecvDataResolution(QByteArray SerialReceivedData);
    float Byte2Float_GYRO24_HL(unsigned char data[], int startIndex);
    void senddata2ui();
    void MakeCheckSum (uint8_t Buf[], int len);
    void run();
    void stop();

signals:
    void data_display();

public slots:

};

struct FluxGate{
    double Mag_XVal;
    double Mag_YVal;
    double Mag_ZVal;
    double Mag_allVal;
    double Mag_historyVal[3];
    int  Timestamp_MsVal;

    char Mag_XStr[20];
    char Mag_YStr[20];
    char Mag_ZStr[20];
    char Mag_allStr[20];
    char Timestamp_MsStr[20];
};

struct Pump{
    double pump_allVal;
    double pump_historyVal;
    int  Timestamp_MsVal;

    char pump_allStr[20];
    char Timestamp_MsStr[20];
};

struct Accelerometer
{
    double Acc_XVal;
    double Acc_YVal;
    double Acc_ZVal;
    double Acc_historyVal[3];
    int  Timestamp_MsVal;

    char Acc_XStr[20];
    char Acc_YStr[20];
    char Acc_ZStr[20];

    char Acc_status[20];
    char Timestamp_MsStr[20];
};

struct IMU_withGPS{
    double GPSTime_week_Val;
    double GPSTime_ms_Val;
    double longtitude_Val;
    double latitude_Val;
    double height_Val;
    double risefall_Val;
    double northvelocity_Val;
    double eastvelocity_Val;
    double upvelocity_Val;
    double roll_Val;
    double pitch_Val;
    double yaw_Val;
    double IMU_historyVal[12];

    char GPSTime_week_Str[20];
    char GPSTime_ms_Str[20];
    char longtitude_Str[20];
    char latitude_Str[20];
    char height_Str[20];
    char risefall_Str[20];
    char northvelocity_Str[20];
    char eastvelocity_Str[20];
    char upvelocity_Str[20];
    char roll_Str[20];
    char pitch_Str[20];
    char yaw_Str[20];

    char INS_status[20];
    char POS_status[20];
    char IMUDataAll[30][30];
    char Timestamp_MsStr[20];
};

extern FluxGate FluxGate1,FluxGate2;
extern Accelerometer Acc1;
extern Pump Pump1;
extern IMU_withGPS IMU_GPS1;
extern ofstream oFile_bin;
extern ofstream oFile;
extern QByteArray SerialReceivedData;
/*
class Pump{
public:
    friend class dataprocess;
    double pump_allVal;
    double pump_historyVal;
    int  Timestamp_MsVal;

    char pump_allStr[20];
    char Timestamp_MsStr[20];
private:
    void pumpdata_process();
};

class FluxGate{
public:
    friend class dataprocess;
    double Mag_XVal;
    double Mag_YVal;
    double Mag_ZVal;
    double Mag_allVal;
    double Mag_historyVal[3];
    int  Timestamp_MsVal;

    char Mag_XStr[20];
    char Mag_YStr[20];
    char Mag_ZStr[20];
    char Mag_allStr[20];
    char Timestamp_MsStr[20];
private:
    void fluxgatedata_process();
};

class IMU_Novatel{
public:
    friend class dataprocess;
    double GPSTime_week_Val;
    double GPSTime_ms_Val;
    double longtitude_Val;
    double latitude_Val;
    double height_Val;
    double risefall_Val;
    double northvelocity_Val;
    double eastvelocity_Val;
    double upvelocity_Val;
    double roll_Val;
    double pitch_Val;
    double yaw_Val;
    double IMU_historyVal[12];

    char GPSTime_week_Str[20];
    char GPSTime_ms_Str[20];
    char longtitude_Str[20];
    char latitude_Str[20];
    char height_Str[20];
    char risefall_Str[20];
    char northvelocity_Str[20];
    char eastvelocity_Str[20];
    char upvelocity_Str[20];
    char roll_Str[20];
    char pitch_Str[20];
    char yaw_Str[20];

    char INS_status[20];
    char POS_status[20];
    char IMUDataAll[30][30];
    char Timestamp_MsStr[20];
private:
    void IMU_Novateldata_process();
};

class Accelerometer
{
public:
    friend class dataprocess;
    double Acc_XVal;
    double Acc_YVal;
    double Acc_ZVal;
    double Acc_historyVal[3];
    int  Timestamp_MsVal;

    char Acc_XStr[20];
    char Acc_YStr[20];
    char Acc_ZStr[20];

    char Acc_status[20];
    char Timestamp_MsStr[20];
private:
    void Accelerometerdata_process();
};
*/
#endif
