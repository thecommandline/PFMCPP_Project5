#pragma once

#include "LeakedObjectDetector.h"

struct RadioReceiver
{

    RadioReceiver();
    ~RadioReceiver(); 

    float afOutputPower, frequency, frequencyStability, tunningStep;
    std::string demodulationMode = "FM"; 

    void setFrequency(float);
    void setAudioFrequencyGain(int) const;
    void setRfGain(int) const; 

    struct ReceiverControlInterface
    {

        ReceiverControlInterface();
        ~ReceiverControlInterface();

        int antennaInput;
        float afGain, rfGain;
        bool automaticGainControl = true; 
        bool dspEnabled = true;
       
        enum class AntennaInputSwitch: int
        {
            one,
            two,
            three,
            END_OF_LIST
        };

        void setMode(std::string) const;
        void selectAntennaInput(int);
        void setVolume(float) const;
    } receiverControlInterface;

    JUCE_LEAK_DETECTOR(RadioReceiver)
};
