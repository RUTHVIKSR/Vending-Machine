#pragma once

#include <string>
#include "Coin.h"
class VendingMachine;


class VendingMachineState{
public:

    virtual ~VendingMachineState() = default;

    virtual void insertCoin(VendingMachine& machine, Coin coin) = 0;
    virtual void selectItem(VendingMachine& machine, const std::string& code) = 0;
    virtual void dispense(VendingMachine& machine) = 0;
    virtual void refund(VendingMachine& machine) = 0;
};