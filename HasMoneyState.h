#pragma once

#include "VendingMachineState.h"

class HasMoneyState : public VendingMachineState{
public:
    void insertCoin(VendingMachine& machine, Coin coin) override;
    void selectItem(VendingMachine& machine, const std::string& code) override;
    void dispense(VendingMachine& machine) override;
    void refund(VendingMachine& machine) override;
};