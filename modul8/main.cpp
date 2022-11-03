#include <iostream>

#include "exception_container.cpp"

template <typename T> class Container {

    int m_size{ 0 };
    T* m_array{ nullptr };

public:

    Container(int size) : m_size(size) {

        if (size <= 0) {
            throw BadLenght();
        }

        m_array = new T[size];
    }

    Container(const Container& ref_container) {

        if (ref_container.m_size != m_size) {
            throw BadLenght();
        }

        for (int i = 0; i < m_size; ++i) {
            m_array[i] = ref_container.m_array[i];
        }
    }

    ~Container() {
        delete[] m_array;
    }


    int get_lenght() const {
        return m_size;
    }


    int resize_speed(int size) {

        if (size <= 0) {
            throw BadLenght();
        }


        if (size <= m_size) {
            m_size = size;
            return 0;
        }
        else {

            T* temp = new T[size];

            for (int i = 0; i < m_size; ++i) {
                temp[i] = m_array[i];
            }

            delete[] m_array;
            m_array = temp;

            m_size = size;

            return 0;
        }
    }

    int resize_save_member(int size) {

        if (size <= 0 || size == m_size) {
            throw BadLenght();
        }

        int size_valid_data{ 0 };

        if (size < m_size) {

            bool enter{ true };
            char answer{ '\0' };

            std::cout << "Size does not match, there will be data loss, continue ? Y/N" << std::endl;
            std::cin >> answer;

            while (enter) {
                if (answer == 'Y' || answer == 'N') {
                    enter = false;
                }
                else {
                    std::cout << "write Y or N" << std::endl;
                    std::cin >> answer;
                }
            }

            if (answer == 'N') {
                return -1;
            }

            size_valid_data = size;
        }
        else {
            size_valid_data = m_size;
        }


        T* temp = new T[size];

        for (int i = 0; i < size_valid_data; ++i) {
            temp[i] = m_array[i];
        }

        delete[] m_array;
        m_array = temp;

        m_size = size;

        return 0;
    }


    void add_element(T value, int index) {

        if (index >= m_size) {
            throw BadRange();
        }

        T* temp = new T[m_size + 1];

        for (int i = 0; i < index; ++i) {
            temp[i] = m_array[i];
        }

        temp[index] = value;

        for (int i = index + 1, j = index; i < m_size + 1; ++i, ++j) {
            temp[i] = m_array[j];
        }

        delete[] m_array;
        m_array = temp;

        ++m_size;
    }

    void del_element(int index) {

        if (index >= m_size) {
            throw BadRange();
        }

        T* temp = new T[m_size - 1];

        for (int i = 0, j = 0; i < m_size - 1; ++i, ++j) {

            if (j == index) {
                ++j;
            }
            temp[i] = m_array[i];
        }

        delete[] m_array;
        m_array = temp;

        --m_size;
    }

    void show_container() const {

        for (int i = 0; i < m_size; ++i) {
            std::cout << m_array[i] << " ";
        }
        std::cout << std::endl;
    }

    int find_element(T value) {

        for (size_t i = 0; i < m_size; ++i) {
            if (m_array[i] == value) {
                return i;
            }
        }
        return -1;
    }

    //Операторы
    Container& operator = (const Container& right) {

        if (m_size != right.m_size) {
            throw BadLenght();
        }

        for (int i = 0; i < m_size; ++i) {
            m_array[i] = right.m_array[i];
        }
        return *this;
    }

    T& operator [] (const int index) {
        return m_array[index];
    }
};


int main() {


    try {

        std::string s1;
        std::string s2;
        std::string s3 = "string";

        std::cout << "s1 = " << s1 << std::endl;
        std::cout << "s2 = " << s2 << std::endl;
        std::cout << "s3 = " << s3 << std::endl;

        s1 = s3;

        std::cout << "s1 = " << s1 << std::endl;
        std::cout << "s2 = " << s2 << std::endl;
        std::cout << "s3 = " << s3 << std::endl;

        Container<int> con1(10);

        con1[0] = 1;
        con1[1] = 2;
        con1[2] = 3;
        con1[3] = 4;

        Container<int> con2(10);

        con1.show_container();
        con2.show_container();

        con2 = con1;
        con2.show_container();

        std::cout << "add" << std::endl;
        con2.add_element(777, 9);
        con2.show_container();

        con2.add_element(555, 8);
        con2.show_container();

        con2.add_element(556, 8);
        con2.show_container();

        con2.del_element(8);
        con2.show_container();

        std::cout << "char" << std::endl;

        Container<char> con3(4);
        Container<char>con4(4);
        con3[0] = 'a';
        con3[3] = 'd';
        con3.show_container();
        con4.show_container();

        con4 = con3;
        con3.show_container();
        con4.show_container();

        std::cout << "resize" << std::endl;
        con4.resize_save_member(8);
        con4.add_element('G', 7);
        con4.show_container();

        std::cout << "string" << std::endl;

        Container<std::string> con5(4);
        Container<std::string> con6(4);

        con5[0] = "str0";
        con5[3] = "str3";
        con6 = con5;
        con5.show_container();
        con6.show_container();

        con6.add_element("con_new", 3);
        con6.show_container();
        con6[1] = "1";
        con6[2] = "2";
        con6.show_container();

        std::cout << con6.find_element("1") << std::endl;

        con6.add_element("error", 89);
        con6.show_container();

    }
    catch(BadLenght e) {
        std::cout << e.what() << std::endl;
    }
    catch (BadRange e) {
        std::cout << e.what() << std::endl;
    }

    

    return 0;
}