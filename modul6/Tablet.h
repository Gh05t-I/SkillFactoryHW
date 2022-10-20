#pragma once
#include "IProduct.h"
#include "Television.h"
#include "PC_blok.h"

class Tablet : public Television, PC_blok{ 

    public:

    Tablet(int memory, double frequency_cpu, int diagonal, const std::string &name, double price, double weight, const std::string &sn);
    Tablet();

    ~Tablet();

    Tablet(const Tablet &ref_tablet);

    void get_prise();

    void action() override;


    private:

    void foo();
};