#include "alice.h"
#include "laboratoryview.h"
#include "torusmesh.h"

//===================================================================
LaboratoryView::LaboratoryView() : cgl::View()
{
    // ctor
    mAlice.setParent(this);

    for(int index = 0; index < mAlice.elements().size(); index++)
        scene()->addMesh(mAlice.elements().at(index));


}

//===================================================================
void LaboratoryView::scale(float updown)
{
    // scales ALICE and LHC (LHC must be translated back and forth)

    for (int index = 0; index < mAlice.elements().size(); index++) {
        cgl::Mesh *element = mAlice.elements().at(index);
            element->scale(updown, updown, updown);
    }
}
