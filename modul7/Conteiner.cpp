#include"Conteiner.h"

Conteiner::Conteiner() = default;

Conteiner::Conteiner(int size) : m_size(size) {

    if (size <= 0) {
        throw 0;
    }    
    m_array_integer = new int[size];

    reset_arr(m_array_integer, size);
}

Conteiner::Conteiner(const Conteiner& ref_Conteiner) {
    
    for (int i = 0; i < m_size; ++i) {
        m_array_integer[i] = ref_Conteiner.m_array_integer[i];
    }
}

Conteiner::~Conteiner() {    
    delete[] m_array_integer;
}

void Conteiner::initialization_conteiner() {

    if (m_size <= 0) {
        throw 0;
    }

    std::srand(std::time(nullptr));

    for (int i = 0; i < m_size; ++i) {
        m_array_integer[i] = 1 + std::rand() / ((RAND_MAX + 1u) / 100);
    }
}

void Conteiner::show_conteiner() {

    if (m_size <= 0) {
        throw 0;
    }

    for (int i = 0; i < m_size; ++i) {
        std::cout << m_array_integer[i] << " ";
    }
    std::cout << std::endl;
}

int Conteiner::get_element(int element) const {

    if (m_size <= 0 || element < 0) {
        throw - 1;
    }

    return m_array_integer[element];
}

int Conteiner::get_lenght() const {
    return m_size;
}

void Conteiner::set_element(const int index, const int value) {
    m_array_integer[index] = value;
}

void Conteiner::copy_conteiner(Conteiner* conteiner) {

    if (m_size < conteiner->m_size) {
        throw "Контейнер не может быть полностью скопирован, размер текущего меньше копируемого";
    }

    for (int i = 0; i < conteiner->m_size; ++i) {
        m_array_integer[i] = conteiner->m_array_integer[i];
    }
}

int Conteiner::resize(int size) {

    if (size < m_size) {

        bool enter{ true };
        char answer{ '\0' };

        std::cout << "При изменении размера часть данных будет потеряна, продолжить Y/N" << std::endl;
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

    int* temp = new int[++m_size];

    temp[0] = value;

    for (int i = 0, j = 1; j < m_size; ++i, ++j) {
        temp[j] = m_array_integer[i];
    }

    delete[] m_array_integer;

    m_array_integer = temp;

    return 0;
}

int Conteiner::add_element_end(int value) {

    int* temp = new int[m_size + 1];

    for (int i = 0; i < m_size; ++i) {
        temp[i] = m_array_integer[i];
    }
    temp[m_size] = value;
    ++m_size;

    delete[] m_array_integer;

    m_array_integer = temp;

    return 0;
}

int Conteiner::add_element(int value, int index) {

    if (index >= m_size ) {
        throw - 2;
    }
    else if (index < 0) {
        throw - 1;
    }

    int* temp = new int[m_size + 1];

    for (int i = 0; i < index; ++i) {
        temp[i] = m_array_integer[i];
    }

    temp[index] = value;
    ++m_size;

    for (int i = index + 1, j = index; i < m_size; ++i, ++j) {
        temp[i] = m_array_integer[j];
    }

    delete[] m_array_integer;

    m_array_integer = temp;

    return 0;
}

void Conteiner::reset_arr(int* arr, int size) {

    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}