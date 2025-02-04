#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_

#include <algorithm>
#include <random>
#include <vector>

template <typename T>
class RandomGenerator
{
public:
    // Time: O(2 * amount) = O(amount)
    // Space: O(amount)
    std::vector<T> generateRandomInput(int amount)
    {
        std::vector<T> inputData(amount); // O(amount)

        std::generate(inputData.begin(),
                      inputData.end(),
                      RandomGenerator::getRandom); // O(amount)

        return inputData;
    }

private:
    //  https://stackoverflow.com/a/21102720
    //  Time: O(1)
    //  Space: O(1)
    static T getRandom()
    {
        const T lowerBound = 0.00001;
        const T upperBound = 1.00001;

        std::uniform_real_distribution<T> unif(lowerBound,
                                               upperBound);

        std::random_device randDev;
        std::mt19937       randEngine(randDev());

        return unif(randEngine);
    }
};

#endif
