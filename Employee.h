
#ifndef HW06_EMPLOYEE_H
#define HW06_EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;
public:
    Employee();
    Employee(const std::string &name, const std::string &id, const Adress &adress, int hourWork,
             int salaryPerHour, int workToDo, int workDone);

    Employee(const Employee &);

    /// setters
    void setHourWork(int hourWork);

    void setSalaryPerHour(int salaryPerHour);

    void setWorkToDo(int workToDo);

    void setWorkDone(int workDone);

    /// getters
    int getHourWork() const;

    int getSalaryPerHour() const;

    int getWorkToDo() const;

    int getWorkDone() const;

    friend std::ostream & operator <<(std::ostream & , Employee &);
    friend std::istream & operator >>(std::istream & ,  Employee &);
    Employee & operator=(const Employee &);

     bool validate(std::string) override;

     virtual double calculateSalary() const;

     double efficiency() const;
};


#endif //HW06_EMPLOYEE_H
