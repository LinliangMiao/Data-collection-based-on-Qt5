#include "filetrans.h"
#include "dataprocess.h"

QString SelectFile;
QString TransFileSavePath;

int  FilmHead_Flag = 0,Film_Temp_point = 0,Film_Length = 0;
unsigned char Film_Temp[500] = {0};

QDateTime systime;
QString str_systime;

int FiletransProgress_Val, FiletransProgress_Val_old;

filetrans::filetrans(QObject *parent) :
    QThread(parent)
{
}

void filetrans::run()
{
    systime = QDateTime::currentDateTime();
    str_systime = systime.toString("yyyy-MM-dd-hh-mm-ss");
    savetransfilename = TransFileSavePath +"/FiletransDataRecord" +str_systime + ".csv";
    qDebug()<<savetransfilename;
    //File Operation
    oFile.open(savetransfilename.toStdString(), ios::out | ios::trunc);

    oFile << "Type" << "," <<"Debug Info"<< "," << "OpticalPump1" << "," << "OpticalPump2" << ","
          << "FluxGate1X" << "," << "FluxGate1Y" << "," << "FluxGate1Z"<< ","
          << "FluxGate2X" << "," << "FluxGate2Y" << "," << "FluxGate2Z"<< ","
          << "Acc Status"<< "," << "Acc1X" << "," << "Acc1Y" << "," << "Acc1Z"<< ","
          << "Millisecond"<< "," << "GPS reference week"<< "," << "GPS reference time ms"<< "," <<"INS Status"<< ","
          <<"POS Status"<< "," <<"Latitude(degree)"<< "," <<"Longtitude(degree)"<< ","
          <<"Height(m)"<< "," <<"Undulation(m)"<< "," <<"Velocity North(m/s)"<< ","
          <<"Velocity East(m/s)"<< "," <<"Velocity Up(m/s)"<< "," <<"Roll(degree)"<< ","
          <<"Pitch(degree)"<< "," <<"Azimuth(degree)"<< "," <<"Latitude standard deviation(m)"<< ","
          <<"Longtitude standard deviation(m)"<< "," <<"Height standard deviation(m)"<< ","
          <<"North velocity standard deviation(m/s)"<< "," <<"East velocity standard deviation(m/s)"<< ","
          <<"Up velocity standard deviation(m/s)"<< "," <<"Roll standard deviation(degrees)"<< ","
          <<"Pitch standard deviation(degrees)"<< "," <<"Azimuth standard deviation(degrees)"<<endl;

    const char *SelectFileChar = SelectFile.toStdString().data(); //Qstring convert to char *

    FILE *fp;
    int ch,FC_point = 0;;

    if((fp=fopen(SelectFileChar,"rb"))==NULL)
    {
        qDebug()<<"Failure to open file!\n";
        return;
    }

    fseek(fp, 0, SEEK_END);
    SelectFileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    for(FC_point = 0;FC_point < SelectFileSize;FC_point++)
    {
        ch= fgetc(fp);
        FileContent[FC_point] = ch;
    }
    fclose(fp);

    FiletransProgress_Val_old = -1;
    for(count_com=0;count_com<FileContent.length();count_com++)
    {
        FiletransProgress_Val = int(100*count_com/FileContent.length());
        if(FiletransProgress_Val > FiletransProgress_Val_old)
        {
            FiletransProgress_Update();
            FiletransProgress_Val_old = FiletransProgress_Val;
        }


        if(FileContent[count_com]==char(0xa5))
        {
            if((count_com+1<FileContent.length()) && (count_com+2<FileContent.length()) &&
               (((unsigned char)FileContent[count_com+1] ==  0x00)||
                ((unsigned char)FileContent[count_com+1] ==  0x01)||
                ((unsigned char)FileContent[count_com+1] ==  0x02)||
                ((unsigned char)FileContent[count_com+1] ==  0x03)))
                {
                    switch(FileContent[count_com+1])
                    {
                        case 0: Film_Length = Acc1_LEN;break;
                        case 1: Film_Length = FLUXGATE2_LEN;break;
                        case 2: Film_Length = FLUXGATE1_LEN;break;
                        case 3: Film_Length = IMU1_LEN;break;
                        default:Film_Length = 0;break;
                    }
                    for(int i_temp=0; i_temp<Film_Length; i_temp++)
                    {
                        Film_Temp[i_temp] = (unsigned char)FileContent[count_com+i_temp];
                    }

                    switch(Film_Temp[1])
                    {
                       case 0:
                           {
                               int Acc1_st = 4;
                               Acc1.Acc_XVal = (double)(Byte2Float_GYRO24_HL(Film_Temp, Acc1_st) / 262144.0);
                               Acc1.Acc_YVal = (double)(Byte2Float_GYRO24_HL(Film_Temp, Acc1_st+3) / 262144.0);
                               Acc1.Acc_ZVal = (double)(Byte2Float_GYRO24_HL(Film_Temp, Acc1_st+6) / 262144.0);
                               gcvt(Acc1.Acc_XVal ,8,Acc1.Acc_XStr);
                               gcvt(Acc1.Acc_YVal ,8,Acc1.Acc_YStr);
                               gcvt(Acc1.Acc_ZVal ,8,Acc1.Acc_ZStr);
                               gcvt((float)(((unsigned char)Film_Temp[2] << 8) + (unsigned char)Film_Temp[3])/2,10,Acc1.Timestamp_MsStr );

                               switch(Film_Temp[13])
                               {
                                   case 0:{strcpy(Acc1.Acc_status, "Acc_OK");break;}
                                   default:{strcpy(Acc1.Acc_status, "Acc_Error");break;}
                               }

                               if(Film_Temp[Acc1_LEN-1]==0X69)//get_crc8(Film_Temp,PUMP1_LEN-1))
                               {
                                   oFile << "Acc1" << "," <<" "<< "," << " " << "," << " " << ","
                                         << " " << "," << " " << "," << " "<< "," << " " << "," << " " << "," << " "<< ","
                                         <<Acc1.Acc_status<< "," <<Acc1.Acc_XStr << "," <<Acc1.Acc_YStr<< "," <<Acc1.Acc_ZStr<< ","<<Acc1.Timestamp_MsStr<<endl;
                               }
                               else
                               {
                                   oFile << "Acc1ERR" << "," <<" "<< "," << " " << "," << " " << ","
                                         << " " << "," << " " << "," << " "<< "," << " " << "," << " " << "," << " "<< ","
                                         <<Acc1.Acc_status<< "," <<Acc1.Acc_XStr << "," <<Acc1.Acc_YStr<< "," <<Acc1.Acc_ZStr<< ","<<Acc1.Timestamp_MsStr<<endl;
                               }
                               break;
                           }
                       case 1:
                        {
                            FluxGate2.Mag_XVal=(float(( (unsigned char)Film_Temp[4]<< 16) + ((unsigned char)Film_Temp[5] << 8) + (unsigned char)Film_Temp[6]) / 16777215 -0.5) * 200000;
                            FluxGate2.Mag_YVal=(float(( (unsigned char)Film_Temp[7]<< 16) + ((unsigned char)Film_Temp[8] << 8) + (unsigned char)Film_Temp[9]) / 16777215 -0.5) * 200000;
                            FluxGate2.Mag_ZVal=(float(( (unsigned char)Film_Temp[10]<< 16) + ((unsigned char)Film_Temp[11] << 8) + (unsigned char)Film_Temp[12]) / 16777215 -0.5) * 200000;
                            if(FluxGate2.Mag_XVal==-100000&&FluxGate2.Mag_YVal==-100000&&FluxGate2.Mag_ZVal==-100000)
                            {
                                FluxGate2.Mag_XVal = 0;FluxGate2.Mag_YVal = 0;FluxGate2.Mag_ZVal = 0;
                            }
                            gcvt(FluxGate2.Mag_XVal ,8,FluxGate2.Mag_XStr);
                            gcvt(FluxGate2.Mag_YVal ,8,FluxGate2.Mag_YStr);
                            gcvt(FluxGate2.Mag_ZVal ,8,FluxGate2.Mag_ZStr);

                            FluxGate2.Timestamp_MsVal = (float)((Film_Temp[2] << 8) + Film_Temp[3])/2;
                            gcvt( FluxGate2.Timestamp_MsVal,10,FluxGate2.Timestamp_MsStr );

                            if(Film_Temp[FLUXGATE2_LEN-1]==0X69)//get_crc8(Film_Temp,FLUXGATE1_LEN-1))
                            {
                                oFile << "FluxGate2" << "," <<" "<< "," << " " << "," << " " << ","
                                      << " " << "," << " " << "," << " "<< ","<<FluxGate2.Mag_XStr<< "," <<FluxGate2.Mag_YStr<< "," <<FluxGate2.Mag_ZStr<< ","
                                      << " "<< "," << " " << "," << " "<< "," << " "<< ","<<FluxGate2.Timestamp_MsStr<<endl;
                            }
                            else
                            {
                                oFile << "FluxGate2ERR" << "," <<" "<< "," << " " << "," << " " << ","
                                      << " " << "," << " " << "," << " "<< ","<<FluxGate2.Mag_XStr<< "," <<FluxGate2.Mag_YStr<< "," <<FluxGate2.Mag_ZStr<< ","
                                      << " "<< "," << " " << "," << " "<< "," << " "<< ","<<FluxGate2.Timestamp_MsStr<<endl;
                            }
                            break;
                        }
                       case 2:
                           {
                               FluxGate1.Mag_XVal=(float(( (unsigned char)Film_Temp[4]<< 16) + ((unsigned char)Film_Temp[5] << 8) + (unsigned char)Film_Temp[6]) / 16777215 -0.5) * 200000;
                               FluxGate1.Mag_YVal=(float(( (unsigned char)Film_Temp[7]<< 16) + ((unsigned char)Film_Temp[8] << 8) + (unsigned char)Film_Temp[9]) / 16777215 -0.5) * 200000;
                               FluxGate1.Mag_ZVal=(float(( (unsigned char)Film_Temp[10]<< 16) + ((unsigned char)Film_Temp[11] << 8) + (unsigned char)Film_Temp[12]) / 16777215 -0.5) * 200000;
                               if(FluxGate1.Mag_XVal==-100000&&FluxGate1.Mag_YVal==-100000&&FluxGate1.Mag_ZVal==-100000)
                               {
                                   FluxGate1.Mag_XVal = 0;FluxGate1.Mag_YVal = 0;FluxGate1.Mag_ZVal = 0;
                               }
                               gcvt(FluxGate1.Mag_XVal ,8,FluxGate1.Mag_XStr);
                               gcvt(FluxGate1.Mag_YVal ,8,FluxGate1.Mag_YStr);
                               gcvt(FluxGate1.Mag_ZVal ,8,FluxGate1.Mag_ZStr);

                               FluxGate1.Timestamp_MsVal = (float)((Film_Temp[2] << 8) + Film_Temp[3])/2;
                               gcvt( FluxGate1.Timestamp_MsVal,10,FluxGate1.Timestamp_MsStr );

                               if(Film_Temp[FLUXGATE1_LEN-1]==0X69)//get_crc8(Film_Temp,FLUXGATE1_LEN-1))
                               {
                                   oFile << "FluxGate1" << "," <<" "<< "," << " " << "," << " " << ","
                                         <<FluxGate1.Mag_XStr<< "," <<FluxGate1.Mag_YStr<< "," <<FluxGate1.Mag_ZStr<< "," << " " << "," << " " << "," << " "<< ","
                                         << " "<< "," << " " << "," << " "<< "," << " "<< ","<<FluxGate1.Timestamp_MsStr<<endl;
                               }
                               else
                               {
                                   oFile << "FluxGate1ERR" << "," <<" "<< "," << " " << "," << " " << ","
                                         <<FluxGate1.Mag_XStr<< "," <<FluxGate1.Mag_YStr<< "," <<FluxGate1.Mag_ZStr<< "," << " " << "," << " " << "," << " "<< ","
                                         << " "<< "," << " " << "," << " "<< "," << " "<< ","<<FluxGate1.Timestamp_MsStr<<endl;
                               }
                               break;
                           }
                       case 3:
                           {
                                gcvt((float)((Film_Temp[2] << 8) + Film_Temp[3])/2,10,IMU_GPS1.Timestamp_MsStr );
                                switch(Film_Temp[4]&0X0f)
                                {
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
                                    case 1:{strcpy(IMU_GPS1.POS_status ,"NONE");break;}
                                    case 2:{strcpy(IMU_GPS1.POS_status ,"INS_PSRSP");break;}
                                    case 3:{strcpy(IMU_GPS1.POS_status ,"INS_PSRDIFF");break;}
                                    case 4:{strcpy(IMU_GPS1.POS_status ,"INS_RTKFLOAT");break;}
                                    case 5:{strcpy(IMU_GPS1.POS_status ,"INS_RTKFIXED");break;}
                                    default:{strcpy(IMU_GPS1.POS_status,"-");break;}
                                }
                                gcvt((float)((Film_Temp[6]<<8) + Film_Temp[5]),4,IMU_GPS1.GPSTime_week_Str );

                                for(int i=0;i<20;i++)
                                {
                                    if(i==1||i==2)
                                        gcvt((0x40-((unsigned char)Film_Temp[10+i*8]&0x80))/0x40*((float)(((unsigned char)Film_Temp[7+i*8]) + ((unsigned char)Film_Temp[8+i*8] << 8) + (Film_Temp[9+i*8] << 16)) +
                                        (float)(((unsigned char)Film_Temp[11+i*8]) + ((unsigned char)Film_Temp[12+i*8] << 8) + ((unsigned char)Film_Temp[13+i*8] << 16) + ((unsigned char)Film_Temp[14+i*8] << 24))
                                                /pow(10,((unsigned char)Film_Temp[10+i*8]&0x7f)))/100,14,IMU_GPS1.IMUDataAll[i]);
                                    else {
                                        gcvt((0x40-((unsigned char)Film_Temp[10+i*8]&0x80))/0x40*((float)(((unsigned char)Film_Temp[7+i*8]) + ((unsigned char)Film_Temp[8+i*8] << 8) + (Film_Temp[9+i*8] << 16)) +
                                        (float)(((unsigned char)Film_Temp[11+i*8]) + ((unsigned char)Film_Temp[12+i*8] << 8) + ((unsigned char)Film_Temp[13+i*8] << 16) + ((unsigned char)Film_Temp[14+i*8] << 24))
                                                /pow(10,((unsigned char)Film_Temp[10+i*8]&0x7f))),14,IMU_GPS1.IMUDataAll[i]);
                                    }
                                }
                                oFile << "IMU1" << "," <<" "<< "," << " " << "," << " " << ","<<" "<< "," <<" "<< "," <<" "<< "," << " " << "," << " " << "," << " "<< ","
                                      << " "<< "," << " " << "," << " "<< "," << " "<< ","<<IMU_GPS1.Timestamp_MsStr<<","<<IMU_GPS1.GPSTime_week_Str
                                      <<","<<IMU_GPS1.IMUDataAll[0]<<","<<IMU_GPS1.INS_status<<","<<IMU_GPS1.POS_status ;
                                for(int i=1;i<20;i++)
                                {
                                   oFile << "," <<IMU_GPS1.IMUDataAll[i];
                                }
                               oFile<<endl;
                               break;
                           }
                       default:break;
                    }
                    Film_Length = 0;
                    memset(Film_Temp,0,500);
                }
         }
   }
   oFile.close();
}

void filetrans::stop()
{
    this->terminate();
    this->wait();
}

void filetrans::FiletransProgress_Update()
{
    emit ProgressBar_Update();
}

void filetrans::MakeCheckSum (uint8_t Buf[], int len)
{
    unsigned char  sum=0, idx;
    for(idx=0; idx<(len-1); idx++)
        {
            sum += Buf[idx];
        }
    Buf[len-1] = 256 - sum;
}

float filetrans::Byte2Float_GYRO24_HL(unsigned char data[], int startIndex)
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
