#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N)
{

}

void Span::addNumber(int number)
{
    if (numbers.size() >= max_size) {
        throw std::out_of_range("Span is full!");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to calculate span!");
    }
    std::vector<int> temp = numbers;
    std::sort(temp.begin(), temp.end());
    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < temp.size(); i++) {
        shortest = std::min(shortest, temp[i] - temp[i - 1]);
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to calculate span!");
    }
    int min_val = *std::min_element(numbers.begin(), numbers.end());
    int max_val = *std::max_element(numbers.begin(), numbers.end());
    return max_val - min_val;
}