#include "JulianDate.h"
#include <stdio.h>
#include <time.h>

double getJulianDate() {
    struct tm* terrestrialTime = getCurrentTT();
    printTM(terrestrialTime);
    double julianDate = getJulianDateFromTM(terrestrialTime);

    return julianDate;
}

struct tm* getCurrentTT() {
    //TIA time is exactly 37 seconds ahead of UTC time as of 1/14/2024. I leap second is added each leap year on leap day.
    //TT is exactly 32.184 seconds ahead of TIA (Does not change). So, a total of 69.184 seconds need to be added. Only adding
    //69 seconds for now.
    time_t utcSeconds = time(NULL);
    utcSeconds += 69;
    return gmtime(&utcSeconds);
}

double getJulianDateFromTM(struct tm* TT) {
    const int MINUTESINHOUR = 60;
    const int SECONDSINHOUR = 3600;

    int year = TT->tm_year + 1900;
    int month = TT->tm_mon + 1;
    double julianTimeDecimal = ((double)TT->tm_hour + ((double)TT->tm_min / MINUTESINHOUR) + ((double)TT->tm_sec / SECONDSINHOUR)) / 24;
    return (double)((367 * year) - ((7 * (year + ((month + 9) / 12))) / 4) + (275 * month / 9) + TT->tm_mday + 1721013.5) + julianTimeDecimal;
}

void printTM(struct tm* value) {
    printf("%d/%d/%d %d:%d:%d\n", value->tm_mon, value->tm_mday, value->tm_year+1900, value->tm_hour, value->tm_min, value->tm_sec);
}
