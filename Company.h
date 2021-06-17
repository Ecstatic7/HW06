
#ifndef HW06_COMPANY_H
#define HW06_COMPANY_H

#include "Boss.h"
#include "Employee.h"

class Company {
private:
    int budget;
    Boss * boss;
    Employee ** employees;

public:

    Company() =default;

    Company(int budget, Boss boss,  Employee ** &);

    Company(const Company &);

    ~Company();

    void setBudget(int budget);

    void setBoss(const Boss & boss);

    void setEmployees( Employee ** employees);


    int getBudget() const;

    Boss *getBoss() const;

    Employee **getEmployees() const;

    void sortEmployees() const;


    friend std::ostream & operator << (std::ostream & ,const Company &);
    friend std::istream & operator >> (std::istream & , Company &);



    Employee * maxEfficiency();

    double averageEfficiency();

    void checkBossEfficiency();

    void gift();

    void payForService();

    bool isEnoughBudget();

    void saveToFile();

};



#endif //HW06_COMPANY_H
