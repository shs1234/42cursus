#include <iostream>
#include <vector>

std::vector<int> generateDecreasingArray(const std::vector<int>& numbers) {
    std::vector<int> result;

    for (size_t i = 0; i < numbers.size(); ++i) 
	{
        for (int j = numbers[i]; j >= 1; --j) 
		{
			if (i > 0 && j == numbers[i - 1])
				break;
            result.push_back(j);
        }
    }
    return result;
}

int main() 
{
    std::vector<int> numbers = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    std::vector<int> result = generateDecreasingArray(numbers);
    return 0;
}
