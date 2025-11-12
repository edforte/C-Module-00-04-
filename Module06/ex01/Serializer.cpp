#include "Serializer.hpp"

// Private constructors/destructor
Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void)other; }
Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    return *this;
}
Serializer::~Serializer() {}

// Serialize: Data* to uintptr_t using reinterpret_cast
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

// Deserialize: uintptr_t to Data* using reinterpret_cast
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
