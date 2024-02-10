﻿// Домашнее задание к занятию «Многопоточность»
// Задание 1.Очередь клиентов

#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <atomic>

int maxClients = 5;
std::atomic_int clientCounter = 0;

void clientThread() {
    while (clientCounter < maxClients)
    {
        //std::this_thread::sleep_for(std::chrono::milliseconds (50));
        ++clientCounter;
        std::cout << "Client joined, total clients +1: " << clientCounter << std::endl;
    }
}

void operatorThread() {
    while (true) {
        //std::this_thread::sleep_for(std::chrono::milliseconds(101));
        if (clientCounter > 0)
        { 
            --clientCounter;
            std::cout << "The operator served the client. Number of clients -1: " << clientCounter << std::endl; }
        else
        {
            std::cout << "The operator has finished his work. Number of clients 0: " << clientCounter << std::endl;
            break;
        }
    }
}

int main() {
    std::thread client(clientThread);
    std::thread operatorT(operatorThread);

    client.join();
    operatorT.join();

    return 0;
}