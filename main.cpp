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


    Employee employee("ali", "99*nr20237", adress, 10, 5, 10, 8);
    Employee first("abol", "98*nr20237", adress, 10, 5, 10, 7);
    Employee second("haney", "98*nr20237", adress, 10, 5, 10, 6);
    Employee third("romisa", "96*nr20237", adress, 10, 5, 10, 5);

    Employee ** employees = new Employee *[4];

    for (int i = 0; i < 4; ++i) {
        employees[i] = new Employee;
    }
    *employees[0] = employee;
    *employees[1] = first;
    *employees[2] = third;
    *employees[3] = second;

    Boss boss("nima", "99*32133", adress, 10, 5, 10, 4, 4);


    Company company(10000 , boss , employees);
    cout << company << endl;
    cout << company.getBoss()->getName();
    company.saveToFile();
//    company.checkBossEfficiency();


    for (int i = 0; i < 4; ++i)
        delete employees[i];

    delete [] employees;

    return 0;
}
