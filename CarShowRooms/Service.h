#ifndef SERVICE_H
#define SERVICE_H

#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Service {
public:
    int id;
    string name;
    long long price;

    Service();

    Service(int id, string name, long long price);
};

#endif // SERVICE_H
