#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
private:
    // Private Orthodox Canonical Form - prevents instantiation
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
    
    // Helper methods for detection and conversion
    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isPseudoLiteral(const std::string& str);
    
    // Conversion helpers
    static void convertFromChar(char c);
    static void convertFromInt(int i);
    static void convertFromFloat(float f);
    static void convertFromDouble(double d);
    static void handlePseudoLiteral(const std::string& str);

public:
    static void convert(const std::string& literal);
};

#endif
