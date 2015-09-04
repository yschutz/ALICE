#include "laboratoryview.h"
#include <QGuiApplication>
#include <QDebug>
#include "view.h"
#include "spheremesh.h"
#include "cubemesh.h"
#include "modelmesh.h"

using namespace cgl;

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);


    //    View * view = new View();

    //    ModelMesh * mesh = new ModelMesh("/home/sacha/complexe.obj");
    //    view->scene()->addMesh(mesh);

    //    view->show();



    LaboratoryView w;
    w.show();
    return a.exec();
}
