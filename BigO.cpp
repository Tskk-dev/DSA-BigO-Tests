// BSIT 2-2 Tskk-Dev
// Licensed under GPL 3.0

#include <iostream>
#include <chrono>
#include <iomanip>

// Measure time complexity fragments using different growth rates 
// (N being used on the activity which this was required in, substituted using the contstant bellow).


const int TEST_SIZES[] = {5, 10, 20, 40, 80}; // change this value to change growth rates for each function
const int NUM_SIZES = sizeof(TEST_SIZES) / sizeof(TEST_SIZES[0]);

// Measure O(n) runtime
long long measure_linear(int n) {
    long long sum = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        sum++;
    }

    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// Measure O(n^3) runtime
long long measure_cubic(int n) {
    long long sum = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * n; j++) {
            sum++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

// Measure O(n^5) runtime
long long measure_quintic(int n) {
    long long sum = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i * i; j++) {
            for (int k = 0; k < j; k++) {
                sum++;
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

int main() {
    std::cout << std::left << std::setw(10) << "n"
              << std::setw(25) << "O(n)"
              << std::setw(25) << "O(n^3)"
              << std::setw(25) << "O(n^5)" << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    for (int s = 0; s < NUM_SIZES; s++) {
        int n = TEST_SIZES[s];
        long long t_linear = measure_linear(n);
        long long t_cubic = measure_cubic(n);
        long long t_quintic = measure_quintic(n);

        std::cout << std::left << std::setw(10) << n
                  << std::setw(25) << (std::to_string(t_linear) + " us")
                  << std::setw(25) << (std::to_string(t_cubic) + " us")
                  << std::setw(25) << (std::to_string(t_quintic) + " us")
                  << std::endl;
    }

    return 0;
}
