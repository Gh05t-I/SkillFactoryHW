#include"Conteiner.h"
#include "BadLenght.h"
#include "BadRange.h"

Conteiner::Conteiner() = default;

Conteiner::Conteiner(int size) : m_size(size) {

    if (size <= 0) {
        throw BadLenght();
    }    
    m_array_integer = new int[size];
    reset_arr(m_array_integer, size);
}

Conteiner::Conteiner(const Conteiner& ref_Conteiner) {

    if (ref_Conteiner.get_lenght() != m_size) {
        throw BadLenght();
    }
    
    for (int i = 0; i < m_size; ++i) {
        m_array_integer[i] = ref_Conteiner.m_array_integer[i];
    }
}

Conteiner::~Conteiner() {    
    delete[] m_array_integer;
}

void Conteiner::initialization_conteiner() {

    std::srand(std::time(nullptr));

    for (int i = 0; i < m_size; ++i) {
        m_array_integer[i] = 1 + std::rand() / ((RAND_MAX + 1u) / 100);
    }
}

void Conteiner::show_conteiner() const{

    for (int i = 0; i < m_size; ++i) {
        std::cout << m_array_integer[i] << " ";
    }
    std::cout << std::endl;
}

int Conteiner::get_element(int element) const {

    if (element < 0) {
        throw BadRange();
    }

    return m_array_integer[element];
}

int Conteiner::get_lenght() const {
    return m_size;
}

void Conteiner::set_element(const int index, const int value) {

    if (index >= m_size) {
        throw BadRange();
    }
    m_array_integer[index] = value;
}

void Conteiner::copy_conteiner(Conteiner* conteiner) {

    if (m_size < conteiner->m_size) {
        throw BadLenght();
    }

    for (int i = 0; i < conteiner->m_size; ++i) {
        m_array_integer[i] = conteiner->m_array_integer[i];
    }
}

int Conteiner::resize(int size) {

    if (size < m_size) {

        bool enter{ true };
        char answer{ '\0' };

        std::cout << "ѕри изменении размера часть данных будет потер€на, продолжить Y/N" << std::endl;
        std::cin >> answer;

        while (enter) {
            if (answer == 'Y' || answer == 'N') {
                enter = false;
            }
            else {
                std::cout << "введите Y или N" << std::endl;
                std::cin >> answer;
            }
        }

        if (answer == 'N') {
            return -1;
        }

        m_size = size;
    }

    int* temp = new int[size];

    for (int i = 0; i < m_size; ++i) {
        temp[i] = m_array_integer[i];
    }

    delete[] m_array_integer;

    m_array_integer = temp;

    m_size = size;

    return 0;
}

int Conteiner::add_element_start(int value) {

    int* temp = new int[m_size + 1];

    temp[0] = value;

    for (int i = 0, j = 1; j < m_size + 1; ++i, ++j) {
        temp[j] = m_array_integer[i];
    }

    delete[] m_array_integer;

    m_array_integer = temp;
    ++m_size;

    return 0;
}

int Conteiner::add_element_end(int value) {

    int* temp = new int[m_size + 1];

    for (int i = 0; i < m_size; ++i) {
        temp[i] = m_array_integer[i];
    }
    temp[m_size] = value;   

    delete[] m_array_integer;

    m_array_integer = temp;
    ++m_size;

    return 0;
}

int Conteiner::add_element(int value, int index) {

    if (index >= m_size || index < 0) {
        throw BadRange();
    }


    int* temp = new int[m_size + 1];

    for (int i = 0; i < index; ++i) {
        temp[i] = m_array_integer[i];
    }

    temp[index] = value;    

    for (int i = index + 1, j = index; i < m_size; ++i, ++j) {
        temp[i] = m_array_integer[j];
    }

    delete[] m_array_integer;

    m_array_integer = temp;
    ++m_size;

    return 0;
}


int Conteiner::del_element_start() {

    int* temp = new int[m_size - 1];
    int result = m_array_integer[0];

    for (int i = 0, j = 1; i < m_size - 1; ++i, ++j) {
        temp[i] = m_array_integer[j];
    }

    delete[] m_array_integer;

    m_array_integer = temp;
    --m_size;

    return result;
}

int Conteiner::del_element_end() {

    int* temp = new int[m_size - 1];
    int result = m_array_integer[m_size];

    for (int i = 0; i < m_size - 1; ++i) {
        temp[i] = m_array_integer[i];
    }

    delete[] m_array_integer;

    m_array_integer = temp;
    --m_size;

    return result;
}

int Conteiner::del_element(int index) {

    if (index >= m_size || index < 0) {
        throw BadRange();
    }

    int* temp = new int[m_size - 1];
    int result = m_array_integer[index];

    for (int i = 0, j = 0; i < m_size - 1; ++i, ++j) {

        if (j == index) {
            ++j;
        }
        temp[i] = m_array_integer[j];
    }

    delete[] m_array_integer;

    m_array_integer = temp;
    --m_size;

    return result;
}

int Conteiner::find_element(int value) {

    for (int i = 0; i < m_size; ++i) {
        if (m_array_integer[i] == value) {
            return i;
        }
    }
    return -1;
}

void Conteiner::reset_arr(int* arr, int size) {

    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

int& Conteiner::operator[] (const int index) {
    if (index >= m_size) {
        throw BadRange();
    }
    return m_array_integer[index];
}

Conteiner& Conteiner::operator= (const Conteiner &right) {   

    if (m_size < right.get_lenght()) {
        throw BadLenght();
    }

    for (int i = 0; i < right.get_lenght(); ++i) {
        m_array_integer[i] = right.get_element(i);
    }

}


