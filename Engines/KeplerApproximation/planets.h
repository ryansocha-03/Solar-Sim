#ifndef PLANETS_H
#define PLANETS_H

typedef struct KeplerParameters {
    double semi_major_axis;
    double eccentricity;
    double inclination;
    double mean_longitude;
    double longitude_perihelion;
    double longitude_ascending_node;
} KeplerParameters;

typedef struct Planet {
    KeplerParameters kElements;
    KeplerParameters kRates; 
    KeplerParameters currentKElements;
} Planet;

#endif


                          