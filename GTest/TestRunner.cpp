#include "pch.h"
#include "gtest/gtest.h"
#include <LibraryCode.hpp>

TEST(TestCountPositives, BasicTest)
{
    //Arrange
    std::vector<int> inputVector{ 1, -2, 3, -4, 5, -6, -7 };

    //Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(3, count);
}

TEST(TestCountPositives, EmptyVectorTest)
{
    //Arrange
    std::vector<int> inputVector{};

    //Act
    int count = countPositives(inputVector);

    //Assert
    ASSERT_EQ(0, count);
}

TEST(TestCountPositives, AllNegativesTest)
{

    //Arrange
    std::vector<int> inputVector{ -1, -2, -3 };

    //Act
    int count = countPositives(inputVector);

    //Assert
	ASSERT_EQ(0, count); // This will cause the test to fail
	//EXPECT_GE(20, count); // This will log a failure but continue execution
	std::cout << "After the assertion" << std::endl;
}


// Does not debug break here
// Project GTest, Right click ? Properties ? Debugging, 
//  Working Directory ? $(TargetDir)
//  Debugger Type     ? Auto
// 
// Tools ? Options ? Debugging ? Symbols
//  Check "Microsoft Symbol Servers"
//  Add new location: GoogleTest\x64\Debug\
// 
// Clean and Build solution

TEST(ToUpperTest, BasicTest)
{
    //Arrange
    char inputString[] = "Hello World";

    //Act
    toUpper(inputString);

    std::cout << "After toUpper: " << inputString << '\n';
    if (inputString == "HELLO WORLD") // pointer
    {
        std::cout << "Equal strings\n";
    }
    else
    {
        std::cout << "Unequal strings\n";
    }

    if (0 == strcmp(inputString, "HELLO WORLD")) // content
    {
        std::cout << "Equal strings (strcmp)\n";
    }
    else
    {
        std::cout << "Unequal strings (strcmp)\n";
    }
    //ASSERT
	// Commented out ASSERT_EQ("HELLO WORLD", inputString);  // Fails because ASSERT_EQ compares pointers for char*

    ASSERT_STREQ("HELLO WORLD", inputString);
    ASSERT_STRCASEEQ("Hello WORLD", inputString);

    // or the other example:
    std::string str(inputString);
    ASSERT_EQ("HELLO WORLD", str);
}

