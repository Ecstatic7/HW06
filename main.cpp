#include <iostream>
#include <Adress.h>
#include <Person.h>

using namespace std;

int main(){

    Adress adress("iran","tehran","apadana");
    cout << adress;
//    cin >> adress;
    cout << adress;

    Person person("nima" , "992023037" , adress);
    Person person1;
    cin >> person1;


    cout << person1;





    return 0;
}
