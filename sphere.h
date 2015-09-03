#ifndef SPHERE_H
#define SPHERE_H

#include "mesh.h"

class Sphere : public Mesh
{
    Q_OBJECT

public:
    Sphere(QObject *parent = 0);
    Sphere(float radius, int nseg, QObject *parent = 0);

    void makeMesh() ;

protected:
    float mRadius; // sphere radius
    int   mSeg;    // number of segments to approximate sphere
};

#endif // SPHERE_H
