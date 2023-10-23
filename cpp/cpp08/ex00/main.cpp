#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main(void)
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << easyfind(vec, 30) << std::endl;
    std::cout << easyfind(lst, 30) << std::endl;
    std::cout << easyfind(vec, 15) << std::endl;
    std::cout << easyfind(lst, 15) << std::endl;
}
