/*
Show how structure declarations are used.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLANETSTRLEN 20
#define PLANETPROMPT "name, orbits, distance, mass, radius"

typedef char pstr_t[PLANETSTRLEN+1];

typedef struct {
    pstr_t name, orbits;
    double distance;
    double mass;
    double radius;
} planet_t;

planet_t earth = {"Earth", "Sun", 149.6, 5.9736e+24, 6738.1};
planet_t moon = {"Moon", "Earth", 0.3844, 7.349e+22, 1738.1};

planet_t another_planet;

void print_planet(planet_t one_planet);
planet_t read_planet(void);
int read_planet_ptr(planet_t *one_planet);

int
main(int argc, char *argv[]) {
    planet_t planet;
    planet = read_planet();
    print_planet(planet);

    if (read_planet_ptr(&planet) != EOF) {
        print_planet(planet);
    }    

    return 0;
}

void
print_planet(planet_t one_planet) {
    printf("%s orbits %s\n", one_planet.name, one_planet.orbits);
    printf("\torbital distance is %.2e million km\n", one_planet.distance);
    printf("\tmasss is %.2e kg\n", one_planet.mass);
    printf("\tradius is %.2e km\n", one_planet.radius);
}

planet_t
read_planet(void) {
    planet_t new_planet;
    printf("Enter %s:\n", PLANETPROMPT);
    scanf("%s %s %lf %lf %lf", 
           new_planet.name, 
           new_planet.orbits,
           &new_planet.distance,
           &new_planet.mass,
           &new_planet.radius);
    
    return new_planet; //This will return COPY of new_planet
}

int
read_planet_ptr(planet_t *planet) {
    int nvals_read;
    printf("Enter %s:\n", PLANETPROMPT);
    nvals_read = scanf("%s %s %lf %lf %lf", 
            planet->name,
            planet->orbits,
            &planet->distance,
            &planet->mass,
            &planet->radius);

    if (nvals_read != 5) {
        return EOF;
    } else {
        return 0;
    }
}