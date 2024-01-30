// Задание 2
// Параллельные вычисления

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void sumVectors(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& result, int begin, int end) 
{
    for (int i = begin; i < end; ++i) 
    {
        result[i] = v1[i] + v2[i];
    }
}

int main() 
{
    std::cout << "Number of hardware cores: " << std::thread::hardware_concurrency() << "\n\n";
    std::cout << std::setw(9) << "\t\t\t1'000" << "\t   10'000" << "\t  100'000" << "\t1'000'000" << "\n";
    std::cout << "-------------------------------------------------------------------------" << std::endl;
     
    // Creating two vectors
    //size_t sizeOfVector = 1'000;
    std::vector<int> vector1;
    std::vector<int> vector2;

    // Vector for storing the result
    std::vector<int> sumOfVectors;

    // Vector for threads
    std::vector<std::thread> threads;

    // Vector for num of threads
    std::vector<int> numOfThreads{ 1, 2, 4, 8, 16 };
    std::vector<int> sizeOfVector{ 1'000, 10'000, 100'000, 1'000'000 };



    // Creating threads for vector summation
    for (int j = 0; j < numOfThreads[j]; j++)
    {
        std::cout << std::endl << numOfThreads[j] << " threads";
        threads.clear();
        
        
        for (int i = 0; i < sizeOfVector[i]; i++)
        {
            
            //int num_threads = 1;
            vector1.resize(sizeOfVector[i]);
            vector2.resize(sizeOfVector[i]);
            sumOfVectors.resize(sizeOfVector[i]);
            
            //threads.reserve(0);
            int chunk_size = sizeOfVector[i] / numOfThreads[j];
            auto thr1_10000_start = std::chrono::high_resolution_clock::now();
            threads.push_back(std::thread(sumVectors, std::ref(vector1), std::ref(vector2), std::ref(sumOfVectors), i * chunk_size, (i + 1) * chunk_size));
            auto thr1_10000_stop = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> thr1_10000_time = thr1_10000_stop - thr1_10000_start;
            std::cout << std::setw(9) << "\t" << thr1_10000_time.count() << "ms";

            
        }
        for (auto& it : threads)
        {
            it.join();
        }
        
    }


    std::cout << "\n\n";
    return 0;
}