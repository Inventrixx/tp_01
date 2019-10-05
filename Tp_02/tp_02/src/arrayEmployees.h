#define TEXT_SIZE 51

struct
{
  int id;
  char name[TEXT_SIZE];
  char lastName[TEXT_SIZE];
  float salary;
  int sector;
  int isEmpty;
}typedef Employee;

int initEmployees(Employee* list, int len);
int searchEmpty(Employee* list, int len, int* index);
int addEmployee(Employee* list, int len, int *countID);
int findEmployeeById(Employee* list, int len,int searchValue, int* index);
int modifyEmployee(Employee* list, int len);
int removeEmployee(Employee* list, int len);
int sortEmployees(Employee* list, int len);
int printEmployees(Employee* list, int len);
int validateData(Employee* list, int len);
