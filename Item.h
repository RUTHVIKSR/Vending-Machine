#pragma once

#include <string>

class Item{
public:

    Item(const std::string& code, const std::string& name, int price);
    
    std::string getCode() const;
    std::string getName() const;
    int getPrice() const;

private:

    std::string code_;
    std::string name_;
    int price_;
};