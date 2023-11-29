#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Candy {
    string name;
    string description;
    double price;
    string candy_type;
};

vector<Candy> readCandy(string file_name, vector<Candy> candies){
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
        candies.push_back(sweet);
    }
    return candies;
}

int main(){
    string filename = "";
    cout << "Enter file to read: " << endl;
    cin >> filename;
    vector<Candy> candies2;
    vector<Candy> candies = readCandy(filename, candies2);
    int size = candies.size();
    for (int i = 0; i < size; i++){
        cout << "Name: " << candies[i].name << ". Description: " << candies[i].description << ". Price: " << fixed << setprecision(2) << candies[i].price << ". Type: " << candies[i].candy_type << endl;
    }
}