//
// Created by alexander on 6/1/21.
//

#include "Variable.hpp"

namespace storage {

Variable::Type getType(const allType &value) {
  if (std::get_if<int>(&value)) {
    return Variable::Type::INT;
  } else if (std::get_if<double>(&value)) {
    return Variable::Type::DOUBLE;
  } else if (std::get_if<bool>(&value)) {
    return Variable::Type::BOOL;
  } else if (std::get_if<std::string>(&value)) {
    return Variable::Type::STRING;
  } else if (std::get_if<std::vector<int>>(&value)) {
    return Variable::Type::INT_ARRAY;
  } else if (std::get_if<std::vector<double>>(&value)) {
    return Variable::Type::DOUBLE_ARRAY;
  } else if (std::get_if<std::vector<bool>>(&value)) {
    return Variable::Type::BOOL_ARRAY;
  } else if (std::get_if<std::vector<std::string>>(&value)) {
    return Variable::Type::STRING_ARRAY;
  } else {
    return Variable::Type::NONE;
  }
}

Variable &Variable::newMember(const std::string &name, const allType &value) {
  memory_.insert(std::make_pair(name, Variable(name, value)));
  return memory_.at(name);
}

Variable &Variable::newMember(const Variable &variable) {
  memory_.insert(std::make_pair(variable.name_, variable));
  return memory_.at(variable.name_);
}

Variable::Variable(const std::string &name, const allType &value) {
  Variable temp(name);
  temp.type_ = getType(value);
  temp.value_ = value;
}

bool Variable::hasMember(const std::string &name_var) noexcept {
  return memory_.find(name_var) != memory_.end();
}

//get cast type variable
int Variable::asInt() const{
  if (type_ == Type::INT) {
    return std::get<int>(value_);
  } else {
    throw std::runtime_error("Types don't match");
  }
}

double Variable::asDouble() const{
  if (type_ == Type::DOUBLE) {
    return std::get<double>(value_);
  } else {
    throw std::runtime_error("Types don't match");
  }
}

bool Variable::asBool() const{
  if (type_ == Type::BOOL) {
    return std::get<bool>(value_);
  } else {
    throw std::runtime_error("Types don't match");
  }
}

std::string Variable::asString() const{
  if (type_ == Type::STRING) {
    return std::get<std::string>(value_);
  } else {
    throw std::runtime_error("Types don't match");
  }
}

//get cast array type variable
std::vector<int> Variable::asIntArray() const{
  if (type_ == Type::INT_ARRAY) {
    return std::get<std::vector<int>>(value_);
  } else {
    throw std::runtime_error("Types don't match");
  }
}

std::vector<double> Variable::asDoubleArray() const{
  if (type_ == Type::DOUBLE_ARRAY) {
    return std::get<std::vector<double>>(value_);
  } else {
    throw std::runtime_error("Types don't match");
  }
}

std::vector<bool> Variable::asBoolArray() const{
  if (type_ == Type::BOOL_ARRAY) {
    return std::get<std::vector<bool>>(value_);
  } else {
    throw std::runtime_error("Types don't match");
  }
}

std::vector<std::string> Variable::asStringArray() const{
  if (type_ == Type::STRING_ARRAY) {
    return std::get<std::vector<std::string>>(value_);
  } else {
    throw std::runtime_error("Types don't match");
  }
}

Variable &Variable::operator[](const std::string &name) {
  std::map<std::string, Variable>::iterator it = memory_.find(name);
  if (it == memory_.end()) {
    throw std::runtime_error("Types don't match");
  } else {
    return it->second;
  }
}

Variable &Variable::operator=(const allType &variable) {
  if (getType(variable) == type_) {
    value_ = variable;
  } else if (type_ == Type::NONE) {
    value_ = variable;
    type_ = getType(variable);
  } else {
    throw std::runtime_error("Types don't match");
  }
  return *this;
}

const std::string &Variable::name() const noexcept {
  return name_;
}

Variable::Type Variable::type() const noexcept {
  return type_;
}

bool operator==(const Variable &variable, const allType &value) noexcept {
  return variable.value_ == value;
}

bool operator!=(const Variable &variable, const allType &value) noexcept {
  return not(variable == value);
}

}// namespace storage
