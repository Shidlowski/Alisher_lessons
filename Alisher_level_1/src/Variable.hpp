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

namespace storage {

class Variable {

 public:
  enum class Type {
    STRUCT, INT, DOUBLE, BOOL, STRING, INT_ARRAY, DOUBLE_ARRAY, BOOL_ARRAY, STRING_ARRAY, NONE
  };

  explicit Variable(const std::string &name, const Type &type = Type::NONE) : name_(name), type_(type) {}

  ~Variable() = default;

  Variable(const Variable &variable) = default;

  Variable &operator=(const Variable &variable) = default;

  bool hasMember(const std::string &name) noexcept;

  Variable &newMember(const std::string &name, const allType &value);

  Variable &newMember(const Variable &variable);

  const std::string &name() const noexcept;

  Type type() const noexcept;

  int asInt();

  double asDouble();

  bool asBool();

  std::string asString();

  std::vector<int> asIntArray();

  std::vector<double> asDoubleArray();

  std::vector<bool> asBoolArray();

  std::vector<std::string> asStringArray();

  Variable &operator[](const std::string &name);

  void operator=(const allType &variable);

  friend bool operator==(const Variable &variable, const allType &value) noexcept;

  friend bool operator!=(const Variable &variable, const allType &value) noexcept;

 private:
  Type type_;
  std::string name_;
  allType value_;
  std::map<std::string, Variable> memory_;

  Type getType(const allType &var);

  Variable newVariable(const std::string &name, const allType &value);

};

}

#endif //ALISHER_LEVEL_1_VARIABLE_HPP
