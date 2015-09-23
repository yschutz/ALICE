#include "alice.h"
#include "annulusmesh.h"
#include "torusmesh.h"
#include "tubemesh.h"

//===================================================================
Alice::Alice(QObject *parent) : QObject(parent)
{
    // decfault ctor: defines the shapes making ALICE

    setObjectName("ALICE");

    mElementsName.resize(NELE);
    mElementsName[L3B]       = "L3B";
    mElementsName[L3F]       = "L3F";
    mElementsName[L3BODY]    = "L3Body";
    mElementsName[BEAMSPIPE] = "Beams Pipe";

    Create();
    if (mElements.isEmpty()) {
        qWarning("Alice::Alice: ALICE elements have not been created");
        exit(QtWarningMsg);
    }
}

//===================================================================
Alice::~Alice()
{
    //dtor
    mElements.clear();
}

//===================================================================
void Alice::Create()
{
    CreateLHC();
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
    const double kLength      =  l3Length(); //meters
    const int    kSides       =   8;      //it's an octogone
    const double kRotate      = 180. / kSides;


    cgl::AnnulusMesh *l3B = new cgl::AnnulusMesh(kOuterRadius, kInnerRadius, kSides);       // back of L3
    l3B->setObjectName(mElementsName[L3B]);
    l3B->setTextureImage(":/textures/images/IronRed.jpg");
    l3B->rotate(kRotate, 0.0, 0.0, 1.0);
    l3B->translate(0.0, 0.0, -kLength / 2.0);
    mElements.append(l3B);

    cgl::AnnulusMesh *l3F = new cgl::AnnulusMesh(kOuterRadius, kInnerRadius, kSides);       // front of L3
    l3F->setObjectName(mElementsName[L3F]);
    l3F->setTextureImage(":/textures/images/IronRed.jpg");
    l3F->rotate(kRotate, 0.0, 0.0, 1.0);
    l3F->translate(0.0, 0.0, kLength / 2.0);
    mElements.append(l3F);

    cgl::TubeMesh *l3Body = new cgl::TubeMesh(kOuterRadius, kInnerRadius, kSides, kLength); // the body of L3
    l3Body->setObjectName(mElementsName[L3BODY]);
    l3Body->setTextureImage(":/textures/images/IronRed.jpg");
    l3Body->rotate(kRotate, 0.0, 0.0, 1.0);
    mElements.append(l3Body);
}

//===================================================================
void Alice::CreateLHC()
{
    // create the LHC ring

    const double kRadius         = lhcRadius();
    const double kBeamPipeRadius = 53E-3;            // beam pipe radius is 53mm


    qDebug() << Q_FUNC_INFO;

    mLHC = new cgl::TorusMesh(kBeamPipeRadius, kRadius, 100);
    mLHC->setObjectName(mElementsName[BEAMSPIPE]);
    mLHC->setTextureImage(":/textures/images/brushed_aluminium_texture__tileable___2048x2048__by_fabooguy-d6z6quk.jpg");
    float scale = 1.5;
    mLHC->translate(kRadius, 0.0, 0.0);
    mLHC->rotate(90.0, 1.0, 0.0, 0.0);
    mElements.append(mLHC);
}

