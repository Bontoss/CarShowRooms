#ifndef SHOWROOMS_H
#define SHOWROOMS_H

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Car.h"

using namespace std;

class Showrooms {
public:
    int id;
    string name;
    string location;
    string phone_number;
    vector<Car> list_of_Cars;

    Showrooms();

    Showrooms(int id, string name, string location, string phone_number, vector<Car> list_of_Cars);

    static vector<Showrooms> ListOfShowrooms;
    vector<Car> Reserved_Cars;
};

#endif // SHOWROOMS_H
