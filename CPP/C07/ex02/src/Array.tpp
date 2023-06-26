#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    _n = 0;
    _arr = new T[_n];
}

template <typename T>
Array<T>::~Array()
{
    delete [] _arr;
}

template <typename T>
Array<T>::Array(const unsigned int &size)
{
    _n = size;
    _arr = new T[size];
    for (unsigned int i = 0; i < size; i++)
        _arr[i] = 0;
}

template <typename T>
Array<T>::Array(const Array<T> &a)
{
    if (_arr)
        delete _arr;
    _n = a._n;
    if (_n > 0)
        _arr = new T[_n];
    for(int i =0; i < _n; i++)
        _arr[i] = a._arr[i];
}

template <typename T>
Array<T>   &Array<T>::operator=(const Array<T> &a)
{
    if (_arr)
        delete _arr;
    _n = a._n;
    if (_n > 0)
        _arr = new T[_n];
    for(int i = 0; i < _n; i++)
        _arr[i] = a._arr[i];
    return *this;
}

template <typename T>
T   &Array<T>::operator[](unsigned int i)
{
    if (i >= _n)
        throw ArrayIndexException();
    return _arr[i];
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& array) {
    for (unsigned int i = 0; i < array.size(); i++) {
        stream << array[i] << " ";
    }
    return stream;
}

template <typename T>
T   Array<T>::size() const
{
    return _n;
}


template <typename T>
const char *Array<T>::ArrayIndexException::what() const throw()
{
        return "Exception: Index invalid";
}
