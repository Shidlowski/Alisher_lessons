#ifndef ISTORAGE_INCLUDE_STORAGELIB_PCH_HPP_
#define ISTORAGE_INCLUDE_STORAGELIB_PCH_HPP_

#define CHECK_FUNC(func_name, template_name)                                    \
  template<typename C, typename = std::true_type>                               \
  struct has_member_func : std::false_type {};                                  \
                                                                                \
  template<typename C, typename = void>                                         \
  struct got_type : std::false_type {};                                         \
                                                                                \
  template<typename C>                                                          \
  struct got_type<C> : std::true_type {                                         \
    typedef C type;                                                             \
  };                                                                            \
                                                                                \
  template<typename C>                                                          \
  struct has_member_func<C,                                                     \
    std::integral_constant<bool,                                                \
    got_type<decltype(&C::open_impl)>::value>>:                                 \
    std::true_type {};                                                          \
                                                                                \
  static const bool v = has_member_func<template_name>::value;

namespace storagelib {

template<typename T>
struct has_open {
  CHECK_FUNC(open_impl, T);
};

template<typename T>
struct has_close {
  CHECK_FUNC(close_impl, T);
};

template<typename T>
struct has_write {
  CHECK_FUNC(write_impl, T);
};

class Bar {};

class Foo {
 public:
  void open_impl();
  void write_impl();
  void close_impl();
};

static_assert(has_open<Foo>::v, "Foo has got open_impl method");
static_assert(not has_open<Bar>::v, "Bar hasn't got open_impl method");

static_assert(has_close<Foo>::v, "Foo has got close_impl method");
static_assert(not has_close<Bar>::v, "Bar hasn't got close_impl method");

static_assert(has_write<Foo>::v, "Foo has got close_impl method");
static_assert(not has_write<Bar>::v, "Bar hasn't got close_impl method");

}

#endif // ISTORAGE_INCLUDE_STORAGELIB_PCH_HPP_
