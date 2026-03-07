#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>


template <typename T>
class Array
{
private:
    T *data;
    size_t _size;
public:
    Array();
    ~Array();
    Array(size_t n);
    Array(const Array &other);
    Array &operator=(const Array &other);

    T &operator[](size_t index);
    size_t size() const;
};

#include "Array.tpp"

#endif