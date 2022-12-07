#include <iostream>
#include <chrono>
#include <ctime>

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

class SinceEpoch {
public:
    SinceEpoch():
        ONE_DAY(std::chrono::hours(24)),
        ONE_HOUR(std::chrono::hours(1)),
        ONE_MINUTE(std::chrono::minutes(1))
    {}

    std::string GetTimePointSinceEpoch(const uint64_t& target) {
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

        return std::string(getHumanReadable(cur_tp));
}

private:
    const decltype(std::chrono::hours()) ONE_DAY;
    const decltype(std::chrono::hours()) ONE_HOUR;
    const decltype(std::chrono::minutes()) ONE_MINUTE;

    static char* getHumanReadable(TimePoint tp) {
        std::time_t time = std::chrono::system_clock::to_time_t(tp);
        return std::ctime(&time);
    }

    static uint64_t getDurationSinceEpoch(const TimePoint& tp) {
        uint64_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();
        return duration;
    }
};

int main()
{
    SinceEpoch since_epoch;
    uint64_t j_date;
    while (true) {
        std::cout << "INPUT JS DATE:" << std::endl;
        if (!(std::cin >> j_date)) break;
        std::string datetime = since_epoch.GetTimePointSinceEpoch(j_date);
        std::cout << datetime
                  << "--------------------------------------" << std::endl;
    }
    return 0;
}