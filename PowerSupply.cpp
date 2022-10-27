#include "PowerSupply.h"
#include <iostream>

PowerSupply::PowerSupply() : inputPower(110), outputPower(24), outputCurrentMax(20)
{
    std::cout << "PowerSupply has been constructed." << std::endl;
}

PowerSupply::~PowerSupply()
{
    std::cout << "PowerSupply has been deconstructed." << std::endl;
}

void PowerSupply::enable(bool powerState) const
{
    std::cout << "PowerSupply Powered On: " << powerState << std::endl;
}

void PowerSupply::setDisplayMetric(std::string displayMetric) const
{
    std::cout << "PowerSupply Display Metric: " << displayMetric << std::endl;
}

void PowerSupply::setOutputPower(int newOutputPower)
{
    while(this->outputPower < newOutputPower)
    {
        this->outputPower += 1;
    }
    std::cout << "PowerSupply Output Power: " << this->outputPower << std::endl;
}
