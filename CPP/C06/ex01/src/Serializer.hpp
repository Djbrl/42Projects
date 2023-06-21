#include <iostream>
#include <string>

struct Data {
	int n;
	std::string s1;
	std::string s2;
} ;

class Serializer
{
    private:
    public:
        Serializer();
        ~Serializer();
        Serializer(const Serializer &src);
        Serializer &operator=(const Serializer &src);
        uintptr_t serialize(Data *ptr_to_uint);
        Data *deserialize(uintptr_t uint_to_ptr);
};

