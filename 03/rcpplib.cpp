#include <ruby.h>
#include <memory>
#include "cpplib/cpplib.hpp"

static VALUE mRcpplib;

struct Wrap_Cpplib_A {
    std::shared_ptr<A> obj;
};
static void wrap_Cpplib_A_free(struct Wrap_Cpplib_A* ptr){
    ptr->obj.reset();
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
    ptr->obj = std::make_shared<A>();
    return Qnil;
}
static std::shared_ptr<A> get_Cpplib_A(VALUE self){
    struct Wrap_Cpplib_A* ptr;
    TypedData_Get_Struct(self, struct Wrap_Cpplib_A, &Cpplib_A_type, ptr);
    return ptr->obj;
}
static VALUE wrap_Cpplib_A_alloc(VALUE klass){
    struct Wrap_Cpplib_A* ptr = nullptr;
    VALUE ret = TypedData_Make_Struct(klass, struct Wrap_Cpplib_A, &Cpplib_A_type, ptr);
    return ret;
}
static VALUE wrap_Cpplib_A_method1(int argc, VALUE *argv, VALUE self){
    get_Cpplib_A(self)->method1();
    return Qnil;
}

static const rb_data_type_t Cpplib_B_type {
    "B",
    {NULL, reinterpret_cast<RUBY_DATA_FUNC>(wrap_Cpplib_A_free), NULL},
    &Cpplib_A_type, NULL,
    RUBY_TYPED_FREE_IMMEDIATELY
};
static VALUE wrap_Cpplib_B_init(int argc, VALUE *argv, VALUE self){
    Wrap_Cpplib_A* ptr;
    TypedData_Get_Struct(self, struct Wrap_Cpplib_A, &Cpplib_B_type, ptr);
    ptr->obj = std::make_shared<B>();
    return Qnil;
}
static std::shared_ptr<B> get_Cpplib_B(VALUE self){
    struct Wrap_Cpplib_A* ptr;
    TypedData_Get_Struct(self, struct Wrap_Cpplib_A, &Cpplib_B_type, ptr);
    std::shared_ptr<B> p = std::static_pointer_cast<B>(ptr->obj);
    return p;
}
static VALUE wrap_Cpplib_B_alloc(VALUE klass){
    struct Wrap_Cpplib_A* ptr = nullptr;
    VALUE ret = TypedData_Make_Struct(klass, struct Wrap_Cpplib_A, &Cpplib_B_type, ptr);
    return ret;
}
static VALUE wrap_Cpplib_B_method2(int argc, VALUE *argv, VALUE self){
    get_Cpplib_B(self)->method2();
    return Qnil;
}

extern "C" {
void Init_rcpplib(){
    mRcpplib = rb_define_module("Rcpplib");
    VALUE cCpplib_A = rb_define_class_under(mRcpplib, "A", rb_cObject);
    rb_define_alloc_func(cCpplib_A, wrap_Cpplib_A_alloc);
    rb_define_private_method(cCpplib_A, "initialize", RUBY_METHOD_FUNC(wrap_Cpplib_A_init), -1);
    rb_define_method(cCpplib_A, "method1", RUBY_METHOD_FUNC(wrap_Cpplib_A_method1), -1);

    VALUE cCpplib_B = rb_define_class_under(mRcpplib, "B", cCpplib_A);
    rb_define_alloc_func(cCpplib_B, wrap_Cpplib_B_alloc);
    rb_define_private_method(cCpplib_B, "initialize", RUBY_METHOD_FUNC(wrap_Cpplib_B_init), -1);
    rb_define_method(cCpplib_B, "method2", RUBY_METHOD_FUNC(wrap_Cpplib_B_method2), -1);
}
}
