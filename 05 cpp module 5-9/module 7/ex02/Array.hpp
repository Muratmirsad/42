#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
private:
    T* elements;
    size_t arraySize;

public:
    Array() : elements(nullptr), arraySize(0) {}

    explicit Array(size_t n) : arraySize(n) {
        elements = new T[arraySize]();
    }

    Array(const Array& other) : arraySize(other.arraySize) {
        elements = new T[arraySize];
        for (size_t i = 0; i < arraySize; ++i)
		{
            elements[i] = other.elements[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other)
		{
            delete[] elements;

            arraySize = other.arraySize;

            elements = new T[arraySize];
            for (size_t i = 0; i < arraySize; ++i)
			{
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] elements;
    }

    T& operator[](size_t index) {
        if (index >= arraySize)
		{
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    const T& operator[](size_t index) const {
        if (index >= arraySize)
		{
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    size_t size() const{
        return arraySize;
    }
};

#endif