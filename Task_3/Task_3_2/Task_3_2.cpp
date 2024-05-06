#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

enum class dividingIntervals
{
    valueOfMinIntervals = 3

};


void multiplyVec(int& MultiplierVec)
{
    MultiplierVec *= 2;
}

template <typename Iterator, dividingIntervals chunkSizeOf = dividingIntervals::valueOfMinIntervals>
void parallelForEachAsyncRecursive(Iterator begin, Iterator end)
{
    auto currSize = std::distance(begin, end);
    
    if (currSize <= chunkSize)
    {
        std::for_each(begin, end, multiplyVec);
    }
    else
    {
        auto mid = begin;
        std::advance(mid, currSize / 2);
        auto ftRes = std::async(parallelForEachAsyncRecursive<Iterator>, begin, mid);
        parallelForEachAsyncRecursive(mid, end);

        ftRes.get();
    }
}

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::cout << "Before: ";
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    parallelForEachAsyncRecursive(vec.begin(), vec.end());

    std::cout << "\nAfter: ";
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}