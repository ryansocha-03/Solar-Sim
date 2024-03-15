#ifndef PLANETS_H
#define PLANETS_H

// All of the Kepler elements and their rates are defined in degrees except for eccentricity which is in radians.
// Therefore, whenever you are using C trig functions, you should convert to radians before using them (again eccentricity is the exception).
typedef struct KeplerParameters {
    double semi_major_axis;
    double eccentricity;
    double inclination;
    double mean_longitude;
    double longitude_perihelion;
    double longitude_ascending_node;
} KeplerParameters;

typedef struct Coordinates {
    double x;
    double y;
    double z;
} Coordinates;

typedef struct AdditionalTerms {
    double b;
    double c;
    double s;
    double f;
} AdditionalTerms;

typedef struct Planet {
    KeplerParameters k_elements;
    KeplerParameters k_rates; 
    KeplerParameters current_k_elements;
    AdditionalTerms additional_terms;
    Coordinates heliocentric_coordinates;
    double argument_perihelion;
    double mean_anomaly;
    double eccentric_anomaly;
} Planet;

#endif


                          