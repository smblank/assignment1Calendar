#include <iostream>
#include <string>

#include "TradCalendar.h"
#include "NumDaysCalendar.h"

int main() {
    char userCommand;
    std::string userChoice;
    Calendar *calendar;

    std::cout << "Choose a type of calendar (Month/Day or Day-of-Year): " << std::endl;
    getline(std::cin, userChoice);

    if (userChoice == "Month/Day") {
        int userMonth, userDay;
        char slash;
        std::cout << "Enter the starting date (m/d): " << std::endl;
        std::cin >> userMonth >> slash >> userDay;

        if (userMonth < 1 || userMonth > 12 ||
            userDay < 1 || userDay > 31 ||
            (userMonth == 2 && userDay > 28) ||
            ((userMonth == 4 || userMonth == 6 || userMonth == 9 || userMonth == 11) && userDay > 30)) {
                std::cout << "Invalid Input" << std::endl;
                return -1;
            }

        calendar = new TradCalendar(userMonth, userDay);
    }

    else if (userChoice == "Day-of-Year") {
        int userDays;
        std::cout << "Enter the starting date in Day-of-Year format: " << std::endl;
        std::cin >> userDays;

        if (userDays < 0 || userDays > 364) {
            std::cout << "Invalid Input" << std::endl;
            return -1;
        }

        calendar = new NumDaysCalendar(userDays);
    }
    else {
        std::cout << "Invalid Input" << std::endl;
        return -1;
    }

    std::cout << calendar->getMonth() << "/" << calendar->getDay() << std::endl;
    std::cout << "Enter a command: " << std::endl 
            << "\tT - Turn to next day" << std::endl 
            << "\tS - Skip to next month" << std::endl
            << "\tQ - Exit program" << std::endl;

    std::cin >> userCommand;
    while (userCommand != 'Q') {
        if (userCommand == 'T') {
            calendar->goToNextDay();
        }

        else if (userCommand == 'S') {
            calendar->goToNextMonth();
        }

        else if (userCommand != 'Q') {
            std::cout << "Invalid command" << std::endl;
        }

        std::cout << calendar->getMonth() << "/" << calendar->getDay() << std::endl;
        std::cout << "Enter a command: " << std::endl 
            << "\tT - Turn to next day" << std::endl 
            << "\tS - Skip to next month" << std::endl
            << "\tQ - Exit program" << std::endl;

        std::cin >> userCommand;
    }

    return 0;
}