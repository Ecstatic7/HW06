
#include "Company.h"


Company::Company(int budget, Boss boss, Employee **&employees) : budget(budget) {
    setBoss(boss);
    setEmployees(employees);

    sortEmployees();
}

Company::~Company() {
    delete boss;

    for (int i = 0; i < boss->getNumberOfEmployees(); ++i)
        delete  employees[i];

    delete [] employees;
}

Company::Company(const Company &company) {

    this->Company::~Company();

    this->budget = company.budget;

    setBoss(*company.boss);
    setEmployees(company.employees);
}

void Company::setBudget(int budget) {
    Company::budget = budget;
}

void Company::setBoss(const Boss & boss) {
    this->boss = new Boss;
    *this->boss = boss;
}

void Company::setEmployees(Employee **employees) {
    int numberOfEmployees = boss->getNumberOfEmployees();
    this->employees = new Employee *[numberOfEmployees];

    for (int i = 0; i < numberOfEmployees; ++i) {
        this->employees[i] = new Employee;
        *this->employees[i] = *employees[i];
    }
}

std::ostream &operator<<(std::ostream & output, const Company & company) {
    int n = company.boss->getNumberOfEmployees();
    for (int i = 0; i < n; ++i) {
        output << *company.employees[i] << '\t';
    }

    return output;
}

void Company::sortEmployees() {
    int n = this->boss->getNumberOfEmployees();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (std::stoi(employees[j]->getId().substr(0,2)) > std::stoi(employees[j+1]->getId().substr(0,2)) )
                std::swap(*employees[j] , *employees[j+1]);
        }
    }
}


