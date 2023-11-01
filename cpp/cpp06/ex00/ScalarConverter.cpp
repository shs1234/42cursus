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

std::string detectType(std::string n)
{
    if (n.size() == 3 && n[0] == '\'' && n[2] == '\'' && isascii(n[1]))
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
    return ("int"); // 오버플로우 검사
}

void ScalarConverter::convert(std::string n)
{
    char c;
    int i;
    float f;
    double d;
    if (detectType(n) == "char")
    {
        std::string n2 = "";
        n2 += n[1];
        std::istringstream(n2) >> i;
        c = static_cast<char>(i);
        i = static_cast<int>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        // std::cout << c << std::endl; // ./convert \'b\' 가 왜 0?
    }
    else if (detectType(n) == "int")
    { 
        std::istringstream(n) >> i;
        c = static_cast<char>(i);
        i = static_cast<int>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        // std::cout << i << std::endl;
    }
    else if (detectType(n) == "float")
    {
        std::istringstream(n) >> f;
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        f = static_cast<float>(f);
        d = static_cast<double>(f);
        // std::cout << f << std::endl;
    }
    else if (detectType(n) == "double")
    {
        std::istringstream(n) >> d;
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        d = static_cast<double>(d);
        // std::cout << d << std::endl;
    }
    else if (detectType(n) == "else")
    {
        std::cout << "Error" << std::endl;
    }
    if (isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    if (i == f)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (i == d)
        std::cout << "double: " << d << ".0" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
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