#ifndef Collision_H
#define Collision_H

#include <QObject>

#include "particle.h"

class Collision : public QObject
{
    Q_OBJECT
public:
   explicit Collision(QObject *parent = 0);
   ~Collision();

//    void Draw(qreal xcent, qreal ycent, qreal zcent) const;

    QList<Particle*> finalStateParticles() const { return mFSParticles; }
    
protected:
    void addHadrons(int nHadrons);
    void addParticles(Particle::PARTICLETYPE type, int howMany);
    void addQuarks(int howMany);

private:
    QList<Particle*> mFSParticles; // final state particles
    int              mHadrons;     // number of hadrons
    int              mQuarks;      // number of quarks
};

#endif // Collision_H
