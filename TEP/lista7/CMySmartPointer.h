//
// Created by Madatt on 01.12.2019.
//

#ifndef LISTA7_CMYSMARTPOINTER_H
#define LISTA7_CMYSMARTPOINTER_H

#include <iostream>

class CRefCounter {
public:
    CRefCounter() { i_count = 0; }

    int iAdd() { return (++i_count); }
    int iDec() { return (--i_count); };
    int iGet() { return (i_count); }

private:
    int i_count;
};


template <typename T>
class CMySmartPointer {
public:
    CMySmartPointer(T *pcPointer) {
        std::cout << "Tworzymy" << std::endl;
        pc_pointer = pcPointer;
        pc_counter = new CRefCounter();
        pc_counter->iAdd();
    }

    CMySmartPointer(const CMySmartPointer &pcOther) {
        std::cout << "Kopiujemy: " << pcOther.pc_counter->iGet() << std::endl;
        pc_pointer = pcOther.pc_pointer;
        pc_counter = pcOther.pc_counter;
        pc_counter->iAdd();
    }

    ~CMySmartPointer() {
        std::cout << "Usuwamy: " << pc_counter->iGet() << std::endl;
        if (pc_counter->iDec() == 0) {
            delete pc_pointer;
            delete pc_counter;
            std::cout << "Usuwamy wskaznik" << std::endl;
        }
    }

    CMySmartPointer& operator=(const CMySmartPointer& pcOther) {
        if(this != &pcOther)
        {
            std::cout << "Usuwamy: " << pcOther.pc_counter->iGet() << std::endl;
            if (pc_counter->iDec() == 0) {
                delete pc_pointer;
                delete pc_counter;
                std::cout << "Usuwamy wskaznik" << std::endl;
            }

            std::cout << "Kopiujemy: " << pcOther.pc_counter->iGet() << std::endl;
            pc_counter = pcOther.pc_counter;
            pc_pointer = pcOther.pc_pointer;
            pc_counter->iAdd();
        }

        return *this;
    }

    T &operator*() { return (*pc_pointer); }
    T *operator->() { return (pc_pointer); }

private:
    CRefCounter *pc_counter;
    T *pc_pointer;
};


#endif //LISTA7_CMYSMARTPOINTER_H
