#include <gtest/gtest.h>
#include "../src/Variable.hpp"

TEST(Variable, Interface) {
    using namespace storage;
    Variable var("var", Variable::Type::STRUCT);

    int intVar = 0;
    ASSERT_NO_THROW(intVar = var.newMember("intVar", 1).asInt());
    ASSERT_TRUE(var.hasMember("intVar"));
    ASSERT_EQ(intVar, var["intVar"].asInt());
    ASSERT_EQ("intVar", var["intVar"].name());
    ASSERT_EQ(Variable::Type::INT, var["intVar"].type());

    double doubleVar = 0.0;
    ASSERT_NO_THROW(doubleVar = var.newMember("doubleVar", 4.3).asDouble());
    ASSERT_TRUE(var.hasMember("doubleVar"));
    ASSERT_EQ(doubleVar, var["doubleVar"].asDouble());
    ASSERT_EQ("doubleVar", var["doubleVar"].name());
    ASSERT_EQ(Variable::Type::DOUBLE, var["doubleVar"].type());

    bool boolVar = false;
    ASSERT_NO_THROW(boolVar = var.newMember("boolVar", true).asBool());
    ASSERT_TRUE(var.hasMember("boolVar"));
    ASSERT_EQ(boolVar, var["boolVar"].asBool());
    ASSERT_EQ("boolVar", var["boolVar"].name());
    ASSERT_EQ(Variable::Type::BOOL, var["boolVar"].type());

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
    ASSERT_TRUE(std::equal(intArray.begin(), intArray.end(), var["intArray"].asIntArray().begin()));

    std::vector<double> doubleArray{1.6, 3.2, 4.5, 9.0};
    var["foo"].newMember("doubleArray", doubleArray);
    ASSERT_TRUE(std::equal(doubleArray.begin(), doubleArray.end(), var["foo"]["doubleArray"].asDoubleArray().begin()));

}
