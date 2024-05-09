#ifndef GARAGES_H
#define GARAGES_H

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Service.h"

using namespace std;

class Garages {
public:
    int id;
    string name;
    string location;
    string phone_number;
    vector<Service> list_of_Services;

    Garages();

    Garages(int id, string name, string location, string phone_number, vector<Service> list_of_Services);

    static vector<Garages> ListOfgarages;
};

#endif // GARAGES_H
