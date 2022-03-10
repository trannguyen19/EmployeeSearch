// Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c

// gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    // defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);

    // defined in employeeTable.c

    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; // Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    // Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");


    // Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");

    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, (double) 8.32 );

    // Example found
    if (matchPtr != NULL)
        printf("Employee Salary: 8.32 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Salary: 8.32 is NOT found in the record\n");

    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries,(double) 7.35);

    // Example NOT found
    if (matchPtr != NULL)
        printf("Employee Salary: 7.35 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Salary: 7.35 is NOT found in the record\n");    


    // Example found
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "310-555-1215");

    if (matchPtr != NULL)
        printf("Employee phone number: 310-555-1215 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number: 310-555-1215 is NOT found in the record\n");

    // Example found
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-123-4567");

    if (matchPtr != NULL)
        printf("Employee phone number: 909-123-4567 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number: 909-123-4567 is NOT found in the record\n");
    

    return EXIT_SUCCESS;
}