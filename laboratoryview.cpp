#include "alice.h"
#include "laboratoryview.h"
#include "torusmesh.h"

//===================================================================
LaboratoryView::LaboratoryView() : cgl::View()
{
    // ctor
    mAlice.setParent(this);

    for(int index = 0; index < mAlice.Elements().size(); index++)
        scene()->addMesh(mAlice.Elements().at(index));


}

//===================================================================
void LaboratoryView::scale(float updown)
{
    // scales ALICE and LHC (LHC must be translated back and forth)

    for (int index = 0; index < mAlice.Elements().size(); index++) {
        cgl::Mesh *element = mAlice.Elements().at(index);
        if(element->objectName() == mAlice.ElementName(Alice::BEAMSPIPE)) {
            element->translate(-mAlice.lhcRadius(), 0.0, 0.0);
            element->scale(updown, updown, updown);
            element->translate(mAlice.lhcRadius(), 0.0, 0.0);
        }
        else if(element->objectName() == mAlice.ElementName(Alice::L3F)) {
            element->translate(0.0, 0.0, -mAlice.l3Length() / 2.0);
            element->scale(updown, updown, updown);
            element->translate(0.0, 0.0, mAlice.l3Length() / 2.0);
        } else if(element->objectName() == mAlice.ElementName(Alice::L3B)) {
            element->translate(0.0, 0.0, mAlice.l3Length() / 2.0);
            element->scale(updown, updown, updown);
            element->translate(0.0, 0.0, -mAlice.l3Length() / 2.0);
        } else
            element->scale(updown, updown, updown);
    }
}


