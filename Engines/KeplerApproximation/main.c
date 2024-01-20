#include <emscripten.h>
#include <stdio.h>
#include "JulianDate.h"

EMSCRIPTEN_KEEPALIVE
int* KeplerEngine(int a, int b) {
    int result[2];
    result[0] = a;
    double julianDate = getJulianDate();
    printf("%.6f\n", julianDate);
    result[1] = b * 4;
    return result;
}
