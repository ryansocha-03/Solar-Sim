#include <emscripten.h>
#include "JulianDate.h"

EMSCRIPTEN_KEEPALIVE
int* KeplerEngine(int a, int b) {
    int result[2];
    result[0] = a;
    int julianTest = Julian(b);
    result[1] = julianTest;
    return result;
}
