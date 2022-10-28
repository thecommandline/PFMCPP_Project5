#pragma once

struct RadioReceiver;
struct RadioTransmitter;
struct PowerSupply;
struct Transceiver;
struct AmatureRadioStation;


struct RadioReceiverWrapper
{
    RadioReceiverWrapper(RadioReceiver* ptr);
    ~RadioReceiverWrapper();
    RadioReceiver* pointerToRadioReceiver = nullptr;
};

struct RadioTransmitterWrapper
{
    RadioTransmitterWrapper(RadioTransmitter* ptr);
    ~RadioTransmitterWrapper();
    RadioTransmitter* pointerToRadioTransmitter = nullptr;
};

struct PowerSupplyWrapper
{
    PowerSupplyWrapper(PowerSupply* ptr);
    ~PowerSupplyWrapper();
    PowerSupply* pointerToPowerSupply = nullptr;
};

struct TransceiverWrapper
{
    TransceiverWrapper(Transceiver* ptr);
    ~TransceiverWrapper();
    Transceiver* pointerToTransceiver = nullptr;
};

struct AmatureRadioStationWrapper
{
    AmatureRadioStationWrapper(AmatureRadioStation* ptr);
    ~AmatureRadioStationWrapper();
    AmatureRadioStation* pointerToAmatureRadioStation = nullptr;
};
