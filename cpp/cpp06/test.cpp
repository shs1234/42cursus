#include <iostream>
#include <iomanip> // std::setprecision
#include <sstream> // std::ostringstream

int main() {
    float number = 42.42f;

    // 방법 1: cout과 형식 지정자 사용
    std::cout << std::fixed << std::setprecision(1) << number << std::endl;

    // 방법 2: 문자열로 변환 후 출력
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(1) << number;
    std::string formattedNumber = ss.str();
    std::cout << formattedNumber << std::endl;

    return 0;
}
