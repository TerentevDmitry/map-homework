#include "Data.h"
#include <iostream>


void Data::swapWithLock(Data& other)
{
    std::swap(this->vec, other.vec);
    std::cout << std::endl << __FUNCTION__ << std::endl;
}

void Data::swapWithScopedLock(Data& other)
{
    std::swap(this->vec, other.vec);
    std::cout << std::endl << __FUNCTION__ << std::endl;
}

void Data::swapWithUniqueLock(Data& other)
{
    std::swap(this->vec, other.vec);
    std::cout << std::endl << __FUNCTION__ << std::endl;
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
