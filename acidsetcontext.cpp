#include "acidsetcontext.h"
#include "QSlider"


AcidSetContext::AcidSetContext()
{
    acidArrayCreator = new AcidArrayCreator();
    acidSetter = new AcidSetter();
}

AcidSetContext::~AcidSetContext()
{
    delete acidArrayCreator, acidSetter;
}

void AcidSetContext::setAcidsArray(const char *fileName, QSlider * slider,QSpinBox *spinBox)
{
    acidArrayCreator->setFile(fileName);
    acidSetter->setAcidMap(acidArrayCreator->getAcidArray(slider, spinBox));
}

void AcidSetContext::setAcids(GenomNode *mainNode, int position)
{
    acidSetter->setAcids(mainNode, position);
}
