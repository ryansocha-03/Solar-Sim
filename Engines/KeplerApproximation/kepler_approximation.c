#include "planets.h"
#include "math.h"

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
    double additionalTrigTerms = (planet->additional_terms.c * cos(planet->additional_terms.f * T)) + (planet->additional_terms.s * sin(planet->additional_terms.f * T));
    planet->mean_anomaly = planet->current_k_elements.mean_longitude - planet->current_k_elements.longitude_perihelion + (planet->additional_terms.b * (T * T)) + additionalTrigTerms;
}



