
#include "Person.h"

Person::Person() = default;

Person::Person(std::string name, std::string id, const Adress &adress) {
    if (validate(id)) {
        this->name = name;
        this->id = id;
        this->adress = adress;
    } else {
        std::cout << "invalid ID!";
        exit(1);
    }
}

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

std::ostream &operator<<(std::ostream &output, const Person &person) {
    output << "My name is " << person.getName() << " with the ID of " << person.getId()
    <<" and " << person.getAdress();
    return output;
}

std::istream &operator>>(std::istream &istream, Person &person) {
    std::cout << "Enter the name:";
    istream >> person.name;
    std::cout << "Enter the ID:";
    istream >> person.id;

    if (!person.validate(person.id)){
        std::cout << "invalid id";
        exit(1);
    }

    istream >> person.adress;
    return istream;
}

Person &Person::operator=(const Person &person) {
    if (this != &person) {
        this->name = person.getName();
        this->id = person.getId();
        this->adress = person.getAdress();
    }
    return *this;
}

bool Person::validate(std::string id) {
    if (id.length() < 8 || id.length() > 10)
        return false;

    if (std::stoi(id.substr(0, 2)) < 84 || std::stoi(id.substr(0, 2)) > 99)
        return false;                                       /// checking if the first two words are a valid number

    int numberOfChars = (int) id.length() - 7;

    for (int i = 2; i < 2 + numberOfChars; ++i) {           /// checking if the 1 - 3 characters are not number
        if ((47 < (int) id.at(i) && (int) id.at(i) < 58))   /// numbers ascii code
            return false;
    }

    for (int i = 2 + numberOfChars; i < id.length(); ++i) {    /// checking the last five characters are number
        if (!(47 < (int) id.at(i) && (int) id.at(i) < 58))
            return false;                                      /// if they're not number return false

        if ((int) ((id.at(i) - '0') >= 4 && (int) (id.at(i) - '0') <= 6) || (int) (id.at(i) - '0') < 0)
            return false;                                      /// checking if it is not less than 0 or between 4 - 6
    }

    return true;                                               /// it's valid
}