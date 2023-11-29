#include "Player.h"
#include <limits>

void clearInputBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void playRockPaperScissors(Player players[2]) {
    if (players[0].getCandyAmount() == 0 || players[1].getCandyAmount() == 0){
        cout << "Not enough candy!" << endl;
        return;
    }

    string player1_bet;
    cout << "Player 1 Inventory" << endl;
    players[0].printInventory();
    cout << "Player 1: Select candy to bet" << endl;
    do {
        getline(cin, player1_bet);
        if (players[0].findCandy(player1_bet).name == ""){
            cout << "Invalid selection!" << endl;
        }
    } while (players[0].findCandy(player1_bet).name == "");

    string player2_bet;
    cout << "Player 2 Inventory" << endl;
    players[1].printInventory();
    cout << "Player 2: Select candy to bet " << endl;
    do {
        getline (cin, player2_bet);
        if (players[1].findCandy(player2_bet).name == ""){
            cout << "Invalid selection!" << endl;
        }
    } while (players[1].findCandy(player2_bet).name == "");

    while(true){
        char player1_choice, player2_choice;
        cout << "Player 1: Enter r, p, or s " << endl;
        do {
            cin >> player1_choice;
            if (player1_choice != 'r' && player1_choice != 'p' && player1_choice != 's'){
                cout << "Invalid selection!" << endl;
                clearInputBuffer();
            }
        } while (player1_choice != 'r' && player1_choice != 'p' && player1_choice != 's');

        cout << "Player 2: Enter r, p, or s " << endl;
        do {
            
            cin >> player2_choice;
            if (player2_choice != 'r' && player2_choice != 'p' && player2_choice != 's'){
                cout << "Invalid selection!" << endl;
                clearInputBuffer();
            }
            
        } while (player2_choice != 'r' && player2_choice != 'p' && player2_choice != 's');

        if (player1_choice == player2_choice) {
            cout << "Tie! Play again" << endl;
            clearInputBuffer();
            continue;
            
        } else if ((player1_choice == 'r' && player2_choice == 's') ||
                (player1_choice == 's' && player2_choice == 'p') ||
                (player1_choice == 'p' && player2_choice == 'r')) {
            cout << "Player 1 has won " << player2_bet << " from player 2!" << endl;
            players[0].addCandy(players[1].findCandy(player2_bet));
            players[1].removeCandy(player2_bet);
        } else {
            cout << "Player 2 has won " << player1_bet << " from player 1!" << endl;
            players[1].addCandy(players[0].findCandy(player1_bet));
            players[0].removeCandy(player1_bet);
        }

        break;
    }    
}

int main() {
    Candy brown{"brown candy", "very very chewy", 3.3, "Buff"};
    Candy striped{"striped candy", "stretchy aussie candy", 5.0, "Buff"};
    Candy molasses{"Molasses", "ooey gooey bullshit", 1.0, "Nerf"};
    Candy p1_inventory[3] = {brown, brown, striped};
    Candy p2_inventory[3] = {brown, brown, striped};
    Player player1(5, 30, "Effect", p1_inventory, 3);
    Player player2(10, 20, "Effect", p2_inventory, 3);
    Player duel[2] = {player1, player2};


    playRockPaperScissors(duel);

    cout << "Player 1 inventory: " << endl;
    player1.printInventory();
    cout << "Player 2 inventory: " << endl;
    player2.printInventory();
}