#include <qmath.h>
#include "particle.h"

//===================================================================
Particle::Particle(PARTICLETYPE type, QObject *parent) : Sphere(parent),
    mType(type), mVelocity(0.0, 0.0, 0.0)
{
    // ctor
    setObjectName(name());

    mTextures[RED]   = ":/textures/images/RedQuark.png";
    mTextures[BLUE]  = ":/textures/images/BlueQuark.png";
    mTextures[GREEN] = ":/textures/images/GreenQuark.png";
    mTextures[WHITE] = ":/textures/images/WhiteHadron.png";

    mSeg   = 20;
    switch (type) {
    case QUARK:
        mRadius = 0.5;
        break;
    case HADRON:
        mRadius = 1.0;
        break;
    default:
        break;
    }

    makeMesh();
}

//===================================================================
Particle::COLOR Particle::color() const
{
    // return color charge
       COLOR rv;
       switch (mColor) {
       case RED:
           rv = RED;
           break;
       case BLUE:
           rv = BLUE;
           break;
       case GREEN:
           rv = GREEN;
           break;
       case WHITE:
           rv = WHITE;
           break;
       default:
           rv = NONE;
           break;
       }
       return rv;
}

//===================================================================
const char *Particle::colorName() const
{
    // returns the color name
    const char * name;
    switch (mColor) {
    case RED:
        name = "RED";
        break;
    case BLUE:
        name = "BLUE";
        break;
    case GREEN:
        name = "GREEN";
        break;
    case WHITE:
        name = "WHITE";
        break;
    default:
        name = "WHITE";
        break;
    }
    return name;
}

//===================================================================
QString Particle::name() const
{
    // return the name of the particle

    switch (mType) {
    case QUARK:
        return QString("Quark");
        break;
    case HADRON:
        return QString("Hadron");
        break;
    default:
        qDebug() << Q_FUNC_INFO << ": " << mType << "not a valid particle type";
        exit(1);
        break;
    }
}

//===================================================================
void Particle::setColor(Particle::COLOR color)
{
    // set the color charge of the particle

    switch (mType) {
    case QUARK:
        mColor = color;
        break;
    case HADRON:
        mColor = WHITE;
    default:
        break;
    }
    setTextureImage(mTextures[mColor]);
}

//===================================================================
void Particle::setVelocity(double betat, double betaz)
{
    // set the 3D velocity vector of particle: betat (transverse velocity), betaz (longitudinal velocity)

    int sign = (2 * ((qreal)qrand() / (qreal) RAND_MAX) - 1.0) > 0 ? 1 : -1 ;
    sign = 1;
    mVelocity.setZ(betaz * sign);
    double x = (double)qrand() / ((double)RAND_MAX);
    sign = (2 * ((qreal)qrand() / (qreal) RAND_MAX) - 1.0) > 0 ? 1 : -1 ;
    mVelocity.setX(betat * x * sign);
    double y =  qSqrt(1 - x*x);
    sign = (2 * ((qreal)qrand() / (qreal) RAND_MAX) - 1.0) > 0 ? 1 : -1 ;
    mVelocity.setY(betat * y * sign);
}
