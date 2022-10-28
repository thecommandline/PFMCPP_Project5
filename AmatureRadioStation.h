#pragma once

#include "LeakedObjectDetector.h"
#include "Transceiver.h"
#include "PowerSupply.h"

struct AmatureRadioStation
{
    AmatureRadioStation();
    ~AmatureRadioStation();

    Transceiver primaryTransceiver;
    PowerSupply primaryPowerSupply;

    void powerDownStation();
    void displayPowerConsumption() const;

    JUCE_LEAK_DETECTOR(AmatureRadioStation)
};
