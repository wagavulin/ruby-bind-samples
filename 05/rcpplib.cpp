#include <ruby.h>
#include <memory>
#include "cpplib/cpplib.hpp"

static VALUE mRcpplib;

static VALUE cCpplib_B;
struct Wrap_Cpplib_B {
    B* obj;
};
static void wrap_Cpplib_B_free(struct Wrap_Cpplib_B* ptr){
    delete ptr->obj;
    ruby_xfree(ptr);
};
static const rb_data_type_t Cpplib_B_type {
    "B",
    {NULL, reinterpret_cast<RUBY_DATA_FUNC>(wrap_Cpplib_B_free), NULL},
    NULL, NULL,
    RUBY_TYPED_FREE_IMMEDIATELY
};
static VALUE wrap_Cpplib_B_init(int argc, VALUE *argv, VALUE self){
    Wrap_Cpplib_B* ptr;
    TypedData_Get_Struct(self, struct Wrap_Cpplib_B, &Cpplib_B_type, ptr);
    ptr->obj = new B();
    return Qnil;
}
static B* get_Cpplib_B(VALUE self){
    struct Wrap_Cpplib_B* ptr;
    TypedData_Get_Struct(self, struct Wrap_Cpplib_B, &Cpplib_B_type, ptr);
    return ptr->obj;
}
static VALUE wrap_Cpplib_B_alloc(VALUE klass){
    struct Wrap_Cpplib_B* ptr = nullptr;
    VALUE ret = TypedData_Make_Struct(klass, struct Wrap_Cpplib_B, &Cpplib_B_type, ptr);
    return ret;
}
static VALUE wrap_Cpplib_B_x_getter(VALUE self){
    const int& raw_retval = get_Cpplib_B(self)->x;
    return INT2NUM(raw_retval);
}
static VALUE wrap_Cpplib_B_x_setter(VALUE self, VALUE value_x){
    int raw_x = NUM2INT(value_x);
    get_Cpplib_B(self)->x = raw_x;
    return Qnil;
}

static VALUE cCpplib_A;
struct Wrap_Cpplib_A {
    A* obj;
};
static void wrap_Cpplib_A_free(struct Wrap_Cpplib_A* ptr){
    delete ptr->obj;
    ruby_xfree(ptr);
};
static const rb_data_type_t Cpplib_A_type {
    "A",
    {NULL, reinterpret_cast<RUBY_DATA_FUNC>(wrap_Cpplib_A_free), NULL},
    NULL, NULL,
    RUBY_TYPED_FREE_IMMEDIATELY
};
static VALUE wrap_Cpplib_A_init(int argc, VALUE *argv, VALUE self){
    Wrap_Cpplib_A* ptr;
    TypedData_Get_Struct(self, struct Wrap_Cpplib_A, &Cpplib_A_type, ptr);
    ptr->obj = new A();
    return Qnil;
}
static A* get_Cpplib_A(VALUE self){
    struct Wrap_Cpplib_A* ptr;
    TypedData_Get_Struct(self, struct Wrap_Cpplib_A, &Cpplib_A_type, ptr);
    return ptr->obj;
}
static VALUE wrap_Cpplib_A_alloc(VALUE klass){
    struct Wrap_Cpplib_A* ptr = nullptr;
    VALUE ret = TypedData_Make_Struct(klass, struct Wrap_Cpplib_A, &Cpplib_A_type, ptr);
    return ret;
}
static VALUE wrap_Cpplib_A_b_getter(VALUE self){
    B* raw_b = new B(get_Cpplib_A(self)->b);
    //B* raw_b = &(get_Cpplib_A(self)->b);
    Wrap_Cpplib_B* ptr;
    VALUE ret = TypedData_Make_Struct(cCpplib_B, struct Wrap_Cpplib_B, &Cpplib_B_type, ptr);
    ptr->obj = raw_b;
    return ret;
}
static VALUE wrap_Cpplib_A_b_setter(VALUE self, VALUE value_b){
    B* raw_b = get_Cpplib_B(value_b);
    A* raw_a = get_Cpplib_A(self);
    raw_a->b = *raw_b;
    return Qnil;
}

extern "C" {
void Init_rcpplib(){
    mRcpplib = rb_define_module("Rcpplib");
    cCpplib_A = rb_define_class_under(mRcpplib, "A", rb_cObject);
    rb_define_alloc_func(cCpplib_A, wrap_Cpplib_A_alloc);
    rb_define_private_method(cCpplib_A, "initialize", RUBY_METHOD_FUNC(wrap_Cpplib_A_init), -1);
    rb_define_method(cCpplib_A, "b", RUBY_METHOD_FUNC(wrap_Cpplib_A_b_getter), 0);
    rb_define_method(cCpplib_A, "b=", RUBY_METHOD_FUNC(wrap_Cpplib_A_b_setter), 1);

    cCpplib_B = rb_define_class_under(mRcpplib, "B", rb_cObject);
    rb_define_alloc_func(cCpplib_B, wrap_Cpplib_B_alloc);
    rb_define_private_method(cCpplib_B, "initialize", RUBY_METHOD_FUNC(wrap_Cpplib_B_init), -1);
    rb_define_method(cCpplib_B, "x", RUBY_METHOD_FUNC(wrap_Cpplib_B_x_getter), 0);
    rb_define_method(cCpplib_B, "x=", RUBY_METHOD_FUNC(wrap_Cpplib_B_x_setter), 1);
}
}
