#include <iostream>
#include "Adress.h"

Adress::Adress() = default;

Adress::Adress(std::string country, std::string city, std::string street) {
    this->country = std::move(country);
    this->city = std::move(city);
    this->street = std::move(street);
}

void Adress::setCountry(const std::string &country) {
    Adress::country = country;
}

void Adress::setCity(const std::string &city) {
    Adress::city = city;
}

void Adress::setStreet(const std::string &street) {
    Adress::street = street;
}

const std::string &Adress::getCountry() const {
    return country;
}

const std::string &Adress::getCity() const {
    return city;
}

const std::string &Adress::getStreet() const {
    return street;
}

std::ostream & operator<<(std::ostream & ostream, const Adress& adress) {
    ostream << "The address is in the country of " << adress.getCountry();
    ostream << " in " << adress.getCity() << " city";
    ostream << " and the " << adress.getStreet() << " street\n";
    return ostream;
}

std::istream &operator>>(std::istream & istream, Adress & adress) {
//    std::cout << "please complete the address\n";
    std::cout << "Enter the country:";
    istream >> adress.country;
    std::cout << "Enter the city:";
    istream >> adress.city;
    std::cout << "Enter the street:";
    istream >> adress.street;
    return istream;
}
