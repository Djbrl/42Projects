#include <iostream>
#include "MutantStack.hpp"
#include <stack>
#include <deque>
#include <list>

int main() {
    // Create an array of integers
		MutantStack<int> mstack;
		MutantStack<int, std::deque<int> > mstack;

		mstack.push(1);
		mstack.push(2);

		std::cout << "top: " << mstack.top() << std::endl;

		mstack.pop();
		std::cout << "top: " << mstack.top() << std::endl;

		mstack.push(3);
		mstack.push(4);
		mstack.push(5);
		mstack.push(6);

		std::cout << "top: " << mstack.top() << std::endl;
		std::cout << "size: " << mstack.size() << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while(it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);

		std::cout << "copy size: " << s.size() << std::endl;
		std::cout << "original size: "<< mstack.size() << std::endl;


    return 0;
}
