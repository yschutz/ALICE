#include "alice.h"
#include "laboratoryview.h"
#include "torusmesh.h"

//===================================================================
LaboratoryView::LaboratoryView() : cgl::View()
{
    // ctor
    Alice * alice = new Alice();
    alice->setParent(this);
    addObject(KALICE, alice);

    for(int index = 0; index < alice->elements().size(); index++)
        scene()->addMesh(alice->elements().at(index));
}

//===================================================================
void LaboratoryView::scale(float updown)
{
    // scales ALICE and LHC (LHC must be translated back and forth)

    Alice *alice = dynamic_cast<Alice*>(getObject(KALICE));
    for (int index = 0; index < alice->elements().size(); index++) {
        cgl::Mesh *element = alice->elements().at(index);
            element->scale(updown, updown, updown);
    }
}

//===================================================================
void LaboratoryView::setOpacity()
{
    Alice *alice = dynamic_cast<Alice*>(getObject(KALICE));
    for (int index = 0; index < alice->elements().size(); index++) {
        cgl::Mesh *element = alice->elements().at(index);
            element->setOpacity(0.5);
    }

}
