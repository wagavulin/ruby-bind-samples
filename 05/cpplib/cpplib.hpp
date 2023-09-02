#pragma once

#include <cstdio>

struct B {
    ~B(){ printf("[%s]\n", __func__); fflush(stdout); }
    int x{10};
};
struct A {
    ~A(){ printf("[%s]\n", __func__); fflush(stdout); }
    B b{};
};
