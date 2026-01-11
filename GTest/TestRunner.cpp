#include "pch.h"
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
	ASSERT_EQ(20, count); // This will cause the test to fail
	//EXPECT_GE(20, count); // This will log a failure but continue execution
	std::cout << "After the assertion" << std::endl;
}

