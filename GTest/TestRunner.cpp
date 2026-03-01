#include "pch.h"
// Commented out #include "gtest/gtest.h"
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

TEST(SquareRootTest, NegativeArgumentTest)
{
    double inputValue = -9;

    ASSERT_ANY_THROW(mySqrt(inputValue));
    ASSERT_THROW(mySqrt(inputValue), std::runtime_error);
}


TEST(SquareRootTest, PositiveArgumentTest)
{
    double inputValue = 9;

    ASSERT_NO_THROW(mySqrt(inputValue));
}

// #define __WIN32
// or WIN32, or __WIN32__

TEST(UnixSuite, DummyTest1)
{
    std::cout << "Dummy test 1 - Unix \n";
#ifdef /*__WIN32*/ _WIN64
    FAIL();
#else
    SUCCEED();
#endif
}


TEST(UnixSuite, DummyTest2)
{
    std::cout << "Dummy test 2 - Unix \n";
#ifdef _WIN64
    FAIL();
#else
    SUCCEED();
#endif
}


TEST(WindowsSuite, DummyTest1)
{
    std::cout << "Dummy test 1 - Windows \n";
#ifdef _WIN64
    SUCCEED();
#else
    FAIL();
#endif
}


TEST(WindowsSuite, DummyTest2)
{
    std::cout << "Dummy test 2 - Windows \n";
#ifdef _WIN64
    SUCCEED();
#else
    FAIL();
#endif
}

TEST(WindowsSuite, DummyTest3)
{
    std::cout << "Dummy test 3 - Windows \n";
#ifdef _WIN64
    SUCCEED();
	// No in this version of googletest Microsoft GTEST_SKIP() << "Skipping this test for demonstration purposes.";   
#else
    FAIL();
#endif
}

// In Linux in commnad line
// Examples
// ./unitTestRunner --gtest_filter="UnixSuite.*
// ./unitTestRunner --gtest_filter="UnixSuite.DummyTest1"   

//int main(int argc, char** argv)
//{
//#ifdef _WIN64
//    testing::GTEST_FLAG(filter) = "WindowsSuite.*";  // "-WindowsSuite.DummyTest1" does all except WindowsSuite.DummyTest1
//#else
//    testing::GTEST_FLAG(filter) = "UnixSuite.*";
//#endif
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}

// In Visual studio, you can set the command line arguments for debugging the tests.    
// See in Porpertires ? Debugging ? Command Arguments  --gtest_output="xml:test_output.xml"
// In the output directory, you will find test_output.xml with the test results in XML format. You can use this file to generate reports or integrate with CI/CD pipelines. 
// Threre are also other options for test output format, such as JSON, which can be specified using --gtest_output="json:test_output.json". This allows you to choose the format that best suits your needs for analyzing test results. 

// In Linux in Visual Studio Code, you can install an extension similar to the Test Explorer here in Visual Studio in windows :
// C++ TestMate, and in Linux : GoogleTest Adapter. These extensions provide a user-friendly interface for running and debugging tests directly from the editor. You can easily navigate through test cases, view results, and even set breakpoints for debugging specific tests. This integration enhances the overall testing experience and allows for efficient test management within Visual Studio Code. 

// Suggested reading: Test Driven Development with C++ by Abdul Wahid Tanner



