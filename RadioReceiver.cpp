#include "RadioReceiver.h"
#include <iostream>

RadioReceiver::RadioReceiver() : afOutputPower(100), frequency(7000), frequencyStability(0.5), tunningStep(100)
{
    std::cout << "RadioReceiver has been constructed." << std::endl;
}

RadioReceiver::~RadioReceiver()
{
    std::cout << "RadioReceiver has been deconstructed." << std::endl;
}

RadioReceiver::ReceiverControlInterface::ReceiverControlInterface() : antennaInput(50), afGain(2), rfGain(5)
{
    std::cout << "ReceiverControlInterface has been constructed." << std::endl;
}

RadioReceiver::ReceiverControlInterface::~ReceiverControlInterface()
{
    std::cout << "ReceiverControlInterface has been deconstructed." << std::endl;
}

void RadioReceiver::setFrequency(float newFrequency)
{
    if (this->frequency < newFrequency)
    {
        while(this->frequency < newFrequency)
        {
            this->frequency += this->tunningStep;
            std::cout << "Frequency is being adjusted up: " << this->frequency << std::endl; 
        }
    }
    else if (this->frequency > newFrequency)
    {
        while(this->frequency > newFrequency)
        {
            this->frequency -= this->tunningStep;
            std::cout << "Frequency is being adjusted down: " << this->frequency << std::endl; 
        }
    }
    std::cout << "Frequency has been set to the desired value: " << newFrequency << std::endl;
}

void RadioReceiver::setAudioFrequencyGain(int audioFrequencyGain) const
{
    std::cout << "AF gain has been updated: " << audioFrequencyGain << std::endl;
}

void RadioReceiver::setRfGain(int rfGain) const
{
    std::cout << "RF gain has been updated: " << rfGain << std::endl;
}

void RadioReceiver::ReceiverControlInterface::setMode(std::string mode) const
{
    std::cout << "Mode has been updated: " << mode << std::endl;
}

void RadioReceiver::ReceiverControlInterface::selectAntennaInput(int antennaInputSelection)
{
    for(int i = 0; i < 3; ++i)
    {
        ++this->antennaInput;
        std::cout << "Antenna Switch Position: " << this->antennaInput << std::endl;
        if(this->antennaInput == antennaInputSelection)
        {
            break;
        }
    }
}

void RadioReceiver::ReceiverControlInterface::setVolume(float volume) const
{
    std::cout << "Volume has been updated: " << volume << std::endl;
}
