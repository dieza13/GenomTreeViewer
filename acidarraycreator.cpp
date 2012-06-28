#include "acidarraycreator.h"
#include "map"
#include "QSlider"
#include "QSpinBox"

void AcidArrayCreator::setFile(const char *fileName)
{
    file.open(fileName);
}

AcidArrayCreator::AcidArrayCreator()
{    
}

std::map<std::string, std::string>  AcidArrayCreator::getAcidArray(QSlider * slider, QSpinBox *spinBox)
{
    int acidCount;
    std::map<std::string, std::string>  acidArray;
    std::string  genomName = "", str;
    while(!file.eof()){
        char ch;
        file.get(ch);
        if (isalnum(ch)) {
            if (str.compare("node") == 0) str = "";
            str += ch;
        }
        if (ch == '\n') {
            if (genomName.compare("") != 0) {
                acidArray[genomName] = str;
                acidCount = str.size();
                genomName = "";
            } else {
                genomName = str;
            }
            str = "";
        }
    }
    file.close();
    slider->setMaximum(acidCount - 1);
    spinBox->setMaximum(acidCount - 1);
    return acidArray;
}
