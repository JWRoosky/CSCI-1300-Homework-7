#ifndef CANDY_H
#define CANDY_H

#include <iostream>
using namespace std;

struct Candy {
    string name;
    string description;
    double price;
    string candy_type;
};

class Player {
    private:
        const static int _MAX_CANDY_AMOUNT = 4;
        int _stamina;
        double _gold;
        string _effect;
        Candy _inventory[_MAX_CANDY_AMOUNT];
        int _candy_amount = 0;
    public:
        Player();
        Player(int stamina, double gold, string effect, Candy inventory[], const int CANDY_ARR_SIZE);

        // Accessors
        int getCandyAmount() const;
        int getStamina() const;
        double getGold() const;
        string getEffect() const;

        // Mutators
        void setStamina(int stamina);
        void setGold(double gold);
        void setEffect(string effect);

        // Functional
        void printInventory();
        Candy findCandy(string candy_name);
        bool addCandy(Candy candy);
        bool removeCandy(string candy_name);
};

#endif