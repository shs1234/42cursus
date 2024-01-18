#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <sstream>
#include <cmath>
#include <set>
#include <ctime>

typedef std::vector<int> Vec;

class PmergeMe
{
private:
    Vec _vec;
    std::list<int> _lst;

    PmergeMe();

    void before();
    void after();
    void printTime();
    int	biSearch(Vec &v, int s, int e, const int k);

    void pmsort(int loop);
    void insertion(int loop);

public:
    PmergeMe(int len, char **arr);
    PmergeMe(const PmergeMe& pm);
    PmergeMe& operator=(const PmergeMe& pm);
    ~PmergeMe();

    void exec();
    void printvec(Vec &v);

    class Error : public std::exception
    {
        const char *what() const throw();
    };
};

template <typename It1, typename It2>
void my_swap_ranges(It1 it1_begin, It1 it1_end, It2 it2_begin) {
    while (it1_begin != it1_end)
    {
        std::swap(*it1_begin++, *it2_begin++);
    }
}

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



// 분할한다.
// 2개씩 남은 애들을 각각 정렬. 큰게 앞으로.
// 앞 숫자를 기준으로 정렬(큰 수 기준) - 재귀 이용
// 뒷 숫자들 이진탐색으로 삽입정렬 할 것. 야콥스탈 수열 이용.

// 리스트는 해당 위치의 이터레이터 반환하는 함수 만들어서
// 리스트 스왑함수 쓰면 순서대로 출력될까? 테스트