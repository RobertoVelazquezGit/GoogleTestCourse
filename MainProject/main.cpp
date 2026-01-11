
#include <iostream>
#include <LibraryCode.hpp>

int main()
{
    std::vector<int> inputVector{ 1, -2, 3, -4, 5, -6, -7 };
    int count = countPositives(inputVector);
    std::cout << "countPositives: " << count << std::endl;
    return 0;
}

