/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */





#include <iostream>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */

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

struct RadioReceiverWrapper
{
    RadioReceiverWrapper(RadioReceiver* ptr) : pointerToRadioReceiver(ptr) {}
    ~RadioReceiverWrapper()
    {
        delete pointerToRadioReceiver;
    }
    RadioReceiver* pointerToRadioReceiver = nullptr;
};

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
    for(int i = 0; i < 3; i++)
    {
        this->antennaInput = i + 1;
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

/*
 copied UDT 2:
 */

struct RadioTransmitter
{
    RadioTransmitter();
    ~RadioTransmitter();

    float maxOutputLevel, minOutputLevel;
    float antennaImpedance=50.f;
    float microphoneImpedance=4.f;
    bool antennaTunnerStatus=true;  

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

struct RadioTransmitterWrapper
{
    RadioTransmitterWrapper(RadioTransmitter* ptr) : pointerToRadioTransmitter(ptr) {}
    ~RadioTransmitterWrapper()
    {
        delete pointerToRadioTransmitter;
    }
    RadioTransmitter* pointerToRadioTransmitter = nullptr;
};

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
            antennaTunnerStatus = true;
        }
        else
        {
            antennaTunnerStatus = true; 
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




/*
 copied UDT 3:
 */
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

struct PowerSupplyWrapper
{
    PowerSupplyWrapper(PowerSupply* ptr) : pointerToPowerSupply(ptr) {}
    ~PowerSupplyWrapper()
    {
        delete pointerToPowerSupply;
    }
    PowerSupply* pointerToPowerSupply = nullptr;
};

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

/*
 new UDT 4:
 with 2 member functions
 */

struct Transciever
{
    Transciever();
    ~Transciever();
    
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

    JUCE_LEAK_DETECTOR(Transciever)

};

struct TranscieverWrapper
{
    TranscieverWrapper(Transciever* ptr) : pointerToTransciever(ptr) {}
    ~TranscieverWrapper()
    {
        delete pointerToTransciever;
    }
    Transciever* pointerToTransciever = nullptr;
};

Transciever::Transciever(): powerState(Transciever::PowerState::Off)
{
    std::cout << "Transciever has been constructed." << std::endl;
}

Transciever::~Transciever()
{
    std::cout << "Transciever has been constructed." << std::endl;
}

void Transciever::setPowerState(PowerState newState)
{
    for(int i = 0; i<2; i++)
    {
        if(i == 0)
        {
            this->powerState = Transciever::PowerState::Off;
            std::cout << "Transciever is Powered Off" << std::endl;
        }
        else
        {
            this->powerState = Transciever::PowerState::On;
            std::cout << "Transciever is Powered On" << std::endl;
        }
        if(this->powerState == newState)
        {
            break;
        }
    }
}

void Transciever::enableTransmitter() const
{
    this->tx.transmitterControlInterface.txEnabled(true);
}

/*
 new UDT 5:
 with 2 member functions
 */

struct AmatureRadioStation
{
    AmatureRadioStation();
    ~AmatureRadioStation();

    Transciever primaryTransciever;
    PowerSupply primaryPowerSupply;

    void powerDownStation();
    void displayPowerConsumption() const;

    JUCE_LEAK_DETECTOR(AmatureRadioStation)
};

struct AmatureRadioStationWrapper
{
    AmatureRadioStationWrapper(AmatureRadioStation* ptr) : pointerToAmatureRadioStation(ptr) {}
    ~AmatureRadioStationWrapper()
    {
        delete pointerToAmatureRadioStation;
    }
    AmatureRadioStation* pointerToAmatureRadioStation = nullptr;
};

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
    this->primaryTransciever.setPowerState(Transciever::PowerState::Off);
    this->primaryPowerSupply.enable(false);
}

void AmatureRadioStation::displayPowerConsumption() const
{
    this->primaryPowerSupply.setDisplayMetric("Watts");
}


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    RadioReceiverWrapper primaryReceiver( new RadioReceiver() );
    primaryReceiver.pointerToRadioReceiver->frequency = 7300.f;
    std::cout << "Frequency has been set to the desired value: " << primaryReceiver.pointerToRadioReceiver->frequency << std::endl;
    primaryReceiver.pointerToRadioReceiver->setFrequency(7300.f);
    primaryReceiver.pointerToRadioReceiver->setAudioFrequencyGain(4);
    primaryReceiver.pointerToRadioReceiver->setRfGain(5);
    primaryReceiver.pointerToRadioReceiver->receiverControlInterface.setMode("FM");
    primaryReceiver.pointerToRadioReceiver->receiverControlInterface.selectAntennaInput(3);
    primaryReceiver.pointerToRadioReceiver->receiverControlInterface.setVolume(50);

    RadioTransmitterWrapper primaryTransmitter( new RadioTransmitter() );
    primaryTransmitter.pointerToRadioTransmitter->antennaTunnerStatus = true;
    std::cout << "Antenna Tunner Status: " << primaryTransmitter.pointerToRadioTransmitter->antennaTunnerStatus << std::endl;
    primaryTransmitter.pointerToRadioTransmitter->antennaTunnerStatus = false;
    primaryTransmitter.pointerToRadioTransmitter->toggleAntennaTunner(); 
    primaryTransmitter.pointerToRadioTransmitter->toggleVoiceMemoryUnit();
    primaryTransmitter.pointerToRadioTransmitter->toggleAntennaTunner();
    primaryTransmitter.pointerToRadioTransmitter->toggleDataManagementUnit();
    primaryTransmitter.pointerToRadioTransmitter->transmitterControlInterface.setMode("USB");
    primaryTransmitter.pointerToRadioTransmitter->transmitterControlInterface.txEnabled(false);
    primaryTransmitter.pointerToRadioTransmitter->transmitterControlInterface.enableKeyer(false);

    PowerSupplyWrapper primaryPowerSupply( new PowerSupply() );
    primaryPowerSupply.pointerToPowerSupply->enable(true);
    primaryPowerSupply.pointerToPowerSupply->setDisplayMetric("Amps");
    primaryPowerSupply.pointerToPowerSupply->outputPower = 24;
    std::cout << "PowerSupply Output Power: " << primaryPowerSupply.pointerToPowerSupply->outputPower << std::endl;
    primaryPowerSupply.pointerToPowerSupply->setOutputPower(24);

    TranscieverWrapper primaryTransciever( new Transciever() );
    primaryTransciever.pointerToTransciever->setPowerState(Transciever::PowerState::On);
    primaryTransciever.pointerToTransciever->enableTransmitter();
    primaryTransciever.pointerToTransciever->rx.frequency = 3000.f;
    std::cout << "Frequency has been set to the desired value: " << primaryTransciever.pointerToTransciever->rx.frequency << std::endl;
    primaryTransciever.pointerToTransciever->rx.setFrequency(3000.f);


    AmatureRadioStationWrapper primaryAmatureRadioStation( new AmatureRadioStation() );
    primaryAmatureRadioStation.pointerToAmatureRadioStation->powerDownStation();
    primaryAmatureRadioStation.pointerToAmatureRadioStation->displayPowerConsumption();
    primaryAmatureRadioStation.pointerToAmatureRadioStation->primaryPowerSupply.outputPower = 12;
    std::cout << "PowerSupply Output Power: " << primaryAmatureRadioStation.pointerToAmatureRadioStation->primaryPowerSupply.outputPower << std::endl;
    primaryAmatureRadioStation.pointerToAmatureRadioStation->primaryPowerSupply.setOutputPower(12);

    std::cout << "good to go!" << std::endl;
}
