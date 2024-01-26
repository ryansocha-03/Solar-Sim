#ifndef JULIAN_DATE_H
#define JULIAN_DATE_H

#include <time.h>

double getJulianEphemerisDate();

double getJulianDateFromTM(struct tm*);

struct tm *getCurrentTT();

void printTM(struct tm*);

#endif
