#include <iomanip>
#include "Employee.h"

Employee::Employee(const std::string &name, const std::string &id, const Adress &adress, int hourWork,
                   int salaryPerHour, int workToDo, int workDone): Person(name, id, adress){
    if (validate(id)){
        this->hourWork = hourWork;
        this->salaryPerHour = salaryPerHour;
        this->workDone = workDone;
        this->workToDo = workToDo;
    } else{
        std::cout << "invalid id";
        exit(1);
    }
}

Employee::Employee(const Employee & employee) : Person(employee) {
    this->hourWork = employee.hourWork;
    this->salaryPerHour = employee.salaryPerHour;
    this->workDone = employee.workDone;
    this->workToDo = employee.workToDo;
}

void Employee::setHourWork(int hourWork) {
    Employee::hourWork = hourWork;
}

void Employee::setSalaryPerHour(int salaryPerHour) {
    Employee::salaryPerHour = salaryPerHour;
}

void Employee::setWorkToDo(int workToDo) {
    Employee::workToDo = workToDo;
}

void Employee::setWorkDone(int workDone) {
    Employee::workDone = workDone;
}

int Employee::getHourWork() const {
    return hourWork;
}

int Employee::getSalaryPerHour() const {
    return salaryPerHour;
}

int Employee::getWorkToDo() const {
    return workToDo;

}

int Employee::getWorkDone() const {
    return workDone;
}

std::ostream &operator<<(std::ostream & ostream, Employee & employee) {
    ostream << static_cast<Person&> (employee);
    ostream << " and my hour Work:" << employee.getHourWork()
    << " salary per hour:" << employee.getSalaryPerHour() << '$'
    << "  Works to do:" << employee.getWorkToDo()
    << "  Works that i have done:" << employee.getWorkDone();
    return ostream;
}

std::istream &operator>>(std::istream & istream, Employee & employee) {
    istream >> static_cast<Person &>(employee);
    std::cout << "Enter your hour work:";
    istream >> employee.hourWork;
    std::cout << "Enter your salary per hour:";
    istream >> employee.salaryPerHour;
    std::cout << "Enter number of works to do:";
    istream >> employee.workToDo;
    std::cout << "Enter number of works you done:";
    istream >> employee.workDone;
    return istream;
}

Employee::Employee() {}

Employee &Employee::operator=(const Employee & employee) {
    if (this != &employee) {
        Person::operator=(employee);
        setHourWork(employee.hourWork);
        setSalaryPerHour(employee.salaryPerHour);
        setWorkToDo(employee.workToDo);
        setWorkDone(employee.workDone);
    }
    return *this;
}

bool Employee::validate(std::string id) {
    if (!Person::validate(id))
        return false;

    if (id.at(2) != '*')
        return false;

    return true;
}

double Employee::calculateSalary() const {
    double percentage =(double )workDone/workToDo;
    double salary = hourWork * salaryPerHour;

    return salary * percentage;
}

double Employee::efficiency() const {
    double percentage =(double )workDone/workToDo * 100;

    return percentage/hourWork;
}