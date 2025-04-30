#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <thread>
#include <mutex>
#include <queue>
#include <sstream>
#include <filesystem>

const int NUM_THREADS = 1;
const int BATCH_SIZE = 10000000 / NUM_THREADS;
std::mutex outputMutex;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void processNumbers(const std::vector<int>& numbers, int threadId) {
    std::stringstream filename;
    filename << "prime_numbers_thread_" << threadId << ".txt";
    std::ofstream outputFile(filename.str());
    
    if (!outputFile.is_open()) {
        std::cerr << "Thread " << threadId << " cikti dosyasi acilamadi!" << std::endl;
        return;
    }
    
    for (int number : numbers) {
        if (isPrime(number)) {
            outputFile << number << std::endl;
        }
    }
    
    outputFile.close();
}

int main() {
    std::ifstream inputFile("10000000.txt");
    
    if (!inputFile.is_open()) {
        std::cerr << "Girdi dosyasi acilamadi!" << std::endl;
        return 1;
    }

    std::vector<std::thread> threads;
    std::vector<std::vector<int>> threadBatches(NUM_THREADS);
    int currentThread = 0;
    
    int number;
    while (inputFile >> number) {
        threadBatches[currentThread].push_back(number);
        
        if (threadBatches[currentThread].size() >= BATCH_SIZE) {
            threads.emplace_back(processNumbers, threadBatches[currentThread], currentThread);
            threadBatches[currentThread].clear();
            currentThread = (currentThread + 1) % NUM_THREADS;
        }
    }
    
    // Process remaining numbers in each thread's batch
    for (int i = 0; i < NUM_THREADS; ++i) {
        if (!threadBatches[i].empty()) {
            threads.emplace_back(processNumbers, threadBatches[i], i);
        }
    }
    
    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
    
    inputFile.close();
    
    std::cout << "Asal sayilar " << NUM_THREADS << " farkli dosyaya yazildi:" << std::endl;
    for (int i = 0; i < NUM_THREADS; ++i) {
        std::cout << "prime_numbers_thread_" << i << ".txt" << std::endl;
    }
    
    return 0;
} 
