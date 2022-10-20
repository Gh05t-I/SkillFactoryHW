#include "Tablet.h"

Tablet::Tablet(int memory, double frequency_cpu, int diagonal, const std::string &name, double price, double weight, const std::string &sn) : IProduct(name, price, weight, sn), Television(diagonal), PC_blok(memory, frequency_cpu)
{         
}

Tablet::Tablet() = default;
Tablet::~Tablet() = default;

Tablet::Tablet(const Tablet &ref_tablet){    

    this->_memory = ref_tablet._memory;
    this->_frequency_cpu = ref_tablet._frequency_cpu;

    this->_diagonal = ref_tablet._diagonal;

    this->_name = ref_tablet._name;
    this->_price = ref_tablet._price;
    this->_serial_number = ref_tablet._serial_number;
    this->_weight = ref_tablet._weight;    
}

void Tablet::get_prise() {
    std::cout << "price on tablet = " << _price << std::endl;
}

void Tablet::action() {
    std::cout << "your action on tablet = 41%" << std::endl;
}

void Tablet::foo(){
    std::cout << "" << std::endl;
}