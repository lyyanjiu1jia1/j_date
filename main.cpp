#include <iostream>
#include <since_epoch.h>
#include <vector>

int main()
{
    const std::vector<char> BYE = {'b', 'y', 'e'};
    const auto DURATION_THRESH = 100000000000;
    const SinceEpoch since_epoch;
    std::string input;

    while (true) {
        std::cout << "[INPUT] SAY BYE IF YOU WANT TO LEAVE" << std::endl;

        std::getline(std::cin, input);

        // check bye
        if (input.size() == 3) {
            bool check_bye = true;
            for (std::size_t i = 0; i < 3; ++i) {
                if (std::tolower(input.at(i)) != BYE.at(i)) {
                    check_bye = false;
                }
            }
            if (check_bye) {
                std::cout << "[BYE]" << std::endl;
                break;
            }
        }

        uint64_t j_date;
        try {
            j_date = std::stoll(input);
        } catch (std::invalid_argument&) {
            std::cout << "[INVALID INPUT]\n" << std::endl;
            continue;
        } catch (std::out_of_range&) {
            std::cout << "[TOO LARGE INPUT]\n" << std::endl;
            continue;
        }

        if (j_date <= DURATION_THRESH) {
            std::cout << "[TOO SMALL INPUT]\n" << std::endl;
            continue;
        }

        try {
            std::string datetime = since_epoch.GetTimePointSinceEpoch(j_date);
            std::cout << "[OUTPUT]\n"
                      << datetime
                      << std::endl;
        } catch (std::out_of_range&) {
            std::cout << "[TOO RECENT INPUT]\n" << std::endl;
        }
    }
    return 0;
}