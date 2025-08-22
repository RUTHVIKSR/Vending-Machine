#pragma once

#include <unordered_map>
#include <memory>

class Item;

class Inventory {
public:
    Inventory() = default;
    ~Inventory() = default;

    void addItem(const std::string& code, const std::string& name, int price, int quantity);
    void removeItem(const std::string& code);
    void updateItemQuantity(const std::string& code, int quantity);

    bool isItemAvailable(const std::string& code) const;
    // returns a raw pointer because other might alter the object in the future
    Item* getItem(const std::string& code) const;
    
private:
    std::unordered_map<std::string, std::unique_ptr<Item>> itemMap_;
    std::unordered_map<std::string, int> stockMap_;
};