#include "alice.h"
#include "annulusmesh.h"
#include "cubemesh.h"
#include "cylindermesh.h"
#include "polygonmesh.h"
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
    mElementsName[TRD0]      = "TRD outer envelop";
    mElementsName[TRD1]      = "TRD layer 1";
    mElementsName[TRD2]      = "TRD layer 2";
    mElementsName[TRD3]      = "TRD layer 3";
    mElementsName[TRD4]      = "TRD layer 4";
    mElementsName[TRD5]      = "TRD layer 5";
    mElementsName[TRD6]      = "TRD layer 6";
    mElementsName[TRD01]     = "TRD EP 01";
    mElementsName[TRD12]     = "TRD EP 12";
    mElementsName[TRD23]     = "TRD EP 23";
    mElementsName[TRD34]     = "TRD EP 34";
    mElementsName[TRD45]     = "TRD EP 45";
    mElementsName[TRD56]     = "TRD EP 56";
    mElementsName[TRD60]     = "TRD EP 60";
    mElementsName[TOFCYL]    = "TOF Cylinder";
    mElementsName[TOFBA]     = "TOF backward cap";
    mElementsName[TOFFO]     = "TOF forward cap";
    mElementsName[EMCM]      = "EMCAL Module";
    mElementsName[EMCSM]      = "EMCAL Super Module";
    mElementsName[BEAMSPIPE] = "Beams Pipe";

    create();
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
void Alice::create()
{
//    createLHC();
    createITS();
    createTPC();
    createTRD();
    createTOF();
    createEMCAL();
//    createL3();

    for(int index = 0; index < mElements.size(); index++)
        qDebug() << Q_FUNC_INFO<< mElements.at(index)->objectName();
}

//===================================================================
void Alice::createITS()
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
void Alice::createEMCAL()
{
    // create EMCAL
    const int kSuperModulesFull =  5; //10;
    const int kSuperModulesHalf = 0;

    for (int index = 0; index < kSuperModulesFull; index++)
        createEMCALSuperModule(index, true);

    for (int index = 0; index < kSuperModulesHalf; index++)
        createEMCALSuperModule(index, false);
}

//===================================================================
void Alice::createEMCALSuperModule(int index, bool full)
{
    // create one EMCAL Super Module full or half

    static int countH = 0;

    // the SM
    const float kEMCSMHeight = 0.4018;    // meters
    const float kEMCSMWidth  = 12 * 0.06; // meters
    const float kEMCSMLength = 24 * 0.06; // meters
    mEMCALAngle    = qAbs(2 * qAsin(kEMCSMWidth / emcPosX())) * 1.01;

    float angle = mEMCALAngle * index;

    if (full) {
        cgl::CubeMesh *emcSM;
        if (index == 0)
            emcSM = new cgl::CubeMesh(kEMCSMWidth, kEMCSMLength, kEMCSMHeight);
        else
            emcSM = new cgl::CubeMesh(*static_cast<cgl::CubeMesh*>(mElements.last()));

        emcSM->setTextureImage(":/textures/images/texture-1075992_960_720.jpg");
        emcSM->setObjectName(QString("%1 %2").arg(mElementsName[EMCSM]).arg(index));
        emcSM->translate(emcPosX() * qCos(angle), -emcPosX() * qSin(angle), 0.0);
        emcSM->rotate(90.0, 0, 1, 0);
        emcSM->rotate(90.0, 0, 0, 1);
        emcSM->rotate(-qRadiansToDegrees(angle), 0, 1, 0);
        mElements.append(emcSM);

//        createEMCALModule();
    }
    else
        qDebug() << Q_FUNC_INFO << ++countH;

}

//===================================================================
void Alice::createEMCALModule()
{
    // create one EMCAL Module, a module is made of 2x2 Towers

    // the tower
    const double kEMCTWidth      = 0.06;   // meters
    const double kEMCTLength     = 0.3418; // meters
    const int    kTowersInModule = 2;

    cgl::CubeMesh *emcM = new cgl::CubeMesh(kTowersInModule * kEMCTWidth, kTowersInModule * kEMCTWidth, kEMCTLength);
    emcM->setObjectName(mElementsName[EMCM]);
    emcM->setTextureImage(":/textures/images/texture-1075992_960_720.jpg");
    mElements.append(emcM);
}

//===================================================================
void Alice::createL3()
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
void Alice::createLHC()
{
    // create the LHC ring

    const double kRadius         = lhcRadius();
    const double kBeamPipeRadius = 30E-3; //53E-3;            // beam pipe radius is 53mm


    qDebug() << Q_FUNC_INFO;

    mLHC = new cgl::TorusMesh(kBeamPipeRadius, kRadius, 200, 1);
    mLHC->setObjectName(mElementsName[BEAMSPIPE]);
    mLHC->setTextureImage(":/textures/images/BeamPipeTexture.jpg");
    mLHC->rotate(90.0, 1.0, 0.0, 0.0);
    mLHC->translate(kRadius, 0.0, 0.0);
    mElements.append(mLHC);
}

//===================================================================
void Alice::createTOF()
{
    // Create the TOF

    const double kTOFInnerRadius = 3.70;        // meters
    const double kTOFOuterRadius = 4.00;        // meters
    const int    kTOFSectors     = 18;          // number of azimuthal sectors
    const double kTOFLength      = tofLength(); // meters

    cgl::AnnulusMesh *TOFback = new cgl::AnnulusMesh(kTOFOuterRadius, kTOFInnerRadius, kTOFSectors);
    TOFback->translate(0.0, 0.0, -kTOFLength / 2.0);
    TOFback->setObjectName(mElementsName[TOFBA]);
    TOFback->setTextureImage(":/textures/images/TPCTexture.jpg");
    mElements.append(TOFback);

    cgl::AnnulusMesh *TOFforw = new cgl::AnnulusMesh(kTOFOuterRadius, kTOFInnerRadius, kTOFSectors);
    TOFforw->translate(0.0, 0.0, kTOFLength / 2.0);
    TOFforw->setObjectName(mElementsName[TOFFO]);
    TOFforw->setTextureImage(":/textures/images/TPCTexture.jpg");
    mElements.append(TOFforw);

    cgl::TubeMesh *TOFcyl = new cgl::TubeMesh(kTOFOuterRadius, kTOFInnerRadius, kTOFSectors, kTOFLength);
    TOFcyl->setObjectName(mElementsName[TOFCYL]);
    TOFcyl->setTextureImage(":/textures/images/TPCTexture.jpg");
    mElements.append(TOFcyl);
}

//===================================================================
void Alice::createTPC()
{
    // create the TPC

    // all dimensions in meters

    const double kTPCLength = tpcLength();

    // Inner vessel
    const int    kSegInnerVessel = 18;
    const double kTPCInnerRadius = 1.140 / 2.0;
    cgl::CylinderMesh *TPCInnerVessel = new cgl::CylinderMesh(kTPCInnerRadius, kSegInnerVessel, kTPCLength);
    TPCInnerVessel->setObjectName(mElementsName[TPCINNER]);
    TPCInnerVessel->setTextureImage(":/textures/images/TPCTexture.jpg");
    mElements.append(TPCInnerVessel);

    // Outer vessel
    const int    kSegOuterVessel = 18;
    const double kTPCOuterRadius = 5.560 / 2.0;
    cgl::CylinderMesh *TPCOuterVessel = new cgl::CylinderMesh(kTPCOuterRadius, kSegOuterVessel, kTPCLength);
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
    endPlateF->translate(0.0, 0.0, kTPCLength / 2.0);
    endPlateF->setObjectName(mElementsName[TPCEPF]);
    endPlateF->setTextureImage(":/textures/images/TPCEndPlateTexture.jpg");
    mElements.append(endPlateF);

    cgl::AnnulusMesh *endPlateB = new cgl::AnnulusMesh(kTPCOuterRadius, kTPCInnerRadius, kSegEndPlate);
    endPlateB->translate(0.0, 0.0, -kTPCLength / 2.0);
    endPlateB->setObjectName(mElementsName[TPCEPB]);
    endPlateB->setTextureImage(":/textures/images/TPCEndPlateTexture.jpg");
    mElements.append(endPlateB);

}

//===================================================================
void Alice::createTRD()
{
    // create the TRD

    // all dimensions in meters

    const double kTRDLength  = trdLength();
    const double kTRDRou      = 3.69;
    const double kTRDRin      = 2.9;
    const double kTRDRLayer1 = 2.945;
    const double kTRDRLayer2 = 3.071;
    const double kTRDRLayer3 = 3.197;
    const double kTRDRLayer4 = 3.323;
    const double kTRDRLayer5 = 3.449;
    const double kTRDRLayer6 = 3.575;
    const int    kTRDPhiSeg  = 18;

    // outer envelops
    cgl::CylinderMesh *TRDOuterEnvelopIn = new cgl::CylinderMesh(kTRDRin, kTRDPhiSeg, kTRDLength);
    TRDOuterEnvelopIn->setObjectName(mElementsName[TRD0]);
    TRDOuterEnvelopIn->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(TRDOuterEnvelopIn);

    cgl::CylinderMesh *TRDOuterEnvelopOu = new cgl::CylinderMesh(kTRDRou, kTRDPhiSeg, kTRDLength);
    TRDOuterEnvelopOu->setObjectName(mElementsName[TRD0]);
    TRDOuterEnvelopOu->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(TRDOuterEnvelopOu);

    //layers and endplates
    cgl::CylinderMesh *TRDLayer1 = new cgl::CylinderMesh(kTRDRLayer1, kTRDPhiSeg, kTRDLength);
    TRDLayer1->setObjectName(mElementsName[TRD1]);
    TRDLayer1->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(TRDLayer1);

    cgl::AnnulusMesh *TRDEP01 = new cgl::AnnulusMesh(kTRDRLayer1, kTRDRin, kTRDPhiSeg);
    TRDEP01->translate(0.0, 0.0, kTRDLength / 2.0);
    TRDEP01->setObjectName(mElementsName[TRD01]);
    TRDEP01->setTextureImage(":/textures/images/TPCEndPlateTexture.jpg");
    mElements.append(TRDEP01);

    cgl::CylinderMesh *TRDLayer2 = new cgl::CylinderMesh(kTRDRLayer2, kTRDPhiSeg, kTRDLength);
    TRDLayer2->setObjectName(mElementsName[TRD1]);
    TRDLayer2->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(TRDLayer2);


    cgl::CylinderMesh *TRDLayer3 = new cgl::CylinderMesh(kTRDRLayer3, kTRDPhiSeg, kTRDLength);
    TRDLayer3->setObjectName(mElementsName[TRD1]);
    TRDLayer3->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(TRDLayer3);


    cgl::CylinderMesh *TRDLayer4 = new cgl::CylinderMesh(kTRDRLayer4, kTRDPhiSeg, kTRDLength);
    TRDLayer4->setObjectName(mElementsName[TRD1]);
    TRDLayer4->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(TRDLayer4);

    cgl::CylinderMesh *TRDLayer5 = new cgl::CylinderMesh(kTRDRLayer5, kTRDPhiSeg, kTRDLength);
    TRDLayer5->setObjectName(mElementsName[TRD1]);
    TRDLayer5->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(TRDLayer5);


    cgl::CylinderMesh *TRDLayer6 = new cgl::CylinderMesh(kTRDRLayer6, kTRDPhiSeg, kTRDLength);
    TRDLayer6->setObjectName(mElementsName[TRD6]);
    TRDLayer6->setTextureImage(":/textures/images/gold-texture.jpg");
    mElements.append(TRDLayer6);
}

