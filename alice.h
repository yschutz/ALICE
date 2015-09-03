#ifndef ALICE_H
#define ALICE_H

#include <QObject>

#include "mesh.h"

class Alice : public QObject
{
    Q_OBJECT
public:
    explicit Alice(QObject *parent = 0);

    void Init();
    QList<Mesh*> Elements() const { return mElements; }

private:
    void Create();
    void CreateL3();

    QList<Mesh*> mElements; // list of meshes needed to build ALICE
};

#endif // ALICE_H
