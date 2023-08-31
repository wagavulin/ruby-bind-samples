#pragma once

#include <cstdio>

class A {
public:
    virtual ~A(){ printf("~A()\n"); }
    virtual void method1(){ printf("A::method1()\n"); }
    virtual void method2() = 0;
};
class B : public A {
public:
    ~B(){ printf("~B()\n"); }
    virtual void method3() = 0;
};
class C : public B {
public:
    ~C(){ printf("~C()\n"); }
    void method2() override { printf("C::method2()\n"); }
    void method3() override { printf("C::method3()\n"); }
};
