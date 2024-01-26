#include <emscripten.h>
#include <stdio.h>
#include "../util/julian_date.h"
#include "planets.h"
#include "kepler_approximation.h"

EMSCRIPTEN_KEEPALIVE
double* KeplerEngine(int a, int b) {
    Planet mercury = { .kElements.semi_major_axis = 0.38709927, .kElements.eccentricity = 0.20563593, .kElements.inclination = 7.00497902, .kElements.mean_longitude = 252.25032350, .kElements.longitude_perihelion = 77.45779628, .kElements.longitude_ascending_node = 48.33076593, .kRates.semi_major_axis = 0.00000037, .kRates.eccentricity = 0.00001906, .kRates.inclination = -0.00594749, .kRates.mean_longitude = 149472.67411175, .kRates.longitude_perihelion = 0.16047689, .kRates.longitude_ascending_node = -0.12534081 };
    Planet venus = { .kElements.semi_major_axis = 0.72333566, .kElements.eccentricity = 0.00677672, .kElements.inclination = 3.39467605, .kElements.mean_longitude = 181.97909950, .kElements.longitude_perihelion = 131.60246718, .kElements.longitude_ascending_node = 76.67984255, .kRates.semi_major_axis = 0.00000390, .kRates.eccentricity = -0.00004107, .kRates.inclination = -0.00078890, .kRates.mean_longitude = 58517.81538729, .kRates.longitude_perihelion = 0.00268329, .kRates.longitude_ascending_node = -0.27769418 };
    Planet earth = { .kElements.semi_major_axis = 1.00000261, .kElements.eccentricity = 0.01671123, .kElements.inclination = -0.00001531, .kElements.mean_longitude = 100.46457166, .kElements.longitude_perihelion = 102.93768193, .kElements.longitude_ascending_node = 0.0, .kRates.semi_major_axis = 0.00000562, .kRates.eccentricity = -0.00004392, .kRates.inclination = -0.01294668, .kRates.mean_longitude = 35999.37244981, .kRates.longitude_perihelion = 0.32327364, .kRates.longitude_ascending_node = 0.0 };
    Planet mars = { .kElements.semi_major_axis = 1.52371034, .kElements.eccentricity = 0.09339410, .kElements.inclination = 1.84969142 , .kElements.mean_longitude = -4.55343205, .kElements.longitude_perihelion = -23.94362959, .kElements.longitude_ascending_node = 49.55953891, .kRates.semi_major_axis = 0.00001847, .kRates.eccentricity = 0.00007882, .kRates.inclination = -0.00813131, .kRates.mean_longitude = 19140.30268499, .kRates.longitude_perihelion = 0.44441088, .kRates.longitude_ascending_node = -0.29257343 };
    Planet jupiter = { .kElements.semi_major_axis = 5.20288700, .kElements.eccentricity = 0.04838624, .kElements.inclination = 1.30439695, .kElements.mean_longitude = 34.39644051, .kElements.longitude_perihelion = 14.72847983, .kElements.longitude_ascending_node = 100.47390909, .kRates.semi_major_axis = -0.00011607, .kRates.eccentricity = -0.00013253, .kRates.inclination = -0.00183714, .kRates.mean_longitude = 3034.74612775, .kRates.longitude_perihelion = 0.21252668, .kRates.longitude_ascending_node = 0.20469106 };
    Planet saturn = { .kElements.semi_major_axis = 9.53667594, .kElements.eccentricity = 0.05386179, .kElements.inclination = 2.48599187, .kElements.mean_longitude = 49.95424423, .kElements.longitude_perihelion = 92.59887831, .kElements.longitude_ascending_node = 113.66242448, .kRates.semi_major_axis = -0.00125060, .kRates.eccentricity = -0.00050991, .kRates.inclination = 0.00193609, .kRates.mean_longitude = 1222.49362201, .kRates.longitude_perihelion = -0.41897216, .kRates.longitude_ascending_node = -0.28867794 };
    Planet uranus = { .kElements.semi_major_axis = 19.18916464, .kElements.eccentricity = 0.04725744, .kElements.inclination = 0.77263783, .kElements.mean_longitude = 313.23810451, .kElements.longitude_perihelion = 170.95427630, .kElements.longitude_ascending_node = 74.01692503, .kRates.semi_major_axis = -0.00196176, .kRates.eccentricity = -0.00004397, .kRates.inclination = -0.00242939, .kRates.mean_longitude = 428.48202785, .kRates.longitude_perihelion = 0.40805281, .kRates.longitude_ascending_node = 0.04240589 };
    Planet neptune = { .kElements.semi_major_axis = 30.06992276, .kElements.eccentricity = 0.00859048, .kElements.inclination = 1.77004347, .kElements.mean_longitude = -55.12002969, .kElements.longitude_perihelion = 44.96476227, .kElements.longitude_ascending_node = 131.78422574, .kRates.semi_major_axis = 0.00026291, .kRates.eccentricity = 0.00005105, .kRates.inclination = 0.00035372, .kRates.mean_longitude = 218.45945325, .kRates.longitude_perihelion = -0.32241464, .kRates.longitude_ascending_node = -0.00508664 };

    double result[2];
    double julianEphemerisDate = getJulianEphemerisDate();
    double currentT = getKeplerT(julianEphemerisDate);
    printf("%.6f\n", julianEphemerisDate);
    printf("%.6f\n", currentT);

    printf("%.6f\n", mercury.currentKElements.semi_major_axis);
    getCurrentElements(&mercury, currentT);
    printf("%.6f\n", mercury.currentKElements.semi_major_axis);

    result[0] = julianEphemerisDate;
    result[1] = currentT;
    return result;
}
