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


    Employee employee("nima", "99*nr20237", adress, 10, 5, 10, 8);

    const Employee& employee1 = employee;

    Employee ** employees = new Employee *[2];

    for (int i = 0; i < 2; ++i) {
        employees[i] = new Employee;
        *employees[i] = employee1;
    }

    Boss boss("nima", "99*32133", adress, 10, 5, 10, 8, 2);


    Company company(10000 , boss , employees);
    cout << company;


//    for (int i = 0; i < 2; ++i)
//        delete employees[i];
//
//    delete [] employees;

    return 0;
}
