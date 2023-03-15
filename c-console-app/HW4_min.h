#include <iostream>

template <typename T> T min_template(T val1, T val2)
{
    if (val1 == val2)
    {
        std::cout << "The values are equal to each other... " << "Returning the first input" << std::endl;
        return val1;
    }
    if (val1 < val2)
    {
        return val1;
    }
    return val2;
}
