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

int main(int argc, char** argv)
{
    return 0;
}
