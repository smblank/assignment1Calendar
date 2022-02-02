#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar{
    public:
        virtual void goToNextMonth() = 0;
        virtual void goToNextDay() = 0;
        virtual int getMonth() = 0;
        virtual int getDay() = 0;
};

#endif