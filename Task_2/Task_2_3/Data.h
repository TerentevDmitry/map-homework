#pragma once
#include <mutex>
#include <vector>


class Data
{
private:
	int value_ = 0;
	

public:
	Data() = default;
	Data(int value) : value_(value) {}
	
	std::mutex mutex_;
	
	int getValue() const;
	void setValue(int value);

	//friend void swapWithLock(Data& d1, Data& d2);
	//friend void swapWithScopedLock(Data& d1, Data& d2);
	//friend void swapWithUniqueLock(Data& d1, Data& d2);

	//void printDataValue() const;
};