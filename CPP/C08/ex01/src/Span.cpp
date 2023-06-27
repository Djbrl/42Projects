#include "Span.hpp"

const char *Span::SpanFullException::what() const throw()
{
    return "Exception : Span is full";
}

const char *Span::SpanTooShortException::what() const throw()
{
    return "Exception : Span is too short";
}

Span::Span() : _size(0)
{}

Span::Span(const unsigned n) : _size(n)
{
	if (_size < 2)
		throw SpanTooShortException();
}

Span::Span(const Span &src) : _size(src._size)
{
	*this = src;
}

Span::~Span()
{
}

Span	&Span::operator=(const Span &src)
{
	this->_num = src._num;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_num.size() < this->_size)
		this->_num.push_back(n);
	else
		throw SpanFullException();
}

void	Span::addNumber(int start, int end)
{
	if (this->_num.size() >= this->_size)
	{
		throw SpanFullException();
		return ;
	}
	if (start == end)
	{
		throw SpanTooShortException();
		return ;
	}
	while (start <= end)
	{
		if (this->_num.size() >= this->_size)
		{
			throw SpanFullException();
			return ;
		}
		this->_num.push_back(start);
		start++;
	}	
}

int Span::shortestSpan()
{
	//sort into a tmp
	std::vector<int> tmp(_num.begin(), _num.end());
	std::sort(tmp.begin(), tmp.end());

	//compare it to it in sorted tmp, update with min span
	int res = std::abs(tmp[1] - tmp[0]);
	std::vector<int>::iterator it = tmp.begin();
	std::vector<int>::iterator nextIt = it;
	++nextIt;
	while (nextIt != tmp.end())
	{
		int span = std::abs(*nextIt - *it);
		if (span < res)
			res = span;
		++it;
		++nextIt;
	}
	return res;
}


int	Span::longestSpan(void)
{
	int	min = *std::min_element(this->_num.begin(), this->_num.end());
	int	max = *std::max_element(this->_num.begin(), this->_num.end());
	return (max - min);
}

std::vector<int>::iterator Span::returnBeginIt()
{
	return _num.begin();
}

std::vector<int>::iterator Span::returnEndIt()
{
	return _num.end();
}