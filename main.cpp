#include "laboratoryview.h"
#include <QGuiApplication>
#include <QDebug>
#include "view.h"
#include "spheremesh.h"
#include "cubemesh.h"
#include "modelmesh.h"
#include "torusmesh.h"
#include <QVector2D>
using namespace cgl;

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

// --- METHODE FACILE ------
//        View * view = new View();

//      TorusMesh * mesh = new TorusMesh(5.0, 20.0, 20);
//      mesh->setTextureImage(":/textures/images/BeamPipeTexture.jpg");
//        view->scene()->addMesh(mesh);
//        view->show();
//        mesh->translate(0,-20,0);
//        view->scene()->addMesh(mesh);
//        view->show();
//        for (int index = 0; index < mesh->verticesCount(); index++)
//            qDebug() << mesh->vertex(index).x() << mesh->vertex(index).y() << mesh->vertex(index).z() << mesh->vertex(index).u() << mesh->vertex(index).v();
//        view->scene()->setDebug(true);
// -------------------------


 //---- METHODE ON AIME SE PRENDRE LA TETE
    LaboratoryView w;
    w.scene()->setDebug(false);

    w.show();
// -------------------------


    return a.exec();
}
