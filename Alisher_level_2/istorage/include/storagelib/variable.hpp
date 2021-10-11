//
// Created by alexander on 6/1/21.
//

#ifndef ALISHER_LEVEL_1_VARIABLE_HPP
#define ALISHER_LEVEL_1_VARIABLE_HPP

#include <string>
#include <map>
#include <variant>
#include <vector>
#include <iostream>

using allType = std::variant<int,
                             double,
                             bool,
                             std::string,
                             std::vector<int>,
                             std::vector<double>,
                             std::vector<bool>,
                             std::vector<std::string>>;

namespace storagelib {

class Variable {

 public:
  enum class Type {
    STRUCT, INT, DOUBLE, BOOL, STRING, INT_ARRAY, DOUBLE_ARRAY, BOOL_ARRAY, STRING_ARRAY, NONE
  };

  explicit Variable(const std::string &name, const Type &type = Type::NONE) : name_(name), type_(type) {}

  explicit Variable(const std::string &name, const allType &value);

  ~Variable() = default;

  Variable(const Variable &variable) = default;

  Variable &operator=(const Variable &variable) = default;

  Variable(Variable &&variable) noexcept = default;

  Variable &operator=(Variable &&variable) noexcept = default;

  bool hasMember(const std::string &name) noexcept;

  Variable &newMember(const std::string &name, const allType &value);

  Variable &newMember(const Variable &variable);

  const std::string &name() const noexcept;

  Type type() const noexcept;

  int asInt() const;

  double asDouble() const;

  bool asBool() const;

  std::string asString() const;

  std::vector<int> asIntArray() const;

  std::vector<double> asDoubleArray() const;

  std::vector<bool> asBoolArray() const;

  std::vector<std::string> asStringArray() const;

  Variable &operator[](const std::string &name);

  Variable &operator=(const allType &variable);

  friend bool operator==(const Variable &variable, const allType &value) noexcept;

  friend bool operator!=(const Variable &variable, const allType &value) noexcept;

 private:
  Type type_;
  std::string name_;
  allType value_;
  std::map<std::string, Variable> memory_;

};

}

#endif //ALISHER_LEVEL_1_VARIABLE_HPP
