#pragma once
#include"IProduct.h"

class Television : virtual public IProduct{

    public:

    Television(int diagonal, const std::string &name, double price, double weight, const std::string &sn); 
    Television(int diagonal);
    Television();

    ~Television();

    Television(const Television &ref_television);

    int get_diagonal() const;
    void get_prise();

    void action() override;


    protected:   

    int _diagonal;

    void foo();
};