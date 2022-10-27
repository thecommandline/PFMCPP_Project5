#pragma once

#include "LeakedObjectDetector.h"
#include "RadioReceiver.h"
#include "RadioTransmitter.h"
#include "PowerSupply.h"

struct Transceiver
{
    Transceiver();
    ~Transceiver();
    
    RadioReceiver rx;
    RadioTransmitter tx;
    PowerSupply psu; 

    enum class PowerState: int
    {
        Off, 
        On,
        END_OF_LIST
    } powerState = PowerState::Off;

    void setPowerState(PowerState);
    void enableTransmitter() const;

    JUCE_LEAK_DETECTOR(Transceiver)

};
