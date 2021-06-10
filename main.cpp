#include <iostream>
#include <iomanip>
#include <Adress.h>
#include <Person.h>
#include <Employee.h>

using namespace std;

int main(){

    Adress adress("iran","tehran","apadana");

    Person person1("ali", "99dr23787",adress);
    cout << person1;
//
//    Employee employee("nima" , "99nn20237" , adress , 2 , 5 , 7 , 9);
//    cout << employee;

//    Employee employee1;
//    cin >> employee1;
//    cout << employee1;

    Employee employee("nima","99*nr20237",adress,10,4,7,6);
//    cout << employee;
//    cout << endl;
    cout << employee.calculateSalary() << endl;
    cout << fixed <<std::setprecision(3) << employee.efficiency();







    return 0;
}
