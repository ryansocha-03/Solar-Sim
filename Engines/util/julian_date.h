#ifndef JULIAN_DATE_H
#define JULIAN_DATE_H

#include <time.h>

double calcJulianEphemerisDate(long long requestedTime);

double calcJulianDateFromTM(struct tm*);

struct tm *calcCurrentTT(long long requestedTime);

void printTM(struct tm*);

#endif
