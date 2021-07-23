//
// Created by alexander on 6/1/21.
//

#ifndef UNTITLED_VARIABLE_HPP
#define UNTITLED_VARIABLE_HPP

#include <string>
#include <map>
#include <variant>
#include <vector>
#include <iostream>

typedef std::variant<int, double, bool, std::string, std::vector<int>, std::vector<double>, std::vector<bool>, std::vector<std::string>> allType;

namespace storage {

    class Variable {

    public:
        enum class Type {
            STRUCT, INT, DOUBLE, BOOL, STRING, INT_ARRAY, DOUBLE_ARRAY, BOOL_ARRAY, STRING_ARRAY, NONE
        };

        explicit Variable(const std::string &name, const Type &type) : name_(name), type_(type) {}

        explicit Variable(const std::string &name) : name_(name), type_(Type::NONE) {}

        ~Variable() = default;

        Variable(const Variable &variable) : name_(variable.name_), type_(variable.type_), value_(variable.value_),
                                             memory_(variable.memory_) {}


        bool hasMember(const std::string &name);

        Variable &newMember(const std::string &name, const allType &value);

        Variable &newMember(const Variable &variable);

        std::string name();

        Type type();

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

        /// Test method for development
        void list() {
            std::map<std::string, Variable>::iterator it;
            for (it = memory_.begin(); it != memory_.end(); it++)
                std::cout << it->first << ' ' << '\n';
        }

        friend bool operator==(const Variable &variable,
                               const allType &value);

        friend bool operator!=(const Variable &variable,
                               const allType &value);

        /// Test method for development
        void printValue() {
            if (std::get_if<int>(&value_)) {
                std::cout << std::get<int>(value_) << std::endl;
            } else if (std::get_if<double>(&value_)) {
                std::cout << std::get<double>(value_) << std::endl;
            } else if (std::get_if<bool>(&value_)) {
                std::cout << std::get<bool>(value_) << std::endl;
            } else if (std::get_if<std::string>(&value_)) {
                std::cout << std::get<std::string>(value_) << std::endl;
            } else
                std::cout << "NOT FOUND" << std::endl;
        }

    private:
        Type type_;
        std::string name_;
        allType value_;
        std::map<std::string, Variable> memory_;

        Type getType(const allType &var);

        Variable newVariable(const std::string &name, const allType &value);

    };

}


#endif //UNTITLED_VARIABLE_HPP
