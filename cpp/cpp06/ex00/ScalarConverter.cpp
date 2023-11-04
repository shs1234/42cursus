#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter& sc)
{
    (void)sc;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& sc)
{
    (void)sc;
    return (*this);
}
ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::_charOverflow;
bool ScalarConverter::_intOverflow;
bool ScalarConverter::_inf;
bool ScalarConverter::_inff;
bool ScalarConverter::_nan;
bool ScalarConverter::_nanf;

int	ScalarConverter::numLen(long long n)
{
	int	len = 0;

	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

bool ScalarConverter::chkOverflow(const char *str, long long max)
{
	int intlen = numLen(max);
	int	cutlim = max / 10;
	int	cutoff = max % 10;
	int	num = 0;
	int	len = 0;

	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cutoff++;
		str++;
	}
	while (*str == '0')
		str++;
	while (isdigit(*str))
	{
		num = (10 * num) + (*str - '0');
		len++;
		if (isdigit(*(str + 1)) 
        && (num > cutlim || (num == cutlim && *(str + 1) - '0' > cutoff)
        || (len == intlen - 1 && num < cutlim && isdigit(*(str + 2)))))
			return (0);
		str++;
	}
	return (1);
}

std::string ScalarConverter::detectType(std::string n)
{
    if (n == "-inff" || n == "+inff" || n == "nanf")
        return ("float");
    if (n == "-inf" || n == "+inf" || n == "nan")
        return ("double");
    if (n.size() == 3 && n[0] == '\'' && n[2] == '\'')
        return ("char");
    int dot = std::count(n.begin(), n.end(), '.');
    int plus = std::count(n.begin(), n.end(), '+');
    int minus = std::count(n.begin(), n.end(), '-');
    if (dot > 1 || plus > 1 || minus > 1)
        return ("else");
    if ((plus && n[0] != '+') || (minus && n[0] != '-'))
        return ("else");
    for (std::size_t i = 0; i < n.size(); i++)
    {
        if (i == 0 && (n[i] == '+' || n[i] == '-'))
            continue;
        if (i == n.size() - 1 && n[i] == 'f')
            return ("float");
        if (!isdigit(n[i]) && n[i] != '.')
            return ("else");
    }
    if (dot)
        return ("double");
    return ("int");
}


void ScalarConverter::convert(std::string n)
{
    char c;
    int i;
    float f;
    double d;

    if (detectType(n) == "char")
    {
        if (!chkOverflow(n.c_str(), std::numeric_limits<char>::max()))
        {
            std::cout << "overflow" << std::endl;
            return;
        }
        c = static_cast<char>(n[1]);
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (detectType(n) == "int")
    {
        if (!chkOverflow(n.c_str(), std::numeric_limits<int>::max()))
        {
            std::cout << "overflow" << std::endl;
            return;
        }
        std::istringstream(n) >> i;
        if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
            _charOverflow = true;
        else
            c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (detectType(n) == "float")
    {
        f = std::strtof(n.c_str(), NULL);
        if (f == HUGE_VALF)
        {
            std::cout << "inff" << std::endl;
            return;
        }
        if (f == -HUGE_VALF)
        {
            std::cout << "-inff" << std::endl;
            return;
        }
        if (std::isnan(f))
            _nanf = true;
        if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
            _charOverflow = true;
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            _intOverflow = true;
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    }
    else if (detectType(n) == "double")
    {
        d = std::strtod(n.c_str(), 0);
        if (d == HUGE_VAL)
        {
            std::cout << "inf" << std::endl;
            return;
        }
        if (d == -HUGE_VAL)
        {
            std::cout << "-inf" << std::endl;
            return;
        }
        if (std::isnan(d))
            _nan = true;
        if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min())
            _charOverflow = true;
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            _intOverflow = true;
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        if (f == HUGE_VALF || f == -HUGE_VAL)
            _inff = true;
        d = static_cast<double>(d);
    }
    else
    {
        std::cout << "Error" << std::endl;
        return;
    }

    // char
    if (_charOverflow)
        std::cout << "char: overflow" << std::endl;
    else if (_nan || _nanf)
        std::cout << "char: impossible" << std::endl;
    else
    {
        if (isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    // int
    if (_intOverflow)
        std::cout << "int: overflow" << std::endl;
    else if (_nan || _nanf)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    // float
    if (_inff)
            std::cout << "float: " << f << 'f' << std::endl;
    else
    {
        if (i == f)
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
    }

    // double
    if (i == d)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}
