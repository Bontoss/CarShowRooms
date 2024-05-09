#include "Garages.h"

Garages::Garages() {}

Garages::Garages(int id, string name, string location, string phone_number, vector<Service> list_of_Services) {
    this->id = id;
    this->name = name;
    this->location = location;
    this->phone_number = phone_number;
    this->list_of_Services = list_of_Services;
}

vector<Garages> Garages::ListOfgarages;


