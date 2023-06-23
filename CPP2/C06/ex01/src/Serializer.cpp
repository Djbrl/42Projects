#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
    (void)src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr_to_uint)
{
    return reinterpret_cast<uintptr_t>(ptr_to_uint);
}

Data *Serializer::deserialize(uintptr_t uint_to_ptr)
{
    return reinterpret_cast<Data *>(uint_to_ptr);
}
