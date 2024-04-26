#ifndef ITER_HPP
#define ITER_HPP

#include  <iostream>

template<typename T>
void iter(T* arr, size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(arr[i]);
    }
}

template<typename T>
void doubleElement(T& arg) {
    elem *= 2;
}

template<typename T>
void printElement(const T& arg) {
    std::cout << elem << " ";
}

#endif