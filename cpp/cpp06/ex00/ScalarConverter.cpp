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
    if (n.size() == 3 && n[0] == '\'' && n[2] == '\'' && isascii(n[1]))
        return ("char");
    _dot = std::count(n.begin(), n.end(), '.');
    _plus = std::count(n.begin(), n.end(), '+');
    _minus = std::count(n.begin(), n.end(), '-');
    if (_dot > 1 || _plus > 1 || _minus > 1)
        return ("else");
    if ((_plus && n[0] != '+') || (_minus && n[0] != '-'))
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
    if (_dot)
        return ("double");
    return ("int");
}

bool ScalarConverter::_charOverflow;
bool ScalarConverter::_intOverflow;
bool ScalarConverter::_inf;
bool ScalarConverter::_inff;
int ScalarConverter::_dot;
int ScalarConverter::_plus;
int ScalarConverter::_minus;

void ScalarConverter::convert(std::string n)
{
    char c;
    int i;
    float f;
    double d;

    if (detectType(n) == "char")
    {
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
        i = static_cast<int>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    }
    else if (detectType(n) == "float") // float에서 int변환시 오버플로 나면, float의 정수 부분과 int를 비교해서 판별하자.
    {
        f = std::strtof(n.c_str(), NULL);
        // std::cout << f;
        if (f == std::numeric_limits<float>::infinity() || -f == std::numeric_limits<float>::infinity())
        {
            _charOverflow = true;
            _intOverflow = true;
            _inff = true;
            // f = static_cast<float>(f);
            d = static_cast<double>(f);
        }
        else
        {
            if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min())
                _charOverflow = true;
            if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
                _intOverflow = true;
            // f = static_cast<float>(f);
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
        }
        // if (!chkOverflow(n.c_str(), std::numeric_limits<float>::max()))
        // {
        //     std::cout << "overflow f" << std::endl;
        //     return;
        // }
        // std::istringstream(n) >> f;
        // // if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
        // //     _charOverflow = true;
        // // else
        //     // c = static_cast<char>(i);
    }
    else if (detectType(n) == "double")
    {
        // if (!chkOverflow(n.c_str(), std::numeric_limits<double>::max()))
        // if (!chkOverflow(n.c_str(), std::numeric_limits<double>::max()))
        // {
        //     std::cout << "overflow d" << std::endl;
        //     return;
        // }
        std::istringstream(n) >> d;
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        d = static_cast<double>(d);
    }
    else
    {
        // nan inf inff 여기서 처리
        std::cout << "Error" << std::endl;
        return;
    }

    // char
    if (_charOverflow)
        std::cout << "char: overflow" << std::endl;
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
    else
        std::cout << "int: " << i << std::endl;
    // float
    if (_inff)
    {
        std::cout << "float: " << "inff" << std::endl;
    }
    else
    {
        if (i == f)
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
        if (i == d)
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    // double
}
// "convert" 메서드를 포함하는 정적 클래스 ScalarConverter를 작성합니다.
// 매개변수로 C++ 리터럴의 가장 일반적인 형식의 문자열 표현을 받습니다. 이 리터럴
// 은 다음 스칼라 유형 중 하나에 속해야 합니다:
// -char
// -int
// -float
// -double
// 문자 매개변수를 제외하고는 십진수 표기법만 사용됩니다.
// 문자 리터럴의 예: 'c', 'a', ...
// 작업을 단순화하기 위해 표시할 수 없는 문자를 입력으로 사용해서는 안 된다는 점에 유의하세요.
// 입력으로 사용해서는 안 됩니다. 문자열로 변환할 때 표시할 수 없는 경우 정보 메시지를 인쇄합니다.
// int 리터럴의 예: 0, -42, 42...
// 실수 리터럴의 예: 0.0f, -4.2f, 4.2f...
// 이러한 의사 리터럴도 처리해야 합니다(과학을 위해): -inff, +inff 및 nanf.
// 이중 리터럴의 예: 0.0, -4.2, 4.2...
// 이러한 의사 리터럴도 처리해야 합니다(재미로): -inf, +inf 및 nan.
// 먼저 매개변수로 전달된 리터럴의 유형을 감지하여
// 문자열에서 실제 유형으로 변환한 다음 다른 세 가지 데이터 유형으로 명시적으로 변환해야 합니다. 마지막으로
// 를 실행하면 아래와 같이 결과가 표시됩니다.
// 변환이 의미가 없거나 오버플로우가 발생하면 사용자에게 유형 변환이 실패했음을 알리는 메시지를 표시합니다.
// 사용자에게 유형 변환이 불가능하다는 메시지를 표시합니다. 숫자 제한 및 특수 값을 처리하기 위해 필요한 헤더를 포함하세요.
// 숫자 제한 및 특수 값을 처리합니다.
// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0
// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan
// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0