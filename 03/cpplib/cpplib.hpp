#pragma once

#include <cstdio>

class A {
public:
    A(){}
    ~A(){ printf("~A()\n"); }
    void method1(){ printf("A::method1()\n"); }
};
class B : public A {
public:
    ~B(){ printf("~B()\n"); }
    void method2(){ printf("B::method2()\n"); }
};
