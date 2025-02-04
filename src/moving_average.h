#ifndef MOVING_AVERAGE_H_
#define MOVING_AVERAGE_H_

#include <cstdint>
#include <vector>

template <typename T>
class MovingAverage
{
public:
    MovingAverage(int windowSize) : mWindowSize(windowSize),
                                    mCurrSum(0.0),
                                    mValuesProcessedNum(0),
                                    mValues(windowSize, 0) /* O(windowSize) */
    {
    }

    // Time: O(1)
    // Space: O(1)
    T calculate(T value)
    {
        const int currIdx = mValuesProcessedNum % mWindowSize;

        mCurrSum -= mValues[currIdx];
        mCurrSum += value;

        mValues[currIdx] = value;

        mValuesProcessedNum++;

        return mCurrSum / std::min(mValuesProcessedNum,
                                   static_cast<uint64_t>(mWindowSize));
    }

private:
    const int      mWindowSize;
    T              mCurrSum;
    uint64_t       mValuesProcessedNum; // a possible overflow after 2^64 - 1
    std::vector<T> mValues;             // a circular queue
};

#endif
