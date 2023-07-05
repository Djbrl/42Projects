#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        std::vector<int>    _num;
        unsigned int  _size;
        Span();
    public:
        ~Span();
        Span(unsigned int size);
        Span(const Span &src);
        Span &operator=(const Span &src);
        void    addNumber(int number);
        void    addNumber(int start, int end);
        int     shortestSpan();
        int     longestSpan();
        std::vector<int>::iterator returnBeginIt();
        std::vector<int>::iterator returnEndIt();

    class SpanFullException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class SpanTooShortException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};
