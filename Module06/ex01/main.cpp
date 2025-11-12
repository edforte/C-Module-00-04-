#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    // Create a Data object
    Data original;
    original.id = 42;
    original.name = "Test Data";
    original.value = 3.14159;
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << &original << std::endl;
    std::cout << "  ID: " << original.id << std::endl;
    std::cout << "  Name: " << original.name << std::endl;
    std::cout << "  Value: " << original.value << std::endl;
    
    // Serialize
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "\nSerialized: 0x" << std::hex << serialized << std::dec << std::endl;
    
    // Deserialize
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "  Address: " << deserialized << std::endl;
    std::cout << "  ID: " << deserialized->id << std::endl;
    std::cout << "  Name: " << deserialized->name << std::endl;
    std::cout << "  Value: " << deserialized->value << std::endl;
    
    // Verify pointers are equal
    if (deserialized == &original) {
        std::cout << "\n✓ Success: Pointers match!" << std::endl;
    } else {
        std::cout << "\n✗ Error: Pointers don't match!" << std::endl;
    }
    
    // Additional tests with multiple objects
    std::cout << "\n=== Additional Tests ===" << std::endl;
    
    Data test1;
    test1.id = 1;
    test1.name = "First";
    test1.value = 1.1;
    
    Data test2;
    test2.id = 2;
    test2.name = "Second";
    test2.value = 2.2;
    
    uintptr_t s1 = Serializer::serialize(&test1);
    uintptr_t s2 = Serializer::serialize(&test2);
    
    Data* d1 = Serializer::deserialize(s1);
    Data* d2 = Serializer::deserialize(s2);
    
    std::cout << "Test 1 - Match: " << (d1 == &test1 ? "✓" : "✗") << std::endl;
    std::cout << "Test 2 - Match: " << (d2 == &test2 ? "✓" : "✗") << std::endl;
    
    return 0;
}
