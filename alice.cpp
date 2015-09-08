#include "alice.h"
#include "annulusmesh.h"
#include "tubemesh.h"

//===================================================================
Alice::Alice(QObject *parent) : QObject(parent)
{
    // decfault ctor: defines the shapes making ALICE

    setObjectName("ALICE");
    Create();
    if (mElements.isEmpty()) {
        qWarning("Alice::Alice: ALICE elements have not been created");
        exit(QtWarningMsg);
    }
}

//===================================================================
void Alice::Create()
{
    CreateL3();

    for(int index = 0; index < mElements.size(); index++)
        qDebug() << Q_FUNC_INFO<< mElements.at(index)->objectName();
}

//===================================================================
void Alice::CreateL3()
{
    // create the L3 magnet

    const double kInnerRadius =   5.930; //meters
    const double kOuterRadius =   7.900; //meters
    const double kLength      =  14.1; //meters
    const int    kSides       =   8;      //it's an octogone
    const double kRotate      = 180. / kSides;


    cgl::AnnulusMesh *l3B = new cgl::AnnulusMesh(kOuterRadius, kInnerRadius, kSides);       // back of L3
    l3B->setObjectName(QString("L3B"));
    l3B->setTextureImage(":/textures/images/IronRed.jpg");
    l3B->rotate(kRotate, 0.0, 0.0, 1.0);
    l3B->translate(0.0, 0.0, -kLength / 2.0);
    mElements.append(l3B);

    cgl::AnnulusMesh *l3F = new cgl::AnnulusMesh(kOuterRadius, kInnerRadius, kSides);       // front of L3
    l3F->setObjectName(QString("L3F"));
    l3F->setTextureImage(":/textures/images/BlueQuark.png");
    l3F->rotate(kRotate, 0.0, 0.0, 1.0);
    l3F->translate(0.0, 0.0, kLength / 2.0);
    mElements.append(l3F);

    cgl::TubeMesh *l3Body = new cgl::TubeMesh(kOuterRadius, kInnerRadius, kSides, kLength); // the body of L3
    l3Body->setObjectName(QString("L3Body"));
    l3Body->setTextureImage(":/textures/images/IronRed.jpg");
    l3Body->rotate(kRotate, 0.0, 0.0, 1.0);
    mElements.append(l3Body);
}

