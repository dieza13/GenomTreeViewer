#ifndef ACIDSETCONTEXT_H
#define ACIDSETCONTEXT_H
#include "acidarraycreator.h"
#include "acidsetter.h"
#include "genomnode.h"
#include "QSpinBox"

class AcidSetContext
{
private:

    AcidArrayCreator * acidArrayCreator;
    AcidSetter * acidSetter;


public:
    AcidSetContext();
    ~AcidSetContext();
    void setAcidsArray(const char *fileName, QSlider * slider, QSpinBox * spinBox);
    void setAcids(GenomNode * mainNode, int position);
};

#endif // ACIDSETCONTEXT_H
