#include "acidsetter.h"
#include "map"
#include "string"


AcidSetter::AcidSetter()
{
}

void AcidSetter::setAcidMap(std::map<std::string, std::string> acidMap)
{
    this->acidMap = acidMap;
}

void AcidSetter::setAcids(GenomNode *mainNode, int position)
{
    char ch = acidMap[mainNode->getGenomName().toAscii().data()][position];
    std::string acid = "";
    acid += ch;
    mainNode->setAcid(acid.c_str());
    if (mainNode->getLeftChild() != NULL) {
        setAcids(mainNode->getLeftChild(), position);
        setAcids(mainNode->getRightChild(), position);
    }
}
