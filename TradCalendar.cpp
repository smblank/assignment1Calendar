#include "TradCalendar.h"

TradCalendar::TradCalendar(int m, int d) {
    month = m;
    day = d;
}

void TradCalendar::goToNextMonth() {
    //Loop around to beginning of year
    if (month >= 12) {
        month = 1;
    }

    //Move to next month
    else {
        month += 1;
    }

    day = 1;
}

void TradCalendar::goToNextDay() {
    //Last day of February
    if (month == 2 && day == 28) {
        month += 1;
        day = 1;
    }

    //Last day of 30-day months
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) {
        month += 1;
        day = 1;
    }

    //Last day of 31-day months
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31) {
        //Loop around for December
        if (month == 12) {
            month = 1;
        }
        
        else {
            month += 1;
        }
        day = 1;
    }

    else {
        day += 1;
    }
}


int TradCalendar::getMonth() {
    return month;
}

int TradCalendar::getDay() {
    return day;
}