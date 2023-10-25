#include<iostream>
#include<sstream>
#include <algorithm>

// void readData()
// {
//     std::string line;
//     std::string key;
//     std::string val;
//     std::size_t pos;
//     // float val_f;

// //     std::getline(_datafile, line);
//     while (getline(_datafile, line))
//     {
//         pos = line.find(',');
//         key = line.substr(0, pos);
//         val = line.substr(pos + 1);
//         // std::istringstream(val) >> val_f;
//         _dataMap.insert(std::make_pair(key, val));
//     }
//     // std::map<std::string, float>::iterator it = _dataMap.begin();
//     // for (; it != _dataMap.end(); it++)
//     //     std::cout << "key : " << it->first << " val : " << it->second << std::endl;
// }

float stringToFloat(const std::string& str) {
    std::istringstream iss(str);
    float result;
    if (iss >> result) {
        return result;
    } else {
        // 에러 처리: 올바른 형식의 숫자가 아닌 경우
        std::cerr << "Invalid input: " << str << std::endl;
        return 0.0; // 에러를 나타내는 값 또는 다른 적절한 처리를 수행할 수 있습니다.
    }
}

int main()
{
	float val_f;
	std::string val;

	val = "1234-456-789";
	// stringToFloat(val);
	std::string a, b, c;
	std::istringstream iss(val);
	std::getline(iss, a, '-');
	std::getline(iss, b, '-');
	std::getline(iss, c);
	// iss >> a >> b >> c;
	std::cout << a << b << c;

	// int co;
	// co = std::count(val.begin(), val.end(), '.');
	// std::cout << co;
	// std::cout << stringToFloat(val);
	// std::istringstream(val) >> val_f;
	// std::cout << val_f;
}