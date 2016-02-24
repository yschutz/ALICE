#ifndef ALICE_H
#define ALICE_H

#include <qmath.h>
#include <QObject>

#include "mesh.h"
#include "torusmesh.h"

class Alice : public QObject
{
    Q_OBJECT
    Q_ENUMS(ELEMENTS)

public:

    enum ELEMENTS {
        L3B, L3F, L3BODY, SPD1, SPD2, SDD1, SDD2, SSD1, SSD2, TPCINNER, TPCOUTER, TPCEPF, TPCEPB, TPCCE,
        TRD0, TRD1, TRD2, TRD3, TRD4, TRD5, TRD6, TRD01, TRD12, TRD23, TRD34, TRD45, TRD56, TRD60,
        TOFCYL, TOFBA, TOFFO, EMCM, EMCSM, PHOSM, BEAMSPIPE, NELE
    };

    explicit Alice(QObject *parent = 0);
    ~Alice();

    void              init();
    QString           elementName(ELEMENTS index) const { return mElementsName[index]; }
    QList<cgl::Mesh*> elements() const { return mElements; }

private:
    void create();
    void createITS();
    void createEMCAL();
    void createEMCALSuperModule(int index, bool full);
    void createEMCALModule();
    void createL3();
    void createLHC();
    void createPHOS();
    void createTOF();
    void createTPC();
    void createTRD();

//    float mEMCALAngle;                     //azimuthal angle covered by one EMCAL super module
    QList<cgl::Mesh*> mElements;           // list of meshes needed to build ALICE
    QVector<QString>  mElementsName;       // name of the various elements
    cgl::TorusMesh    *mLHC;               // the LHC beam pipe
};

#endif // ALICE_H
