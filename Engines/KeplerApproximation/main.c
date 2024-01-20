#include <emscripten.h>
#include <stdio.h>
#include "../util/JulianDate.h"
#include "../util/Planets.h"

EMSCRIPTEN_KEEPALIVE
int* KeplerEngine(int a, int b) {
    int result[2];
    result[0] = a;
    double julianDate = getJulianEphemerisDate();
    printf("%.6f\n", julianDate);

    printf("%.8f\n", mercury.kElements.semi_major_axis);

    result[1] = b * 4;
    return result;
}
