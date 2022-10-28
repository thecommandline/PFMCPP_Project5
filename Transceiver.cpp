#include "Transceiver.h"
#include <iostream> 

Transceiver::Transceiver(): powerState(Transceiver::PowerState::Off)
{
    std::cout << "Transceiver has been constructed." << std::endl;
}

Transceiver::~Transceiver()
{
    std::cout << "Transceiver has been constructed." << std::endl;
}

void Transceiver::setPowerState(PowerState newState)
{
    for(int i = 0; i < 2; ++i)
    {
        if(i == 0)
        {
            this->powerState = Transceiver::PowerState::Off;
            std::cout << "Transceiver is Powered Off" << std::endl;
        }
        else
        {
            this->powerState = Transceiver::PowerState::On;
            std::cout << "Transceiver is Powered On" << std::endl;
        }
        if(this->powerState == newState)
        {
            break;
        }
    }
}

void Transceiver::enableTransmitter() const
{
    this->tx.transmitterControlInterface.txEnabled(true);
}
