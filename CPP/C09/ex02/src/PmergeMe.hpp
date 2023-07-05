#include <iostream>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>

template <typename T, typename Container>
void printSequence(Container &sequence, const std::string &str)
{
    typename Container::iterator start = sequence.begin();

    std::cout << str << ": ";
    while (start != sequence.end())
    {
        std::cout << *start << " ";
        start++;
    }
    std::cout << std::endl;
}

template <typename T, typename Container>
Container parseArguments(int ac, char **av)
{
    Container sequence;

    if (ac < 2)
    {
        std::cout << "Error: No sequence provided." << std::endl;
        return sequence;
    }
    for (int i = 1; i < ac; ++i)
    {
        std::string arg(av[i]);

        // Check if the argument is numeric
        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!std::isdigit(arg[j]) && arg[j] != '-')
            {
                std::cout << "Error: Invalid argument '" << av[i] << "'." << std::endl;
                sequence.clear();
                return sequence;
            }
        }
        sequence.push_back(std::atoi(av[i]));
    }
    return sequence;
}

//TEMPLATE VECTOR/DEQUE FOR FORD-JOHNSON ALG
template <typename T, typename Container>
void mergeInsertSort(Container &sequence)
{
    Container   tmp;

    //ALREADY SORETD
    if (sequence.size() < 2)
        return;
    tmp.push_back(sequence[0]);
    for (size_t i = 1; i < sequence.size(); ++i)
    {
        T current = sequence[i];
        size_t j = i;
        tmp.push_back(tmp[j - 1]);
        while (j > 0 && tmp[j - 1] > current)
        {
            tmp[j] = tmp[j - 1];
            --j;
        }
        tmp[j] = current;
    }
    sequence.swap(tmp);
    tmp.clear();
}