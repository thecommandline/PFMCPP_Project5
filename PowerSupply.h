#pragma once

#include "LeakedObjectDetector.h"

struct PowerSupply
{
    PowerSupply();
    ~PowerSupply();

    int inputPower, outputPower;
    float outputCurrentMax;
    std::string inputConnectorType = "IEC", 
    outputConnectorType = "Binding Post";

    void enable(bool) const;
    void setDisplayMetric(std::string) const;
    void setOutputPower(int);

    JUCE_LEAK_DETECTOR(PowerSupply)
};
