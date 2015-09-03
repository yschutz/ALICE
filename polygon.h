#ifndef POLYGON_H
#define POLYGON_H

#include "mesh.h"

class Polygon : public Mesh
{
    Q_OBJECT

public:
    Polygon(QObject *parent = 0);
    Polygon(float radius, int nseg, QObject *parent = 0);

    void makeMesh();

private:
    float mRadius ; // radius cercle circonscrit
    int   mSeg;     // number of segments
};

#endif // POLYGON_H
