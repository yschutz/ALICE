#ifndef ANNULUS_H
#define ANNULUS_H

#include "mesh.h"

class Annulus : public Mesh
{
    Q_OBJECT

public:
    Annulus(QObject *parent = 0);
    Annulus(float rou, float rin, int nseg, QObject *parent = 0);

    void makeMesh();

private:
    float mRin;  // inner radius
    float mRou;  // outer radius
    int   mSeg;  // number of segments to aproximate circle
};

#endif // ANNULUS_H
