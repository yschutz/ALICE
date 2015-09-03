#include <qmath.h>
#include "annulus.h"
#include "polygon.h"

//===================================================================
Annulus::Annulus(QObject *parent) : Mesh(parent),
    mRin(0.0), mRou(0.0), mSeg(0.0)
{

}

//===================================================================
Annulus::Annulus(float rou, float rin, int nseg, QObject *parent) : Mesh(parent),
    mRin(rou), mRou(rin), mSeg(nseg)
{
    // ctor

    setObjectName("Annulus");

    if (rou < rin) {
        qWarning("Annulus::Annulus: outer radius must be larger than inner radius");
        exit(QtWarningMsg);
    }

    makeMesh();
}

//===================================================================
void Annulus::makeMesh()
{
    // calculates the vertices of the mesh

    Polygon polOu(mRou, mSeg, this);
    Polygon polIn(mRin,  mSeg, this);

    float angStep = qDegreesToRadians(360. / mSeg);
    float ang = 0.0;

    int index = 0;

    for (int count = 0; count < polOu.countVertices() / 3; count++) {
        addVertex(polOu.vertices().at(index));
        addVertex(polOu.vertices().at(index+1));
        polIn.vertices()[index].setU(0.5 + mRin/mRou * 0.5 * qCos(ang));
        polIn.vertices()[index].setV(0.5 + mRin/mRou * 0.5 * qSin(ang));
        addVertex(polIn.vertices().at(index));

        addVertex(polOu.vertices().at(index+1));
        polIn.vertices()[index+1].setU(0.5 + mRin/mRou * 0.5 * qCos(ang + angStep));
        polIn.vertices()[index+1].setV(0.5 + mRin/mRou * 0.5 * qSin(ang + angStep));
        addVertex(polIn.vertices().at(index+1));
        addVertex(polIn.vertices().at(index));
        index +=3;
        ang += angStep;
    }

}

