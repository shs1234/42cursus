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
        // if (tmp == 0)
        //     throw Error();
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

int	PmergeMe::biSearch(Vec &v, int s, int e, const int k)
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

// 5 9 14 2 8 3 10 1 16 7 12 15 4 13 11 17 6 18 19 21 20 0 22
void PmergeMe::insertion(int loop)
{
	Vec main;
	Vec pend;
	Vec oddvec;

	int flag = 1;
	int pair = _vec.size() / std::pow(2, loop);
	int odd = _vec.size() % (size_t)std::pow(2, loop);
	// std::cout << odd << std::endl;
	Vec test1;
	Vec test2;
	Vec test3;
	for (int i = 0; i < pair * 2; i++)
	{
		if (flag)
		{
			main.insert(main.end(), _vec.begin() + std::pow(2, loop - 1) * i, _vec.begin() + std::pow(2, loop - 1) * (i + 1));
			test1.insert(test1.end(), *(_vec.begin() + std::pow(2, loop - 1) * i));
		}
		else
		{
			pend.insert(pend.end(), _vec.begin() + std::pow(2, loop - 1) * i, _vec.begin() + std::pow(2, loop - 1) * (i + 1));
			test2.insert(test2.end(), *(_vec.begin() + std::pow(2, loop - 1) * i));
		}
		flag = !flag;
		if (odd && i == pair * 2 - 1)
		{
			oddvec.insert(oddvec.end(), _vec.begin() + std::pow(2, loop - 1) * (i + 1), _vec.end());
			test3.insert(test3.end(), *(_vec.begin() + std::pow(2, loop - 1) * (i + 1)));
		}
	}
	printvec(test1); // main
	printvec(test2); // pend
	printvec(test3); // odd
	// test를 가지고 삽입 정렬 시행. 그 순서대로 다시 정렬.
	Vec temp(test1);
	int index;
	int pos;
	for (int i = 0; i < test2.size(); i++)
	{
		index = std::find(temp.begin(), temp.end(), test1[i]) - temp.begin();
		std::cout << "index : " << index << std::endl;
		pos = biSearch(temp, 0, index, test2[i]);
		std::cout << "pos : " << pos << std::endl;
		temp.insert(temp.begin() + pos, *(test2.begin() + i));
	}
	printvec(temp);
	// odd부분이 잘못됨.
}

void PmergeMe::pmsort(int loop)
{
	std::cout << "loop " << loop << " / " << (int)(_vec.size() / std::pow(2, loop)) << std::endl;
	int pair = _vec.size() / std::pow(2, loop);
	printvec(_vec);
	Vec::iterator it = _vec.begin();
	Vec::iterator it2 = it + std::pow(2, loop - 1);
	for (int i = 0; i < pair; i++)
	{
		if (*it < *it2)
			my_swap_ranges(it, it2, it2);
		// printvec(_vec);
		it += std::pow(2, loop);
		it2 += std::pow(2, loop);
	}
	printvec(_vec);
	if (static_cast<int>(_vec.size() / std::pow(2, loop + 1)))
		pmsort(loop + 1);
	std::cout << "------------------" << std::endl;
	insertion(loop);
}

void PmergeMe::exec()
{
    // before();
	pmsort(1);
	// after();
    // printTime();
}

void PmergeMe::printvec(Vec &v)
{
	for (Vec::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::before()
{
    // std::cout << "Before : ";
    for (Vec::iterator it = _vec.begin(); it != _vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
	// std::cout << "Before : ";
    // for (Vec::iterator it2 = _vec.begin(); it2 != _vec.end(); it2++)
    //     std::cout << *it2 << " ";
    // std::cout << std::endl;
}
void PmergeMe::after()
{
    std::cout << "After : ";
    for (Vec::iterator it = _vec.begin(); it != _vec.end(); it++)
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
