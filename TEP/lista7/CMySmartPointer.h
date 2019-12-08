//
// Created by Madatt on 01.12.2019.
//

#ifndef LISTA7_CMYSMARTPOINTER_H
#define LISTA7_CMYSMARTPOINTER_H

#include <iostream>

const int C_ITVAL1 = 123;
const int C_ITVAL2 = -1323;
const int C_ITVAL3 =  555;
const std::string C_STVAL1 = "test1";
const std::string C_STVAL2 = "test2";

class CRefCounter {
public:
    CRefCounter() { i_count = 0; }

    int iAdd() { return (++i_count); }
    int iDec() { return (--i_count); };
    int iGet() { return (i_count); }

private:
    int i_count;
};


template<typename T>
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
        vCheckDelete();
    }

    CMySmartPointer &operator=(const CMySmartPointer &pcOther) {
        if (this != &pcOther) {
            std::cout << "Usuwamy: " << pcOther.pc_counter->iGet() << std::endl;
            vCheckDelete();

            std::cout << "Kopiujemy: " << pcOther.pc_counter->iGet() << std::endl;
            pc_counter = pcOther.pc_counter;
            pc_pointer = pcOther.pc_pointer;
            pc_counter->iAdd();
        }

        return *this;
    }

    T &operator*() { return (*pc_pointer); }
    T *operator->() { return (pc_pointer); }

    CMySmartPointer<T> cDuplicate() {
        return CMySmartPointer(new T(*pc_pointer));
    }

private:
    CRefCounter *pc_counter;
    T *pc_pointer;

    void vCheckDelete() {
        if (pc_counter->iDec() == 0) {
            delete pc_pointer;
            delete pc_counter;
            std::cout << "Usuwamy wskaznik" << std::endl;
        }
    }

};


#endif //LISTA7_CMYSMARTPOINTER_H
