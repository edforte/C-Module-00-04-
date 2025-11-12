#include "ScalarConverter.hpp"

// Private constructors/destructor (not implemented)
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str) {
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& str) {
    if (str.empty())
        return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-')
        start = 1;
    
    if (start >= str.length())
        return false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
    if (str.empty() || str[str.length() - 1] != 'f')
        return false;
    
    std::string noF = str.substr(0, str.length() - 1);
    if (noF.empty())
        return false;
    
    size_t dotCount = 0;
    size_t start = 0;
    
    if (noF[0] == '+' || noF[0] == '-')
        start = 1;
    
    if (start >= noF.length())
        return false;
    
    for (size_t i = start; i < noF.length(); i++) {
        if (noF[i] == '.') {
            dotCount++;
            if (dotCount > 1)
                return false;
        } else if (!std::isdigit(noF[i])) {
            return false;
        }
    }
    return dotCount == 1;
}

bool ScalarConverter::isDouble(const std::string& str) {
    if (str.empty())
        return false;
    
    size_t dotCount = 0;
    size_t start = 0;
    
    if (str[0] == '+' || str[0] == '-')
        start = 1;
    
    if (start >= str.length())
        return false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1)
                return false;
        } else if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return dotCount == 1;
}

bool ScalarConverter::isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" || 
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff");
}

void ScalarConverter::convertFromChar(char c) {
    // Char conversion
    std::cout << "char: '" << c << "'" << std::endl;
    
    // Int conversion
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    
    // Float conversion
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    
    // Double conversion
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int i) {
    // Char conversion
    std::cout << "char: ";
    if (i < 0 || i > 127)
        std::cout << "impossible";
    else if (i < 32 || i == 127)
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(i) << "'";
    std::cout << std::endl;
    
    // Int conversion
    std::cout << "int: " << i << std::endl;
    
    // Float conversion
    std::cout << "float: " << static_cast<float>(i);
    if (i == static_cast<int>(static_cast<float>(i)))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    
    // Double conversion
    std::cout << "double: " << static_cast<double>(i);
    if (i == static_cast<int>(static_cast<double>(i)))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convertFromFloat(float f) {
    // Char conversion
    std::cout << "char: ";
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        std::cout << "impossible";
    else if (f < 32 || f == 127)
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(f) << "'";
    std::cout << std::endl;
    
    // Int conversion
    std::cout << "int: ";
    if (std::isnan(f) || std::isinf(f) || 
        f < static_cast<float>(std::numeric_limits<int>::min()) || 
        f > static_cast<float>(std::numeric_limits<int>::max()))
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(f);
    std::cout << std::endl;
    
    // Float conversion
    std::cout << "float: " << f;
    if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    
    // Double conversion
    std::cout << "double: " << static_cast<double>(f);
    if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(double d) {
    // Char conversion
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible";
    else if (d < 32 || d == 127)
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(d) << "'";
    std::cout << std::endl;
    
    // Int conversion
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || 
        d < static_cast<double>(std::numeric_limits<int>::min()) || 
        d > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(d);
    std::cout << std::endl;
    
    // Float conversion
    std::cout << "float: " << static_cast<float>(d);
    if (d == static_cast<int>(d) && !std::isnan(d) && !std::isinf(d))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    
    // Double conversion
    std::cout << "double: " << d;
    if (d == static_cast<int>(d) && !std::isnan(d) && !std::isinf(d))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::handlePseudoLiteral(const std::string& str) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (str == "nanf" || str == "nan") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (str == "+inff" || str == "+inf") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (str == "-inff" || str == "-inf") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    // Check for pseudo-literals first
    if (isPseudoLiteral(literal)) {
        handlePseudoLiteral(literal);
        return;
    }
    
    // Check for char literal
    if (isChar(literal)) {
        convertFromChar(literal[1]);
        return;
    }
    
    // Check for int literal
    if (isInt(literal)) {
        std::stringstream ss(literal);
        long long temp;
        ss >> temp;
        if (temp < std::numeric_limits<int>::min() || 
            temp > std::numeric_limits<int>::max()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        convertFromInt(static_cast<int>(temp));
        return;
    }
    
    // Check for float literal
    if (isFloat(literal)) {
        std::stringstream ss(literal);
        float f;
        ss >> f;
        convertFromFloat(f);
        return;
    }
    
    // Check for double literal
    if (isDouble(literal)) {
        std::stringstream ss(literal);
        double d;
        ss >> d;
        convertFromDouble(d);
        return;
    }
    
    // Invalid input
    std::cout << "Error: Invalid input" << std::endl;
}
