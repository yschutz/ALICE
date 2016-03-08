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
    mElementsName[EMCSM]     = "EMCAL Super Module";
    mElementsName[PHOSM]     = "PHOS Module";
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
}

//===================================================================
QString Alice::whereIs() const
{
    // check if point is inside a volume of ALICE

    for (int index = 0; index < mElements.size(); index++)
        qDebug() << "Checking" << mElementsName[index];
    return "";
}

//===================================================================
void Alice::create()
{
//    createLHC();
//    createITS();
//    createTPC();
//    createTRD();
//    createTOF();
//    createEMCAL();
//    createPHOS();
    createL3();

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
    const int kSuperModulesFull = 5;
    const int kSuperModulesHalf = 2;

    for (int index = 0; index < kSuperModulesFull; index++)
        createEMCALSuperModule(index, true);

    for (int index = 0; index < kSuperModulesHalf; index++)
        createEMCALSuperModule(index, false);
}

//===================================================================
void Alice::createEMCALSuperModule(int index, bool full)
{
    // create two EMCAL Super Modules full or half

    static int count = 0;

    // the SM
    const float kEMCSMHeight = 0.246;            // meters
    const float kEMCSMWidth  = 12 * 0.06 * 1.058; // meters
    const float kEMCSMLength = 24 * 0.06 * 1.058; // meters
    const float kEMCSMPosX   = 4.4;               // x distance of EMCAL super module to ALICE center in meters

    float emcAngle = qAbs(2 * qAsin(kEMCSMWidth / kEMCSMPosX));

    const float spacexy = 1.1;
    const float spacez  = 1.01;
    float width         = kEMCSMWidth ;
    float angle         = 0.0;

    cgl::CubeMesh *emcSM1, *emcSM2;

    if (full) {
       angle = emcAngle * index + emcAngle / 2.0;
    } else {
        width /= 2.0;
        if (index == 0)
            angle = - emcAngle / 4.0;
        else if (index == 1)
            angle = emcAngle * 5 + emcAngle / 4.0;
    }
    if (index == 0)
        emcSM1 = new cgl::CubeMesh(width, kEMCSMLength, kEMCSMHeight);
    else
        emcSM1 = new cgl::CubeMesh(*static_cast<cgl::CubeMesh*>(mElements.last()));

    emcSM1->setTextureImage(":/textures/images/texture-1075992_960_720.jpg");

    emcSM2 = new cgl::CubeMesh(*emcSM1);
    emcSM1->setObjectName(QString("%1 %2").arg(mElementsName[EMCSM]).arg(count));
    emcSM2->setObjectName(QString("%1 %2").arg(mElementsName[EMCSM]).arg(++count));

    emcSM1->translate(-kEMCSMPosX * qCos(angle) * spacexy, kEMCSMPosX * qSin(angle) * spacexy, spacez * kEMCSMLength);
    emcSM1->rotate(90.0, 0, 1, 0);
    emcSM1->rotate(90.0, 0, 0, 1);
    emcSM1->rotate(-qRadiansToDegrees(angle), 0, 1, 0);
    mElements.append(emcSM1);

    emcSM2->translate(-kEMCSMPosX * qCos(angle) * spacexy, kEMCSMPosX * qSin(angle) * spacexy, -spacez * kEMCSMLength);
    emcSM2->rotate(90.0, 0, 1, 0);
    emcSM2->rotate(90.0, 0, 0, 1);
    emcSM2->rotate(-qRadiansToDegrees(angle), 0, 1, 0);
    mElements.append(emcSM2);

    count++;
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

    const float kInnerRadius =   5.930; //meters
    const float kOuterRadius =   7.900; //meters
    const float kLength      =  14.1;   //L3 Length in meters
    const int    kSides      =   8;      //it's an octogone
    const float kRotate      = 180. / kSides;


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

    const float kRadius         = 26659 / 2 / M_PI;          // circumference is 26659 m
    const float kBeamPipeRadius = 30E-3; //53E-3;            // beam pipe radius is 53mm

    mLHC = new cgl::TorusMesh(kBeamPipeRadius, kRadius, 200, 1);
    mLHC->setObjectName(mElementsName[BEAMSPIPE]);
    mLHC->setTextureImage(":/textures/images/BeamPipeTexture.jpg");
    mLHC->rotate(90.0, 1.0, 0.0, 0.0);
    mLHC->translate(kRadius, 0.0, 0.0);
    mElements.append(mLHC);
}

//===================================================================
void Alice::createPHOS()
{
    // create PHOS
    const float kPHOSPosR    = 4.6;  // distance to center in meters
    const int   kPHOSModules = 5;    // number of modules;
    const float kPHOSWidth   = 56 * 0.022 / 1.9;  // width of one module in meters
    const float kPHOSLength  = 64 * 0.022 / 1.9;  // length of one module in meters
    const float kPHOSDepth   = 0.18; // length of one crystal

    const float phosAngle = qAbs(2 * qAsin(kPHOSWidth / kPHOSPosR));

    cgl::CubeMesh *phosM;
    float spacexy;
    for (int index = 0; index < kPHOSModules; index++) {
        if (index == 0) {
            phosM = new cgl::CubeMesh(kPHOSWidth, kPHOSLength, kPHOSDepth);
            phosM->setTextureImage(":/textures/images/texture-1075992_960_720.jpg");
        } else {
            phosM = new cgl::CubeMesh(*static_cast<cgl::CubeMesh *>(mElements.last()));
        }
        phosM->setObjectName(QString("%1 %2").arg(mElementsName[PHOSM]).arg(index));
        float angle = 2 * phosAngle - phosAngle * index;
        if (angle == 0)
            spacexy = 1.0;
        else
            spacexy = 1.0;
        phosM->translate(kPHOSPosR * spacexy * qSin(angle), -kPHOSPosR * qCos(angle), 0.0);
        phosM->rotate(90.0, 1, 0, 0);
        phosM->rotate(qRadiansToDegrees(angle), 0, 1, 0);
        mElements.append(phosM);
    }
}

//===================================================================
void Alice::createTOF()
{
    // Create the TOF

    const float kTOFInnerRadius = 3.70;                         // meters
    const float kTOFOuterRadius = 4.00;                         // meters
    const int    kTOFSectors     = 18;                           // number of azimuthal sectors
    const float kTOFLength      = 1.7829 * 2 + 1.47 * 2 + 1.14; // TOF length in meters

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

    const float kTPCLength = 5.1; // TPC length in meter

    // Inner vessel
    const int    kSegInnerVessel = 18;
    const float kTPCInnerRadius = 1.140 / 2.0;
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

    const double kTRDLength  = 7.0;  // TRD length in meter
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

