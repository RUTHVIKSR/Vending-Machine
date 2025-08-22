#include "Item.h"

#include <string>

Item::Item(const std::string& code, const std::string& name, int price)
: code_(code), name_(name), price_(price)
{}

std::string Item::getCode() const {
    return code_;
}

std::string Item::getName() const {
    return name_;
}

int Item::getPrice() const {
    return price_;
}