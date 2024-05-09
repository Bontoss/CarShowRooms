#include "Service.h"
#include "Car.h"
#include "Buy_Rent_Process.h"
#include "Service_Process.h"
#include "Showrooms.h"
#include "Garages.h"
#include "Customer.h"
#include<fstream>
#include<ctime>
#include <set>
#define ListOfShowrooms Showrooms::ListOfShowrooms
#define ListOfgarages Garages::ListOfgarages
#define MapOfShowrooms Admin::MapOfShowrooms
#define MapOfCars Admin::MapOfCars
#define MapOfGarages Admin::MapOfGarages
#define MapOfServices Admin::MapOfServices
#define clr Admin::clr
#define ErrorChecking Admin::ErrorChecking
#define cid Customer::cid
#define SetOfEmails Admin::SetOfEmails
#pragma warning(disable : 4996)

set<pair<string, string>> SetOfEmails;
map<pair<string, string>, int> m_id;

map<string, int> Admin::MapOfShowrooms;
map<pair<int, pair<string, string>>, int> Admin::MapOfCars;
map<string, int> Admin::MapOfGarages;
map<pair<int, string>, int> Admin::MapOfServices;

Admin::Admin(int id, string userName, string password) {
    this->id = id;
    this->userName = userName;
    this->password = password;
}

template<typename T>
void Erase(vector<T>& X, int Y) {
    for (int i = Y; i < X.size() - 1; i++) {
        swap(X[i], X[i + 1]);
    }
    if (X.size() != 0)
        X.pop_back();
}

void clr(int& x) {
    cin.clear();
    cin.ignore(100000, '\n');
}

void ErrorChecking(int& check) {
    while (true) {
        cin >> check;
           if (cin.fail()) {
              cout << "Enter a valid number" << endl;
              clr(check);
           }
        else break;
    }
}

date DATE() {
    int Day, Month, Year;
    time_t now = time(0);

    tm* ltm = localtime(&now);

    Year = 1900 + ltm->tm_year;
    Month = 1 + ltm->tm_mon;
    Day = ltm->tm_mday;
    return { Day,Month,Year };
}

void Admin::add() {
    Customer::DATE();
    int x;
    cout << "1 : ShowRoom" << endl << endl << "2 : Car" << endl << endl << "3 : Garage" << endl << endl << "4 : Service" << endl << endl ;
    ErrorChecking(x);
    system("cls");
    if (x == 1) {
    here_a_sh:string name, location, phone;
        cout << endl << "Enter Showroom Name : " ;
        cin >> name;
        cout << endl << "Enter Showroom Location : " ;
        cin >> location;
        cout << endl << "Enter Showroom Phone : " ;
        cin >> phone;
        system("cls");
        vector<Car> cars;
        Showrooms showroom(ListOfShowrooms.size() + 1, name, location, phone, cars);
        ListOfShowrooms.push_back(showroom);
        MapOfShowrooms[showroom.name] = showroom.id;
        cout << endl << "          Added Successfully" << endl;
        cout << endl << "Do you want to add another showroom ! \n       1:YES       2:NO " << endl<<endl;
        int d; ErrorChecking(d); 
        system("cls");
        if (d == 1) {
            goto here_a_sh;
        }
    }
    else if (x == 2) {
        here_a_shr:
        string nameshowroom;
        cout << endl << "Enter Showroom Name : " ;
        cin >> nameshowroom;
        system("cls");
        int sh_id = MapOfShowrooms[nameshowroom];
        if (sh_id != 0) {
            here_a_c:
            int inst;
            bool in;
            string make, model, year;
            double price;
            int c_id;
            cout << endl << "Enter Car Model : " ;
            cin >> model;
            cout << endl <<"Enter Car Make : ";
            cin >> make;
            cout << endl << "Enter Car Year : " ;
            cin >> year;
            cout << endl << "Enter Car Price : " ;
            cin >> price;
            cout << endl << "Available for installment or no  \n       1 : YES       2 : NO  " <<endl;
            ErrorChecking(inst);
            if (inst == 2) {
                in = false;
            }
            else if (inst == 1) {
                in = true;
            }
            system("cls");
            c_id = ListOfShowrooms[sh_id - 1].list_of_Cars.size() + 1;
            Car car(c_id, year, price, make, true, model, in, DATE());
            ListOfShowrooms[sh_id - 1].list_of_Cars.push_back(car);
            MapOfCars[{sh_id, { model, year }}] = car.id;
            cout << endl << "        Added Successfully" << endl;
            cout << endl <<"Do you want to add another car ! \n      1 : YES       2 : NO  " << endl;
            int d; ErrorChecking(d); 
            system("cls");
            if (d == 1) {
                goto here_a_c;
            }
        }
        else {
            cout << endl << "        Showroom Not Found!" << endl << endl;
            goto here_a_shr;
        }
    }
    else if (x == 3) {
    here_a_g: string name, location, phone;
        cout << endl << "Enter garage Name : ";
        cin >> name;
        cout << endl << "Enter garage Location : ";
        cin >> location;
        cout << endl << "Enter garage Phone : ";
        cin >> phone;
        system("cls");
        vector<Service> service;
        Garages garage(ListOfgarages.size() + 1, name, location, phone, service);
        ListOfgarages.push_back(garage);
        MapOfGarages[garage.name] = garage.id;
        cout << endl << "          Added Successfully" << endl;
        cout << endl <<"Do you want to add another garage ! \n       1 : YES       2 : NO  " << endl;
        int d; ErrorChecking(d); 
        system("cls"); 
        if (d == 1) {
            goto here_a_g;
        }
    }
    else if (x == 4) {
        here_a_gr:
        string gname;
        cout << endl << "Enter garage Name : ";
        cin >> gname;
        system("cls");
    here_a_s:int g_id = MapOfGarages[gname];
        if (g_id != 0) {
            int s_id;
            string name;
            long long price;
            cout << endl << "Enter service name : ";
            cin >> name;
            cout << endl << "Enter service price : ";
            cin >> price;
            system("cls");
            s_id = ListOfgarages[g_id - 1].list_of_Services.size() + 1;
            Service service(s_id, name, price);
            ListOfgarages[g_id - 1].list_of_Services.push_back(service);
            MapOfServices[{g_id, name}] = service.id;
            cout << endl << "          Added Successfully" << endl;
            cout << endl << "Do you want to add another service ! \n       1 : YES       2 : NO  " << endl;
            int d; ErrorChecking(d); 
            system("cls"); 
            if (d == 1) {
                goto here_a_s;
            }
        }
        else {
            cout << endl << "         Garage Not Found!" << endl<< endl ;
            goto here_a_gr;
        }
    }
}

void Admin::update() {
    int x;
    cout << "1 : ShowRoom" << endl << endl << "2 : Car" << endl << endl << "3 : Garage" << endl << endl << "4 : Service" << endl << endl;

    ErrorChecking(x);
    system("cls");
    if (x == 1) {
    here_u_sh:
        string old_name;
        cout << endl << "Enter Name Of Showroom : ";
        cin >> old_name;
        system("cls");
        int sh_id = MapOfShowrooms[old_name];
        if (sh_id != 0) {
            cout << "1 : Name " << endl << endl << "2 : Location " << endl << endl << "3 : Phone Number " << endl;
            int choice; string new_name, location, Phone;
            ErrorChecking(choice);
            system("cls");
            if (choice == 1) {
                cout << endl << "Enter New Name Of Showroom : ";
                cin >> new_name;
                system("cls");
                ListOfShowrooms[sh_id - 1].name = new_name;
                cout << "       Name Modified Successfully" << endl;
            }
            else if (choice == 2) {
                cout << endl << "Enter New Location Of Showroom" << endl;
                cin >> location;
                system("cls");
                ListOfShowrooms[sh_id - 1].location = location;
                cout << "       Location Modified Successfully" << endl;
            }
            else if (choice == 3) {
                cout << endl << "Enter New Phone Number Of Showroom" << endl;
                cin >> Phone;
                system("cls");
                ListOfShowrooms[sh_id - 1].phone_number = Phone;
                cout << "     Phone Number Modified Successfully" << endl;
            }
            cout << endl << "Do you want to update another showroom ! \n       1 : YES       2 : NO  " << endl;
            int up; ErrorChecking(up); if (up == 1) {
                goto here_u_sh;
            }
            else if (sh_id == 0)
            {
                cout << "         Invalid Showroom" << endl;
                goto here_u_sh;
            }
        }
    }
    if (x == 2) {
        here_u_s:
        int choice;
        string name;
        cout << endl <<"Enter Name Of Showroom : " ;
        cin >> name;
        system("cls");
        int sh_id = MapOfShowrooms[name];
        if (sh_id != 0) {
        here_u_c:
            string model, year;
            cout << endl << "Enter Car Model : ";
            cin >> model;
            cout << endl << "Enter Car Year : " ;
            cin >> year;
            system("cls");
            int car_id = MapOfCars[{sh_id, { model,year }}];
            if (car_id != 0) {
                cout << "1 : price" << endl << endl << "2 : installment" << endl;
                int r; long long price;
                ErrorChecking(r);
                system("cls");
                if (r == 1) {
                    cout << endl <<"Enter New Price Of Car : ";
                    cin >> price;
                    system("cls");
                    ListOfShowrooms[sh_id - 1].list_of_Cars[car_id - 1].price = price;
                    cout << "       Price Modified Successfully" << endl;
                }
                else if (r == 2) {
                    bool insta;
                    cout << endl << "Enter new state for installment" << endl;
                    cin >> insta;
                    ListOfShowrooms[sh_id - 1].list_of_Cars[car_id - 1].installment = insta;
                    system("cls");
                    cout << "   New state for installment Modified Successfully" << endl;
                }
            }
            else if (car_id == 0) {
                cout << "         Invalid Car" << endl;
                goto here_u_c;
            }
        }
        else if (sh_id == 0) {
            cout << "       Invalid Showroom" << endl;
            goto here_u_s;
        }
        cout << endl << "Do you want to update another car ! \n       1 : YES       2 : NO  " << endl;
        int up; ErrorChecking(up); if (up == 1) {
            goto here_u_c;
        }
    }


    if (x == 3) {
    here_u_g:
        string old_name;
        cout << endl << "Enter Name Of Garage : ";
        cin >> old_name;
        system("cls");
        int g_id = MapOfGarages[old_name];
        if (g_id != 0) {
            cout << "1 : Name" << endl << endl << "2 : Location " << endl << endl << "3 : Phone Number " << endl;
            int choice; string new_name, location, phone;
            cin >> choice;
            system("cls");
            if (choice == 1) {
                cout << endl << "Enter New Name Of Garage : ";
                cin >> new_name;
                system("cls");
                ListOfgarages[g_id - 1].name = new_name;
                cout << "       Name Modified Successfully" << endl;
            }
            else if (choice == 2) {
                cout << endl << "Enter New Location Of Garage : ";
                cin >> location;
                system("cls");
                ListOfgarages[g_id - 1].location = location;
                cout << "      Location Modified Successfully" << endl;
            }
            else if (choice == 3) {
                cout << endl << "Enter New Phone Number Of Garage : ";
                cin >> phone;
                system("cls");
                ListOfgarages[g_id - 1].phone_number = phone;
                cout << "    Phone Number Modified Successfully" << endl;
            }
            cout << endl << "Do you want to update another garage ! \n       1 : YES       2 : NO  " << endl;
            int up; ErrorChecking(up); if (up == 1) {
                goto here_u_g;
            }
            else if (g_id == 0) {
                cout << "       Invalid Garage";
                goto here_u_g;
            }
        }
    }
    else if (x == 4) {
        string name_of_garage;
        here_G: cout << endl << "Enter Name Of Garage : " << endl;
        cin >> name_of_garage;
        system("cls");
        int g_id = MapOfGarages[name_of_garage];
        if (g_id != 0) {
        here_u_ser:cout << endl <<"Enter Service Name : ";
            string name_of_service;
            cin >> name_of_service;
            system("cls");
            int s_id = MapOfServices[{g_id, name_of_service}];
            if (s_id != 0) {
                long long price;
                cout << endl << "Enter New Price Of Service : " ;
                cin >> price;
                system("cls");
                ListOfgarages[g_id - 1].list_of_Services[s_id - 1].price = price;
                cout << "       Price Modified Successfully" << endl;
                cout << endl <<"Do you want to update another service ! \n       1 : YES       2 : NO  " << endl;
                int up;  ErrorChecking(up);
                if (up == 1) {
                    goto here_u_ser;
                }
            }
            else if (s_id == 0) {
                cout << "       Invalid Service" << endl;
                goto here_u_ser;
            }
        }
        else if (g_id == 0) {
            cout << "       Invalid Garage" << endl;
            goto here_G;
        }
    }
}

void Admin::Delete() {
    int x;
    cout << "1 : Showroom" << endl << endl << "2 : Car" << endl << endl << "3 : Garage" << endl << endl << "4 : Service" << endl <<endl;
    ErrorChecking(x);
    system("cls");
    if (x == 1) {
    here_sh:int sh_id; string n;
        cout << endl <<"Enter Name Of Showroom : ";
        cin >> n;
        sh_id = MapOfShowrooms[n];
        system("cls");
        if (sh_id != 0) {
            Erase(ListOfShowrooms, sh_id - 1);
            cout << endl << "     Showroom Deleted Successfully" << endl;
            cout << endl << "Do you want to delete another showroom ! \n       1 : YES       2 : NO  " << endl;
            int de; ErrorChecking(de); if (de == 1) {
                goto here_sh;
            }
        }
        else {
            cout << "       Invalid showroom " << endl;
            goto here_sh;
        }
        for (int i = sh_id - 1; i < ListOfShowrooms.size(); i++) {
            ListOfShowrooms[i].id--;
            MapOfShowrooms[ListOfShowrooms[i].name] = ListOfShowrooms[i].id;
        }
    }
    else if (x == 2) {
    in:string m, y, s;
        cout << endl <<"Enter Name Of Showroom  : ";
        cin >> s;
        system("cls");
        int sh_id;
        sh_id = MapOfShowrooms[s];
        if (sh_id != 0) {
        here_c: cout << endl <<"Enter Model of car : " ;
            cin >> m;
            cout << endl << "Enter Year of car : " ;
            cin >> y;
            system("cls");
            int car_id = MapOfCars[{sh_id, { m, y }}];
            if (car_id != 0) {
                Erase(ListOfShowrooms[sh_id - 1].list_of_Cars, car_id - 1);
                cout << "       Car Deleted Successfully" << endl;
                cout << "Do you want to delete another car ! \n       1 : YES       2 : NO  " << endl;
                int de;ErrorChecking(de); if (de == 1) {
                    goto here_c;
                }
            }
            else {
                cout << "       Invalid car " << endl;
                goto here_c;
            }
            for (int i = car_id - 1; i < ListOfShowrooms[sh_id - 1].list_of_Cars.size(); i++) {
                ListOfShowrooms[sh_id - 1].list_of_Cars[i].id--;
                MapOfCars[{sh_id, { ListOfShowrooms[sh_id - 1].list_of_Cars[i].model,ListOfShowrooms[sh_id - 1].list_of_Cars[i].year }}]
                    = ListOfShowrooms[sh_id-1].list_of_Cars[i].id;
            }
        }
        else {
            cout << "       Invalid showroom " << endl;
            goto in;
        }
    }
    else if (x == 3) {
    here_g: int g_id; string ng;
        cout << endl << "Enter Name Of Garage : ";
        cin >> ng;
        g_id = MapOfGarages[ng];
        system("cls");
        if (g_id != 0) {
            Erase(ListOfgarages, g_id - 1);
            cout << "       Garage Deleted Successfully" << endl;
            cout << "Do you want to delete another garage ! \n       1 : YES       2 : NO  " << endl;
            int de; ErrorChecking(de); if (de == 1) {
                goto here_g;
            }
        }
        else {
            cout << "           Invalid garage " << endl;
            goto here_g;
        }
        for (int i = g_id - 1; i < ListOfgarages.size(); i++) {
            ListOfgarages[i].id--;
            MapOfGarages[ListOfgarages[i].name] = ListOfgarages[i].id;
        }
    }
    else if (x == 4) {
    garag:string g;
        cout << endl <<"Enter Name Of Garage : " ;
        cin >> g;
        system("cls");
        int ga_id = MapOfGarages[g];
        if (ga_id != 0) {
        serv: cout << endl << "Enter Name Of Service : " ;
            string ns; cin >> ns;
            int ser_id = MapOfServices[{ga_id, ns}];
            system("cls");
            if (ser_id != 0) {
                Erase(ListOfgarages[ga_id - 1].list_of_Services, ser_id - 1);
                cout << "       Service Deleted Successfully" << endl;
                cout << "Do you want to delete another service ! \n       1 : YES       2 : NO  " << endl;
                int de; ErrorChecking(de); 
                if (de == 1) {
                    goto serv;
                }
            }
            else {
                cout << "           Invalid service " << endl;
                goto serv;
            }
            for (int i = ser_id - 1; i < ListOfgarages[ga_id - 1].list_of_Services.size(); i++) {
                ListOfgarages[ga_id - 1].list_of_Services[i].id--;
                MapOfServices[{ga_id, ListOfgarages[ga_id - 1].list_of_Services[i].name}]
                    = ListOfgarages[ga_id].list_of_Services[i].id;
            }
        }
        else {
            cout << "           Invalid garage " << endl;
            goto garag;
        }
    }
}

void Admin::Registration() {
    int id = SetOfEmails.size();
    string us, ps;
    ifstream input("data.txt");
    while (input >> id >> us >> ps) {
        m_id[{us, ps}] = id;
        SetOfEmails.insert({ us, ps });
    }
    int c;
    cout << "\t\t\t\t*************************************************" << endl;
    cout << "\t\t\t\t          Welcome to our application              " << endl << endl;
    cout << "\t\t\t\t     1 : REGISTER" << "   " << "2 : LOGIN " << "   " <<"3 : Exit " << endl << endl;
    cout << "\t\t\t\t*************************************************" << endl << endl;
    ErrorChecking(c);
    system("cls");
    if (c == 1) {
        int idd = SetOfEmails.size();
        idd++;
        string reguser, regpass;
        cout << "*************************************************" << endl;
        cout << "Enter Username : ";
        cin >> reguser;
        cout << endl << "Enter Password : ";
        char ch;
        cin >> regpass;
        cout << "*************************************************" << endl;
        system("cls");
        if (SetOfEmails.count({ reguser, regpass })) {
            cout << endl << "\t\t\t\t\t   Username Already Exist" << endl << endl;
            Registration();
        }
        else {
            SetOfEmails.insert({ reguser, regpass });
            ofstream output("data.txt", ios::app);
            output << idd << " " << reguser << " " << regpass << " " << endl;
            cout << endl << "\t\t\t\t\t   Registration Successfully" << endl << endl;
            Registration();
        }
    }
    else if (c == 2) {
        string loguser, logpass;
        cout << "*************************************************" << endl;
        cout << "Enter Username : ";
        cin >> loguser;
        cout << endl << "Enter Password : ";
        cin >> logpass;
        cout << "*************************************************" << endl;
        system("cls");
        if (loguser == "admin" && logpass == "admin123") {
            cout << "*************************************************" << endl << endl;
            cout << "*                 Welcome Admin                 *" << endl << endl;
            cout << "*************************************************" << endl << endl;
            administration();

        }
        else {
            if (SetOfEmails.count({ loguser, logpass })) {
                cid = m_id[{loguser, logpass}];
                cout << "*************************************************" << endl << endl;
                cout << "*                  Welcome Customer             *" << endl << endl;
                cout << "*************************************************" << endl << endl;
                Customer::customer();
            }
            else {
                cout << endl << "               Account Not Found!" << endl << endl;
                Registration();
            }
        }
    }
    else if (c == 3)
        return;
    input.close();
}

void Admin::administration() {
    int x;
    cout << "1 : Add" << endl << endl;
    cout << "2 : Update" << endl << endl;
    cout << "3 : Delete" << endl << endl;
    cout << "4 : Log Out" << endl << endl;
    cout << "5 : Exit" << endl << endl;
    ErrorChecking(x);
    system("cls");
    if (x == 1) {
        add();
        administration();
    }
    else if (x == 2) {
        update();
        administration();
    }
    else if (x == 3) {
        Delete();
        administration();
    }
    else if (x == 4) {
        Registration();
    }
    else if (x == 5)
        return;
}