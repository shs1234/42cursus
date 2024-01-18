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

bool doublechk(Vec numbers)
{
    std::set<int> uniqueNumbers;

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
	{
        if (uniqueNumbers.find(*it) != uniqueNumbers.end())
            return 1;
        else
            uniqueNumbers.insert(*it);
    }
	return 0;
}


void PmergeMe::insertion(int loop)
{
	int pair = _vec.size() / std::pow(2, loop);
	int odd = _vec.size() % (size_t)std::pow(2, loop);
	int flag = 1;
	Vec main;
	Vec pend;
	Vec tail;
	for (int i = 0; i < pair * 2; i++)
	{
		if (flag)
			main.insert(main.end(), *(_vec.begin() + std::pow(2, loop - 1) * i));
		else
			pend.insert(pend.end(), *(_vec.begin() + std::pow(2, loop - 1) * i));
		flag = !flag;
		if (odd && i == pair * 2 - 1)
		{
			if (odd >= std::pow(2, loop - 1))
			{
				pend.insert(pend.end(), *(_vec.begin() + std::pow(2, loop - 1) * (i + 1)));
				if (odd == std::pow(2, loop - 1))
					break;
				i++;
			}
			tail.insert(tail.end(), *(_vec.begin() + std::pow(2, loop - 1) * (i + 1)));
		}
	}

	Vec temp(main);
	int index;
	int pos;
	for (int i = 0; i < pend.size(); i++)
	{
		index = std::find(temp.begin(), temp.end(), main[i]) - temp.begin();
		if (i == pend.size() - 1 && main.size() < pend.size())
			index = temp.size();
		pos = biSearch(temp, 0, index, pend[i]);
		temp.insert(temp.begin() + pos, *(pend.begin() + i));
	}
	if (tail.size() > 0)
		temp.insert(temp.end(), tail.begin(), tail.end());

	Vec res;
	for (int i = 0; i < temp.size(); i++)
	{
		index = std::find(_vec.begin(), _vec.end(), temp[i]) - _vec.begin();
		if (i == temp.size() - 1)
			res.insert(res.end(), _vec.begin() + index, _vec.begin() + index + _vec.size() - res.size());
		else
			res.insert(res.end(), _vec.begin() + index, _vec.begin() + index + std::pow(2, loop - 1));
	}
	_vec.clear();
	_vec = res;
}

void PmergeMe::pmsort(int loop)
{
	int pair = _vec.size() / std::pow(2, loop);
	Vec::iterator it = _vec.begin();
	Vec::iterator it2 = it + std::pow(2, loop - 1);
	for (int i = 0; i < pair; i++)
	{
		if (*it < *it2)
			my_swap_ranges(it, it2, it2);
		it += std::pow(2, loop);
		it2 += std::pow(2, loop);
	}
	if (static_cast<int>(_vec.size() / std::pow(2, loop + 1)))
		pmsort(loop + 1);
	insertion(loop);
}

void verify(Vec &v)
{
	for (int i = 0;i < v.size() - 1; i++)
	{
		if (v[i] > v[i + 1])
		{
			std::cout << "fail" << std::endl;
			return;
		}
	}
	std::cout << "ok" << std::endl;
}

void PmergeMe::exec()
{
	if (doublechk(_vec))
	{
		std::cout << "double" << std::endl;
		return;
	}
    std::cout << "-Before: ";
	printvec(_vec);
	pmsort(1);
	std::cout << "-After: ";
	printvec(_vec);
	verify(_vec);
    // printTime();
}

void PmergeMe::printvec(Vec &v)
{
	int count = 0;
	for (Vec::iterator it = v.begin(); it != v.end(); it++)
	{
        std::cout << *it << " ";
		if (count > 3 && v.size() > 3)
		{
			std::cout << "[...]";
			break;
		}
		++count;
	}
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
