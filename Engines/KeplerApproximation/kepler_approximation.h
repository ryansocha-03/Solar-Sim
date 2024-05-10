#ifndef KEPLER_APPROXIMATION_H
#define KEPLER_APPROXIMATION_H

#include "planets.h"

double calcKeplerT(double);

void calcCurrentElements(Planet*, double);

void calcArgumentPerihelion(Planet*);

void calcMeanAnomaly(Planet*, double);

void calcEccentricAnomaly(Planet*);

void calcHeliocentricCoords(Planet*);

#endif