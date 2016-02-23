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
        if(element->objectName() == mAlice.elementName(Alice::BEAMSPIPE)) {
            element->translate(-mAlice.lhcRadius(), 0.0, 0.0);
            element->scale(updown, updown, updown);
            element->translate(mAlice.lhcRadius(), 0.0, 0.0);
        }
        else if(element->objectName() == mAlice.elementName(Alice::L3F)) {
            element->translate(0.0, 0.0, -mAlice.l3Length() / 2.0);
            element->scale(updown, updown, updown);
            element->translate(0.0, 0.0, mAlice.l3Length() / 2.0);
        } else if(element->objectName() == mAlice.elementName(Alice::L3B)) {
            element->translate(0.0, 0.0, mAlice.l3Length() / 2.0);
            element->scale(updown, updown, updown);
            element->translate(0.0, 0.0, -mAlice.l3Length() / 2.0);
        } else if(element->objectName() == mAlice.elementName((Alice::TPCEPF))) {
            element->translate(0.0, 0.0, -mAlice.tpcLength() / 2.0);
            element->scale(updown, updown, updown);
            element->translate(0.0, 0.0, mAlice.tpcLength() / 2.0);
        } else if(element->objectName() == mAlice.elementName((Alice::TPCEPB))) {
            element->translate(0.0, 0.0, mAlice.tpcLength() / 2.0);
            element->scale(updown, updown, updown);
            element->translate(0.0, 0.0, -mAlice.tpcLength() / 2.0);
        } else if(element->objectName() == mAlice.elementName(Alice::TOFBA)) {
            element->translate(0.0, 0.0, mAlice.tofLength() / 2.0);
            element->scale(updown, updown, updown);
            element->translate(0.0, 0.0, -mAlice.tofLength() / 2.0);
        } else if(element->objectName() == mAlice.elementName(Alice::TOFFO)) {
            element->translate(0.0, 0.0, -mAlice.tofLength() / 2.0);
            element->scale(updown, updown, updown);
            element->translate(0.0, 0.0, mAlice.tofLength() / 2.0);
        } else if(element->objectName() == mAlice.elementName(Alice::TRD01)) {
            element->translate(0.0, 0.0, -mAlice.trdLength() / 2.0);
            element->scale(updown, updown, updown);
            element->translate(0.0, 0.0, mAlice.trdLength() / 2.0);
        } else if(element->objectName().contains(mAlice.elementName(Alice::EMCSM))) {
            float angle = mAlice.emcAngle() * element->objectName().right(1).toInt();
            qDebug() << Q_FUNC_INFO << angle;
            element->rotate(qRadiansToDegrees(angle), 0, 1, 0);
            element->rotate(-90.0, 0, 0, 1);
            element->rotate(-90.0, 0, 1, 0);
            element->translate(-mAlice.emcPosX() * qCos(angle), mAlice.emcPosX() * qSin(angle), 0.0);
            element->scale(updown, updown, updown);
            element->translate(mAlice.emcPosX() * qCos(angle), -mAlice.emcPosX() * qSin(angle), 0.0);
            element->rotate(90.0, 0, 1, 0);
            element->rotate(90.0, 0, 0, 1);
            element->rotate(-qRadiansToDegrees(angle), 0, 1, 0);

        } else
            element->scale(updown, updown, updown);
    }
}
