//
// Created by madatt on 03.01.20.
//

#ifndef LISTA9_RANDOM_H
#define LISTA9_RANDOM_H


#include <random>

class Random {
public:
    Random()
    : seed(), engine(seed()){

    }

    Random(int t_seed)
            : seed(), engine(t_seed){

    }

    ~Random() = default;

    template<typename T>
    T randomInteger(T t_min, T t_max) {
        std::uniform_int_distribution<T> dis(t_min, t_max);
        return dis(engine);
    }

    template<typename T>
    T randomReal(T t_min, T t_max) {
        std::uniform_real_distribution<T> dis(t_min, t_max);
        return dis(engine);
    }

private:
    std::random_device seed;
    std::mt19937 engine;
};


#endif //LISTA9_RANDOM_H
