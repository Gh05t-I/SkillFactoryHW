#include<iostream>

#include "Telefon.h"
#include "Television.h"
#include "PC_blok.h"
#include "Tablet.h"

void add_telefon(IProduct **basket, int count);
void add_television(IProduct **basket, int count);
void add_pc_blok(IProduct **basket, int count);
void add_tablet(IProduct **basket, int count);

int main(int argc, char *argv[]){

    setlocale(LC_ALL, "Russian");   

    const int max_siz_basket = 10;
    IProduct *basket[max_siz_basket];

    bool open { true };
    int choice { 0 };
    int count { 0 };

    while(open){

        std::cout << "Выберите продукт: 1 - телевон \n 2- телевизор \n 3 - ПК блок \n 4 - планшет \n 0 - выход" << std::endl;
        std::cin >> choice;

        switch(choice){
            case 0:
                open = false;
                break;

            case 1:
                add_telefon(basket, count);
                ++count;
                break;
            case 2:
                add_television(basket, count);
                ++count;
                break;
            case 3:
                add_pc_blok(basket, count);
                ++count;
                break;
            case 4:
                add_tablet(basket, count);
                ++count;
                break;
            default:
                std::cout << "Ввод не распознан" << std::endl;
                break;
        }
    }

    for(int i = 0; i < count; ++i){
        
        std::cout << std::endl;
        std::cout << "товар " << i << std::endl;
        std::cout << std::endl;

        std::cout << basket[i]->get_name() << std::endl;
        std::cout << basket[i]->get_price() << std::endl;
        std::cout << basket[i]->get_serial_number() << std::endl;
        std::cout << basket[i]->get_weight() << std::endl;
     }

    return 0;
}

void add_telefon(IProduct **basket, int count){

    Telefon *fon = new  Telefon(123154187921732, "htc",  14.4, 0.1, "FF-TT-4R");
    basket[count] = fon;
}

void add_television(IProduct **basket, int count){

    Television *tv = new  Television(12, "Hair",  20.0, 2.0, "TT-RT-489R");
    basket[count] = tv;
}

void add_pc_blok(IProduct **basket, int count){

    PC_blok *pc = new  PC_blok(4, 2.7, "Ryzen",  180.0, 6.0, "RZ-TR3434-GF3");
    basket[count] = pc;
}

void add_tablet(IProduct **basket, int count){

    Tablet *tab = new  Tablet(2, 1.8, 8, "Huawei",  35.0, 1.1, "HR-WE-7FE556");
    basket[count] = tab;
}