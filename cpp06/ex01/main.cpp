#include "Serializer.hpp"

int main()
{
    // 1️⃣ Data nesnesi oluştur
    Data data;
    data.id = 42;
    data.name = "Serialization Test";

    // 2️⃣ Pointer al
    Data* originalPtr = &data;

    // 3️⃣ Serialize
    uintptr_t raw = Serializer::serialize(originalPtr);

    // 4️⃣ Deserialize
    Data* newPtr = Serializer::deserialize(raw);

    // 5️⃣ Sonuçları yazdır
    std::cout << "Original pointer:   " << originalPtr << std::endl;
    std::cout << "Serialized value:   " << raw << std::endl;
    std::cout << "Deserialized ptr:   " << newPtr << std::endl;

    std::cout << std::endl;

    // 6️⃣ Pointer karşılaştırması
    if (originalPtr == newPtr)
        std::cout << "✅ Pointers are equal!" << std::endl;
    else
        std::cout << "❌ Pointers are NOT equal!" << std::endl;

    std::cout << std::endl;

    // 7️⃣ İçerik kontrolü
    std::cout << "Data via newPtr:" << std::endl;
    std::cout << "id: " << newPtr->id << std::endl;
    std::cout << "name: " << newPtr->name << std::endl;

    return 0;
}