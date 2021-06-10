#ifndef HW06_PERSON_H
#define HW06_PERSON_H

#include <iostream>
#include <Adress.h>

class Person {
private:
    std::string name;
    std::string id;
    Adress adress;

public:
    Person();

    Person(std::string name, std::string id, const Adress &adress);

    Person(const Person &);

    void setName(const std::string &name);

    void setId(const std::string &id);

    void setAdress(const Adress &adress);

    std::string getName() const;

    std::string getId() const;

    Adress getAdress() const;

    static bool validate(std::string);

    friend std::ostream &operator<<(std::ostream &, const Person &);

    friend std::istream &operator>>(std::istream &, Person &);

    Person &operator=(const Person &);
};


#endif //HW06_PERSON_H
