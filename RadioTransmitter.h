#pragma once

#include "LeakedObjectDetector.h"

struct RadioTransmitter
{
    RadioTransmitter();
    ~RadioTransmitter();

    float maxOutputLevel, minOutputLevel;
    float antennaImpedance = 50.f;
    float microphoneImpedance = 4.f;
    bool antennaTunnerStatus = true;  

    void toggleVoiceMemoryUnit() const;
    void toggleAntennaTunner();
    void toggleDataManagementUnit() const;

    struct TransmitterControlInterface 
    {
        TransmitterControlInterface();
        ~TransmitterControlInterface();

        int antennaSelection, vfoSelection;
        float frequency = 7.000f;
        float microphoneGain = 2.f;
        std::string mode = "AM";

        void setMode(std::string modeSelection) const;
        void txEnabled(bool txEnabled) const;
        void enableKeyer(bool keyerEnabled) const;
    } transmitterControlInterface;

    JUCE_LEAK_DETECTOR(RadioTransmitter)
};
