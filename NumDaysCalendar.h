#ifndef NUM_DAYS_CALENDAR_H
#define NUM_DAYS_CALENDAR_H

#include "Calendar.h"

class NumDaysCalendar: public Calendar{
    /**
        @invariant 0 <= numDays <= 364 and
                   daysInMonth[2, 4, 6, 7, 9, 11] = 31 and
                   daysInMonth[0, 3, 5, 8, 10] = 30 and
                   daysInMonth[1] = 28
    */
    private:
        int numDays;
        int const daysInMonth[12] = {30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    public:
        /**
            @pre 0 <= d <= 364
            @post numDays = d
        */
        NumDaysCalendar(int d);
        
        /**
            @post numDays += daysInMonth[i] + j where
                    [daysInMonth[i] is the last element of array that could not be subtracted from numDays] and
                    j = numDays - daysInMonth[k] where numDays > daysInMonth[k]
        */
        void goToNextMonth();
        
        /**
            @post if numDays < 364 then numDays += 1
                    else numDays = 0
        */
        void goToNextDay();
        

        /**
            @post getMonth = i where [i is the index of the element in daysInMonth that could not be subtracted from numDays]
        */
        int getMonth();
        
        /**
            @post getDay = numDays - daysInMonth[i] while numDays > daysInMonth[i]
        */
        int getDay();
};

#endif