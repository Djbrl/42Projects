#include <iostream>
#include "Array.tpp"

int main() {
    // Create an array of integers
    Array<int> intArray(5);

    std::cout << intArray[3];
    try
    {
        intArray[-2];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // // Assign values to the array
    // for (int i = 0; i < 5; i++) {
    //     intArray[i] = i * 10;
    // }

    // // Print the array
    // for (int i = 0; i < 5; i++) {
    //     std::cout << intArray[i] << " ";
    // }
    // std::cout << std::endl;

    return 0;
}
