#ifndef JULIAN_DATE_H
#define JULIAN_DATE_H

#include <time.h>

double calcJulianEphemerisDate();

double calcJulianDateFromTM(struct tm*);

struct tm *calcCurrentTT();

void printTM(struct tm*);

#endif
