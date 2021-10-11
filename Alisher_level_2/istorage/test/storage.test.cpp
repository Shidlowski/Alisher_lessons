//
// Created by alisher on 26.04.2021.
//

#include <gtest/gtest.h>
#include <storagelib/storage.hpp>

class Storage : public storagelib::IStorage<Storage, std::string, 0> {
 public:
  explicit Storage(const std::string &uri) : storagelib::IStorage<Storage, std::string, 0>(uri) {}

  ~Storage() = default;
  Storage(const Storage &) = delete;
  Storage(Storage &&) noexcept = delete;
  Storage &operator=(const Storage &) = delete;
  Storage &operator=(Storage &&) noexcept = delete;

  void close_impl() {}
  void open_impl(const std::string &uri) {}
  void write_impl(const std::string &uri, const storagelib::Variable &var) {}
};

TEST(Storage, Interface) {
  Storage storage("./example.json");
  ASSERT_NO_THROW(storage.open());

  int intVar = 0;
  storage.set("/foo/intVar", intVar = 6);
  ASSERT_EQ(intVar, storage.at("/foo/intVar").asInt());
  ASSERT_ANY_THROW(storage.set("/foo/intVar", false));
  ASSERT_ANY_THROW(storage.at("/foo/intVar").asDoubleArray());

  auto doubleVar = 7.8;
  ASSERT_NO_THROW(storage.set("/foo/doubleVar", doubleVar));
  ASSERT_EQ(doubleVar, storage.at("/foo/doubleVar").asDouble());

  std::vector<double> doubleArray{1.0, 2.3, 4.3, 6.7, 9.3, 10.1};
  ASSERT_NO_THROW(storage.set("/foo/doubleArray", doubleArray));
  ASSERT_TRUE(std::equal(doubleArray.begin(), doubleArray.end(),
                         storage.at("/foo/doubleArray").asDoubleArray().begin()));

  ASSERT_NO_THROW(storage.close());
}
