#ifndef LABORATORYVIEW_H
#define LABORATORYVIEW_H

#include "alice.h"
#include "view.h"


class LaboratoryView : public cgl::View
{
    Q_OBJECT

public:
    enum { KALICE };
    LaboratoryView();

    void scale(float updown);
    void setOpacity();

private:
};

#endif // LABORATORYVIEW_H
