#include "laboratoryview.h"
#include <QGuiApplication>

#include <QDebug>
int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    LaboratoryView w;
    w.show();
    return a.exec();
}
