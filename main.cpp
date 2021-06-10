#include <iostream>
#include <Adress.h>
#include <Person.h>
#include <Employee.h>

using namespace std;

int main(){

    Adress adress("iran","tehran","apadana");

    Person person1("ali", "99Adr23787",adress);
    cout << person1;
//
//    Employee employee("nima" , "99nn20237" , adress , 2 , 5 , 7 , 9);
//    cout << employee;

//    Employee employee;
//    cin >> employee;
//    cout << employee;

    Employee employee("nima","99*nr20237",adress,2,4,5,6);
    cout << employee;







    return 0;
}
