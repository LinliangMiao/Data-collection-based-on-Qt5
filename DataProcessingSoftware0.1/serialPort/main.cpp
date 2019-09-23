#include <QWidget>
#include <QApplication>
#include "mainwindow.h"
#include"QTextCodec"

bool read_display_mutex;
bool clickedShowWaveBtn;
int precision_data;
bool start;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);

    MainWindow w;
    w.setWindowTitle("MAGDATA AQUISITION");
    w.show();

    return a.exec();
}
