#ifndef ACIDARRAYCREATOR_H
#define ACIDARRAYCREATOR_H
#include <fstream>
#include <string>
#include "map"
#include "QSlider"
#include "QSpinBox"

class AcidArrayCreator
{
private:
    std::fstream file;
public:
    void setFile(const char *fileName);
    AcidArrayCreator();
    std::map<std::string, std::string>  getAcidArray(QSlider *slider, QSpinBox * spinBox);
};

#endif // ACIDARRAYCREATOR_H
