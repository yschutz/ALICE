//#include "laboratoryview.h"
#include <QGuiApplication>
#include <QDebug>
#include "view.h"

using namespace cgl;

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);


    View * view = new View();

    view->show();



//    LaboratoryView w;
//    w.show();
    return a.exec();
}
