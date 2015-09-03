#ifndef CYLINDER_H
#define CYLINDER_H

#include "mesh.h"

class Cylinder : public Mesh
{
    Q_OBJECT

public:
    Cylinder(QObject *parent = 0);
    Cylinder(float radius, int nseg, float length, QObject *parent = 0);

    void makeMesh();

private:
    float mLength;  // length of cylinder
    float mRadius;  // radius of cylinder
    int   mSeg;     // number of segments to approximate circle
};

#endif // CYLINDER_H
