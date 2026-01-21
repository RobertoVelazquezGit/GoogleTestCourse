#include "pch.h"
#include "framework.h"
#include "StringUtils.h"
#include <algorithm>
#include <cctype>

//transform(InputIt first1, InputIt last1,
//    OutputIt d_first,
//    UnaryOperation unary_op);


std::string StringUtils::ToLower(const std::string& input) {
    std::string result = input;

    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) {
            return static_cast<char>(std::tolower(c));
        });

    return result;
}

std::string StringUtils::ToUpper(const std::string& input) {
    std::string result = input;

    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) {
            return static_cast<char>(std::toupper(c));
        });

    return result;
}
