#include <iostream>
#include <Adress.h>
#include <Person.h>

using namespace std;

int main(){

    Adress adress("iran","tehran","apadana");

    Person person1("ali", "99Adr23787",adress);
    cout << person1;







    return 0;
}
