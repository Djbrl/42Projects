#include <iostream>
#include "Span.hpp"

int main() {
    Span span(10);

    try {
        span.addNumber(5);
        span.addNumber(3);
        span.addNumber(9);
        span.addNumber(1);
        span.addNumber(7);
        span.addNumber(2);
        span.addNumber(8);
        span.addNumber(4);
        span.addNumber(6);
        span.addNumber(10);

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
