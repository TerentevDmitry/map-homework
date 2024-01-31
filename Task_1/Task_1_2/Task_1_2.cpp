// Задание 2
// Параллельные вычисления

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void sumVectors(const std::vector<int>& vector1, const std::vector<int>& vector2, std::vector<int>& sumOfVectors, int begin, int end)
{
    for (int i = begin; i < end; ++i) 
    {
        sumOfVectors[i] = vector1[i] + vector2[i];
    }
}

int main() 
{
    std::cout << "Number of hardware cores: " << std::thread::hardware_concurrency() << "\n\n";
    std::cout << std::setw(9) << "\t\t\t1'000" << "\t   10'000" << "\t  100'000" << "\t1'000'000" << "\n";
    std::cout << "-------------------------------------------------------------------------" << std::endl;
     
    // Creating two vectors
    std::vector<int> vector1;
    std::vector<int> vector2;

    // Vector for storing the result
    std::vector<int> sumOfVectors;

    // Vector for threads
    std::vector<std::thread> threads;

    // Vector for num of threads
    std::vector<int> numOfThreads{ 1, 2, 4, 8, 16 };
    std::vector<int> sizeOfVector{ 1'0, 10'000, 100'000, 1'000'000 };

    for (auto& countT : numOfThreads)
    {
        if (countT == 1)
        {
            std::cout << std::endl << countT << " thread";
        } 
        else 
        {
            std::cout << std::endl << countT << " threads";
        }
        
        for (auto& countV : sizeOfVector)
        {
            vector1.resize(countV, 2);
            vector2.resize(countV, 5);
            sumOfVectors.resize(countV);

            int partOfTheSize = static_cast<int> (countV / countT);
            
            auto thr1_10000_start = std::chrono::high_resolution_clock::now();


            threads.push_back(std::thread(sumVectors, std::ref(vector1), std::ref(vector2), std::ref(sumOfVectors), countT * partOfTheSize, (countT + 1) * partOfTheSize));
            
            
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