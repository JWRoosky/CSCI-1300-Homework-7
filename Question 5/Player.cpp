#include "Player.h"

Player::Player(){
    _stamina = 0;
    _gold = 0;
    _candy_amount = 0;
    _effect = "";
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++){
        _inventory[i] = Candy{"", "", 0, ""};
    }
}

Player::Player(int stamina, double gold, string effect, Candy candy_array[], const int CANDY_ARR_SIZE){
    _stamina = stamina;
    _gold = gold;
    _effect = effect;
    for (int i = 0; i < CANDY_ARR_SIZE; i++){
        if (candy_array[i].name != ""){
            _inventory[i] = candy_array[i];
            _candy_amount ++;
        }
        else{
            _inventory[i] = Candy{"", "", 0, ""};
        }
    }
}

// Accessors
int Player::getCandyAmount() const{
    return _candy_amount;
}

int Player::getStamina() const{
    return _stamina;
}

double Player::getGold() const{
    return _gold;
}

string Player::getEffect() const{
    return _effect;
}

// Mutators
void Player::setStamina(int stamina){
    _stamina = stamina;
}

void Player::setGold(double gold){
    _gold = gold;
}

void Player::setEffect(string effect){
    _effect = effect;
}

// Functional

void Player::printInventory(){
    string name;
    for (int i = 0; i < 2; i++){
        if (_inventory[i].name.length() != 0){
            cout << "|[" << _inventory[i].name << "]";
        }
        else{
            cout << "|[Empty]";
        }
    }
    cout << "|" << endl;
    for (int i = 2; i < 4; i++){
        if (_inventory[i].name.length() != 0){
            cout << "|[" << _inventory[i].name << "]";
        }
        else{
            cout << "|[Empty]";
        }
    }
    cout << "|" << endl;
}


Candy Player::findCandy(string candy_name){
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++){
        if (candy_name == _inventory[i].name){
            return _inventory[i];
        }
    }
    Candy candy;
    return candy;
}

bool Player::addCandy(Candy candy){
    if (_candy_amount == _MAX_CANDY_AMOUNT){
        return false;
    }
    _inventory[_candy_amount] = candy;
    if (candy.name != ""){
        _candy_amount ++;
    }
    return true;
}

bool Player::removeCandy(string candy_name){
    for (int i = 0; i < candy_name.length(); i++){
        candy_name[i] = tolower(candy_name[i]);
    }
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++){
        string temp = _inventory[i].name;
        for (int j = 0; j < temp.length(); j++){
            temp[i] = tolower(temp[i]);
        }
        if (temp == candy_name){
            for (int j = i; j < _MAX_CANDY_AMOUNT - 1; j++){
                _inventory[j] = _inventory[j + 1];
            }
            _inventory[_MAX_CANDY_AMOUNT - 1] = Candy{"", "", 0, ""};
            _candy_amount --;
            return true;
        }
    }
    return false;
}
