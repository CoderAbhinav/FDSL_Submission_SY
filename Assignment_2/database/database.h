#pragma once
#include <iostream>
#include <iomanip>
#include "employee.h"
#include "utils.h"
using namespace std;

class database
{
private:
    int pointer = 0;

public:
    Employee *employee_list;
    int max_size;
    int elements = 0;

    database(int);
    void addEmployeeEntry(Employee);
    void displayDatabse();
    int getElementIndexByID(int emloyee_id);
    Employee getEmployeeByID(int index);
    void deleteEmployeeEntry(int index);
};

database::database(int max_size)
{
    this->employee_list = new Employee[max_size];
    this->max_size = max_size;
}

void database::addEmployeeEntry(Employee e)
{
    /*
    The employee id is dominant for comparisons
    */

    // checks if limit is exceeded
    if (elements == max_size)
    {
        cout << "\n!!! DATABASE IS FULL !!! ... Try deleting some entries\n";
        return;
    }

    // getting the target position
    int target_pos = getPerfectPosition(employee_list, elements, e);

    // check if element with same id exists or not
    if (this->employee_list[target_pos - 1].id != e.id)
    {
        // if not then adds a new entry
        shiftPlaceAndInsertForward(target_pos, elements, employee_list, e);
        this->elements++;
    }
    else
    {
        // if yes then merges the entry
        this->employee_list[target_pos - 1] = e;
    }

    this->pointer++;
}

void database::displayDatabse()
{
    cout << left << std::setfill(' ') << std::setw(5) << "ID" << std::setw(15) << "NAME" <<  std::setw(10) << "SALARY"
         << "\n";
    for (int i = 0; i < this->elements; i++)
    {
        Employee temp = this->employee_list[i];
        cout << setfill(' ') << setw(5) << temp.id << setw(15) << temp.name << std::setw(10) << temp.salary << "\n";
    }
}

int database::getElementIndexByID(int employee_id)
{
    return binarySearch(employee_list, 0, elements, employee_id);
}

Employee database::getEmployeeByID(int index)
{
    // returns employee object at given index
    return this->employee_list[index];
}

void database::deleteEmployeeEntry(int index)
{
    if (index == this->elements - 1)
    {
    }
    else
    {
        shiftEntriesBackward(index, elements, employee_list);
    }
    elements--;
}