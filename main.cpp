/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */

#include <iostream>

/*
 copied UDT 1:
 */

struct RadioReceiver
{

    RadioReceiver();
    ~RadioReceiver(); 

    float afOutputPower, selectivity, frequencyStability, tunningStep;
    std::string demodulationMode; 

    void setFrequency(float frequency);
    void setAudioFrequencyGain(int audioFrequencyGain);
    void setRfGain(int rfGain);

    struct RecieverControlInterface 
    {

        RecieverControlInterface();
        ~RecieverControlInterface();

        int antennaInput;
        float afGain, rfGain;
        bool automaticGainControl, dspEnabled;
       
        void setMode(std::string mode);
        void selectAntennaInput(int antennaInputSelection);
        void setVolume(float volume);
    } recieverControlInterface;
};

RadioReceiver::RadioReceiver() : afOutputPower(100), selectivity(-60), frequencyStability(0.5), tunningStep(10), demodulationMode("SSB")
{
    std::cout << "RadioReceiver has been constructed." << std::endl;
}

RadioReceiver::~RadioReceiver()
{
    std::cout << "RadioReceiver has been deconstructed." << std::endl;
}

RadioReceiver::RecieverControlInterface::RecieverControlInterface() : antennaInput(50), afGain(2), rfGain(5), automaticGainControl(true), dspEnabled(true)
{
    std::cout << "RecieverControlInterface has been constructed." << std::endl;
}

RadioReceiver::RecieverControlInterface::~RecieverControlInterface()
{
    std::cout << "RecieverControlInterface has been deconstructed." << std::endl;
}

void RadioReceiver::setFrequency(float frequency)
{
    std::cout << "Frequency has been updated: " << frequency << std::endl;
}

void RadioReceiver::setAudioFrequencyGain(int audioFrequencyGain)
{
    std::cout << "AF gain has been updated: " << audioFrequencyGain << std::endl;
}

void RadioReceiver::setRfGain(int rfGain)
{
    std::cout << "RF gain has been updated: " << rfGain << std::endl;
}

void RadioReceiver::RecieverControlInterface::setMode(std::string mode)
{
    std::cout << "Mode has been updated: " << mode << std::endl;
}

void RadioReceiver::RecieverControlInterface::selectAntennaInput(int antennaInputSelection)
{
    std::cout << "Antenna Input has been updated: " << antennaInputSelection << std::endl;
}

void RadioReceiver::RecieverControlInterface::setVolume(float volume)
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

    float maxOutputLevel, minOutputLevel, antennaImpedance, microphoneImpedance;
    bool monitorEnabled;  

    void enableVoiceMemoryUnit(bool enableVoiceMemoryUnit);
    void enableAntennaTunner(bool enableAntennaTunner);
    void enableDataManagementUnit(bool enableDataManagementUnit);

    struct TransmitterControlInterface 
    {
        TransmitterControlInterface();
        ~TransmitterControlInterface();

        int antennaSelection, vfoSelection;
        float frequency, microphoneGain;
        std::string mode;

        void setMode(std::string modeSelection);
        void txEnabled(bool txEnabled);
        void enableKeyer(bool keyerEnabled);
    } transmitterControlInterface;
};

RadioTransmitter::RadioTransmitter() : maxOutputLevel(100.f), minOutputLevel(5.f), antennaImpedance(50.f), microphoneImpedance(4.f), monitorEnabled(true)
{
    std::cout << "RadioTransmitter has been constructed." << std::endl;
}

RadioTransmitter::~RadioTransmitter()
{
    std::cout << "RadioTransmitter has been deconstructed." << std::endl;
}

RadioTransmitter::TransmitterControlInterface::TransmitterControlInterface() : antennaSelection(1), vfoSelection(2), frequency(7.100f), microphoneGain(2.f), mode("AM")
{
    std::cout << "TransmitterControlInterface has been constructed." << std::endl;
}

RadioTransmitter::TransmitterControlInterface::~TransmitterControlInterface()
{
    std::cout << "TransmitterControlInterface has been deconstructed." << std::endl;
}

void RadioTransmitter::enableVoiceMemoryUnit(bool enableVoiceMemoryUnit)
{
    std::cout << "Voice Memory Unit Enabled: " << enableVoiceMemoryUnit << std::endl;
}
 
void RadioTransmitter::enableAntennaTunner(bool enableAntennaTunner)
{
    std::cout << "Antenna Tunner Enabled: " << enableAntennaTunner << std::endl;
}

void RadioTransmitter::enableDataManagementUnit(bool enableDataManagementUnit)
{
    std::cout << "Data Management Unit Enabled: " << enableDataManagementUnit << std::endl;
}

void RadioTransmitter::TransmitterControlInterface::setMode(std::string modeSelection)
{
    std::cout << "Tx Mode has been set to: " << modeSelection << std::endl;
}

void RadioTransmitter::TransmitterControlInterface::txEnabled(bool txEnabled)
{
    std::cout << "Tx Enabled: " << txEnabled << std::endl;
}

void RadioTransmitter::TransmitterControlInterface::enableKeyer(bool keyerEnabled)
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

    float inputPower, outputPower, outputCurrentMax;
    std::string inputConnectorType, outputConnectorType;

    void enable(bool powerState);
    void setDisplayMetric(std::string displayMetric);
    void setInputVoltage(int inputVoltage);
};

PowerSupply::PowerSupply()
{
    std::cout << "PowerSupply has been constructed." << std::endl;
}

PowerSupply::~PowerSupply()
{
    std::cout << "PowerSupply has been deconstructed." << std::endl;
}

void PowerSupply::enable(bool powerState)
{
    std::cout << "PowerSupply Powered On: " << powerState << std::endl;
}

void PowerSupply::setDisplayMetric(std::string displayMetric)
{
    std::cout << "PowerSupply Display Metric: " << displayMetric << std::endl;
}

void PowerSupply::setInputVoltage(int inputVoltage)
{
    std::cout << "PowerSupply Input Voltage: " << inputVoltage << std::endl;
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

    enum PowerState: int
    {
       Off, 
       On
    } powerState;

    void setPowerState(PowerState newState);
    void enableTransmitter();
};

Transciever::Transciever()
{
    std::cout << "Transciever has been constructed." << std::endl;
}

Transciever::~Transciever()
{
    std::cout << "Transciever has been constructed." << std::endl;
}

void Transciever::setPowerState(PowerState newState)
{
    this->powerState = newState;
    std::cout << "Transciever PowerState has changed to: "  << newState << std::endl;
}

void Transciever::enableTransmitter()
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
        void displayPowerConsumption();
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

void AmatureRadioStation::displayPowerConsumption()
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
    RadioReceiver primaryReciever;
    primaryReciever.setFrequency(7.100f);
    primaryReciever.setAudioFrequencyGain(2);
    primaryReciever.setRfGain(5);
    primaryReciever.recieverControlInterface.setMode("FM");
    primaryReciever.recieverControlInterface.selectAntennaInput(1);
    primaryReciever.recieverControlInterface.setVolume(50);

    RadioTransmitter primaryTransmitter;
    primaryTransmitter.enableVoiceMemoryUnit(false);
    primaryTransmitter.enableAntennaTunner(true);
    primaryTransmitter.enableDataManagementUnit(false);
    primaryTransmitter.transmitterControlInterface.setMode("USB");
    primaryTransmitter.transmitterControlInterface.txEnabled(false);
    primaryTransmitter.transmitterControlInterface.enableKeyer(false);

    PowerSupply primaryPowerSupply;
    primaryPowerSupply.enable(true);
    primaryPowerSupply.setDisplayMetric("Amps");
    primaryPowerSupply.setInputVoltage(110);

    Transciever primaryTransciever;
    primaryTransciever.setPowerState(Transciever::PowerState::On);
    primaryTransciever.enableTransmitter();

    AmatureRadioStation primaryAmatureRadioStation;
    primaryAmatureRadioStation.powerDownStation();
    primaryAmatureRadioStation.displayPowerConsumption();

    std::cout << "good to go!" << std::endl;
}
