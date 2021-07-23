//
// Created by alexander on 6/1/21.
//

#include "Variable.hpp"
#include <iostream>


using namespace storage;

Variable &Variable::newMember(const std::string &name, const allType &value) {
    memory_.insert(std::make_pair(name, newVariable(name, value)));
    return memory_.at(name);
}

Variable &Variable::newMember(const Variable &variable) {
    memory_.insert(std::make_pair(variable.name_, variable));
    return memory_.at(variable.name_);
}

Variable Variable::newVariable(const std::string &name, const allType &value) {
    Variable temp(name);
    temp.type_ = getType(value);
    temp.value_ = value;
    return temp;
}

Variable::Type Variable::getType(const allType &value) {
    if (std::get_if<int>(&value)) {
        return Type::INT;
    } else if (std::get_if<double>(&value)) {
        return Type::DOUBLE;
    } else if (std::get_if<bool>(&value)) {
        return Type::BOOL;
    } else if (std::get_if<std::string>(&value)) {
        return Type::STRING;
    } else if (std::get_if<std::vector<int>>(&value)) {
        return Type::INT_ARRAY;
    } else if (std::get_if<std::vector<double>>(&value)) {
        return Type::DOUBLE_ARRAY;
    } else if (std::get_if<std::vector<bool>>(&value)) {
        return Type::BOOL_ARRAY;
    } else if (std::get_if<std::vector<std::string>>(&value)) {
        return Type::STRING_ARRAY;
    }
}

bool Variable::hasMember(const std::string &name_var) {
    if (memory_.find(name_var) == memory_.end()) {
        return false;
    } else {
        return true;
    }
}


//get cast type variable
int Variable::asInt() {
    if (type_ == Type::INT) {
        return std::get<int>(value_);
    } else throw "cannot be cast to type";
}

double Variable::asDouble() {
    if (type_ == Type::DOUBLE) {
        return std::get<double>(value_);
    } else throw "cannot be cast to type";
}

bool Variable::asBool() {
    if (type_ == Type::BOOL) {
        return std::get<bool>(value_);
    } else throw "cannot be cast to type";
}

std::string Variable::asString() {
    if (type_ == Type::STRING) {
        return std::get<std::string>(value_);
    } else throw "cannot be cast to type";
}


//get cast array type variable
std::vector<int> Variable::asIntArray() {
    if (type_ == Type::INT_ARRAY) {
        return std::get<std::vector<int>>(value_);
    } else throw "cannot be cast to type";
}

std::vector<double> Variable::asDoubleArray() {
    if (type_ == Type::DOUBLE_ARRAY) {
        return std::get<std::vector<double>>(value_);
    } else throw "cannot be cast to type";
}

std::vector<bool> Variable::asBoolArray() {
    if (type_ == Type::BOOL_ARRAY) {
        return std::get<std::vector<bool>>(value_);
    } else throw "cannot be cast to type";
}

std::vector<std::string> Variable::asStringArray() {
    if (type_ == Type::STRING_ARRAY) {
        return std::get<std::vector<std::string>>(value_);
    } else throw "cannot be cast to type";
}


Variable &Variable::operator[](const std::string &name) {
    std::map<std::string, Variable>::iterator it = memory_.find(name);
    if (it == memory_.end()) {
        throw "Error get element";
    } else {
        return it->second;
    }
}

void Variable::operator=(const allType &variable) {
    if (getType(variable) == type_) {
        if (getType(variable) == Type::STRING) std::cout << "string" << std::endl;
        value_ = variable;
    } else {
        throw "Types don't match";
    }
}


std::string Variable::name() {
    return name_;
}

Variable::Type Variable::type() {
    return type_;
}


bool storage::operator==(const Variable &variable,
                         const allType &value) {
    try {
        if (variable.value_ == value) {
            return true;
        } else {
            return false;
        }
    }
    catch (int e) {
        return false;
    }
}

bool storage::operator!=(const Variable &variable,
                         const allType &value) {
    return not(variable == value);
}
