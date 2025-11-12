#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Random Generation ===" << std::endl;
    Base* random1 = generate();
    std::cout << "Identify by pointer: ";
    identify(random1);
    std::cout << "Identify by reference: ";
    identify(*random1);
    delete random1;
    
    std::cout << "\n=== Test 2: Multiple Instances ===" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base* obj = generate();
        std::cout << "Instance " << i + 1 << std::endl;
        std::cout << "  Pointer: ";
        identify(obj);
        std::cout << "  Reference: ";
        identify(*obj);
        delete obj;
    }
    
    std::cout << "\n=== Test 3: Specific Types ===" << std::endl;
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    
    std::cout << "Type A - Pointer: ";
    identify(a);
    std::cout << "Type A - Reference: ";
    identify(*a);
    
    std::cout << "Type B - Pointer: ";
    identify(b);
    std::cout << "Type B - Reference: ";
    identify(*b);
    
    std::cout << "Type C - Pointer: ";
    identify(c);
    std::cout << "Type C - Reference: ";
    identify(*c);
    
    delete a;
    delete b;
    delete c;
    
    return 0;
}
