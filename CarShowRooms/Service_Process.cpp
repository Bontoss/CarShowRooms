#include "Service_Process.h"
int Service_Process::y = 1;
Service_Process::Service_Process() {};
Service_Process::Service_Process(int customer_id, date Date, string name, long long amount_of_money, Service chosen_service) {
    this->process_id = y++;
    this->customer_id = customer_id;
    this->name = name;
    this->Date = Date;
    this->amount_of_money = amount_of_money;
    this->chosen_service = chosen_service;
}
vector<Service_Process>Service_Process::s_process[1000];
