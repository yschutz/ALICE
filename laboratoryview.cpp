#include "alice.h"
#include "laboratoryview.h"
#include "torusmesh.h"

//===================================================================
LaboratoryView::LaboratoryView() : cgl::View()
{
    // ctor
    mALICE = new Alice();
    mALICE->setParent(this);

    for(int index = 0; index < mALICE->elements().size(); index++)
        scene()->addMesh(mALICE->elements().at(index));
}

//===================================================================
void LaboratoryView::scale(float updown)
{
    // scales ALICE and LHC (LHC must be translated back and forth)

    for (int index = 0; index < mALICE->elements().size(); index++) {
        cgl::Mesh *element = mALICE->elements().at(index);
            element->scale(updown, updown, updown);
    }
}
