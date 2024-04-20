// Task_2_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Data.h"
#include <iostream>
#include <vector>
#include <Windows.h>

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

    d1.swapWithLock(d2);

    std::cout << "\nafter:\n";
    d1.printData();
    d2.printData();


//swapWithScopedLock
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    std::cout << "\nbefore:\n";
    d1.printData();
    d2.printData();

    d1.swapWithScopedLock(d2);

    std::cout << "\nafter:\n";
    d1.printData();
    d2.printData();


//swapWithScopedLock
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    std::cout << "\nbefore:\n";
    d1.printData();
    d2.printData();

    d1.swapWithUniqueLock(d2);

    std::cout << "\nafter:\n";
    d1.printData();
    d2.printData();



    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    std::cout << "\n\nend of main\n";
}