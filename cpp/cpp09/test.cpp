#include<iostream>
#include<sstream>

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

#include <algorithm>
int main()
{
	float val_f;
	std::string val;
	val = "123.asd23";
	int co;
	co = std::count(val.begin(), val.end(), '.');
	
	// std::istringstream(val) >> val_f;
	std::cout << co;
}