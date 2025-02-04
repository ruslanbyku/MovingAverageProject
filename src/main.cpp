#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>

#include "moving_average.h"
#include "random_generator.h"

// #define NDEBUG

static const int dataSize      = 1'000'000;
static const int windowSizes[] = { 4, 8, 16, 32, 64, 128 };

template <typename T>
void printVector(const std::vector<T>& data)
{
    for (const auto& value : data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
};

void calculateMovingAverageForDouble()
{
    RandomGenerator<double> randomGenerator;
    std::vector<double>     inputData =
        randomGenerator.generateRandomInput(dataSize); // Time: O(dataSize)
    // printVector<double>(inputData);

    for (auto windowSize : windowSizes) { // Time: O(1)

        MovingAverage<double> movingAverage(windowSize); // Time: O(windowSize) ~ O(1)
        std::vector<double>   outputData(dataSize); // Time: O(dataSize)

        std::chrono::steady_clock::time_point begin =
            std::chrono::steady_clock::now();
        for (int idx = 0; idx < dataSize; ++idx) { // Time: O(dataSize)
            outputData[idx] = movingAverage.calculate(inputData[idx]); // Time: O(1)
        }
        std::chrono::steady_clock::time_point end =
            std::chrono::steady_clock::now();
        // printVector<double>(outputData);

        auto elapsedTime =
            std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

        std::cerr << "Elements(double)/windowSize[" << dataSize
                  << "/" << windowSize << "] - " << elapsedTime
                  << " us" << std::endl;

        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// The Time complexity is the same as for `calculateMovingAverageForDouble()`
void calculateMovingAverageForFloat()
{
    RandomGenerator<float> randomGenerator;
    std::vector<float>     inputData =
        randomGenerator.generateRandomInput(dataSize);
    // printVector<float>(inputData);

    for (auto windowSize : windowSizes) {

        MovingAverage<float> movingAverage(windowSize);
        std::vector<float>   outputData(dataSize);

        std::chrono::steady_clock::time_point begin =
            std::chrono::steady_clock::now();
        for (int idx = 0; idx < dataSize; ++idx) {
            outputData[idx] = movingAverage.calculate(inputData[idx]);
        }
        std::chrono::steady_clock::time_point end =
            std::chrono::steady_clock::now();
        // printVector<float>(outputData);

        auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

        std::cerr << "Elements(float)/windowSize[" << dataSize
                  << "/" << windowSize << "] - " << elapsedTime
                  << " us" << std::endl;

        // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void testMovingAverage();

int main(int argc, char** argv)
{
    testMovingAverage();

    calculateMovingAverageForDouble();
    calculateMovingAverageForFloat();

    return 0;
}

//
// TESTS
//

// Test the double type
void testMovingAverage()
{
    const int           testDataSize = 10;
    std::vector<double> inputData    = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };

    {
        const int windowSize = 4;

        MovingAverage<double> movingAverage(windowSize);
        std::vector<double>   outputData(testDataSize);
        for (int idx = 0; idx < testDataSize; ++idx) {
            outputData[idx] = movingAverage.calculate(inputData[idx]);
        }
        // printVector<double>(outputData);

        const std::vector<double> expectedResult = { 1.0, 1.5, 2.0, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5 };

        for (int i = 0; i < testDataSize; ++i) {
            assert(("Failed, values do not match!", outputData[i] == expectedResult[i]));
        }

        std::cout << "Test for window size of " << windowSize << " passed" << std::endl;
    }

    {
        const int windowSize = 8;

        MovingAverage<double> movingAverage(windowSize);
        std::vector<double>   outputData(testDataSize);
        for (int idx = 0; idx < testDataSize; ++idx) {
            outputData[idx] = movingAverage.calculate(inputData[idx]);
        }
        // printVector<double>(outputData);

        const std::vector<double> expectedResult = { 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.5, 6.5 };

        for (int i = 0; i < testDataSize; ++i) {
            assert(("Failed, values do not match!", outputData[i] == expectedResult[i]));
        }

        std::cout << "Test for window size of " << windowSize << " passed" << std::endl;
    }

    {
        const int windowSize = 16;

        MovingAverage<double> movingAverage(windowSize);
        std::vector<double>   outputData(testDataSize);
        for (int idx = 0; idx < testDataSize; ++idx) {
            outputData[idx] = movingAverage.calculate(inputData[idx]);
        }
        // printVector<double>(outputData);

        const std::vector<double> expectedResult = { 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5 };

        for (int i = 0; i < testDataSize; ++i) {
            assert(("Failed, values do not match!", outputData[i] == expectedResult[i]));
        }

        std::cout << "Test for window size of " << windowSize << " passed" << std::endl;
    }

    // Tests for window sizes 32, 64 and 128 will be the same as with 16.
}
