#include <iostream>
#include "Span.hpp"

int main() {
    Span span(10);

    try {
        span.addNumber(5);
        span.addNumber(3);
        span.addNumber(-312);
        span.addNumber(1);
        span.addNumber(7);
        span.addNumber(3);
        span.addNumber(8);
        span.addNumber(4);
        span.addNumber(6);
        span.addNumber(10);
        //EXCEPTION TEST
        // span.addNumber(11);
        // Span test(1);

        //STANDARD TEST
        std::cout << "==STD TEST==\n" << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        //2nd TEST
        Span test2(4);
        test2.addNumber(-3, -2);
        std::cout << "==2ND TEST==\n" << "Shortest span: " << test2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << test2.longestSpan() << std::endl;
        //EXCEPTION TEST
        // test2.addNumber(-3, -3);
        test2.addNumber(-1, 0);
        std::cout << "==3RD TEST==\n" << "Shortest span: " << test2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << test2.longestSpan() << std::endl;
        //EXCEPTION TEST
        // test2.addNumber(-3, -3);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    Span span2(10000);
    span2.addNumber(-5000,4999);
    std::vector<int>::iterator start = span2.returnBeginIt();
    std::vector<int>::iterator end = span2.returnEndIt();
    while (start != end)
    {
        std::cout << *start << std::endl;
        start++;
    }
    return 0;
}
