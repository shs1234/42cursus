long long getJacobsthal(int n)
{
	static long long arr[100];
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
    if (arr[n] == 0)
	{
        arr[n] = getJacobsthal(n - 1) + getJacobsthal(n - 2) * 2;
	}
	return (arr[n]);
}
#include <iostream>
int main()
{
    // for(int i = 0;i < 20;i++)
    //     std::cout << getJacobsthal(i) << " ";
    std::cout << getJacobsthal(3) << " ";
}