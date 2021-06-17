#include <iostream>
#include <iomanip>
#include <Adress.h>
#include <Person.h>
#include <Employee.h>
#include <Boss.h>
#include <Company.h>

using namespace std;

int main() {

    Adress adress("iran", "tehran", "apadana");
    Adress adress2("iran", "tabriz", "ekbatan");
    Adress adress3("iran", "LA", "zafar");

    Person person("amir" , "94fd33223",adress3);

    Employee first("abol", "98*r20237", adress, 10, 10, 10, 7);
    Employee second("haney", "98*nr20237", adress3, 10, 10, 10, 6);
    Employee third("mani", "96*nr20237", adress, 10, 10, 10, 5);
    Employee forth("reyhane", "96*nr20237", adress, 10, 10, 10, 4);
    Employee fifth("ahmad", "91*nr20237", adress, 10, 10, 10, 5);
    Employee sixth("farnam", "93*nr20237", adress3, 10, 10, 10, 3);
    Employee seventh("sepideh", "87*nr20237", adress, 10, 10, 10, 7);
    Employee eighth("rozhan", "90*nr20237", adress2, 10, 10, 10, 8);
    Employee ninth("mohsen", "89*nr20237", adress, 10, 10, 10, 7);
    Employee tenth("ali", "99*nr20237", adress, 10, 10, 10, 8);

    Employee ** employees = new Employee *[10];

    for (int i = 0; i < 10; ++i) {
        employees[i] = new Employee;
    }
    *employees[0] = first; *employees[1] = second;
    *employees[2] = third; *employees[3] = forth;
    *employees[4] = fifth; *employees[5] = sixth;
    *employees[6] = seventh; *employees[7] = eighth;
    *employees[8] = ninth; *employees[9] = tenth;
    

    Boss boss("nima", "94*32133", adress, 10, 5, 10, 2, 10);
    cout << boss.calculateSalary();

    Company company(100'000 , boss , employees);

    cout << company;
    cout << company.getBoss()->getName() << endl;
    cout << company.getBoss()->getAdress() << endl;

    company.checkBossEfficiency();

    cout << company.getBoss()->getName() << endl;
    cout << company.getBoss()->getNumberOfEmployees() << endl;
    cout << company.getBoss()->getId() << endl;
    cout << company.getBoss()->getAdress() << endl;

    company.gift();
    company.payForService();
    cout << company.isEnoughBudget() << endl;
    cout << endl;
    cout << company.averageEfficiency();
    cout << endl;
    company.saveToFile();
    cout << company;



    for (int i = 0; i < 10; ++i)
        delete employees[i];

    delete [] employees;

    return 0;
}
