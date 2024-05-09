#ifndef BUY_RENT_PROCESS_H
#define BUY_RENT_PROCESS_H
#include "Date.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Car.h"

using namespace std;

class Buy_Rent_Process {
public:
    int c = 1;
    int process_id, customer_id;
    date Date;
    long long amount_of_money;
    Car car_chosen;

    Buy_Rent_Process(int customer_id, date Date, long long amount_of_money, Car car_chosen);
};

#endif // BUY_RENT_PROCESS_H
