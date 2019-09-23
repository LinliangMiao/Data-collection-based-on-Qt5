#ifndef FILETRANS_H
#define FILETRANS_H

#include <QThread>
#include "QDebug"
#include "QFile"
#include "QMessageBox"
#include "qmath.h"
#include <iostream>
#include <fstream>
#include "QString"

using namespace std;

extern QString SelectFile;
extern QString TransFileSavePath;

extern int  FilmHead_Flag,Film_Temp_point,Film_Length;
extern unsigned char Film_Temp[500];

extern QDateTime systime;
extern QString str_systime;
extern int FiletransProgress_Val, FiletransProgress_Val_old;

class filetrans : public QThread
{
    Q_OBJECT
public:
    QFile openFile;
    QByteArray FileContent;
    QString savetransfilename;
    explicit filetrans(QObject *parent = nullptr);
    void run();
    void stop();
    void FiletransProgress_Update();
    void MakeCheckSum (uint8_t Buf[], int len);
    float Byte2Float_GYRO24_HL(unsigned char data[], int startIndex);
    ofstream oFile;
    int count_com;
    qint64 SelectFileSize;

signals:
    void ProgressBar_Update();
};

#endif
