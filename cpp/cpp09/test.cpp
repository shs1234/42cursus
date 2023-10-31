#include <iostream>
#include <vector>
#include <utility>

template <typename T>
void swap(T *a, T *b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	// std::vector<std::pair> data = {12, 11, 13, 5, 6, 7};
	std::vector<std::pair<int, int>> data;
	for (int i = 0; i < 6; i++)
	{
		data.push_back(std::make_pair(10, 5-i));
		// data[i] = std::pair<int, int>(i+10, i);
	}
	// for (int i = 0; i < 6; i++)
	// {
	// 	std::cout << data[i].first << " " << data[i].second << std::endl;
	// }
	int tmp;
    std::vector<std::pair<int, int>>::iterator it = data.begin();
    for (; it != data.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
		swap(&it->first, &it->second);
    }
	it = data.begin();
    for (; it != data.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
	if (data[2] < 5)
		std::cout << "오름";
	else
		std::cout << "내림";
	return (0);
}
