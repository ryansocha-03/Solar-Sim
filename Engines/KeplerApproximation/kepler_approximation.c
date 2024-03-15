#include "planets.h"
#include "math.h"
#include "../util/util_math.h"
#include <stdio.h>

double calcKeplerT(double julianEphemerisDate) {
    const double T_SUBTRACTOR = 2451545.0;
    const double T_DIVISOR = 36525.0;
    return (julianEphemerisDate - T_SUBTRACTOR) / T_DIVISOR;
}

void calcCurrentElements(Planet *planet, double T) {
    planet->current_k_elements.semi_major_axis = planet->k_elements.semi_major_axis + planet->k_rates.semi_major_axis * T;
    planet->current_k_elements.eccentricity = planet->k_elements.eccentricity + planet->k_rates.eccentricity * T;
    planet->current_k_elements.inclination = planet->k_elements.inclination + planet->k_rates.inclination * T;
    planet->current_k_elements.mean_longitude = planet->k_elements.mean_longitude + planet->k_rates.mean_longitude * T;
    planet->current_k_elements.longitude_perihelion = planet->k_elements.longitude_perihelion + planet->k_rates.longitude_perihelion * T;
    planet->current_k_elements.longitude_ascending_node = planet->k_elements.longitude_ascending_node + planet->k_rates.longitude_ascending_node * T;
}

void calcArgumentPerihelion(Planet *planet) {
    planet->argument_perihelion = planet->current_k_elements.longitude_perihelion - planet->current_k_elements.longitude_ascending_node;
}

void calcMeanAnomaly(Planet *planet, double T) {
    double additionalTrigTerms = planet->additional_terms.c * radiansToDegrees((planet->additional_terms.f * T)) + planet->additional_terms.s * radiansToDegrees((planet->additional_terms.f * T));
    planet->mean_anomaly = planet->current_k_elements.mean_longitude - planet->current_k_elements.longitude_perihelion + (planet->additional_terms.b * (T * T)) + additionalTrigTerms;
}

void calcEccentricAnomaly(Planet *planet) {
    double mod_mean_anomaly;
    if (planet->mean_anomaly <= 0) {
        mod_mean_anomaly = fmod(planet->mean_anomaly, -180.0);
    } else {
        mod_mean_anomaly = fmod(planet->mean_anomaly, 180.0);
    }
    double deg_e = radiansToDegrees(planet->current_k_elements.eccentricity);

    //deg e is the eccentricity in degrees. Mod mean anomaly is the mean anomaly in degrees modded to be between -180 and 180.
    double e_n = mod_mean_anomaly - deg_e * radiansToDegrees(sin(degreesToRadians(mod_mean_anomaly)));
    const double STOP = 0.000001;
    double delta_e = 1.0;
    double delta_m;
   
    int iterations = 0;
    while(fabs(delta_e) > STOP) {
        iterations += 1;
        delta_m = mod_mean_anomaly - (e_n - deg_e * radiansToDegrees(sin(degreesToRadians(e_n))));
        delta_e = delta_m / (1 - deg_e * radiansToDegrees(cos(degreesToRadians(e_n))));
        e_n = e_n + delta_e;
    }
    //printf("Number of iterations: %d\n", iterations);
    planet->eccentric_anomaly = e_n;
}

void calcHeliocentricCoords(Planet *planet) {
    planet->heliocentric_coordinates.x = planet->current_k_elements.semi_major_axis * (radiansToDegrees(cos(degreesToRadians(planet->eccentric_anomaly))) - planet->current_k_elements.eccentricity);
    planet->heliocentric_coordinates.y = planet->current_k_elements.semi_major_axis * sqrt(1 - planet->current_k_elements.eccentricity * planet->current_k_elements.eccentricity) * radiansToDegrees(sin(degreesToRadians(planet->eccentric_anomaly)));
    planet->heliocentric_coordinates.z = 0.0;
}


