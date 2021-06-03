//
// Created by alexander on 6/1/21.
//

#ifndef UNTITLED_VARIABLE_HPP
#define UNTITLED_VARIABLE_HPP

#include <iostream>
#include <map>
#include <variant>
#include <vector>
#include <typeinfo>

namespace storage {

    using namespace std::literals;

    class Variable {

    public:
        enum class Type {
            STRUCT, DOUBLE, INT, BOOL
        };

        Variable(const std::string &name, Type type) {
            name_ = name;
            type_ = type;
        }

        Variable(const std::string &name) {
            name_ = name;
        }

        template<typename T>
        Variable newMember(const std::string &name_var, T var) {
            Variable temp = newVariable(name_var, var);
            memory_.insert(std::make_pair(name_var, temp));
            return temp;
        }

        void list() {
            std::map<std::string, Variable>::iterator it;
            for (it = memory_.begin(); it != memory_.end(); it++)
                std::cout << it->first << ' ' << '\n';
        }

        Variable newMember(Variable &variable_obj) {
            Variable temp = newVariable(variable_obj);
            memory_.insert(std::make_pair(variable_obj.name_, temp));
            return temp;
        }

        bool hasMember(const std::string &name_var) {
            if (memory_.find(name_var) == memory_.end()) {
                return false;
            } else {
                return true;
            }
        }

        int asInt() {
            if (type_ == Type::INT) {
                return std::get<int>(value_);
            } else {
                throw "Error get type";
            }
        }

        std::vector<int> asIntArray() {
            if (type_ == Type::INT) {
                try {
                    return std::get<std::vector<int>>(value_);
                }
                catch (int e) {
                    throw "Error get type";
                }
            } else {
                throw "Error get type";
            }
        }

        double asDouble() {
            if (type_ == Type::DOUBLE) {
                return std::get<double>(value_);
            } else {
                throw "Error get type";
            }
        }

        std::vector<double> asDoubleArray() {
            if (type_ == Type::DOUBLE) {
                try {
                    return std::get<std::vector<double>>(value_);
                }
                catch (int e) {
                    throw "Error get type";
                }
            } else {
                throw "Error get type";
            }
        }

        bool asBool() {
            if (type_ == Type::BOOL) {
                return std::get<bool>(value_);
            } else {
                throw "Error get type";
            }
        }

        std::vector<bool> asBoolArray() {
            if (type_ == Type::BOOL) {
                try {
                    return std::get<std::vector<bool>>(value_);
                }
                catch (int e) {
                    throw "Error get type";
                }
            } else {
                throw "Error get type";
            }
        }

        Type type() {
            return type_;
        }

        std::string name() {
            return name_;
        }

        Variable &operator[](const std::string &name) {
            std::map<std::string, Variable>::iterator it = memory_.find(name);
            if (it == memory_.end()) {
                throw "Error get element";
            } else {
                return it->second;
            }
        }

    private:

        Type type_;
        std::string name_;
        std::variant<int, double, bool, std::vector<int>, std::vector<double>, std::vector<bool>> value_;
        std::map<std::string, Variable> memory_;

        Variable newVariable(const std::string &name_var, int var) {
            Variable temp = Variable(name_var, Type::INT);
            temp.value_ = var;
            return temp;
        }

        Variable newVariable(const std::string &name_var, double var) {
            Variable temp = Variable(name_var, Type::DOUBLE);
            temp.value_ = var;
            return temp;
        }

        Variable newVariable(const std::string &name_var, bool var) {
            Variable temp = Variable(name_var, Type::BOOL);
            temp.value_ = var;
            return temp;
        }

        Variable newVariable(const std::string &name_var, std::vector<int> var) {
            Variable temp = Variable(name_var, Type::INT);
            temp.value_ = var;
            return temp;
        }

        Variable newVariable(const std::string &name_var, std::vector<double> var) {
            Variable temp = Variable(name_var, Type::DOUBLE);
            temp.value_ = var;
            return temp;
        }

        Variable newVariable(const std::string &name_var, std::vector<bool> var) {
            Variable temp = Variable(name_var, Type::BOOL);
            temp.value_ = var;
            return temp;
        }

        Variable newVariable(Variable variable_obj) {
            Variable temp = Variable(variable_obj.name_);
            temp.type_ = variable_obj.type_;
            temp.value_ = variable_obj.value_;
            temp.memory_ = variable_obj.memory_;
            return temp;
        }

        friend bool operator==(const Variable &var1,
                               const std::variant<int, double, bool, std::vector<int>, std::vector<double>, std::vector<bool>> &var2);

        friend bool operator!=(const Variable &var1,
                               const std::variant<int, double, bool, std::vector<int>, std::vector<double>, std::vector<bool>> &var2);

    };


    bool operator==(const Variable &var1,
                    const std::variant<int, double, bool, std::vector<int>, std::vector<double>, std::vector<bool>> &var2) {
        try {
            if (var1.value_ == var2) {
                return true;
            } else {
                return false;
            }
        }
        catch (int e) {
            return false;
        }
    }

    bool operator!=(const Variable &var1,
                    const std::variant<int, double, bool, std::vector<int>, std::vector<double>, std::vector<bool>> &var2) {
        try {
            if (var1.value_ != var2) {
                return true;
            } else {
                return false;
            }
        }
        catch (int e) {
            return true;
        }
    }

}


#endif //UNTITLED_VARIABLE_HPP
