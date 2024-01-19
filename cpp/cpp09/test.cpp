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
    std::advance()
}
