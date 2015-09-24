#include "alice.h"
#include "annulusmesh.h"
#include "cylindermesh.h"
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
    mElementsName[SPD1]      = "Pixel Layer 1";
    mElementsName[SPD2]      = "Pixel Layer 2";
    mElementsName[SDD1]      = "Drift Layer 1";
    mElementsName[SDD2]      = "Drift Layer 2";
    mElementsName[SSD1]      = "Strip Layer 1";
    mElementsName[SSD2]      = "Strip Layer 2";
    mElementsName[TPCINNER]  = "TPC Inner Vessel";
    mElementsName[TPCOUTER]  = "TPC Outer Vessel";
    mElementsName[TPCEPF]    = "TPC End Plate Front";
    mElementsName[TPCEPB]    = "TPC End Plate Back";
    mElementsName[TPCCE]     = "TPC End Central Electrode";
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
    CreateITS();
    CreateTPC();
    CreateL3();

    for(int index = 0; index < mElements.size(); index++)
        qDebug() << Q_FUNC_INFO<< mElements.at(index)->objectName();
}

//===================================================================
void Alice::CreateITS()
{
    // create ITS 6 concentric cylinders

    // SPD all dimensions in meters
    const double kSPD1Radius  = 0.040;
    const double kSPD2Radius  = 0.070;
    const double kSPD1Length  = 0.165 * 2;
    const double kSPD2Length  = 0.165 * 2;
    const int    kSPD1Staves  = 20;
    const int    kSPD2Staves  = 40;

    cgl::CylinderMesh *spd1 = new cgl::CylinderMesh(kSPD1Radius, kSPD1Staves, kSPD1Length);
    spd1->setObjectName(mElementsName[SPD1]);
    spd1->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(spd1);
    cgl::CylinderMesh *spd2 = new cgl::CylinderMesh(kSPD2Radius, kSPD2Staves, kSPD2Length);
    spd2->setObjectName(mElementsName[SPD2]);
    spd2->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(spd2);

    // SDD all dimensions in meters
    const double kSDD1Radius = 0.149;
    const double kSDD2Radius = 0.238;
    const double kSDD1Length  = 0.222 * 2;
    const double kSDD2Length  = 0.297 * 2;
    const int    kSDD1Ladders  = 14;
    const int    kSDD2Ladders  = 22;

    cgl::CylinderMesh *sdd1 = new cgl::CylinderMesh(kSDD1Radius, kSDD1Ladders, kSDD1Length);
    sdd1->setObjectName(mElementsName[SDD1]);
    sdd1->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(sdd1);
    cgl::CylinderMesh *sdd2 = new cgl::CylinderMesh(kSDD2Radius, kSDD2Ladders, kSDD2Length);
    sdd2->setObjectName(mElementsName[SDD2]);
    sdd2->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(sdd2);

    // SSD all dimensions in meters
    const double kSSD1Radius = 0.391;
    const double kSSD2Radius = 0.436;
    const double kSSD1Length  = 0.451 * 2;
    const double kSSD2Length  = 0.508 * 2;
    const int    kSSD1Ladders  = 34;
    const int    kSSD2Ladders  = 38;

    cgl::CylinderMesh *ssd1 = new cgl::CylinderMesh(kSSD1Radius, kSSD1Ladders, kSSD1Length);
    ssd1->setObjectName(mElementsName[SSD1]);
    ssd1->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(ssd1);
    cgl::CylinderMesh *ssd2 = new cgl::CylinderMesh(kSSD2Radius, kSSD2Ladders, kSSD2Length);
    ssd2->setObjectName(mElementsName[SSD2]);
    ssd2->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(ssd2);


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
    const double kBeamPipeRadius = 30E-3; //53E-3;            // beam pipe radius is 53mm


    qDebug() << Q_FUNC_INFO;

    mLHC = new cgl::TorusMesh(kBeamPipeRadius, kRadius, 200);
    mLHC->setObjectName(mElementsName[BEAMSPIPE]);
    mLHC->setTextureImage(":/textures/images/BeamPipeTexture.jpg");
    mLHC->rotate(90.0, 1.0, 0.0, 0.0);
    mLHC->translate(kRadius, 0.0, 0.0);
    mElements.append(mLHC);
}

//===================================================================
void Alice::CreateTPC()
{
    // create the TPC

    // all dimensions in meters

    const double kLength = tpcLength();

    // Inner vessel
    const int    kSegInnerVessel = 18;
    const double kTPCInnerRadius = 1.140 / 2.0;
    cgl::CylinderMesh *TPCInnerVessel = new cgl::CylinderMesh(kTPCInnerRadius, kSegInnerVessel, kLength);
    TPCInnerVessel->setObjectName(mElementsName[TPCINNER]);
    TPCInnerVessel->setTextureImage(":/textures/images/TPCTexture.jpg");
    mElements.append(TPCInnerVessel);

    // Outer vessel
    const int    kSegOuterVessel = 18;
    const double kTPCOuterRadius = 5.560 / 2.0;
    cgl::CylinderMesh *TPCOuterVessel = new cgl::CylinderMesh(kTPCOuterRadius, kSegOuterVessel, kLength);
    TPCOuterVessel->setObjectName(mElementsName[TPCOUTER]);
    TPCOuterVessel->setTextureImage(":/textures/images/TPCTexture.jpg");
    mElements.append(TPCOuterVessel);

    //central Electode
    cgl::AnnulusMesh *centralElectrode = new cgl::AnnulusMesh(kTPCOuterRadius, kTPCInnerRadius, kSegOuterVessel);
    centralElectrode->setObjectName(mElementsName[TPCCE]);
    centralElectrode->setTextureImage(":/textures/images/TPCCETexture.jpg");
    mElements.append(centralElectrode);

    // End Plates
    const int kSegEndPlate = 18;
    cgl::AnnulusMesh *endPlateF = new cgl::AnnulusMesh(kTPCOuterRadius, kTPCInnerRadius, kSegEndPlate);
    endPlateF->translate(0.0, 0.0, kLength / 2.0);
    endPlateF->setObjectName(mElementsName[TPCEPF]);
    endPlateF->setTextureImage(":/textures/images/TPCEndPlateTexture.jpg");
    mElements.append(endPlateF);

    cgl::AnnulusMesh *endPlateB = new cgl::AnnulusMesh(kTPCOuterRadius, kTPCInnerRadius, kSegEndPlate);
    endPlateB->translate(0.0, 0.0, -kLength / 2.0);
    endPlateB->setObjectName(mElementsName[TPCEPB]);
    endPlateB->setTextureImage(":/textures/images/TPCEndPlateTexture.jpg");
    mElements.append(endPlateB);

}

