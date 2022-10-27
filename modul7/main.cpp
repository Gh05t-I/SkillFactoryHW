#include<iostream>
#include<ctime>

#include"Conteiner.h"

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "Russian");

    try {

        Conteiner* con2 = new Conteiner(10);

        con2->initialization_conteiner();
        con2->show_conteiner();

        Conteiner* con3 = new Conteiner(15);
        con3->show_conteiner();        
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << std::endl;

        con3->copy_conteiner(con2);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << std::endl;

        con3->resize(8);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << std::endl;

        con3->add_element_start(223);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << std::endl;

        con3->add_element_end(212);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;

        con3->add_element(777, 4);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;

        delete con2;
        delete con3;
    }
    catch (int e) {
        if (e == 0) {
            std::cout << "Контейнер не создан" << std::endl;
        }
        else if (e == -1) {
            std::cout << "Неверный параметр для элемента" << std::endl;
        }
        else if (e == -2) {
            std::cout << "Индекс превышает размер массива" << std::endl;
        }
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }

    std::cout << "Test error" << std::endl;

    try {

        Conteiner con(0);

    }
    catch (int e) {
        if (e == 0) {
            std::cout << "Контейнер не создан" << std::endl;
        }
        else if (e == -1) {
            std::cout << "Неверный параметр для элемента" << std::endl;
        }
        else if (e == -2) {
            std::cout << "Индекс превышает размер массива" << std::endl;
        }
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }

    try {

        Conteiner con1(10);
        con1.initialization_conteiner();
        con1.show_conteiner();

        con1.get_element(-2);
    }
    catch (int e) {
        if (e == 0) {
            std::cout << "Контейнер не создан" << std::endl;
        }
        else if (e == -1) {
            std::cout << "Неверный параметр для элемента" << std::endl;
        }
        else if (e == -2) {
            std::cout << "Индекс превышает размер массива" << std::endl;
        }
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }

    try {

        Conteiner con2(10);
        con2.initialization_conteiner();
        con2.show_conteiner();

        con2.add_element(777, -1);
    }
    catch (int e) {
        if (e == 0) {
            std::cout << "Контейнер не создан" << std::endl;
        }
        else if (e == -1) {
            std::cout << "Неверный параметр для элемента" << std::endl;
        }
        else if (e == -2) {
            std::cout << "Индекс превышает размер массива" << std::endl;
        }
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }

    try {

        Conteiner con6(10);
        con6.initialization_conteiner();
        con6.show_conteiner();

        con6.add_element(777, 150);
    }
    catch (int e) {
        if (e == 0) {
            std::cout << "Контейнер не создан" << std::endl;
        }
        else if (e == -1) {
            std::cout << "Неверный параметр для элемента" << std::endl;
        }
        else if (e == -2) {
            std::cout << "Индекс превышает размер массива" << std::endl;
        }
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }

    try {

        Conteiner con3(10);
        con3.initialization_conteiner();
        con3.show_conteiner();

        Conteiner con4(5);
        con4.initialization_conteiner();
        con4.show_conteiner();

        con4.copy_conteiner(&con3);
        con4.show_conteiner();

    }
    catch (int e) {
        if (e == 0) {
            std::cout << "Контейнер не создан" << std::endl;
        }
        else if (e == -1) {
            std::cout << "Неверный параметр для элемента" << std::endl;
        }
        else if (e == -2) {
            std::cout << "Индекс превышает размер массива" << std::endl;
        }
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }

    return 0;
}