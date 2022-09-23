#include <gtest/gtest.h>
#include "../main/MyClass.h"

namespace {
    class MyClassTest : public testing::Test {

    public:
        MyClass myClass;

        void SetUp() override {
            myClass = MyClass();
        }
    };
}

TEST_F(MyClassTest, GetResult_returns_42_plus_value_of_input) {

    auto input = std::rand();
    auto expectedResult = 42 + input;

    auto result = myClass.GetResult(input);

    ASSERT_EQ(expectedResult, result);
}

TEST_F(MyClassTest, GetName_returns_Alex) {

    auto name = myClass.GetName();

    ASSERT_EQ("Alex", name);
}