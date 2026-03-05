#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Serialization Test";

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);

    Data* newPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer:   " << originalPtr << std::endl;
    std::cout << "Serialized value:   " << raw << std::endl;
    std::cout << "Deserialized ptr:   " << newPtr << std::endl;

    std::cout << std::endl;

    if (originalPtr == newPtr)
        std::cout << "Pointers are equal!" << std::endl;
    else
        std::cout << "Pointers are NOT equal!" << std::endl;

    std::cout << std::endl;

    return 0;
}