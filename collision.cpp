#include <QDebug>
#include <QImage>
#include <QTime>
#include "collision.h"

//=====================================================================================
Collision::Collision(QObject *parent) : QObject(parent), mQuarks(0)
{
    // default ctor
    setObjectName("A collision");

    // add 3 quarks to the particle list

    QTime now = QTime::currentTime();
    qsrand(now.msec());
    qrand();
//    AddParticles(Particle::HADRON, 1);
    addParticles(Particle::QUARK,  1);

    for (int index = 0; index < mFSParticles.size(); index++)
        mFSParticles.at(index)->print();
}



//=====================================================================================
Collision::~Collision()
{
    // dtor

//    qDeleteAll(mFSParticles.begin(), mFSParticles.end());
//    mFSParticles.clear();
}

//=====================================================================================
////void Collision::draw(qreal xcent, qreal ycent, qreal zcent) const
//{
//    // draw the collision

//    static qreal time = 0;

//    const char *textureName;
//    for(int index = 0; index < mFSParticles.size(); index++) {
//        Particle * part = mFSParticles.at(index);
//        switch (part->Color()) {
//        case Particle::RED:
//            textureName = ":/textures/images/RedQuark.png";
//            break;
//        case Particle::BLUE:
//            textureName = ":/textures/images/BlueQuark.png";
//            break;
//        case Particle::GREEN:
//            textureName = ":/textures/images/GreenQuark.png";
//            break;
//        case Particle::WHITE:
//            textureName = ":/textures/images/WhiteHadron.png";
//            break;
//        default:
//            break;
//        }
//        part->SetTexture(QImage(textureName));
//        part->Move(time);
//        glLoadIdentity();
//        glTranslatef(xcent + part->PosX(), ycent + part->PosY(), zcent + part->PosZ());
//        part->Draw();
//    }
////    time += 0.01;
//}

//=====================================================================================
void Collision::addHadrons(int nHadrons)
{

    // add hadrons to the final state particles list

    for (int num = 0; num < nHadrons; num++) {
        Particle *part = new Particle(Particle::HADRON, this);
        part->setColor(Particle::WHITE);
        part->setVelocity(0.6, 0.9);
        mFSParticles.append(part);
        mHadrons++;
    }
}

//=====================================================================================
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

//=====================================================================================
void Collision::addQuarks(int nQuarks)
{
    // add a quark to the final state particles list
    // select randomly the color

    const char *textureName;
    for (int num = 0; num < nQuarks; num++) {
        Particle *part = new Particle(Particle::QUARK, this);
        int color = qrand() % ((Particle::GREEN + 1) - Particle::RED) + Particle::RED;
        switch (color) {
        case Particle::RED:
            part->setColor(Particle::RED);
            textureName = ":/textures/images/RedQuark.png";            
            break;
        case Particle::BLUE:
            part->setColor(Particle::BLUE);
            textureName = ":/textures/images/BlueQuark.png";            
            break;
        case Particle::GREEN:
            part->setColor(Particle::GREEN);
            textureName = ":/textures/images/GreenQuark.png";
            break;
        default:
            break;
        }
        part->setVelocity(0.6, 0.9);
        mFSParticles.append(part);
        mQuarks++;
    }
}
