#include "RadioTransmitter.h"
#include <iostream>

RadioTransmitter::RadioTransmitter() : maxOutputLevel(100.f), minOutputLevel(5.f)
{
    std::cout << "RadioTransmitter has been constructed." << std::endl;
}

RadioTransmitter::~RadioTransmitter()
{
    std::cout << "RadioTransmitter has been deconstructed." << std::endl;
}

RadioTransmitter::TransmitterControlInterface::TransmitterControlInterface() : antennaSelection(1), vfoSelection(2)
{
    std::cout << "TransmitterControlInterface has been constructed." << std::endl;
}

RadioTransmitter::TransmitterControlInterface::~TransmitterControlInterface()
{
    std::cout << "TransmitterControlInterface has been deconstructed." << std::endl;
}

void RadioTransmitter::toggleVoiceMemoryUnit() const
{
    std::cout << "Voice Memory Unit Enabled: " << std::endl;
}

void RadioTransmitter::toggleAntennaTunner()
{
    // simulate faulty switch 
    // unsigned int x; srand(x); would be BAD but it would work without casting.  
    // getpid() also requires type casting :(

    srand(0);
    while(rand() % 100 < 50)
    {
        std::cout << "Attempting to enable Antenna Tunner" << std::endl;
        if(antennaTunnerStatus == false)
        {
            antennaTunnerStatus = !antennaTunnerStatus;
        }
    }
    
    std::cout << "Antenna Tunner Status: " << antennaTunnerStatus << std::endl;
}

void RadioTransmitter::toggleDataManagementUnit() const
{
    std::cout << "Data Management Unit Enabled: " << std::endl;
}

void RadioTransmitter::TransmitterControlInterface::setMode(std::string modeSelection) const
{
    std::cout << "Tx Mode has been set to: " << modeSelection << std::endl;
}

void RadioTransmitter::TransmitterControlInterface::txEnabled(bool txEnabled) const
{
    std::cout << "Tx Enabled: " << txEnabled << std::endl;
}

void RadioTransmitter::TransmitterControlInterface::enableKeyer(bool keyerEnabled) const
{
    std::cout << "Keyer Enabled: " << keyerEnabled << std::endl;
}
