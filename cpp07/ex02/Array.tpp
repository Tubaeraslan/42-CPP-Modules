#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(nullptr), _size(0) {}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
Array<T>::Array(size_t n) : data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array &other) : data(new T[other._size]()), _size(other._size)
{
    for (size_t i = 0; i < _size; i++)
        data[i] = other.data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] data;

        _size = other._size;
        data = new T[_size]();

        for (size_t i = 0; i < _size; i++)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](size_t index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");

    return data[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return _size;
}