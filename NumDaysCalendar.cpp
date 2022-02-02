#include "NumDaysCalendar.h"

#include <iostream>

NumDaysCalendar::NumDaysCalendar(int d) {
    numDays = d;
}

void NumDaysCalendar::goToNextMonth() {
    int tempDays = numDays;
    int i;
    //Get to current month
    for (i = 0; tempDays > daysInMonth[i]; ++i) {
        tempDays -= daysInMonth[i];
    }
    
    int daysToNextMonth = daysInMonth[i] - tempDays;

    numDays += daysToNextMonth + 1;

    if (numDays > 364) {
        numDays = 0;
    }
}

void NumDaysCalendar::goToNextDay() {
    //Loop to beginning of the year
    if (numDays >= 364) {
        numDays = 0;
    }

    else {
        numDays += 1;
    }
}


int NumDaysCalendar::getMonth() {
    int tempDays = numDays;
    int i;
    //Get to current month
    for (i = 0; tempDays > daysInMonth[i]; ++i) {
        tempDays -= daysInMonth[i];
    }

    return i + 1;
}

int NumDaysCalendar::getDay() {
    int tempDays = numDays;
    int i;
    //Get to current month
    for (i = 0; tempDays > daysInMonth[i]; ++i) {
        tempDays -= daysInMonth[i];
    }
    
    //Return numbered day
    if (i == 0) {
        return tempDays + 1;
    }
    else {
        return tempDays;
    }
}