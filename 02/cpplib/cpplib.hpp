#pragma once

#include <cstdio>

class A {
public:
    A(){}
    void method1(){ printf("A::method1()\n"); }
};
class B : public A {
};
