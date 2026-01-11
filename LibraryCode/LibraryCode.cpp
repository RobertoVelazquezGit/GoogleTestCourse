// LibraryCode.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"

#include "LibraryCode.hpp"

#include <algorithm>

bool isPositive(int x)
{
    return x >= 0;
}

int countPositives(std::vector<int> const& inputVector)
{
    return std::count_if(inputVector.begin(), inputVector.end(), isPositive);
}
