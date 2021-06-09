
#include "Person.h"

Person::Person() = default;

Person::Person(std::string name, std::string id, const Adress &adress) :
        name(std::move(name)), id(std::move(id)), adress(adress) {}

Person::Person(const Person &person) {
    this->name = person.name;
    this->adress = person.adress;
    this->id = person.id;
}

void Person::setName(const std::string &name) {
    Person::name = name;
}

void Person::setId(const std::string &id) {
    Person::id = id;
}

void Person::setAdress(const Adress &adress) {
    Person::adress = adress;
}

std::string Person::getName() const {
    return name;
}

std::string Person::getId() const {
    return id;
}

Adress Person::getAdress() const {
    return adress;
}

std::ostream & operator<<(std::ostream & output, const Person & person) {
    output << "My name is " << person.getName() << " with the ID of " << person.getId();
    output << " and " << person.getAdress();
    return output;
}

std::istream &operator>>(std::istream & istream, Person & person) {
//    std::cout << "Please complete the specification of the Person\n";
    std::cout << "Enter the name:";
    istream >> person.name;
    std::cout << "Enter the ID:";
    istream >> person.id;
    std::cout << "Enter the Address";
    istream >> person.adress;
    return istream;
}

Person &Person::operator=(const Person & person) {
    if (this != &person){
        this->name = person.getName();
        this->id = person.getId();
        this->adress = person.getAdress();
    }
    return *this;
}







