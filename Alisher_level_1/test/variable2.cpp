#include <gtest/gtest.h>
#include "../src/Variable.hpp"
#include <string>

TEST(Variable, Interface) {
    using namespace storage;
    Variable var("var", Variable::Type::STRUCT);

    int intVar = 0;
    ASSERT_NO_THROW(intVar = var.newMember("intVar", 1).asInt());
    ASSERT_TRUE(var.hasMember("intVar"));
    ASSERT_EQ(intVar, var["intVar"].asInt());
    ASSERT_EQ("intVar", var["intVar"].name());
    ASSERT_EQ(Variable::Type::INT, var["intVar"].type());
    ASSERT_ANY_THROW(var["intVar"] = 5.5);

    auto &a = var.newMember("a", 2);

    ASSERT_NO_THROW(a = 5);
    ASSERT_EQ(a.asInt(), var["a"].asInt());

    double doubleVar = 0.0;
    ASSERT_NO_THROW(doubleVar = var.newMember("doubleVar", 4.3).asDouble());
    ASSERT_TRUE(var.hasMember("doubleVar"));
    ASSERT_EQ(doubleVar, var["doubleVar"].asDouble());
    ASSERT_EQ("doubleVar", var["doubleVar"].name());
    ASSERT_EQ(Variable::Type::DOUBLE, var["doubleVar"].type());
    ASSERT_ANY_THROW(var["doubleVar"] = true);

    bool boolVar = false;
    ASSERT_NO_THROW(boolVar = var.newMember("boolVar", true).asBool());
    ASSERT_TRUE(var.hasMember("boolVar"));
    ASSERT_EQ(boolVar, var["boolVar"].asBool());
    ASSERT_EQ("boolVar", var["boolVar"].name());
    ASSERT_EQ(Variable::Type::BOOL, var["boolVar"].type());

    ASSERT_ANY_THROW(var["boolVar"] = "qwerty");

    Variable var_test("vafgr", Variable::Type::STRING);


    ASSERT_ANY_THROW(var["foo"]);
    ASSERT_FALSE(var.hasMember("foo"));

    struct Foo {
        int i;
        double d;
        bool b;
    } foo{1, 2.5, true};

    Variable fooVar("foo");
    fooVar.newMember("i", foo.i);
    ASSERT_TRUE(fooVar.hasMember("i"));
    fooVar.newMember("d", foo.d);
    ASSERT_TRUE(fooVar.hasMember("d"));
    fooVar.newMember("b", foo.b);
    ASSERT_TRUE(fooVar.hasMember("b"));

    var.newMember(fooVar);
    ASSERT_TRUE(var.hasMember("foo"));
    ASSERT_TRUE(var["foo"].hasMember("i"));
    ASSERT_TRUE(var["foo"].hasMember("d"));
    ASSERT_TRUE(var["foo"].hasMember("b"));

    ASSERT_EQ(var["foo"]["i"], foo.i);
    ASSERT_EQ(var["foo"]["d"], foo.d);
    ASSERT_EQ(var["foo"]["b"], foo.b);

    {
        Variable barVar("bar");
        barVar.newMember(fooVar);
        var.newMember(barVar);
    }
    ASSERT_EQ(var["bar"]["foo"]["i"], foo.i);

    std::vector<int> intArray{1, 2, 3, 4, 5, 6};
    var.newMember("intArray", intArray);
    ASSERT_ANY_THROW(var["intArray"].asInt());
    ASSERT_EQ(Variable::Type::INT_ARRAY, var["intArray"].type());
    ASSERT_TRUE(std::equal(intArray.begin(), intArray.end(), var["intArray"].asIntArray().begin()));

    std::vector<double> doubleArray{1.6, 3.2, 4.5, 9.0};
    var["foo"].newMember("doubleArray", doubleArray);
    ASSERT_ANY_THROW(var["foo"]["doubleArray"].asDouble());
    ASSERT_EQ(Variable::Type::DOUBLE_ARRAY, var["foo"]["doubleArray"].type());
    ASSERT_TRUE(std::equal(doubleArray.begin(), doubleArray.end(), var["foo"]["doubleArray"].asDoubleArray().begin()));

    auto fooClone = var["foo"]["i"];
    fooClone = var["foo"];
    ASSERT_ANY_THROW(fooClone.asInt());
    ASSERT_ANY_THROW(fooClone.asDouble());
    ASSERT_ANY_THROW(fooClone.asString());
    ASSERT_TRUE(fooClone.hasMember("i"));
    ASSERT_TRUE(fooClone.hasMember("b"));
    ASSERT_TRUE(fooClone.hasMember("d"));
    ASSERT_EQ(var["foo"].type(), fooClone.type());
    ASSERT_ANY_THROW(fooClone["doubleArray"].asInt());
    ASSERT_EQ(fooClone["i"].type(), var["foo"]["i"].type());
    ASSERT_EQ(fooClone["b"].type(), var["foo"]["b"].type());
    ASSERT_EQ(fooClone["d"].type(), var["foo"]["d"].type());
    ASSERT_EQ(fooClone["i"].asInt(), var["foo"]["i"].asInt());
    ASSERT_EQ(fooClone["b"].asBool(), var["foo"]["b"].asBool());
    ASSERT_EQ(fooClone["d"].asDouble(), var["foo"]["d"].asDouble());
    ASSERT_EQ(fooClone["doubleArray"].type(), var["foo"]["doubleArray"].type());
}