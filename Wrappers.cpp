#include "Wrappers.h"
#include "RadioReceiver.h"
#include "RadioTransmitter.h"
#include "PowerSupply.h"
#include "Transceiver.h"
#include "AmatureRadioStation.h"

RadioReceiverWrapper::RadioReceiverWrapper(RadioReceiver* ptr) : pointerToRadioReceiver(ptr) {}
RadioReceiverWrapper::~RadioReceiverWrapper()
{
    delete pointerToRadioReceiver;
}

RadioTransmitterWrapper::RadioTransmitterWrapper(RadioTransmitter* ptr) : pointerToRadioTransmitter(ptr) {}
RadioTransmitterWrapper::~RadioTransmitterWrapper()
{
    delete pointerToRadioTransmitter;
}

PowerSupplyWrapper::PowerSupplyWrapper(PowerSupply* ptr) : pointerToPowerSupply(ptr) {}
PowerSupplyWrapper::~PowerSupplyWrapper()
{
    delete pointerToPowerSupply;
}

TransceiverWrapper::TransceiverWrapper(Transceiver* ptr) : pointerToTransceiver(ptr) {}
TransceiverWrapper::~TransceiverWrapper()
{
    delete pointerToTransceiver;
}

AmatureRadioStationWrapper::AmatureRadioStationWrapper(AmatureRadioStation* ptr) : pointerToAmatureRadioStation(ptr) {}
AmatureRadioStationWrapper::~AmatureRadioStationWrapper()
{
    delete pointerToAmatureRadioStation;
}
