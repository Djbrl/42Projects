#include "Span.hpp"

const char *Span::SpanFullException::what() const throw()
{
    return "Exception : Span is full";
}

const char *Span::SpanTooShortException::what() const throw()
{
    return "Exception : Span is too short";
}

Span::Span()
{}

Span::Span(const unsigned n) : _size(n)
{}

Span::Span(const Span &oth_instance)
{
	*this = oth_instance;
}

Span::~Span()
{
}

Span	&Span::operator=(const Span &to_assign)
{
	this->vec = to_assign.vec;
	this->_size = to_assign._size;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->vec.size() < this->_size)
		this->vec.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	while (it < ite)
	{
		this->_size++;
		if (this->vec.size() > this->_size)
		{
			this->_size--;
			throw std::_sizegth_error("span too long, can't add");
		}
		this->vec.push_back(*it);
		it++;
	}	
}

int	Span::shortestSpan(void)
{
	std::vector<int>	tmp = this->vec;
	int					res = 0;

	std::sort(tmp.begin(), tmp.end());
	res = abs(tmp[1] - tmp[0]);
	for (unsigned int i = 0; i < tmp.size(); i++)
	{
		if (res > abs(tmp[i] - tmp[i + 1]))
			res = abs(tmp[i] - tmp[i + 1]);
	}
	return (res);
}

int	Span::longestSpan(void)
{
	int	min = *std::min_element(this->vec.begin(), this->vec.end());
	int	max = *std::max_element(this->vec.begin(), this->vec.end());
	return (max - min);
}