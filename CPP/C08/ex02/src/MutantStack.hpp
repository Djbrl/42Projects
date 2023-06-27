#include <stack>
#include <deque>
#include <list>

template<typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
    public :
        MutantStack(): std::stack<T, Container>()
        {}

        ~MutantStack()
        {}
        
        MutantStack<T, Container>(MutantStack<T, Container> const & src)
        {
            *this = src;
        }
        
        //std::stack class has protected member "c" that represents the underlying container
        MutantStack<T, Container> & operator=(MutantStack<T, Container> const & src)
        {
            if (this != &src)
                this->c = src.c;
            return *this;
        }

        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;

        // c is the underlying container
        iterator begin() {return this->c.begin();}
        iterator end() {return this->c.end();}
        const_iterator begin() const {return this->c.begin();}
        const_iterator end() const {return this->c.end();}
        reverse_iterator rbegin() {return this->c.rbegin();}
        reverse_iterator rend() {return this->c.rend();}
        const_reverse_iterator rbegin() const {return this->c.rbegin();}
        const_reverse_iterator rend() const {return this->c.rend();}
};

