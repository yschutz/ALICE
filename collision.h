#ifndef COLLISION_H
#define COLLISION_H

#include <QObject>
#include "particle.h"

class Collision : public QObject
{
    Q_OBJECT
public:
    explicit Collision(QObject *parent = 0);

    QList<Particle*> particlesFS() const { return mParticlesFS; }

private:
    void addHadrons(int nHadrons);
    void addParticles(Particle::PARTICLETYPE type, int howMany);
    void addQuarks(int nQuarks);

    QList<Particle*>   mParticlesFS; // final state particles
    int                mHadrons;     // number of hadrons
    int                mQuarks;      // number of quarks
};

#endif // COLLISION_H
