// LibraryCode.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "LibraryCode.hpp"
#include <algorithm>
#include <cctype>
#include <cstring>


bool isPositive(int x)
{
    return x >= 0;
}

int countPositives(std::vector<int> const& inputVector)
{
    return std::count_if(inputVector.begin(), inputVector.end(), isPositive);
}


//hello world -> HELLO WORLD

void toUpper(char* inputString)
{
    for (unsigned i = 0; i < strlen(inputString); i++)
    {
        inputString[i] = toupper(inputString[i]); //a -> A, b -> B
    }
}
