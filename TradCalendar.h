#ifndef TRAD_CALENDAR_H
#define TRAD_CALENDAR_H

#include "Calendar.h"

class TradCalendar: public Calendar {
    /**
        @invariant 1 <= month <= 12 and
                    1 <= day <= 31 and
                    (if month == 4, 6, 9 or 11 then day <= 30) and
                    (if month == 2 then day <= 28)
    */
    private:
        int month;
        int day;


    public:
        /**
        @pre 1 <= m <= 12 and
            1 <= d <= 31 and
            (if m == 4, 6, 9, or 11 then d <= 30) and
            (if m == 2 then d <= 28)
        @post month = m and
            day = d
        */
        TradCalendar(int m, int d);

        /**
        @post (if month < 12 then month += 1
                else month = 1) and
            day = 1
        */
        void goToNextMonth();

        /**
        @post if [day is at the maximum day for corresponding month] then
                (if month < 12 then month +=1 else month = 1) and
                day = 1
            else day += 1
        */
        void goToNextDay();


        /**
        @post getMonth = month
        */
        int getMonth();

        /**
        @post getDay = day
        */
        int getDay();
};

#endif