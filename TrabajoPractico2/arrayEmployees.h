#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int initEmployees(Employee* lista, int len);
int addEmployees(Employee* lista,int id,char name[51],char lastName[51],float salary,int sector,int len);
int findEmptyPlace (Employee* lista,int len, int* result);
void printArray(Employee* lista, int len);
int findEmployeeById(Employee* lista,int id, int len);
int removeEmployee(Employee* lista, int id, int len);
int modifyEmployees(Employee* lista, int id, int len);
int sortEmployees(Employee* lista, int order, int len);
int averageSalary(Employee* lista, int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
