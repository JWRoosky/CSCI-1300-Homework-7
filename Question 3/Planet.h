#ifndef PLANET_H
#define PLANET_H

#include <iostream>
using namespace std;

class Planet
{
    private:
        string _planet_name;
        double _planet_radius;
    
    public:
        Planet();
        Planet(string name, double radius);
        string getName();
        void setName(string name);
        double getRadius();
        void setRadius(double radius);
        double getVolume();
};



#endif

