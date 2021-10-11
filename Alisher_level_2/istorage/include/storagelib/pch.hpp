#ifndef ISTORAGE_INCLUDE_STORAGELIB_PCH_HPP_
#define ISTORAGE_INCLUDE_STORAGELIB_PCH_HPP_

namespace storagelib {

template<typename T>
struct has_open {
 typedef void(T::*P)(void);

  template<class U, P = &U::open_impl>
  struct True { char dummy[2]; };
  typedef char False;
  static False detect(...);
  template<class U>
  static True<U> detect(U *);

  static const bool v = (sizeof(False) != sizeof(detect(static_cast<T *>(0))));

};

template<typename T>
struct has_close {
  typedef void(T::*P)(void);

  template<class U, P = &U::close_impl>
  struct True { char dummy[2]; };
  typedef char False;
  static False detect(...);
  template<class U>
  static True<U> detect(U *);

  static const bool v = (sizeof(False) != sizeof(detect(static_cast<T *>(0))));
};

template<typename T>
struct has_write {
  typedef void(T::*P)(void);

  template<class U, P = &U::write_impl>
  struct True { char dummy[2]; };
  typedef char False;
  static False detect(...);
  template<class U>
  static True<U> detect(U *);

  static const bool v = (sizeof(False) != sizeof(detect(static_cast<T *>(0))));
};

class Bar {};

class Foo {
 public:
  void open_impl();
//  void open_impl(const std::string uri);
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
