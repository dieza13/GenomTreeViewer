#ifndef ACIDSETTER_H
#define ACIDSETTER_H
#include "genomnode.h"
#include "string"
#include "map"

class AcidSetter
{
private:
    std::map<std::string, std::string> acidMap;
public:
    AcidSetter();
    void setAcidMap(std::map<std::string, std::string> acidMap);
    void setAcids(GenomNode * mainNode, int position);
};

#endif // ACIDSETTER_H
