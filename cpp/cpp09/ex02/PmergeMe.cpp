#include "PmergeMe.hpp"

static int	numLen(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static bool	isInt(const char *str)
{
	static int intlen = numLen(__INT_MAX__);
	int	cutlim;
	int	cutoff;
	int	num;
	int	len;

	cutlim = __INT_MAX__ / 10;
	cutoff = __INT_MAX__ % 10;
	num = 0;
	len = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			cutoff++;
		str++;
	}
	while (*str == '0')
		str++;
	while (isdigit(*str))
	{
		num = (10 * num) + (*str - '0');
		len++;
		if (isdigit(*(str + 1)) 
        && (num > cutlim || (num == cutlim && *(str + 1) - '0' > cutoff)
        || (len == intlen - 1 && num < cutlim && isdigit(*(str + 2)))))
			return (0);
		str++;
	}
	return (1);
}

static bool	formatCheck(const char *n)
{
	if (*n == '+')
		n++;
	if (!isdigit(*n))
		return (0);
	while (*n)
	{
		if (!isdigit(*n))
			return (0);
		n++;
	}
	return (1);
}

static bool	isValid(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!formatCheck(av[i]) || !isInt(av[i]))
			return (0);
		i++;
	}
	return (1);
}

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(int len, char **arr)
{
    if (!isValid(len, arr))
        throw Error();
    int tmp;
    for (int i = 0; i < len; i++)
    {
        std::stringstream(arr[i]) >> tmp;
        if (tmp == 0)
            throw Error();
		_vec.push_back(tmp);
		_lst.push_back(tmp);
    }
}
PmergeMe::PmergeMe(const PmergeMe& pm) : _vec(pm._vec), _lst(pm._lst) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& pm)
{
    if (this != &pm)
    {
        _vec = pm._vec;
        _lst = pm._lst;
    }
    return (*this);
}
PmergeMe::~PmergeMe() {}

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

int	PmergeMe::biSearch(std::vector<int> &v, int s, int e, const int k)
{
	int m;

	while (s < e)
	{
		m = (s + e) / 2;
		if (k >= v[m])
			s = m + 1;
		else
			e = m;
	}
	return (e);
}

// template <typename T>
// void merge(std::vector<std::pair<T, T>> &vec)
// {
// 	if (vec.size() < 2)
// 		return;
// 	std::vector<std::pair<T, T>> newVec;
// 	T odd;

// 	for (size_t i = 0; i < vec.size() / 2; i += 2)
// 	{
// 		newVec.push_back(std::make_pair(std::max(vec[i], vec[i + 1]), std::min(vec[i], vec[i + 1])));
// 	}
// 	if (vec.size() % 2 == 1)
// 		odd = vec[vec.size() - 1];
// 	mergeInsertSort(newVec);
// }

// template <typename T>
// void mergeInsertSort(std::vector<T> &vec)
// {
// 	// (void)odd;
// 	// vec.clear();
// 	std::vector<T> vec_b;
// 	for (size_t i = 0; i < vec.size() / 2; i += 2)
// 	{
// 		vec.push_back(newVec[i].first);
// 		vec_b.push_back(newVec[i].second);
// 	}
// 	typename std::vector<T>::iterator it = vec.begin();
// 	for (size_t i = 0; i < vec_b.size(); i++)
//     {
//         vec.insert(it + biSearch(vec, 0, vec.size(), vec_b[i]), vec_b[i]);
//     }
// }

void PmergeMe::pmsort(int loop)
{
	// int odd = _vec.size() % (loop * 2);
	// 1. 한쌍씩 비교해서 큰거 앞으로
	std::cout << "loop " << loop << " / " << (int)(_vec.size() / std::pow(2, loop)) << std::endl;
	int pair = _vec.size() / std::pow(2, loop);
	printvec();
	std::vector<int>::iterator it = _vec.begin();
	std::vector<int>::iterator it2 = it + std::pow(2, loop - 1);
	while (pair--)
	{
		if (*it < *it2)
		{
			my_swap_ranges(it, it2, it2);
		}
		printvec();
		it += std::pow(2, loop);
		it2 += std::pow(2, loop);
	}
	if (static_cast<int>(_vec.size() / std::pow(2, loop + 1)))
		pmsort(loop + 1);
}
// swap_ranges 사용하면 여러개 바꾸기 가능.

void PmergeMe::exec()
{
    // before();
	pmsort(1);
	// after();
    // printTime();
}

void PmergeMe::printvec()
{
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
        std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::before()
{
    // std::cout << "Before : ";
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
	// std::cout << "Before : ";
    // for (std::vector<int>::iterator it2 = _vec.begin(); it2 != _vec.end(); it2++)
    //     std::cout << *it2 << " ";
    // std::cout << std::endl;
}
void PmergeMe::after()
{
    std::cout << "After : ";
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printTime()
{
}

const char *PmergeMe::Error::what() const throw()
{
    return ("Error");
}
