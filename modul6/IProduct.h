#pragma once
#include<iostream>
#include<string>

class IProduct{

    public:    

    double get_price() const; 
    double get_weight() const; 
    std::string get_serial_number() const; 
    std::string get_name() const; 

    protected:

    double _price;
    double _weight;
    std::string _serial_number;
    std::string _name;    

    IProduct(const std::string &name, double price, double weight, const std::string &serial_number);
    IProduct(); 
    
    virtual ~IProduct();

    virtual void action();

    virtual void foo() = 0;
};