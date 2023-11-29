#include "Player.h"
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>

void clearInputBuffer(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void playRockPaperScissors(vector<Player> players) {
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

vector<Candy> readCandy(string file_name, vector<Candy> candies){
    vector<Candy> temp;
    ifstream infile(file_name);
    if (!infile.is_open()){
        cout << "Failed to open file" << endl;
        return candies;
    }
    string line, candy_name, candy_description, candy_price, candy_type;
    while (getline(infile, line)){
        stringstream ss(line);
        getline(ss, candy_name, '|');
        getline(ss, candy_description, '|');
        getline(ss, candy_price, '|');
        getline(ss, candy_type, '|');
        if (candy_name.length() == 0 || candy_description.length() == 0 || candy_price.length() == 0 || candy_type.length() == 0){
            continue;
        }
        Candy sweet{candy_name, candy_description, stod(candy_price), candy_type};
        temp.push_back(sweet);
    }
    return temp;
}

void displayPlayerStats(Player player){
    cout << "Stamina: " << player.getStamina() << " ";
    cout << "Gold: " << player.getGold() << " ";
    cout << "Effect: " << player.getEffect() << " ";
    cout << "Inventory: " << endl;
    player.printInventory();
}

void editPlayerStats(Player player, vector<Candy> candy_list, int player_number){
    int choice;
    cout << "Editing player stats:" << endl;
    cout << "1. Edit stamina" << endl;
    cout << "2. Edit gold" << endl;
    cout << "3. Edit effect" << endl;
    cout << "4. Add candy" << endl;
    cout << "5. Remove candy" << endl;
    cout << "6. Back to main menu" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    do {
        switch (choice){
            case 1: {
                int newStamina;
                cout << "Enter new stamina (1-10): " << endl;
                cin >> newStamina;
                player.setStamina(newStamina);
                break;
            }
            case 2: {
                double newGold;
                cout << "Enter new gold (1-1000): " << endl;
                cin >> newGold;
                player.setGold(newGold);
                break;
            }
            case 3: {
                string newEffect;
                cout << "Enter new effect: " << endl;
                getline(cin, newEffect);
                player.setEffect(newEffect);
                clearInputBuffer();
                break;
            }
            case 4: {
                string candy_choice;
                vector<Candy> candies;
                cout << "Adding candy. Enter one of the following options: " << endl;
                int size = candy_list.size();
                for (int i = 0; i < size; i++){
                    Candy candy;
                    cout << "Name: " << candy_list[i].name << ". Description: " << candy_list[i].description << ". Price: " << candy_list[i].price << ". Type: " << candy_list[i].candy_type << endl;
                    candy.name = candy_list[i].name;
                    candy.description = candy_list[i].description;
                    candy.price = candy_list[i].price;
                    candy.candy_type = candy_list[i].candy_type;
                    candies.push_back(candy);
                }
                getline(cin, candy_choice);

                for (int i = 0; i < size; i++){
                    if (candies[i].name == candy_choice){
                        player.addCandy(candies[i]);
                        return;
                    }
                }
                break;
            }
            case 5: {
                string candy_to_remove;
                cout << "Removing candy. Enter the name of the candy in player " << player_number << "'s inventory." << endl;
                getline(cin, candy_to_remove);
                player.removeCandy(candy_to_remove);
                clearInputBuffer();
                break;
            }
            case 6: {
                cout << "Returning to main menu." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again. " << endl;
        }
    } while (choice != 6);
}

int main(){
    vector<Candy> candy_list;
    vector<Player> players(2);


    int option;
    cout << "Welcome to rock-paper-scissors candy edition!" << endl;

    do {
        cout << "Select from the following options:" << endl;
        cout << "1. Load candy" << endl;
        cout << "2. Display player stats" << endl;
        cout << "3. Edit player stats" << endl;
        cout << "4. Play rock-paper-scissors" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option){
            case 1: {
                clearInputBuffer();
                string filename;
                cout << "Enter file to read: " << endl;
                getline(cin, filename);
                candy_list = readCandy(filename, candy_list);
                break;
            }
            case 2: {
                int playerChoice;
                cout << "Which player's stats do you want to display?" << endl;
                cin >> playerChoice;
                playerChoice --;
                if (playerChoice == 0 || playerChoice == 1) {
                    displayPlayerStats(players[playerChoice]);
                } else {
                    cout << "Invalid player choice. Please try again." << endl;
                }
                break;
            }
            case 3: {
                int playerChoice;
                cout << "Which player's stats do you want to edit? Choose 1 or 2: ";
                cin >> playerChoice;
                playerChoice --;
                if (playerChoice == 0 || playerChoice == 1) {
                    editPlayerStats(players[playerChoice], candy_list, playerChoice);
                } else {
                    cout << "Invalid player choice. Please try again." << endl;
                }
                break;
            }
            case 4: {
                playRockPaperScissors(players);
                break;
            }
            case 5: {
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (option != 5);
}