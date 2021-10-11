//
// Created by alisher on 4/21/21.
//

#ifndef ISTORAGE_INCLUDE_STORAGELIB_STORAGE_HPP_
#define ISTORAGE_INCLUDE_STORAGELIB_STORAGE_HPP_
#include "pch.hpp"

#include <string>
#include <memory>
#include <thread>
#include <type_traits>
#include <atomic>

#include "variable.hpp"
#include "container.hpp"

namespace storagelib {

template<class Storage,                 /// <<< concrete storage implementation
    class Uri = std::string,            /// <<< concrete storage uri
    int th = 1>
class IStorage {
 public:

  explicit IStorage(const Uri &uri) : uri_{uri}, run_{true}, store_{"store"}, uuris_{} {}

  ~IStorage() = default;

  IStorage(const IStorage<Storage, Uri> &) = delete;
  IStorage(IStorage<Storage, Uri> &&) noexcept = delete;
  IStorage &operator=(const IStorage<Storage, Uri> &) = delete;
  IStorage &operator=(IStorage<Storage, Uri> &&) noexcept = delete;

  void open(const std::optional<Uri> uri = std::nullopt) {

    static_cast<Storage*>(this)->open_impl(uri);

    ///????
    static_assert(has_open<Storage>::v, "storage class requires any open implementation");
  };

  void close() {
    static_assert(has_close<Storage>::v, "storage class requires any close implementation");
   ////????
  };

  const Variable &at(const std::string &uri){

  }

  template<bool _ = true, class T>
  Variable &set(const std::string &uri, const T &value){

  }

 protected:

  void write(const std::pair<std::string, Variable> &pair) {
    static_assert(has_write<Storage>::v, "storage class requires any write implementation");
   ////?????
  }

 protected:

  Uri uri_;
  Variable store_;
  std::atomic_bool run_;
  std::vector<std::thread> threads_;
  Queue<std::pair<std::string, Variable >> uuris_;
};

}
#endif //ISTORAGE_INCLUDE_STORAGELIB_STORAGE_HPP_
