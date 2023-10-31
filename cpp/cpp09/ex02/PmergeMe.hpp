#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <sstream>

class PmergeMe
{
private:

    std::vector<int> vec;
    std::list<int> lst;
    // std::vector<int> _vecA;
    // std::vector<int> _vecB;
    // std::list<int> _lstA;
    // std::list<int> _lstB;
    // int _odd;

    std::vector<int>::iterator _itA;
    std::vector<int>::iterator _itB;

    int _indexA; // 넣을 위치
	int _indexB; // 넣을 값의 위치
	int _iter; // 자콥 매개변수로 넣을값. 1씩 증가.
	int _num; // 넣을 값

    PmergeMe();

    void before();
    // void sortVec();
    // void sortLst();
    void after();
    void printTime();
    // void mergeInsertSort(std::vector<int> &vec);
    int getIndex();
public:
    PmergeMe(int ac, char **av);
    PmergeMe(const PmergeMe& pm);
    PmergeMe& operator=(const PmergeMe& pm);
    ~PmergeMe();

    void exec();

    class Error : public std::exception
    {
        const char *what() const throw();
    };
};

template <typename T>
void swap(T *a, T *b)
{
	T tmp = *a;
	*a = *b;
	*b = tmp;
}

#endif

// 인트형 양의 정수 인자로 받을것. 아닐경우 에러처리.
// 머지-인서트 정렬 알고리즘 사용할것. 포드존슨 알고리즘. Ford-Johnson
// 프로그램 실행중 애러 발생시 표준출력에 메시지 출력.
// 두개의 다른 컨테이너 사용. 적어도 3000개의 정수를 처리해야함.
// 알고리즘을 직접 구현하고 제네릭 함수를 사용하지 말것을 강하게 권고.

// -출력내용
// 정렬되지 않은 값들
// 정렬된 값들
// 1컨테이너 작동 시간
// 2컨테이너 작동 시간

// 시간 출력 형식은 자유지만, 두개의 차이가 명확하게 보일수있도록.

// 중복 오류 관리는 내맘대로.

// 분할 한 다음 정렬하는 건 삽입 정렬로. 어디 위치에 삽입할지 찾는건 바이너리 서치로.