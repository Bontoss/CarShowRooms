#include "Showrooms.h"

Showrooms::Showrooms() {}

Showrooms::Showrooms(int id, string name, string location, string phone_number, vector<Car> list_of_Cars) {
    this->id = id;
    this->name = name;
    this->location = location;
    this->phone_number = phone_number;
    this->list_of_Cars = list_of_Cars;
}
vector<Showrooms> Showrooms::ListOfShowrooms;

