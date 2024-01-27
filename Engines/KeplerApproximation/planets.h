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
    double argument_perihelion;
    double mean_anomaly;
} Planet;

#endif


                          