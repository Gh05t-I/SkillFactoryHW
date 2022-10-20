#include"PC_blok.h"

PC_blok::PC_blok(int memory, double frequency_cpu, const std::string &name, double price, double weight, const std::string &sn) : IProduct(name, price, weight, sn), 
_memory(memory), _frequency_cpu(frequency_cpu)
{    
}

PC_blok::PC_blok(int memory, double frequency_cpu) : _memory(memory), _frequency_cpu(frequency_cpu)
{    
}

PC_blok::PC_blok() = default;
PC_blok::~PC_blok() = default;

PC_blok::PC_blok(const PC_blok &ref_television){    

    this->_memory = ref_television._memory;
    this->_frequency_cpu = ref_television._frequency_cpu;

    this->_name = ref_television._name;
    this->_price = ref_television._price;
    this->_serial_number = ref_television._serial_number;
    this->_weight = ref_television._weight;    
}

void PC_blok::get_prise() {
    std::cout << "price on pc_blok = " << _price << std::endl;
}

int PC_blok::get_memory() const {
    return _memory;
}

double PC_blok::get_frequency() const {
    return _frequency_cpu;
}

void PC_blok::action(){
    std::cout << "your action on pc_blok = 23%" << std::endl;
}

void PC_blok::foo(){    
}