#include <iostream>
using namespace std;

int main(){
    struct Dog {
        string name;
        int age;
        string favorite_toy;
    } spot, lassie;

    spot.name = "spot";
    spot.age = 5;
    spot.favorite_toy = "tennis ball";

    lassie.name = "lassie";
    lassie.age = 3;
    lassie.favorite_toy = "frisbee";

    cout << "Name: " << spot.name << ". Age: " << spot.age << ". Favorite Toy: " << spot.favorite_toy << "." << endl;
    cout << "Name: " << lassie.name << ". Age: " << lassie.age << ". Favorite Toy: " << lassie.favorite_toy << "." << endl;
}