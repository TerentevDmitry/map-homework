#include "Data.h"
#include <iostream>



void Data::printThisVec(Data& other)
{
    std::cout << "ID thread " << std::this_thread::get_id() << ": ";
    for (int num : this->vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "ID thread " << std::this_thread::get_id() << ": ";
    for (int num : other.vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void Data::swapWithLock(Data& other)
{
    this->m.lock();
    other.m.lock();

    std::swap(this->vec, other.vec);
    std::cout << std::endl << __FUNCTION__ << std::endl;
    this->printThisVec(other);

    this->m.unlock();
    other.m.unlock();
}

void Data::swapWithScopedLock(Data& other)
{
    std::scoped_lock sl(this->m, other.m);

    std::swap(this->vec, other.vec);
    std::cout << std::endl << __FUNCTION__ << std::endl;
    this->printThisVec(other);
}

void Data::swapWithUniqueLock(Data& other)
{
    std::unique_lock ul1(this->m);
    std::unique_lock ul2(other.m);

    std::swap(this->vec, other.vec);
    std::cout << std::endl << __FUNCTION__ << std::endl;
    this->printThisVec(other);
}


void Data::printData()
{
    std::cout << "ID thread " << std::this_thread::get_id() << ": ";

    for (int num : this->vec) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
