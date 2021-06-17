#include "Employee.h"

#ifndef HW06_BOSS_H
#define HW06_BOSS_H


class Boss : public Employee {
private:
    int numberOfEmployees;
public:
    Boss();

    Boss(const std::string &name, const std::string &id, const Adress &adress, int hourWork, int salaryPerHour,
         int workToDo, int workDone, int numberOfEmployees);

    Boss(const Boss &);

    friend std::ostream &operator<<(std::ostream &, Boss &);

    friend std::istream &operator>>(std::istream &, Boss &);

    Boss & operator=(const Boss &);

    void setNumberOfEmployees(int numberOfEmployees);

    int getNumberOfEmployees() const;

    double calculateSalary() const ;
};


#endif //HW06_BOSS_H
