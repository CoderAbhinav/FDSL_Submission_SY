#include <iostream>
#include "database/database.h"
#include "database/employee.h"
#include "utils.h"

using namespace std;

void UI(int, database);

int main()
{
    cout << "\nEMPLOYEE DATABASE";
    int database_size;
    cout << "\nENTER THE DATABASE SIZE\n>>> ";
    cin >> database_size;
    database db(database_size);
    cout << "\nDATABASE CREATED SUCESSFULLY\n";
    int input = -1;
    while (input)
    {
        if (input == 1)
        {
            Employee temp = createEmployee();
            db.addEmployeeEntry(temp);
        }
        else if (input == 2)
        {
            db.displayDatabse();
        }
        else if (input == 3)
        {
            cout << "\nENTER THE ID\n>>> ";
            int id;
            cin >> id;
            int loc = db.getElementIndexByID(id);
            if (loc != -1)
            {
                Employee temp = db.getEmployeeByID(loc);
                printThisEmployeeDetail(temp);
            }
            else
            {
                cout << "\n!!! GIVEN ID DOES NOT EXIST";
            }
        }
        else if (input == 4)
        {
            cout << "\nENTER THE EMPLOYEE ID YOU WANT TO DELETE\n>>> ";
            int id;
            cin >> id;
            int loc = db.getElementIndexByID(id);
            if (loc != -1)
            {
                db.deleteEmployeeEntry(loc);
            }
            else
            {
                cout << "\n!!! GIVEN ID DOES NOT EXIST";
            }
        }
        input = displayOptions();
    }

    return 0;
}