#include <cassert>
#include <iostream>

#include "moving_average.h"
#include "random_generator.h"

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

void testMovingAverage();

int main(int argc, char** argv)
{
    testMovingAverage();

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
