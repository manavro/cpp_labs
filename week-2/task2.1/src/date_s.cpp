#include <ctime>

time_t date(int year, int mon, int day) {

        struct tm datetime;
        time_t timestamp;

        datetime.tm_year = year - 1900;
        datetime.tm_mon = mon - 1;
        datetime.tm_mday = day;
        datetime.tm_hour = 12;
        datetime.tm_min = 30;
        datetime.tm_sec = 1;
        return mktime(&datetime);


}
