#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        std::vector<int> _num;
        unsigned int _size;
        Span();
    public:
        ~Span();
        Span(unsigned int size);
        Span(const &Span src);
        Span &operator=(const &Span src);
        void    addNumber(int number);
        int     shortestSpan();
        int     longestSpan();

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
