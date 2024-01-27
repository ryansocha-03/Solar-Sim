#include <emscripten.h>
#include <stdio.h>
#include "../util/julian_date.h"
#include "planets.h"
#include "kepler_approximation.h"

EMSCRIPTEN_KEEPALIVE
double* KeplerEngine(int a, int b) {
    Planet mercury = { .k_elements.semi_major_axis = 0.38709927, .k_elements.eccentricity = 0.20563593, .k_elements.inclination = 7.00497902, .k_elements.mean_longitude = 252.25032350, .k_elements.longitude_perihelion = 77.45779628, .k_elements.longitude_ascending_node = 48.33076593, .k_rates.semi_major_axis = 0.00000037, .k_rates.eccentricity = 0.00001906, .k_rates.inclination = -0.00594749, .k_rates.mean_longitude = 149472.67411175, .k_rates.longitude_perihelion = 0.16047689, .k_rates.longitude_ascending_node = -0.12534081, .additional_terms.b = 0.0, .additional_terms.c = 0.0, .additional_terms.s = 0.0, .additional_terms.f = 0.0 };
    Planet venus = { .k_elements.semi_major_axis = 0.72333566, .k_elements.eccentricity = 0.00677672, .k_elements.inclination = 3.39467605, .k_elements.mean_longitude = 181.97909950, .k_elements.longitude_perihelion = 131.60246718, .k_elements.longitude_ascending_node = 76.67984255, .k_rates.semi_major_axis = 0.00000390, .k_rates.eccentricity = -0.00004107, .k_rates.inclination = -0.00078890, .k_rates.mean_longitude = 58517.81538729, .k_rates.longitude_perihelion = 0.00268329, .k_rates.longitude_ascending_node = -0.27769418, .additional_terms.b = 0.0, .additional_terms.c = 0.0, .additional_terms.s = 0.0, .additional_terms.f = 0.0 };
    Planet earth = { .k_elements.semi_major_axis = 1.00000261, .k_elements.eccentricity = 0.01671123, .k_elements.inclination = -0.00001531, .k_elements.mean_longitude = 100.46457166, .k_elements.longitude_perihelion = 102.93768193, .k_elements.longitude_ascending_node = 0.0, .k_rates.semi_major_axis = 0.00000562, .k_rates.eccentricity = -0.00004392, .k_rates.inclination = -0.01294668, .k_rates.mean_longitude = 35999.37244981, .k_rates.longitude_perihelion = 0.32327364, .k_rates.longitude_ascending_node = 0.0, .additional_terms.b = 0.0, .additional_terms.c = 0.0, .additional_terms.s = 0.0, .additional_terms.f = 0.0 };
    Planet mars = { .k_elements.semi_major_axis = 1.52371034, .k_elements.eccentricity = 0.09339410, .k_elements.inclination = 1.84969142 , .k_elements.mean_longitude = -4.55343205, .k_elements.longitude_perihelion = -23.94362959, .k_elements.longitude_ascending_node = 49.55953891, .k_rates.semi_major_axis = 0.00001847, .k_rates.eccentricity = 0.00007882, .k_rates.inclination = -0.00813131, .k_rates.mean_longitude = 19140.30268499, .k_rates.longitude_perihelion = 0.44441088, .k_rates.longitude_ascending_node = -0.29257343, .additional_terms.b = 0.0, .additional_terms.c = 0.0, .additional_terms.s = 0.0, .additional_terms.f = 0.0 };
    Planet jupiter = { .k_elements.semi_major_axis = 5.20288700, .k_elements.eccentricity = 0.04838624, .k_elements.inclination = 1.30439695, .k_elements.mean_longitude = 34.39644051, .k_elements.longitude_perihelion = 14.72847983, .k_elements.longitude_ascending_node = 100.47390909, .k_rates.semi_major_axis = -0.00011607, .k_rates.eccentricity = -0.00013253, .k_rates.inclination = -0.00183714, .k_rates.mean_longitude = 3034.74612775, .k_rates.longitude_perihelion = 0.21252668, .k_rates.longitude_ascending_node = 0.20469106, .additional_terms.b = -0.00012452, .additional_terms.c = 0.06064060, .additional_terms.s = -0.35635438, .additional_terms.f = 38.35125 };
    Planet saturn = { .k_elements.semi_major_axis = 9.53667594, .k_elements.eccentricity = 0.05386179, .k_elements.inclination = 2.48599187, .k_elements.mean_longitude = 49.95424423, .k_elements.longitude_perihelion = 92.59887831, .k_elements.longitude_ascending_node = 113.66242448, .k_rates.semi_major_axis = -0.00125060, .k_rates.eccentricity = -0.00050991, .k_rates.inclination = 0.00193609, .k_rates.mean_longitude = 1222.49362201, .k_rates.longitude_perihelion = -0.41897216, .k_rates.longitude_ascending_node = -0.28867794, .additional_terms.b = 0.00025899, .additional_terms.c = -0.13434469, .additional_terms.s = 0.87320147, .additional_terms.f = 38.35125 };
    Planet uranus = { .k_elements.semi_major_axis = 19.18916464, .k_elements.eccentricity = 0.04725744, .k_elements.inclination = 0.77263783, .k_elements.mean_longitude = 313.23810451, .k_elements.longitude_perihelion = 170.95427630, .k_elements.longitude_ascending_node = 74.01692503, .k_rates.semi_major_axis = -0.00196176, .k_rates.eccentricity = -0.00004397, .k_rates.inclination = -0.00242939, .k_rates.mean_longitude = 428.48202785, .k_rates.longitude_perihelion = 0.40805281, .k_rates.longitude_ascending_node = 0.04240589, .additional_terms.b = 0.00058331, .additional_terms.c = -0.97731848, .additional_terms.s = 0.17689245, .additional_terms.f = 7.67025 };
    Planet neptune = { .k_elements.semi_major_axis = 30.06992276, .k_elements.eccentricity = 0.00859048, .k_elements.inclination = 1.77004347, .k_elements.mean_longitude = -55.12002969, .k_elements.longitude_perihelion = 44.96476227, .k_elements.longitude_ascending_node = 131.78422574, .k_rates.semi_major_axis = 0.00026291, .k_rates.eccentricity = 0.00005105, .k_rates.inclination = 0.00035372, .k_rates.mean_longitude = 218.45945325, .k_rates.longitude_perihelion = -0.32241464, .k_rates.longitude_ascending_node = -0.00508664, .additional_terms.b = -0.00041348, .additional_terms.c = 0.68346318, .additional_terms.s = -0.10162547, .additional_terms.f = 7.67025 };

    double result[2];
    double julianEphemerisDate = calcJulianEphemerisDate();
    double currentT = calcKeplerT(julianEphemerisDate);
    printf("Julian Ephemeris Date:\t\t\t%.6f\n", julianEphemerisDate);
    printf("Argument T:\t\t\t\t\t\t\t%.6f\n", currentT);

    calcCurrentElements(&mercury, currentT);
    printf("Current Semi Major Axis:\t\t%.6f\n", mercury.current_k_elements.semi_major_axis);

    calcArgumentPerihelion(&mercury);
    printf("Argument of Perihelion:\t\t\t%.6f\n", mercury.argument_perihelion);

    calcMeanAnomaly(&mercury, currentT);
    printf("Mean Anomaly:\t\t\t\t\t\t%.6f\n", mercury.mean_anomaly);

    result[0] = julianEphemerisDate;
    result[1] = currentT;
    return result;
}
