#include "laboratoryview.h"
#include <QGuiApplication>
#include <QDebug>
#include "view.h"
#include "spheremesh.h"
#include "cubemesh.h"
#include "modelmesh.h"
#include "annulusmesh.h"
#include "vertex.h"

#include <QVector2D>
using namespace cgl;

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

// --- METHODE FACILE ------
//        View * view = new View();


//      AnnulusMesh * mesh = new AnnulusMesh(5.0, 4.0, 4);

//        mesh->setTextureImage(":/textures/images/BlueQuark.png");
//        view->scene()->addMesh(mesh);
//        view->show();
//        for (int index = 0; index < mesh->verticesCount(); index++)
//            qDebug() << mesh->vertex(index).x() << mesh->vertex(index).y() << mesh->vertex(index).z() << mesh->vertex(index).u() << mesh->vertex(index).v();
//        view->scene()->setDebug(true);
// -------------------------


 //---- METHODE ON AIME SE PRENDRE LA TETE
    LaboratoryView w;
//    w.scene()->setDebug(false);

    w.show();
// -------------------------


    return a.exec();
}
