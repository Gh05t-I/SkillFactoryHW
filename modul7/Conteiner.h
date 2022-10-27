#include<iostream>
#include<ctime>

class Conteiner {
private:

    int m_size{ 0 };
    int* m_array_integer{ nullptr };

    void reset_arr(int* arr, int size);

public:

    //������������
    Conteiner();;
    Conteiner(int size); 

    Conteiner(const Conteiner& ref_Conteiner); 

    //����������
    ~Conteiner(); 

    void initialization_conteiner(); 
    void show_conteiner(); 

    //������� �������
    int get_element(int element) const;
    int get_lenght() const; 
    void set_element(const int index, const int value);

    void copy_conteiner(Conteiner* conteiner);

    int resize(int size); // ������ ������ ����������, ������ ������ ���������

    int add_element_start(int value); 
    int add_element_end(int value);
    int add_element(int value, int index);
};