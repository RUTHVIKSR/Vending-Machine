#include "Inventory.h"
#include "Item.h"
#include <string>
#include <memory>
#include <utility>

void Inventory::addItem(const std::string& code, const std::string& name, int price, int quantity){
    std::unique_ptr<Item> item = std::make_unique<Item>(code, name, price);
    itemMap_[code] = std::move(item);
    stockMap_[code] = quantity;
}


void Inventory::removeItem(const std::string& code){
    itemMap_.erase(code);
}
void Inventory::updateItemQuantity(const std::string& code, int quantity){
    if(stockMap_.find(code) != stockMap_.end())
        stockMap_[code] = quantity;
}

bool Inventory::isItemAvailable(const std::string& code) const{
     auto it = stockMap_.find(code);
    if (it != stockMap_.end()) {
        return it->second > 0;
    }
    return false;
}

Item* Inventory::getItem(const std::string& code) const{
    auto it = itemMap_.find(code);
    if(it != itemMap_.end())
        return it->second.get();
    return nullptr;
}