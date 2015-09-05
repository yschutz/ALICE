#include "laboratoryview.h"
#include <QGuiApplication>
#include <QDebug>
#include "view.h"
#include "spheremesh.h"
#include "cubemesh.h"
#include "modelmesh.h"
#include "annulusmesh.h"
#include "tube.h"

using namespace cgl;

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

// --- METHODE FACILE ------
//        View * view = new View();
//        ModelMesh * mesh = new ModelMesh(":/images/alice.obj");
//        mesh->scale(5);
//        mesh->setTextureImage(":/textures/images/IronRed.jpg");
//        view->scene()->addMesh(mesh);
//        view->show();
// -------------------------


// ---- METHODE ON AIME SE PRENDRE LA TETE
    LaboratoryView w;
    w.show();
// -------------------------


    return a.exec();
}
