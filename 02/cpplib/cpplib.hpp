#pragma once

#include <cstdio>

class A {
public:
    A(){}
    void method1(){ printf("A::method1()\n"); }
};
class B : public A {
public:
    void method2(){ printf("B::method2()\n"); }
};
