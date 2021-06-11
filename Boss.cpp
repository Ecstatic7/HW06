
#include "Boss.h"

Boss::Boss(const std::string &name, const std::string &id, const Adress &adress, int hourWork, int salaryPerHour,
           int workToDo, int workDone, int numberOfEmployees) : Employee(name, id, adress, hourWork, salaryPerHour,
                                                                         workToDo, workDone),
                                                                numberOfEmployees(numberOfEmployees) {}

Boss::Boss() {}

Boss::Boss(const Boss &boss) : Employee(boss) {
    this->numberOfEmployees = boss.numberOfEmployees;
}

std::ostream &operator<<(std::ostream &ostream, Boss &boss) {
    ostream << static_cast<Employee &>(boss);
    ostream << " The number of employees are:" << boss.numberOfEmployees;
    return ostream;
}

std::istream &operator>>(std::istream &istream, Boss &boss) {
    istream >> static_cast<Employee &>(boss);
    std::cout << "Enter the number of Employees:";
    istream >> boss.numberOfEmployees;
    return istream;
}

Boss &Boss::operator=(const Boss & boss) {
    if (this != &boss){
        Employee::operator=(boss);
        this->numberOfEmployees = boss.numberOfEmployees;
    }
    return *this;
}

void Boss::setNumberOfEmployees(int numberOfEmployees) {
    Boss::numberOfEmployees = numberOfEmployees;
}

int Boss::getNumberOfEmployees() const {
    return numberOfEmployees;
}

double Boss::calculateSalary() const{
    double salary = Employee::calculateSalary();

    salary += salary*15/100;
    return salary;

}


