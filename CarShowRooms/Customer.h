#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include "Service.h"
#include "Service_Process.h"
using namespace std;

class Customer {
public:
    static int cid;
    int id = 1;
    string userName;
    string password;
    int choise;

    

    Customer(int id, string userName, string password, int choise);

    static void viewhistory();

    static void customer();

    static void view();

    static void Search();

    static void buy();

    static void rent();

    static void reserve();

    static void book();

    static void clr(int& x);

    static void ErrorChecking(int& x);

    static void DATE();
};
class Admin {
public:
    static map<string, int> MapOfShowrooms;
    static map<pair<int, pair<string, string>>, int> MapOfCars;
    static map<string, int> MapOfGarages;
    static map<pair<int, string>, int> MapOfServices;
    int id;
    string userName;
    string password;

    Admin(int id, string userName, string password);
    static set<pair<string, string>> SetOfEmails;

    static void add();

    static void Delete();

    static void update();

    static void administration();

    static void clr(int& x);

    static void ErrorChecking(int& x);

    static void Registration();

};

#endif // CUSTOMER_H
