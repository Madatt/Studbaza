#include <iostream>

class A {
public:
    virtual ~A() = default;

private:
    virtual std::string name() = 0;

    friend std::string name(A* t_obj);
};

std::string name(A* t_obj) {
    return t_obj->name();
}

class B : public A {
public:
    virtual ~B() = default;

private:
    virtual std::string name() {
        return "B";
    }
};

class C : public B {
public:
    virtual ~C() = default;

private:
    virtual std::string name() {
        return "C";
    }
};


int main() {
    A* b = new B;
    A* c = new C;

    std::cout << name(b) << std::endl;
    std::cout << name(c) << std::endl;
}