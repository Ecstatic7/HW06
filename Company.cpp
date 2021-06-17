
#include "Company.h"
#include <fstream>


Company::Company(int budget, Boss boss, Employee **&employees) : budget(budget) {
    setBoss(boss);
    setEmployees(employees);

}

Company::~Company() {
    delete boss;

    for (int i = 0; i < boss->getNumberOfEmployees(); ++i)
        delete employees[i];

    delete[] employees;
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

void Company::setBoss(const Boss &boss) {
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

std::ostream &operator<<(std::ostream &output, const Company &company) {
    company.sortEmployees();
    int n = company.boss->getNumberOfEmployees();
    for (int i = 0; i < n; ++i) {
        output << *company.employees[i] << std::endl;
    }

    return output;
}

std::istream &operator>>(std::istream &input, Company &company) {
    Boss boss;
    input >> boss;
    company.setBoss(boss);

    int n = company.boss->getNumberOfEmployees();

    company.employees = new Employee *[n];

    for (int i = 0; i < n; ++i) {
        company.employees[i] = new Employee;

        Employee employee;
        input >> employee;
        *company.employees[i] = employee;
    }

    return input;
}

void Company::sortEmployees() const {
    int n = this->boss->getNumberOfEmployees();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (std::stoi(employees[j]->getId().substr(0, 2)) == std::stoi(employees[j + 1]->getId().substr(0, 2)))
                if ((employees[j]->getName() > employees[j + 1]->getName()))
                    std::swap(*employees[j], *employees[j + 1]);

            if (std::stoi(employees[j]->getId().substr(0, 2)) > std::stoi(employees[j + 1]->getId().substr(0, 2)))
                std::swap(*employees[j], *employees[j + 1]);
        }
    }
}

Employee *Company::maxEfficiency() {
    double maxx = this->employees[0]->efficiency();
    Employee *maxEmployee = this->employees[0];
    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i)
        if (this->employees[i]->efficiency() > maxx) {
            maxx = this->employees[i]->efficiency();
            maxEmployee = this->employees[i];
        }

    return maxEmployee;
}

double Company::averageEfficiency() {
    double average = 0;

    for (int i = 0; i < this->boss->getNumberOfEmployees(); ++i)
        average += employees[i]->efficiency();

    return average;
}

void Company::checkBossEfficiency() {
    if (boss->efficiency() < 40) {
        Employee *bestEmployee = maxEfficiency();
        int n = boss->getNumberOfEmployees();
        for (int i = 0; i < n; ++i) {
            if (employees[i] == bestEmployee) {
                *employees[i] = *dynamic_cast<Employee *>(boss);
                boss = dynamic_cast<Boss *>(bestEmployee);
                delete employees[i];
                employees[i] = new Boss;
                *employees[i] = *dynamic_cast<Boss *>(boss);
                delete boss;
                Employee * newBoss = new Boss;
                *newBoss = *bestEmployee;
                boss = dynamic_cast<Boss *>(newBoss);
                boss->setNumberOfEmployees(n);
            }
        }
    }
}

int Company::getBudget() const {
    return budget;
}

Boss *Company::getBoss() const {
    return boss;
}

Employee **Company::getEmployees() const {
    return employees;
}

void Company::gift() {
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        if (std::stoi(employees[i]->getId().substr(0, 2)) < 90) {
            int h = employees[i]->getHourWork();
            employees[i]->setHourWork(h + 5);
        }
    }
    this->maxEfficiency()->setHourWork(maxEfficiency()->getHourWork() + 10);
}

void Company::payForService() {
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        if (employees[i]->getAdress().getCity() != "tehran")
            employees[i]->setHourWork(employees[i]->getHourWork() + 7);
    }

}

bool Company::isEnoughBudget() {
    double maxBudget = 0;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        maxBudget += employees[i]->calculateSalary();
    }
    maxBudget += boss->calculateSalary();
    if (this->budget >= maxBudget)
        return true;
    return false;
}

void Company::saveToFile() {
    std::ofstream inp("properties.txt");
    int numberOfEmployees = boss->getNumberOfEmployees();
    inp << numberOfEmployees;
    for (int i = 0; i < numberOfEmployees; ++i) {
        std::string name = this->employees[i]->getName();
        std::string id = this->employees[i]->getId();
        double efficiency = this->employees[i]->efficiency();
        double salary = this->employees[i]->calculateSalary();
        inp << name << '\t' << id << '\t' << efficiency << '\t' << salary << std::endl;
    }

}







