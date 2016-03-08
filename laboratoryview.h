#ifndef LABORATORYVIEW_H
#define LABORATORYVIEW_H

#include "view.h"

class Alice;

class LaboratoryView : public cgl::View
{
    Q_OBJECT

public:
    enum { KALICE };
    LaboratoryView();

    void scale(float updown);

private:
    Alice *mALICE; // the ALICE experiment
};

#endif // LABORATORYVIEW_H
