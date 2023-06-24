#include <iostream>
#include <exception>

template<typename T>
class Array 
{
    private:
        unsigned int _n;
        T   *_arr;
    public:
        Array();
        ~Array();
        Array(const unsigned int &n);
        Array(const Array &src);
        T       &operator[](unsigned int i);
        Array   &operator=(const Array &a);
        T       size() const;

        class ArrayIndexException : public std::exception {
        public:
            const char* what() const throw();
        };
};
