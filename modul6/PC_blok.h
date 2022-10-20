#pragma once
#include"IProduct.h"

class PC_blok : virtual public IProduct{

    public:

    PC_blok(int memory, double frequency_cpu, const std::string &name, double price, double weight, const std::string &sn);
    PC_blok(int memory, double frequency_cpu);
    PC_blok();

    ~PC_blok();

    PC_blok(const PC_blok &ref_television);

    void get_prise();
    int get_memory() const;
    double get_frequency() const;

    void action();


    protected:

    int _memory;
    double _frequency_cpu;


    private:

    void foo();
};