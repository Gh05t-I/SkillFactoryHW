#pragma once
#include"IProduct.h"

class Telefon final : public IProduct{    

    public:

    Telefon(int imei,const std::string &name, double price, double weight, const std::string &sn); 

    ~Telefon();

    Telefon(const Telefon &ref_telefon);

    int get_imei() const; 
    void get_price();

    void action() override;


    private:

    int _imei;

    void foo();
};