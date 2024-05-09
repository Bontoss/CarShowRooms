#include "Service.h"

Service::Service() {}

Service::Service(int id, string name, long long price) {
    this->id = id;
    this->name = name;
    this->price = price;
}

