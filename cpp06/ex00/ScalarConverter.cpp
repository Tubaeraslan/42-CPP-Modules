#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

/*
'a'        → char
42         → int
42.0       → double
42.0f      → float
nan        → double special
nanf       → float special
+inf       → double special
+inff      → float special
*/

//string olarak gelen literal'ı char, int, float ve double türlerine dönüştürmeye çalışır. Dönüştürme işlemi sırasında, özel durumları (nan, +inf, -inf) ve geçersiz girişleri ele alır. Sonuçları uygun formatta ekrana yazdırır.
void ScalarConverter::convert(const std::string& literal)
{
    //'a'
    if (literal.length() == 3 &&
    literal[0] == '\'' &&
    literal[2] == '\'')
    {
        char c = literal[1];

        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
    }
    //a
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];

        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
    }
    //special double
    if (literal=="nan" || literal=="+inf" || literal=="-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }
    //special float
    if (literal=="nanf" || literal=="+inff" || literal=="-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        return;
    }

    //strtod->string'i double'a dönüştürür "42.5"-> 42.5.
    //çünkü double en geniş tür. sonra double dn diğerlerine cast yapıcaz
    char* endptr;
    double value;

    //float
    if (literal.length() > 1 &&
        literal[literal.length() - 1] == 'f')
    {
        std::string temp = literal.substr(0, literal.length() - 1);
        value = std::strtod(temp.c_str(), &endptr);

        if (*endptr != '\0')
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
    }
    else
    {
        value = std::strtod(literal.c_str(), &endptr);
        if (*endptr != '\0')
        {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
    }
    
    //char
    if (std::isnan(value) || value < 0 || value > 127)
    {
        std::cout << "char: impossible\n";
    }
    else if (!std::isprint(static_cast<char>(value)))
    {
        std::cout << "char: Non displayable\n";
    }
    else
    {
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    }

    //int
    //overflow underflow kontrolü
    if (std::isnan(value) ||
    value > std::numeric_limits<int>::max() ||
    value < std::numeric_limits<int>::min())
    {
        std::cout << "int: impossible\n";
    }
    else
    {
        std::cout << "int: " << static_cast<int>(value) << "\n";
    }

    //float
    std::cout << std::fixed << std::setprecision(1);

    if (std::isnan(value) || std::isinf(value) ||
        value > std::numeric_limits<float>::max() ||
        value < -std::numeric_limits<float>::max())
    {
        std::cout << "float: impossible\n";
    }
    else
    {
        std::cout << "float: "
                  << static_cast<float>(value) << "f\n";
    }

    //double
    std::cout << "double: " << value << "\n";
}