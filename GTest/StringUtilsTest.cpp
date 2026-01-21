//Already in pch.h : #include "gtest/gtest.h"
#include "pch.h"
#include "StringUtils.h"

class StringUtilsTest : public ::testing::Test {
protected:
    std::string mixed;
    std::string upper;
    std::string lower;

    void SetUp() override {
        mixed = "HeLLo WoRLD";
        upper = "HELLO WORLD";
        lower = "hello world";
    }
};

TEST_F(StringUtilsTest, ToLowerConvertsMixedCase) {
    EXPECT_EQ(StringUtils::ToLower(mixed), lower);
}

TEST_F(StringUtilsTest, ToUpperConvertsMixedCase) {
    EXPECT_EQ(StringUtils::ToUpper(mixed), upper);
}

TEST_F(StringUtilsTest, EmptyStringReturnsEmptyString) {
    EXPECT_EQ(StringUtils::ToLower(""), "");
    EXPECT_EQ(StringUtils::ToUpper(""), "");
}

TEST_F(StringUtilsTest, NonAlphabeticCharactersAreUnchanged) {
    std::string input = "1234-+=_!";
    EXPECT_EQ(StringUtils::ToLower(input), input);
    EXPECT_EQ(StringUtils::ToUpper(input), input);
}
