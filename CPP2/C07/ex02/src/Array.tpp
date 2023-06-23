#include <iostream>
#include "Array.hpp"

template<typename T>
class Array 
{
    private:
        unsigned int _n;
        T   *_arr;
    public:
        Array(); //create a [] array
        ~Array(); // delete array
        Array(const unsigned int &n);
        Array(const Array &src);
        Array &operator[](unsigned int i);
        Array &operator=(const Array &a);
};

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
Array<T>   &Array<T>::operator[](unsigned int i)
{
    return _arr[i];
}