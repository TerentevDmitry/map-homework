#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

template <typename Iterator, typename Function>
void parallelForEach(Iterator first, Iterator last, Function f)
{
    std::vector<std::future<void>> futures;
    for (Iterator it = first; it != last; ++it)
    {
        futures.push_back(std::async(std::launch::async, f, std::ref(*it)));
    }

    for (std::future<void>& future : futures)
    {
        future.get();
    }
}

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    std::cout << "Before: ";
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    parallelForEach(vec.begin(), vec.end(), [](int& i)
        {
            i *= 2;
        });

    std::cout << "After: ";
    for (int i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}