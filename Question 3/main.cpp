#include "Planet.h"

int maxRadius(Planet planet_array[], const int PLANET_ARRAY_SIZE){
    double max = planet_array[0].getRadius();
    int max_index = 0;
    if (PLANET_ARRAY_SIZE < 1){
        return -1;
    }
    for (int i = 1; i < PLANET_ARRAY_SIZE; i++){
        if (planet_array[i].getRadius() > max){
            max = planet_array[i].getRadius();
            max_index = i;
        }
    }
    return max_index;
}

int main(){
    Planet planets[3];
    planets[0] = Planet("Planet Squanch",6.8);
    planets[1] = Planet("Delphi 6",8.6);
    planets[2] = Planet("Cronenberg World",8.6);
    int idx = maxRadius(planets, 3);
    cout << planets[idx].getName() << endl;
    cout << planets[idx].getRadius() << endl;
    cout << planets[idx].getVolume() << endl;
}