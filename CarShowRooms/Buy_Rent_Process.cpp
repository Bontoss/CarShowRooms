#include "Buy_Rent_Process.h"

Buy_Rent_Process::Buy_Rent_Process(int customer_id, date Date, long long amount_of_money, Car car_chosen) {
    this->process_id = c++;
    this->customer_id = customer_id;
    this->Date = Date;
    this->amount_of_money = amount_of_money;
    this->car_chosen = car_chosen;
}

