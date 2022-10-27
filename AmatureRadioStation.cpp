#include "AmatureRadioStation.h"
#include <iostream>

AmatureRadioStation::AmatureRadioStation()
{
    std::cout << "AmatureRadioStation has been constructed." << std::endl;
}

AmatureRadioStation::~AmatureRadioStation()
{
    std::cout << "AmatureRadioStation has been deconstructed." << std::endl;
}

void AmatureRadioStation::powerDownStation()
{
    this->primaryTransceiver.setPowerState(Transceiver::PowerState::Off);
    this->primaryPowerSupply.enable(false);
}

void AmatureRadioStation::displayPowerConsumption() const
{
    this->primaryPowerSupply.setDisplayMetric("Watts");
}
