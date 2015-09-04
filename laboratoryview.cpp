#include "alice.h"
#include "laboratoryview.h"

//===================================================================
LaboratoryView::LaboratoryView() : cgl::View()
{
    // ctor
    Alice alice(this);

    for(int index = 0; index < alice.Elements().size(); index++)
        scene()->addMesh(alice.Elements().at(index));


}

//===================================================================
