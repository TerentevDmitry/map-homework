// Домашнее задание к занятию «Конкуренция, состояние гонки»
// Задание 2. Прогресс-бар

#include "Timer.h"
#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::once_flag flag;
std::mutex m1;
std::mutex m2;
std::mutex m3;
std::mutex m4;

static void tableHeader() { std::cout << "#\t" << "id\t" << "Progress Bar\t" << "Time" << std::endl; }


static void progressBar(const int numberThreadsNow)
{
    
    int progress = 15;
    int total = 25;
    int PositionForTime = 35;
    
    std::call_once(flag, tableHeader);    
    

    m2.lock();
    Timer t1;
    consol_parameter d1;
    m2.unlock();

    while (progress < total)
    {
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        m1.lock();
        d1.SetPosition(progress, numberThreadsNow + 1);

        std::cout << char(178);
        //std::cout << '\b';
        
        //std::cout << char(219);
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        
        ++progress;
        m1.unlock();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(333));
    
    m3.lock();
    d1.SetPosition(35, numberThreadsNow + 1);
    t1.print();
    
    m3.unlock();
  
    
    //std::cout << "\n\n\n\n";
}

int main()
{
    int countThreads = 3;
    std::vector<std::thread> vectorThreads(countThreads);
    
    for (size_t i = 0; i < countThreads; i++)
    {
        vectorThreads[i] = std::thread(progressBar, i);
    }
    for (auto& i : vectorThreads)
    {
        i.join();
        
    }
    std::cout << "\n\n\n\nENENE";
}