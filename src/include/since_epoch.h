//
// Created by Yang Liu on 2022/12/7.
//

#ifndef JDATE_CONVERSION_SINCE_EPOCH_H
#define JDATE_CONVERSION_SINCE_EPOCH_H

#include <iostream>
#include <chrono>
#include <ctime>

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

class SinceEpoch {
public:
    SinceEpoch();
    std::string GetTimePointSinceEpoch(const uint64_t& target);

private:
    const decltype(std::chrono::hours()) ONE_DAY;
    const decltype(std::chrono::hours()) ONE_HOUR;
    const decltype(std::chrono::minutes()) ONE_MINUTE;

    static char* getHumanReadable(TimePoint tp);
    static uint64_t getDurationSinceEpoch(const TimePoint& tp);
};

#endif //JDATE_CONVERSION_SINCE_EPOCH_H
