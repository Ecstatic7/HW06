
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

    Company(int budget, Boss boss,  Employee ** &);

    Company(const Company &);

    ~Company();

    void setBudget(int budget);

    void setBoss(const Boss & boss);

    void setEmployees( Employee ** employees);


    friend std::ostream & operator << (std::ostream & ,const Company &);

    void sortEmployees();

};



#endif //HW06_COMPANY_H
