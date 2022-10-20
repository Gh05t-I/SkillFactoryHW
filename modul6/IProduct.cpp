#include<iostream>
#include<string>

#include"IProduct.h"

IProduct::IProduct(const std::string &name, double price, double weight, const std::string &serial_number): _price(price), _weight(weight), _serial_number(serial_number), _name(name)
{        
}
IProduct::IProduct() = default;
IProduct::~IProduct() = default;

double IProduct::get_price() const {
        return _price;
}

double IProduct::get_weight() const {
    return _weight;
}

std::string IProduct::get_serial_number() const {
    return _serial_number;
}

std::string IProduct::get_name() const {
    return _name;
}

void IProduct::action(){
}
    