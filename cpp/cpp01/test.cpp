#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world! This is a sample string.";

    size_t found = str.find("world"); // 문자열 "world"의 첫 번째 등장 위치
    if (found != std::string::npos) {
        std::cout << "Found at index: " << found << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    size_t found2 = str.find("is", 10); // 인덱스 10 이후부터 "is"를 검색
    if (found2 != std::string::npos) {
        std::cout << "Found at index: " << found2 << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    size_t found3 = str.find('z'); // 문자 'z'의 등장 위치
    if (found3 != std::string::npos) {
        std::cout << "Found at index: " << found3 << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}
