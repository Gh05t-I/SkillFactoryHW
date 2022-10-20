#include"Telefon.h"

Telefon::Telefon(int imei,const std::string &name, double price, double weight, const std::string &sn) : IProduct(name, price, weight, sn), _imei(imei)
{
}

Telefon::~Telefon() = default;

Telefon::Telefon(const Telefon &ref_telefon){    

    this->_imei = ref_telefon._imei;

    this->_name = ref_telefon._name;
    this->_price = ref_telefon._price;
    this->_serial_number = ref_telefon._serial_number;
    this->_weight = ref_telefon._weight;    
}

int Telefon::get_imei() const {
    return _imei;
}

void Telefon::get_price() {
    std::cout << "price on telefon = " << _price << std::endl;
}

void Telefon::action() {
    std::cout << "your action on telefon = 3%" << std::endl;
}

void Telefon::foo(){
    std::cout << "" << std::endl;
}