//
// Created by Yang Liu on 2022/12/7.
//

#include "since_epoch.h"

SinceEpoch::SinceEpoch():
            ONE_DAY(std::chrono::hours(24)),
            ONE_HOUR(std::chrono::hours(1)),
            ONE_MINUTE(std::chrono::minutes(1))
{}

std::string SinceEpoch::GetTimePointSinceEpoch(const uint64_t& target) {
    auto cur_tp = std::chrono::system_clock::now();

    uint64_t cur_duration;

    // day-wise search
    do {
        cur_tp = cur_tp - ONE_DAY;
        cur_duration = getDurationSinceEpoch(cur_tp);
    } while (cur_duration > target);
    cur_tp = cur_tp + ONE_DAY;

    // hour-wise search
    do {
        cur_tp = cur_tp - ONE_HOUR;
        cur_duration = getDurationSinceEpoch(cur_tp);
    } while (cur_duration > target);
    cur_tp = cur_tp + ONE_HOUR;


    // minute-wise search
    do {
        cur_tp = cur_tp - ONE_MINUTE;
        cur_duration = getDurationSinceEpoch(cur_tp);
    } while (cur_duration > target);
    cur_tp = cur_tp + ONE_MINUTE;

    return {getHumanReadable(cur_tp)};
}

char* SinceEpoch::getHumanReadable(TimePoint tp) {
    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    return std::ctime(&time);
}

uint64_t SinceEpoch::getDurationSinceEpoch(const TimePoint& tp) {
    uint64_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();
    return duration;
}
