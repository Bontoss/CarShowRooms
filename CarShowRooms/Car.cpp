#include "Car.h"

Car::Car() {}

Car::Car(int id, string year, long long price, string make, bool state, string model, bool installment, date Date) {
    this->id = id;
    this->year = year;
    this->price = price;
    this->make = make;
    this->state = state;
    this->model = model;
    this->installment = installment;
    this->Date = Date;
}


