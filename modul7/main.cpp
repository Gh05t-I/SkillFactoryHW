#include<iostream>
#include<ctime>

#include "Conteiner.h"
#include "BadLenght.h"
#include "BadRange.h"

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

        std::cout << "Копирование контейнера" << std::endl;
        con3->copy_conteiner(con2);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << std::endl;

        std::cout << "Меняем размер контейнера" << std::endl;
        con3->resize(8);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << std::endl;

        std::cout << "Добавление элемента" << std::endl;
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
        std::cout << std::endl;

        std::cout << "Удаление элемента" << std::endl;
        int res{ 0 };
        res = con3->del_element_start();
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << "element = " << res << std::endl;

        res = con3->del_element_end();
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << "element = " << res << std::endl;

        res = con3->del_element(con3->get_lenght() - 1);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << "element = " << res << std::endl;
        std::cout << std::endl;

        std::cout << "Поиск элемента" << std::endl;
        res = con3->find_element(43);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << "index = " << res << std::endl;

        res = con3->find_element(777);
        con3->show_conteiner();
        std::cout << "lenght arr = " << con3->get_lenght() << std::endl;
        std::cout << "index = " << res << std::endl;

        std::cout << std::endl;
        std::cout << "test = and []" << std::endl;
        
        Conteiner con21(4);
        con21[3] = 555;
        con21[0] = 555;
        std::cout << con21[3] << std::endl;

        Conteiner con22(4);
        con22 = con21;

        con21.show_conteiner();
        con22.show_conteiner();

        Conteiner con23(8);
       
        con23 = *con3;
        con3->show_conteiner();
        con23.show_conteiner();
         
        con3->show_conteiner();
        (*con3)[2] = 888;
        con3->show_conteiner();   

        delete con2;
        delete con3;
    }
    catch (BadLenght& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (BadRange& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "Что то не так" << std::endl;
        std::cout << ex.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Test error" << std::endl;
    std::cout << std::endl;

    try {
        std::cout << "Создание сонтейнера с 0 размером" << std::endl;
        Conteiner con(0);

    }
    catch (BadLenght& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (BadRange& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "Что то не так" << std::endl;
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    }

    try {
        std::cout << "Получение элемента" << std::endl;
        Conteiner con1(10);
        con1.initialization_conteiner();
        con1.show_conteiner();

        con1.get_element(-2);
    }
    catch (BadLenght& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (BadRange& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "Что то не так" << std::endl;
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    }

    try {
        std::cout << "Добавление элемента" << std::endl;
        Conteiner con2(10);
        con2.initialization_conteiner();
        con2.show_conteiner();

        con2.add_element(777, -1);
    }
    catch (BadLenght& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (BadRange& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "Что то не так" << std::endl;
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    }

    try {
        std::cout << "Добавление элемента" << std::endl;
        Conteiner con6(10);
        con6.initialization_conteiner();
        con6.show_conteiner();

        con6.add_element(777, 150);
    }
    catch (BadLenght& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (BadRange& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "Что то не так" << std::endl;
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    }

    try {
        std::cout << "Удаление элемента" << std::endl;
        Conteiner con7(10);
        con7.initialization_conteiner();
        con7.show_conteiner();

        con7.del_element(9);
        con7.show_conteiner();

        con7.del_element(9);
        con7.show_conteiner();
    }
    catch (BadLenght& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (BadRange& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "Что то не так" << std::endl;
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    }

    try {
        std::cout << "Копирование элемента" << std::endl;
        Conteiner con3(10);
        con3.initialization_conteiner();
        con3.show_conteiner();

        Conteiner con4(5);
        con4.initialization_conteiner();
        con4.show_conteiner();

        con4.copy_conteiner(&con3);
        con4.show_conteiner();

    }
    catch (BadLenght& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (BadRange& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "Что то не так" << std::endl;
        std::cout << ex.what() << std::endl;
    }
    catch (std::bad_alloc& ba) {
        std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
    }

    try {
        Conteiner con9;
        std::cout << "sizeof(con9) = " << sizeof(con9) << std::endl;
        std::cout << "bad_alloc выделение памяти" << std::endl;
        Conteiner *con8 = new Conteiner[1'000'000];
        con8->initialization_conteiner();
        con8->show_conteiner();
    }
    catch (BadLenght& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (BadRange& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << "Что то не так" << std::endl;
        std::cout << ex.what() << std::endl;
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    }
    return 0;
}