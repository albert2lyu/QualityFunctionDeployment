#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("跨界服务价值—全局质量配置"); // 此处写应用程序在标题栏上显示的名称
    w.show();
    return a.exec();


}
