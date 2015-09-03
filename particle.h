#ifndef PARTICLE_H
#define PARTICLE_H

#include "sphere.h"

class QString;

class Particle : public Sphere
{
    Q_OBJECT
    Q_ENUMS(PARTICLETYPE)
    Q_ENUMS(COLOR)

public:
    enum PARTICLETYPE {
        QUARK, HADRON
    };

    enum COLOR {
        RED, BLUE, GREEN, WHITE, NONE
    };

    explicit Particle(PARTICLETYPE type, QObject *parent = 0);

    COLOR       color() const ;
    const char *colorName() const;
    QString     name() const;
    void        setColor(COLOR color);
    void        setVelocity(double betat, double betaz);



private:
    int                 mColor;          // color charge of the particle
    PARTICLETYPE        mType;           // kind of particle
    QVector3D           mVelocity;       // velocity vector relative to velocity of light
    QString             mTextures[NONE]; // listeof texture files name

};

#endif // PARTICLE_H
