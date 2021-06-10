#ifndef HW06_ADRESS_H
#define HW06_ADRESS_H

#include <iostream>

class Adress {
public:
    Adress();

    Adress(std::string, std::string, std::string);

private:
    std::string country;
    std::string city;
    std::string street;

public:
    void setCountry(const std::string &country);

    void setCity(const std::string &city);

    void setStreet(const std::string &street);

    const std::string &getCountry() const;

    const std::string &getCity() const;

    const std::string &getStreet() const;

    friend std::ostream &operator<<(std::ostream &, const Adress &);

    friend std::istream &operator>>(std::istream &, Adress &);

};


#endif //HW06_ADRESS_H
