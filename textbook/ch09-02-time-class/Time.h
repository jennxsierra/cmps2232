#ifndef CMPS2232_TIME_H
#define CMPS2232_TIME_H

class Time {
public:
    Time();
    void setTime(int, int, int);
    void printUniversal();
    void printStandard();

private:
    int hour;
    int minute;
    int second;
};

#endif //CMPS2232_TIME_H