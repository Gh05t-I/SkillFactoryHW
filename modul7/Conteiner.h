#include<iostream>
#include<ctime>

class Conteiner {
private:

    int m_size{ 0 };
    int* m_array_integer{ nullptr };

    void reset_arr(int* arr, int size);

public:

    //Конструкторы
    Conteiner();
    Conteiner(int size); 

    Conteiner(const Conteiner& ref_Conteiner); 

    //Деструктор
    ~Conteiner(); 

    void initialization_conteiner(); 
    void show_conteiner() const;

    //Геттеры сеттеры
    int get_element(int element) const;
    int get_lenght() const; 
    void set_element(const int index, const int value);

    void copy_conteiner(Conteiner* conteiner);

    int resize(int size); // Меняем размер контейнера, старые данные сохраняем

    int add_element_start(int value); 
    int add_element_end(int value);
    int add_element(int value, int index);

    int del_element_start();
    int del_element_end();
    int del_element(int index);

    int find_element(int value); //Находит элемент по значению, возвращает индекс первого совпадения

    //Операторы
    int& operator[] (const int index);
    Conteiner& operator = (const Conteiner& right);
};