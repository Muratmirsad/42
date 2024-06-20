#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it != container.end())
    {
        return it;
    }
    else
    {
        throw std::runtime_error("No value found!");
    }
}