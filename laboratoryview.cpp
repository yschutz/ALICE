#include "alice.h"
#include "laboratoryview.h"

//===================================================================
LaboratoryView::LaboratoryView() : View()
{
    // ctor
}

//===================================================================
void LaboratoryView::stage()
{
    // add the objects to the scene

    Alice alice(this);

    for(int index = 0; index < alice.Elements().size(); index++)
        mScene->addMesh(alice.Elements().at(index));

}
