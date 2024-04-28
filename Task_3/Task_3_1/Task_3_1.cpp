#include <iostream>
#include <vector>
#include <random>
#include<future>
#include<algorithm>

using namespace std::chrono_literals;

static void sortingByChoice(std::vector<int>& vec)
{
	int n = vec.size();

	for (int i = 0; i < n - 1; i++)
	{
		int minElement = i;
		
		for (int j = i + 1; j < n; j++)
		{
			if (vec[j] < vec[minElement])
			{
				minElement = j;
			}
		}

		if (minElement != i)
		{
			std::swap(vec[i], vec[minElement]);
		}
	}
};

int main()
{
	std::vector<int> vec(11);
	srand(time(0));

	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = std::rand() % 33;
	}

	std::cout << "Before sorting: ";
	for (const auto& i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";


	//std::promise<void> prom;
	//std::future<void> ft_res = prom.get_future();
	//auto ft = std::async(sortingByChoice, std::ref(vec), std::move(prom));

	
	sortingByChoice(std::ref(vec));
	
	std::cout << "After sorting: ";
	for (const auto& i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
}