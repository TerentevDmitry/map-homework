#pragma once
#include <mutex>
#include <vector>


class Data
{
private:
	std::vector<int> vec;
	std::mutex m;

	void printThisVec(Data& other);

public:
	Data() = default;
	Data(std::vector<int> vec) : vec{ vec } {}

	void swapWithLock(Data& other);
	void swapWithScopedLock(Data& other);
	void swapWithUniqueLock(Data& other);

	void printData();
};

