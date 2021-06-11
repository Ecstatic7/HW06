#include <iostream>
#include <iomanip>
#include <Adress.h>
#include <Person.h>
#include <Employee.h>
#include <Boss.h>

using namespace std;

int main() {

    Adress adress("iran", "tehran", "apadana");
//
//    Person person1("ali", "99dr23787",adress);
//    cout << person1;
//
//    Employee employee("nima" , "99nn20237" , adress , 2 , 5 , 7 , 9);
//    cout << employee;

//    Employee employee1;
//    cin >> employee1;
//    cout << employee1;

    Employee employee("nima", "99*nr20237", adress, 10, 5, 10, 8);
//    cout << employee;
    cout << employee.calculateSalary();
    cout << endl;
    const Employee& employee1 = employee;
//    cout << employee1;


    Boss boss("nima", "99*32133", adress, 10, 5, 10, 8, 10);
//    cin >> boss;
//    cout << boss;
    cout << boss.calculateSalary();
    cout << endl;
    Boss boss1;
    boss1 = boss;
//    cout << boss1;

    Employee * nima = new Employee;
    cin >> static_cast<Boss&>(*nima);
    cout << (*nima);

    cout << endl;
//    cout << boss1;
    Boss boss2 = static_cast<Boss &>(*nima);
    cout << boss2;
    cout << endl;
    cout << boss2.calculateSalary();
    cout << endl;
    cout << nima->calculateSalary();

    return 0;
}
