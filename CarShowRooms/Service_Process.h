#ifndef SERVICE_PROCESS_H
#define SERVICE_PROCESS_H
#include "Date.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Service.h"

using namespace std;

class Service_Process {
public:
    static int y;
    int process_id, customer_id;
    string name;
    date Date;
    long long amount_of_money;
    Service chosen_service;
    Service_Process();
    Service_Process(int customer_id, date Date, string name, long long amount_of_money, Service chosen_service);

    static vector<Service_Process>s_process[1000];
};

#endif // SERVICE_PROCESS_H
