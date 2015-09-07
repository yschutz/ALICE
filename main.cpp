#include "laboratoryview.h"
#include <QGuiApplication>
#include <QDebug>
#include "view.h"
#include "spheremesh.h"
#include "cubemesh.h"
#include "modelmesh.h"
#include "annulusmesh.h"
#include "tube.h"
#include <QVector2D>
using namespace cgl;

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    // --- METHODE FACILE ------
//    View * view = new View();


//    ModelMesh * mesh = new ModelMesh(":/man.obj");

//    mesh->setTextureImage(":/textures/damier.png");
//    view->scene()->addMesh(mesh);
//    view->show();

//    view->scene()->setDebug(true);
    // -------------------------


    // ---- METHODE ON AIME SE PRENDRE LA TETE
    LaboratoryView w;
    w.scene()->setDebug(false);

    w.show();
    // -------------------------


    return a.exec();
}
