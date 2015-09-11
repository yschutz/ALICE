#ifndef Particle_H
#define Particle_H

#include <QDebug>
#include <QVector3D>
#include "spheremesh.h"

class Particle : public cgl::SphereMesh
{
    Q_OBJECT
    Q_ENUMS(PARTICLETYPE)
    Q_ENUMS(COLOR)

public:

    enum PARTICLETYPE {
        QUARK, HADRON
    };

    enum COLOR { RED, BLUE, GREEN, WHITE, NONE} ;

    explicit Particle(PARTICLETYPE type, QObject *parent = 0);
    ~Particle();

    COLOR          color() const;
    const char*    colorName() const;
    void           move(qreal time);
    QString        name() const;
    double         posX() const { return mPosition.x(); }
    double         posY() const { return mPosition.y(); }
    double         posZ() const { return mPosition.z(); }
    void           print() const;
    void           setColor(COLOR color);
    void           setPosition(double xpos, double ypos, double zpos, double t = 0.0);
    void           setVelocity(double betat, double betaz);
    PARTICLETYPE   type() const { return mType; }

    bool  isActive() const { return mActive; }
    float life() const { return mLife; }
    float fade() const { return mFade; }
    void setActive() { mActive = true; }
    void unsetActive() { mActive = false; }
    void setLife(float val) { mLife = val; }
    void setFade(float val) { mFade = val; }
    void setDirection( float x, float y, float z) {mXDirection = x; mYDirection = y; mZDirection = z; }
    void setGravity(float x, float y, float z) {mXGravity = x; mYGravity = y; mZGravity = z; }
    void setPos(float x, float y, float z) { mX = x; mY = y; mZ = z; }
    float x() const { return mX; }
    float y() const { return mY; }
    float z() const { return mZ; }
    float xD() const { return mXDirection; }
    float yD() const { return mYDirection; }
    float zD() const { return mZDirection; }
    float xG() const { return mXGravity; }
    float yG() const { return mYGravity; }
    float zG() const { return mZGravity; }

private:
    int                 mColor;         // color charge of the particle
    QVector3D           mPosition;      // particle's position in lab frame
    PARTICLETYPE        mType;          // kind of particle
    QVector3D           mVelocity;      // velocity vector relative to velocity of light
    QString             mTextures[NONE];// liste of texture files name
    bool  mActive;
    float mLife;
    float mFade;
    float mX;
    float mY;
    float mZ;
    float mXDirection;
    float mYDirection;
    float mZDirection;
    float mXGravity;
    float mYGravity;
    float mZGravity;
};

#endif // Particle_H
