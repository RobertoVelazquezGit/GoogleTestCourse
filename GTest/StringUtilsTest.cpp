//Already in pch.h : #include "gtest/gtest.h"
#include "pch.h"
#include "StringUtils.h"
#include <utility>   // std::pair

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

class StringUtilsIsLowerCaseTest
    : public ::testing::TestWithParam<std::pair<std::string, bool>> {
};

TEST_P(StringUtilsIsLowerCaseTest, DetectsLowerCaseCorrectly) {
    const auto& [input, expected] = GetParam();
    EXPECT_EQ(StringUtils::IsLowerCase(input), expected);
}

INSTANTIATE_TEST_CASE_P(
    IsLowerCaseCases,
    StringUtilsIsLowerCaseTest,
    ::testing::Values(
        std::make_pair("hello", true),
        std::make_pair("hello world", true),
        std::make_pair("hello123", true),
        std::make_pair("Hello", false),
        std::make_pair("HELLO", false),
        std::make_pair("HeLLo", false),
        std::make_pair("", true)  // edge case
    )
);
