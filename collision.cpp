#include <QTime>
#include "collision.h"
#include "particle.h"

//===================================================================
Collision::Collision(QObject *parent) : QObject(parent)
{
    // ctor
    setObjectName("A collision");

    QTime now = QTime::currentTime();
    qsrand(now.msec());
    qrand();
    addParticles(Particle::HADRON, 1);
    addParticles(Particle::QUARK,  1);


}

//===================================================================
void Collision::addHadrons(int nHadrons)
{
    // add hadrons to the final state particles list

    for (int num = 0; num < nHadrons; num++) {
        Particle *part = new Particle(Particle::HADRON, this);
        part->setColor(Particle::WHITE);
        part->setTextureImage(":/textures/images/WhiteHadron.png");
        part->setVelocity(0.6, 0.9);
        mParticlesFS.append(part);
        mHadrons++;
    }

}

//===================================================================
void Collision::addParticles(Particle::PARTICLETYPE type, int howMany)
{
    // adds the final state particles to the collisions
    switch (type) {
    case Particle::QUARK:
        addQuarks(howMany);
        break;
    case Particle::HADRON:
        addHadrons(howMany);
        break;
    default:
        break;
    }
}

//===================================================================
void Collision::addQuarks(int nQuarks)
{
    // add a quark to the final state particles list
    // select randomly the color

    QString textureName;
    for (int num = 0; num < nQuarks; num++) {
        Particle *part = new Particle(Particle::QUARK, this);
        int color = qrand() % ((Particle::GREEN + 1) - Particle::RED) + Particle::RED;
        switch (color) {
        case Particle::RED:
            part->setColor(Particle::RED);
            part->setTextureImage(":/textures/images/RedQuark.png");
            break;
        case Particle::BLUE:
            part->setColor(Particle::BLUE);
            part->setTextureImage(":/textures/images/BlueQuark.png");
            break;
        case Particle::GREEN:
            part->setColor(Particle::GREEN);
            part->setTextureImage(":/textures/images/GreenQuark.png");
            break;
        default:
            break;
        }
        part->setVelocity(0.6, 0.9);
        mParticlesFS.append(part);
        mQuarks++;
    }
}

