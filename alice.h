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
        L3B, L3F, L3BODY, SPD1, SPD2, SDD1, SDD2, SSD1, SSD2, BEAMSPIPE, NELE
    };

    explicit Alice(QObject *parent = 0);
    ~Alice();

    void              Init();
    QString           ElementName(ELEMENTS index) const { return mElementsName[index]; }
    QList<cgl::Mesh*> Elements() const { return mElements; }
    float             l3Length() const { return 14.1; } // L3 Length in meter
    float             lhcRadius() const { return 26659 / 2 / M_PI; } // circumference is 26659 m

private:
    void Create();
    void CreateITS();
    void CreateL3();
    void CreateLHC();

    QList<cgl::Mesh*> mElements;           // list of meshes needed to build ALICE
    QVector<QString>  mElementsName;       // name of the various elements
    cgl::TorusMesh    *mLHC;               // the LHC beam pipe
};

#endif // ALICE_H
