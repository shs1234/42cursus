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

template <typename T>
typename T::iterator moveIterator(T& myList, typename T::iterator iter, int distance) {
    for (int i = 0; i < distance && iter != myList.end(); ++i)
        ++iter;
    return iter;
}

template <typename T>
int	biSearch(T &container, int s, int e, const int k)
{
	int m;

	while (s < e)
	{
		m = (s + e) / 2;
		// if (k >= v[m])
		if (k >= *moveIterator(container, container.begin(), m))
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

Vec PmergeMe::jacobArr()
{
	Vec numbers = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};
    Vec result;

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

void PmergeMe::insertion_vec(int loop)
{
	int pair = _vec.size() / std::pow(2, loop);
	int odd = _vec.size() % (size_t)std::pow(2, loop);
	int flag = 1;
	Vec main;
	Vec pend;
	Vec tail;
	for (int i = 0; i < pair * 2; i++) // main pend tail 나누는 과정.
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
	int jacob;
	flag = 1;
	int j = 0;
	for (int i = 0; i < pend.size(); i++) // jacob 수열 순서대로 삽입 정렬
	{
		if (flag == 0 || _jacob[i] > pend.size())
		{
			jacob = pend.size() - j - 1;
			flag = 0;
			++j;
		}
		else
			jacob = _jacob[i] - 1;
		Vec::iterator where = find(temp.begin(), temp.end(), main[jacob]);
		index = std::distance(temp.begin(), where);
		if (i == pend.size() - 1 && main.size() < pend.size())
			index = temp.size();
		pos = biSearch(temp, 0, index, pend[jacob]);
		temp.insert(temp.begin() + pos, *(pend.begin() + jacob));
	}
	if (tail.size() > 0)
		temp.insert(temp.end(), tail.begin(), tail.end());

	Vec res;
	for (int i = 0; i < temp.size(); i++) // 삽입 정렬된 순서대로 새 배열 생성.
	{
		Vec::iterator where = find(_vec.begin(), _vec.end(), temp[i]);
		index = std::distance(_vec.begin(), where);
		if (i == temp.size() - 1)
			res.insert(res.end(), _vec.begin() + index, _vec.begin() + index + _vec.size() - res.size());
		else
			res.insert(res.end(), _vec.begin() + index, _vec.begin() + index + std::pow(2, loop - 1));
	}
	_vec.clear();
	_vec = res;
}

void PmergeMe::pmsort_vec(int loop)
{
	int pair = _vec.size() / std::pow(2, loop);
	Vec::iterator it = _vec.begin();
	Vec::iterator it2 = it + std::pow(2, loop - 1);
	for (int i = 0; i < pair; i++) // 두개 비교해서 큰거 앞으로 배치
	{
		if (*it < *it2)
			my_swap_ranges(it, it2, it2);
		it += std::pow(2, loop);
		it2 += std::pow(2, loop);
	}
	if (static_cast<int>(_vec.size() / std::pow(2, loop + 1)))
		pmsort_vec(loop + 1);
	insertion_vec(loop);
}

void PmergeMe::insertion_lst(int loop)
{
	int pair = _lst.size() / std::pow(2, loop);
	int odd = _lst.size() % (size_t)std::pow(2, loop);
	int flag = 1;
	Lst main;
	Lst pend;
	Lst tail;
	for (int i = 0; i < pair * 2; i++) // main pend tail 나누는 과정.
	{
		if (flag)
			main.insert(main.end(), *moveIterator(_lst, _lst.begin(), std::pow(2, loop - 1) * i));
		else
			pend.insert(pend.end(), *moveIterator(_lst, _lst.begin(), std::pow(2, loop - 1) * i));
		flag = !flag;
		if (odd && i == pair * 2 - 1)
		{
			if (odd >= std::pow(2, loop - 1))
			{
				pend.insert(pend.end(), *moveIterator(_lst, _lst.begin(), std::pow(2, loop - 1) * (i + 1)));
				if (odd == std::pow(2, loop - 1))
					break;
				i++;
			}
			tail.insert(tail.end(), *moveIterator(_lst, _lst.begin(), std::pow(2, loop - 1) * (i + 1)));
		}
	}

	Lst temp(main);
	int index;
	int pos;
	int jacob;
	flag = 1;
	int j = 0;
	for (int i = 0; i < pend.size(); i++) // jacob 수열 순서대로 삽입 정렬
	{
		if (flag == 0 || _jacob[i] > pend.size())
		{
			jacob = pend.size() - j - 1;
			flag = 0;
			++j;
		}
		else
			jacob = _jacob[i] - 1;
		Lst::iterator where = find(temp.begin(), temp.end(), *moveIterator(main, main.begin(), jacob));
		index = std::distance(temp.begin(), where);
		if (i == pend.size() - 1 && main.size() < pend.size())
			index = temp.size();
		pos = biSearch(temp, 0, index, *moveIterator(pend, pend.begin(), jacob));
		temp.insert(moveIterator(temp, temp.begin(), pos), *moveIterator(pend, pend.begin(), jacob));
	}
	if (tail.size() > 0)
		temp.insert(temp.end(), tail.begin(), tail.end());

	Lst res;
	for (int i = 0; i < temp.size(); i++) // 삽입 정렬된 순서대로 새 배열 생성.
	{//moveIterator(_lst, _lst.begin(), index + std::pow(2, loop - 1))
		Lst::iterator where = find(_lst.begin(), _lst.end(), *moveIterator(temp, temp.begin(), i));
		index = std::distance(_lst.begin(), where);
		if (i == temp.size() - 1)
			res.insert(res.end(), moveIterator(_lst, _lst.begin(), index), moveIterator(_lst, _lst.begin(), index + _lst.size() - res.size()));
		else
			res.insert(res.end(), moveIterator(_lst, _lst.begin(), index), moveIterator(_lst, _lst.begin(), index + std::pow(2, loop - 1)));
	}
	_lst.clear();
	_lst = res;
}

void PmergeMe::pmsort_lst(int loop)
{
	int pair = _lst.size() / std::pow(2, loop);
	Lst::iterator it = _lst.begin();
	// Lst::iterator it2 = it + std::pow(2, loop - 1);
	Lst::iterator it2 = moveIterator(_lst, it, std::pow(2, loop - 1));
	for (int i = 0; i < pair; i++) // 두개 비교해서 큰거 앞으로 배치
	{
		if (*it < *it2)
			my_swap_ranges(it, it2, it2);
		it = moveIterator(_lst, it, std::pow(2, loop));
		it2 = moveIterator(_lst, it2, std::pow(2, loop));
		// it += std::pow(2, loop);
		// it2 += std::pow(2, loop);
	}
	if (static_cast<int>(_lst.size() / std::pow(2, loop + 1)))
		pmsort_lst(loop + 1);
	insertion_lst(loop);
}

template <typename T>
void verify(T &v)
{
	typename T::iterator it = v.begin();
	typename T::iterator it2 = it;
	++it2;
	for (int i = 0;i < v.size() - 1; i++)
	{
		if (*it++ > *it2++)
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
	_jacob = jacobArr();
    std::cout << "-Before: ";
	printvec(_vec);
	clock_t start = clock();
	pmsort_vec(1);
	clock_t stop = clock();
	std::cout << "-After: ";
	printvec(_vec);
	double duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
    std::cout << "vector 실행 시간: " << duration << " 초" << std::endl;

	start = clock();
	pmsort_lst(1);
	stop = clock();
	duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;
	std::cout << "list 실행 시간: " << duration << " 초" << std::endl;

	verify(_vec);
	verify(_lst);
    // printTime();
}

void PmergeMe::printvec(Vec &v)
{
	int count = 0;
	for (Vec::iterator it = v.begin(); it != v.end(); it++)
	{
        std::cout << *it << " ";
		// if (count > 3 && v.size() > 3)
		// {
		// 	std::cout << "[...]";
		// 	break;
		// }
		// ++count;
	}
	std::cout << std::endl;
}

const char *PmergeMe::Error::what() const throw()
{
    return ("Error");
}
