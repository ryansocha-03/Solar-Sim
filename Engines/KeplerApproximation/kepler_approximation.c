#include "planets.h"

double getKeplerT(double julianEphemerisDate) {
    const double T_SUBTRACTOR = 2451545.0;
    const double T_DIVISOR = 36525.0;
    return (julianEphemerisDate - T_SUBTRACTOR) / T_DIVISOR;
}

void getCurrentElements(Planet *planet, double T) {
    planet->currentKElements.semi_major_axis = planet->kElements.semi_major_axis + planet->kRates.semi_major_axis * T;
    planet->currentKElements.eccentricity = planet->kElements.eccentricity + planet->kRates.eccentricity * T;
    planet->currentKElements.inclination = planet->kElements.inclination + planet->kRates.inclination * T;
    planet->currentKElements.mean_longitude = planet->kElements.mean_longitude + planet->kRates.mean_longitude * T;
    planet->currentKElements.longitude_perihelion = planet->kElements.longitude_perihelion + planet->kRates.longitude_perihelion * T;
    planet->currentKElements.longitude_ascending_node = planet->kElements.longitude_ascending_node + planet->kRates.longitude_ascending_node * T;
}

