#include"Television.h"

Television::Television(int diagonal, const std::string &name, double price, double weight, const std::string &sn) : IProduct(name, price, weight, sn), _diagonal(diagonal)
{    
}

Television::Television(int diagonal) : _diagonal(diagonal)
{    
}

Television::Television() = default;
Television::~Television() = default;

Television::Television(const Television &ref_television){    

    this->_diagonal = ref_television._diagonal;

    this->_name = ref_television._name;
    this->_price = ref_television._price;
    this->_serial_number = ref_television._serial_number;
    this->_weight = ref_television._weight;    
}

int Television::get_diagonal() const {
    return _diagonal;
}

void Television::get_prise() {
    std::cout << "price on telefon = " << _price << std::endl;
}

void Television::action(){
    std::cout << "your action on television = 33%" << std::endl;
}

void Television::foo(){
    std::cout << "" << std::endl;
}