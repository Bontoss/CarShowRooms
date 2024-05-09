#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include "Customer.h"
#include "Showrooms.h"
#include "Garages.h"
#include "Service_Process.h"
#include <ctime>
#define ListOfShowrooms Showrooms::ListOfShowrooms
#define ListOfgarages Garages::ListOfgarages
#define s_process Service_Process::s_process
#define MapOfShowrooms Admin::MapOfShowrooms
#define MapOfCars Admin::MapOfCars
#define MapOfGarages Admin::MapOfGarages
#define MapOfServices Admin::MapOfServices
#define cid Customer::cid
#define SetOfEmails Admin::SetOfEmails
#pragma warning(disable : 4996)

using namespace std;

template<typename T>
void Erase(vector<T>& X, int Y) {
    for (int i = Y; i < X.size() - 1; i++) {
        swap(X[i], X[i + 1]);
    }
    if (X.size() != 0)
        X.pop_back();
}

int Day1, Month1, Year1;
void DATE_of_day() {
    time_t now = time(0);

    tm* ltm = localtime(&now);

    Year1 = 1900 + ltm->tm_year;
    Month1 = 1 + ltm->tm_mon;
    Day1 = ltm->tm_mday;
}

void Welcome() {
    ifstream input;
    input.open("Showrooms.txt");
    int sizee = 0;
    input >> sizee;
    for (int i = 0; i < sizee; i++) {
        Showrooms x;
        input >> x.id >> x.name >> x.location >> x.phone_number;
        MapOfShowrooms[x.name] = x.id;
        int SizeOfCars;
        input >> SizeOfCars;
        for (int j = 0; j < SizeOfCars; j++) {
            Car car;
            input >> car.id >> car.year >> car.price >> car.make >> car.model >> car.installment
                >> car.Date.day >> car.Date.month >> car.Date.year >> car.state;
            MapOfCars[{x.id, { car.model, car.year }}] = car.id;
            x.list_of_Cars.push_back(car);
        }
        int sizeofreservedcars;
        input >> sizeofreservedcars;
        for (int j = 0; j < sizeofreservedcars; j++)
        {
            Car c;
            input >> c.id >> c.year >> c.price >> c.make >> c.model >> c.installment
                >> c.Date.day >> c.Date.month >> c.Date.year >> c.state;
            x.Reserved_Cars.push_back(c);
        }
        ListOfShowrooms.push_back(x);
    }
    input.close();

    input.open("Garages.txt");
    input >> sizee;
    for (int i = 0; i < sizee; i++) {
        Garages x;
        input >> x.id >> x.name >> x.location >> x.phone_number;
        MapOfGarages[x.name] = x.id;
        int SizeOfServices;
        input >> SizeOfServices;
        for (int j = 0; j < SizeOfServices; j++) {
            Service service;
            input >> service.id >> service.name >> service.price;
            MapOfServices[{x.id, service.name}] = service.id;
            x.list_of_Services.push_back(service);
        }
        ListOfgarages.push_back(x);
    }
    input.close();

    input.open("Historical_service_process.txt");
    input >> sizee;
    for (int i = 0; i < sizee; i++) {
        int sizeee;
        input >> sizeee;
        for (int j = 0; j < sizeee; j++) {
            Service_Process ser_p;
            input >> ser_p.process_id >> ser_p.customer_id >> ser_p.amount_of_money
                >> ser_p.Date.day >> ser_p.Date.month >> ser_p.Date.year >> ser_p.name;
            s_process[i].push_back(ser_p);

        }
    }
    input.close();
}

void ByeBye() {
    ofstream output;
    output.open("Showrooms.txt");
    output << ListOfShowrooms.size() << endl;
    for (int i = 0; i < ListOfShowrooms.size(); i++) {
        output << i + 1 << ' ' << ListOfShowrooms[i].name << ' ' << ListOfShowrooms[i].location << ' '
            << ListOfShowrooms[i].phone_number << endl;
        output << ListOfShowrooms[i].list_of_Cars.size() << endl;
        for (int j = 0; j < ListOfShowrooms[i].list_of_Cars.size(); j++) {
            output << j + 1 << ' ' << ListOfShowrooms[i].list_of_Cars[j].year << ' '
                << ListOfShowrooms[i].list_of_Cars[j].price << ' ' << ListOfShowrooms[i].list_of_Cars[j].make << ' '
                << ListOfShowrooms[i].list_of_Cars[j].model << ' ' << ListOfShowrooms[i].list_of_Cars[j].installment
                << ' ' << ListOfShowrooms[i].list_of_Cars[j].Date.day << ' ' << ListOfShowrooms[i].list_of_Cars[j].Date.month << ' '
                << ListOfShowrooms[i].list_of_Cars[j].Date.year << ' ' << ListOfShowrooms[i].list_of_Cars[j].state
                << endl;
        }
        output << endl;

        output << ListOfShowrooms[i].Reserved_Cars.size() << endl;
        for (int j = 0; j < ListOfShowrooms[i].Reserved_Cars.size(); j++) {
            output << j + 1 << ' ' << ListOfShowrooms[i].Reserved_Cars[j].year << ' '
                << ListOfShowrooms[i].Reserved_Cars[j].price << ' ' << ListOfShowrooms[i].Reserved_Cars[j].make << ' '
                << ListOfShowrooms[i].Reserved_Cars[j].model << ' ' << ListOfShowrooms[i].Reserved_Cars[j].installment
                << ' ' << ListOfShowrooms[i].Reserved_Cars[j].Date.day << ' ' << ListOfShowrooms[i].Reserved_Cars[j].Date.month << ' '
                << ListOfShowrooms[i].Reserved_Cars[j].Date.year << ' ' << ListOfShowrooms[i].Reserved_Cars[j].state
                << endl;
        }
        output << endl << endl << endl;
    }
    output.close();

    output.open("Garages.txt");
    output << ListOfgarages.size() << endl;
    for (int i = 0; i < ListOfgarages.size(); i++) {
        output << i + 1 << ' ' << ListOfgarages[i].name << ' ' << ListOfgarages[i].location << ' '
            << ListOfgarages[i].phone_number << endl;
        output << ListOfgarages[i].list_of_Services.size() << endl;
        for (int j = 0; j < ListOfgarages[i].list_of_Services.size(); j++) {
            output << j + 1 << ' ' << ListOfgarages[i].list_of_Services[j].name << ' '
                << ListOfgarages[i].list_of_Services[j].price << endl;
        }
        output << endl << endl;
    }
    output.close();

    output.open("Historical_service_process.txt");
    output << SetOfEmails.size() << endl;
    for (int i = 0; i < SetOfEmails.size(); i++) {
        output << s_process[i].size() << endl;
        for (int j = 0; j < s_process[i].size(); j++) {
            output << j + 1 << ' ' << s_process[i][j].customer_id << ' '
                << s_process[i][j].amount_of_money << ' ' << s_process[i][j].Date.day << ' '
                << s_process[i][j].Date.month << ' ' << s_process[i][j].Date.year << ' ' << s_process[i][j].name << endl;
        }
        output << endl << endl;
    }
    output.close();
}

void return_car()
{
    DATE_of_day();
    for (int i = 0; i < ListOfShowrooms.size(); i++)
    {
        for (int j = 0; j < ListOfShowrooms[i].list_of_Cars.size(); j++)
        {
            if (ListOfShowrooms[i].list_of_Cars[j].state == 0)
            {
                if (ListOfShowrooms[i].list_of_Cars[j].Date.month < Month1)
                {
                    ListOfShowrooms[i].list_of_Cars[j].state = 1;
                }
                else if (ListOfShowrooms[i].list_of_Cars[j].Date.day <= Day1 && ListOfShowrooms[i].list_of_Cars[j].Date.month <= Month1)
                {
                    ListOfShowrooms[i].list_of_Cars[j].state = 1;
                }
            }
        }

        for (int j = 0; j < ListOfShowrooms[i].Reserved_Cars.size(); j++)
        {
           
            if (ListOfShowrooms[i].Reserved_Cars[j].Date.month < Month1)
            {
                ListOfShowrooms[i].list_of_Cars.push_back(ListOfShowrooms[i].Reserved_Cars[j]);
                ListOfShowrooms[i].Reserved_Cars[j].id = ListOfShowrooms[i].list_of_Cars.size() + 1;
                Erase(ListOfShowrooms[i].Reserved_Cars, j);
            }
            else if (ListOfShowrooms[i].Reserved_Cars[j].Date.day <= Day1 && ListOfShowrooms[i].Reserved_Cars[j].Date.month <= Month1)
            {
                ListOfShowrooms[i].list_of_Cars.push_back(ListOfShowrooms[i].Reserved_Cars[j]);
                ListOfShowrooms[i].Reserved_Cars[j].id = ListOfShowrooms[i].list_of_Cars.size() + 1;
                Erase(ListOfShowrooms[i].Reserved_Cars, j);
            }
        }
    }   
}

int main() {
    Welcome();
    return_car();
    Admin::Registration();
    ByeBye();
    return 0;
}