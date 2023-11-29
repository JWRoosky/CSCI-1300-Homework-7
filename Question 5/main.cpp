#include "Player.h"

int main() {
    Candy test{"brown candy", "candy born from mud", 1.01, "Buff"};
    Candy test2{"striped candy", "This candy dropped from the rainbow", 2.02, "Chance"};   
    Candy c[3] = {test, test2, test2};
    Player player = {5, 100, "Start of game", c, 3};
    player.printInventory();    
}s