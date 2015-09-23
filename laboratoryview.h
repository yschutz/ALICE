#ifndef LABORATORYVIEW_H
#define LABORATORYVIEW_H

#include "alice.h"
#include "view.h"


class LaboratoryView : public cgl::View
{
    Q_OBJECT

public:
    LaboratoryView();

    void scale(float updown);

private:
    Alice mAlice; // the ALICE object including LHCC
};

#endif // LABORATORYVIEW_H
