#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int max_size;

    public:
        Span(unsigned int N);
        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;


        template <typename InputIterator>
        void addNumberRange(InputIterator first, InputIterator last)
        {
            while (first != last && numbers.size() < max_size) {
                numbers.push_back(*first);
                ++first;
            }
            if (first != last) {
                throw std::out_of_range("Span is full!");
            }
        }
};