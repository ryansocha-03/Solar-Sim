#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
int* KeplerEngine(int a, int b) {
    int result[2];
    result[0] = a;
    result[1] = b;
    return result;
}