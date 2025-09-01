#pragma once

#include <string>
#include <memory>
#include "Coin.h"
class VendingMachineState;
class Inventory;
class Item;

class VendingMachine{
public:

    static VendingMachine& getInstance();

    void insertCoin(Coin coin);
    void selectItem(const std::string& code);
    void dispense();
    void refund();

    void setState(std::unique_ptr<VendingMachineState> state);

    Inventory* getInventory();
    int getBalance() const;
    Item* getSelectedItem();

    void setSelectedItemCode(const std::string& code);
    void addBalance(int value);
    void dispenseItem();
    void refundBalance();
    void reset();

private:
    // Private constructor for Singleton pattern
    VendingMachine();

    // Deleted copy constructor and assignment operator to prevent copying
    VendingMachine(const VendingMachine&) = delete;
    void operator=(const VendingMachine&) = delete;

    std::unique_ptr<Inventory> inventory_;
    std::unique_ptr<VendingMachineState> currentState_;
    int balance_ = 0;
    std::string selectedItemCode_;
};