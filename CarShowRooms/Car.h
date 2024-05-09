#ifndef CAR_H
#define CAR_H
#include "Date.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Car {
public:
    int id;
    string year;
    long long price;
    string make;
    bool state;
    string model;
    date Date;
    bool installment;

    Car();

    Car(int id, string year, long long price, string make, bool state, string model, bool installment, date Date);
};

#endif // CAR_H
