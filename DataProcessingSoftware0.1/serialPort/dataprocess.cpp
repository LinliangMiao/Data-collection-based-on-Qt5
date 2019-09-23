#include "dataprocess.h"
#include "mainwindow.h"

FluxGate FluxGate1,FluxGate2;
Accelerometer Acc1;
Pump Pump1;
IMU_withGPS IMU_GPS1;
ofstream oFile_bin;
ofstream oFile;
QByteArray SerialReceivedData;

dataprocess::dataprocess(QObject *parent) :
    QThread(parent)
{
}

void dataprocess::run()
{
    RecvDataResolution(SerialReceivedData);
    senddata2ui();
}

void dataprocess::stop()
{
    this->terminate();
    this->wait();
}

void dataprocess::senddata2ui()
{
    emit data_display();
}

void dataprocess::RecvDataResolution(QByteArray SerialReceivedData)
{

    for(int count_com=0;count_com<SerialReceivedData.length();count_com++)
    {
        oFile_bin << SerialReceivedData[count_com] ;
        if(((count_com + FilmLength-1)<SerialReceivedData.length()) && SerialReceivedData[count_com]==char(0xaa)
                && SerialReceivedData[count_com+1]==char(0x55) )
        {
            for(int i = 0;i < FilmLength;i++)
            {
                Film_Temp[i] = SerialReceivedData[count_com+i];
            }
            /* Acc1 Decode */
            if(Film_Temp[2] & 0x01)
            {
                int Acc1_st = 24;
                Acc1.Acc_XVal = (double)(Byte2Float_GYRO24_HL(Film_Temp, Acc1_st) / 262144.0);
                Acc1.Acc_YVal = (double)(Byte2Float_GYRO24_HL(Film_Temp, Acc1_st+3) / 262144.0);
                Acc1.Acc_ZVal = (double)(Byte2Float_GYRO24_HL(Film_Temp, Acc1_st+6) / 262144.0);
                gcvt(Acc1.Acc_XVal ,8,Acc1.Acc_XStr);
                gcvt(Acc1.Acc_YVal ,8,Acc1.Acc_YStr);
                gcvt(Acc1.Acc_ZVal ,8,Acc1.Acc_ZStr);

                switch(Film_Temp[3])
                {
                    case 0:{strcpy(Acc1.Acc_status, "Acc_OK");break;}
                    default:{strcpy(Acc1.Acc_status, "Acc_Error");break;}
                }
            }
            /* FluxGate1 Decode */
            if(Film_Temp[2] & 0x04)
            {
                int FluxGate1_st = 6;
                FluxGate1.Mag_XVal=(float(( (unsigned char)Film_Temp[FluxGate1_st]<< 16) + ((unsigned char)Film_Temp[FluxGate1_st+1] << 8) + (unsigned char)Film_Temp[FluxGate1_st+2]) / 16777215 -0.5) * 200000;
                FluxGate1.Mag_YVal=(float(( (unsigned char)Film_Temp[FluxGate1_st+3]<< 16) + ((unsigned char)Film_Temp[FluxGate1_st+4] << 8) + (unsigned char)Film_Temp[FluxGate1_st+5]) / 16777215 -0.5) * 200000;
                FluxGate1.Mag_ZVal=(float(( (unsigned char)Film_Temp[FluxGate1_st+6]<< 16) + ((unsigned char)Film_Temp[FluxGate1_st+7] << 8) + (unsigned char)Film_Temp[FluxGate1_st+8]) / 16777215 -0.5) * 200000;
                if((FluxGate1.Mag_XVal==-100000)&&(FluxGate1.Mag_YVal==-100000)&&(FluxGate1.Mag_ZVal==-100000))
                {
                    FluxGate1.Mag_XVal = 0;FluxGate1.Mag_YVal = 0;FluxGate1.Mag_ZVal = 0;
                }

                FluxGate1.Mag_allVal=sqrt(FluxGate1.Mag_XVal*FluxGate1.Mag_XVal+FluxGate1.Mag_YVal*FluxGate1.Mag_YVal+FluxGate1.Mag_ZVal*FluxGate1.Mag_ZVal);
                gcvt(FluxGate1.Mag_XVal ,8,FluxGate1.Mag_XStr);
                gcvt(FluxGate1.Mag_YVal ,8,FluxGate1.Mag_YStr);
                gcvt(FluxGate1.Mag_ZVal ,8,FluxGate1.Mag_ZStr);
                gcvt(FluxGate1.Mag_allVal ,8,FluxGate1.Mag_allStr);
            }

            /* FluxGate2 Decode */
            if(Film_Temp[2] & 0x02)
            {
                int FluxGate2_st = 15;
                FluxGate2.Mag_XVal=(float(( (unsigned char)Film_Temp[FluxGate2_st]<< 16) + ((unsigned char)Film_Temp[FluxGate2_st+1] << 8) + (unsigned char)Film_Temp[FluxGate2_st+2]) / 16777215 -0.5) * 200000;
                FluxGate2.Mag_YVal=(float(( (unsigned char)Film_Temp[FluxGate2_st+3]<< 16) + ((unsigned char)Film_Temp[FluxGate2_st+4] << 8) + (unsigned char)Film_Temp[FluxGate2_st+5]) / 16777215 -0.5) * 200000;
                FluxGate2.Mag_ZVal=(float(( (unsigned char)Film_Temp[FluxGate2_st+6]<< 16) + ((unsigned char)Film_Temp[FluxGate2_st+7] << 8) + (unsigned char)Film_Temp[FluxGate2_st+8]) / 16777215 -0.5) * 200000;
                if(FluxGate2.Mag_XVal==-100000&&FluxGate2.Mag_YVal==-100000&&FluxGate2.Mag_ZVal==-100000)
                {
                    FluxGate2.Mag_XVal = 0;FluxGate2.Mag_YVal = 0;FluxGate2.Mag_ZVal = 0;
                }

                FluxGate2.Mag_allVal=sqrt(FluxGate2.Mag_XVal*FluxGate2.Mag_XVal+FluxGate2.Mag_YVal*FluxGate2.Mag_YVal+FluxGate2.Mag_ZVal*FluxGate2.Mag_ZVal);
                gcvt(FluxGate2.Mag_XVal ,8,FluxGate2.Mag_XStr);
                gcvt(FluxGate2.Mag_YVal ,8,FluxGate2.Mag_YStr);
                gcvt(FluxGate2.Mag_ZVal ,8,FluxGate2.Mag_ZStr);
                gcvt(FluxGate2.Mag_allVal ,8,FluxGate2.Mag_allStr);
            }

            /* IMU1 Decode */
            if(Film_Temp[2] & 0x08)
            {
                switch(Film_Temp[4]&0X0f)
                {
                    case 0:{strcpy(IMU_GPS1.INS_status , "MOTION_DETECT");break;}
                    case 1:{strcpy(IMU_GPS1.INS_status , "INS_INACTIVE");break;}
                    case 2:{strcpy(IMU_GPS1.INS_status , "INS_ALIGNING");break;}
                    case 3:{strcpy(IMU_GPS1.INS_status , "INS_HIGH_VARIANCE");break;}
                    case 4:{strcpy(IMU_GPS1.INS_status , "INS_SOLUTION_GOOD");break;}
                    case 5:{strcpy(IMU_GPS1.INS_status , "INS_SOLUTION_FREE");break;}
                    case 6:{strcpy(IMU_GPS1.INS_status , "INS_ALIGNMENT_COMPLETE");break;}
                    case 7:{strcpy(IMU_GPS1.INS_status , "DETERMINING_ORIENTATION");break;}
                    case 8:{strcpy(IMU_GPS1.INS_status , "WAITING_INITIALPOS");break;}
                    default:{strcpy(IMU_GPS1.POS_status, "-");break;}
                }
                switch((Film_Temp[4]>>4)&0X0f)
                {
                    case 0:{strcpy(IMU_GPS1.POS_status ,"SINGLE");break;}
                    case 1:{strcpy(IMU_GPS1.POS_status ,"NONE");break;}
                    case 2:{strcpy(IMU_GPS1.POS_status ,"INS_PSRSP");break;}
                    case 3:{strcpy(IMU_GPS1.POS_status ,"INS_PSRDIFF");break;}
                    case 4:{strcpy(IMU_GPS1.POS_status ,"INS_RTKFLOAT");break;}
                    case 5:{strcpy(IMU_GPS1.POS_status ,"INS_RTKFIXED");break;}
                    default:{strcpy(IMU_GPS1.POS_status,"-");break;}
                }

                int IMU1_st = 33;
                gcvt((float)((Film_Temp[IMU1_st+1] << 8) + Film_Temp[IMU1_st]),4,IMU_GPS1.GPSTime_week_Str );

                for(int i=0;i<11;i++)
                {
                    if(i == 1 || i == 2)
                    {
                        gcvt((0x40-((unsigned char)Film_Temp[IMU1_st+5+i*8]&0x80))/0x40*((float)(((unsigned char)Film_Temp[IMU1_st+2+i*8]) + ((unsigned char)Film_Temp[IMU1_st+3+i*8] << 8) + ((unsigned char)Film_Temp[IMU1_st+4+i*8] << 16)) +
                        (float)(((unsigned char)Film_Temp[IMU1_st+6+i*8]) + ((unsigned char)Film_Temp[IMU1_st+7+i*8] << 8) + ((unsigned char)Film_Temp[IMU1_st+8+i*8] << 16) + ((unsigned char)Film_Temp[IMU1_st+9+i*8] << 24))
                                /pow(10,((unsigned char)Film_Temp[IMU1_st+5+i*8]&0x7f)))/100,14,IMU_GPS1.IMUDataAll[i]);
                    }
                    else
                    {
                        gcvt((0x40-((unsigned char)Film_Temp[IMU1_st+5+i*8]&0x80))/0x40*((float)(((unsigned char)Film_Temp[IMU1_st+2+i*8]) + ((unsigned char)Film_Temp[IMU1_st+3+i*8] << 8) + ((unsigned char)Film_Temp[IMU1_st+4+i*8] << 16)) +
                        (float)(((unsigned char)Film_Temp[IMU1_st+6+i*8]) + ((unsigned char)Film_Temp[IMU1_st+7+i*8] << 8) + ((unsigned char)Film_Temp[IMU1_st+8+i*8] << 16) + ((unsigned char)Film_Temp[IMU1_st+9+i*8] << 24))
                                /pow(10,((unsigned char)Film_Temp[IMU1_st+5+i*8]&0x7f))),14,IMU_GPS1.IMUDataAll[i]);
                    }
                }
            }
            if(Film_Temp[2] & 0x0f)
            {
                oFile << "GroundReception" << "," <<Acc1.Acc_status<< "," <<IMU_GPS1.INS_status<< ","<<IMU_GPS1.POS_status<< ","
                      << FluxGate1.Mag_XStr << "," << FluxGate1.Mag_YStr << "," << FluxGate1.Mag_ZStr<< ","
                      << FluxGate2.Mag_XStr << "," << FluxGate2.Mag_YStr<< "," <<FluxGate2.Mag_ZStr<< ","
                      << Acc1.Acc_XStr<< "," <<Acc1.Acc_YStr << ","<<Acc1.Acc_ZStr << ","
                      <<IMU_GPS1.GPSTime_week_Str<< "," <<IMU_GPS1.IMUDataAll[0]<< "," <<IMU_GPS1.IMUDataAll[1]<< "," <<IMU_GPS1.IMUDataAll[2]<< ","<<IMU_GPS1.IMUDataAll[3]<< ","
                      <<IMU_GPS1.IMUDataAll[4]<< ","<<IMU_GPS1.IMUDataAll[5]<< ","<<IMU_GPS1.IMUDataAll[6]<< ","<<IMU_GPS1.IMUDataAll[7]<< ","
                      <<IMU_GPS1.IMUDataAll[8]<< ","<<IMU_GPS1.IMUDataAll[9]<< "," <<IMU_GPS1.IMUDataAll[10]<< "," << " " << "," << " " <<endl;
            }

        }
    }
}

float dataprocess::Byte2Float_GYRO24_HL(unsigned char data[], int startIndex)
{
   float res;

   int temp = 0;

   if ((data[startIndex] & 0x80) == 0x80)
   {
       temp = (int)(0xFF000000 | ((int)(data[startIndex] << 16)) | ((int)(data[startIndex + 1] << 8)) | (data[startIndex + 2]));
   }
   else
   {
       temp = data[startIndex] * 65536 + data[startIndex + 1] * 256 + data[startIndex + 2];
   }

   res = (float)temp;

   return res;
}

void dataprocess::MakeCheckSum (uint8_t Buf[], int len)
{
    unsigned char  sum=0, idx;
    for(idx=0; idx<(len-1); idx++)
        {
            sum += Buf[idx];
        }
    Buf[len-1] = 256 - sum;
}
