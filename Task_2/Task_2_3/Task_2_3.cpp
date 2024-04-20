// Task_2_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Data.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <thread>

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    std::cout << "ID main thread: " << std::this_thread::get_id() << "\n";

    std::vector<int> vec1(5, 1);
    std::vector<int> vec2(7, 2);
    
    Data d1(vec1);
    Data d2(vec2);

//swapWithLock
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::cout << "\nbefore:\n";
    d1.printData();
    d2.printData();

    auto funcSwapWithLock = [&d1, &d2]()
    {
        d1.swapWithLock(d2);
    };

    auto funcSwapWithScopedLock = [&d1, &d2]()
        {
            d1.swapWithScopedLock(d2);
        };

    auto funcSwapWithUniqueLock = [&d1, &d2]()
        {
            d1.swapWithUniqueLock(d2);
        };


    std::thread thread1(funcSwapWithLock);
    std::thread thread2(funcSwapWithScopedLock);
    std::thread thread3(funcSwapWithUniqueLock);
    
    
    thread1.join();
    thread2.join();
    thread3.join();


    
    std::cout << "\nafter:\n";
    d1.printData();
    d2.printData();

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    std::cout << "\n\nend of main\n";
}