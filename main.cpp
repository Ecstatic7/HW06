#include <iostream>
#include <Adress.h>
#include <Person.h>

using namespace std;

int main(){

    Adress adress("iran","tehran","apadana");
//    cout << adress;
//    cin >> adress;
//    cout << adress;
    Person person1("ali", "99Adr23787",adress);
    cout << person1;

//    Person person("nima" , "992023037" , adress);
//    cout << person;
//    cin >> person1;

//    cout << Person::validate("99.23037");


//    cout << person1;





    return 0;
}
