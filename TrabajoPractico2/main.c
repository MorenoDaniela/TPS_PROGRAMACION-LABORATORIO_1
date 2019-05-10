#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "arrayEmployees.h"
#define QTY_EMPLEADOS 1000
#define TRIES 3

int main()
{
    int opcion=0;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;
    int idEmployee=0;
    int flag=0;
    int posLibre;
    int ordena;

    Employee empleados [QTY_EMPLEADOS];
    initEmployees(empleados,QTY_EMPLEADOS);

    //Utilizar para probar
    strcpy(empleados[0].name,"Daniela");
    strcpy(empleados[0].lastName,"Moreno");
    empleados[0].id=0;
    empleados[0].salary=15000;
    empleados[0].sector=3;
    empleados[0].isEmpty=0;

    strcpy(empleados[1].name,"Ana");
    strcpy(empleados[1].lastName,"Corso");
    empleados[1].id=1;
    empleados[1].salary=20000;
    empleados[1].sector=3;
    empleados[1].isEmpty=0;

    strcpy(empleados[2].name,"Natalia");
    strcpy(empleados[2].lastName,"Branca");
    empleados[2].id=2;
    empleados[2].salary=30000;
    empleados[2].sector=2;
    empleados[2].isEmpty=0;

    strcpy(empleados[3].name,"Roman");
    strcpy(empleados[3].lastName,"Moreno");
    empleados[3].id=3;
    empleados[3].salary=30000;
    empleados[3].sector=1;
    empleados[3].isEmpty=0;
    flag=1;

    while (opcion!=7)
    {
        getInt("\n****MENU****\n1-Alta.\n2-Modificar.\n3-Baja.\n4-Lista sin ordenar.\n5-Lista ordenada por apellido y por sector\n"
               "6-Total y promedio de los salarios y cuantos empleados superan el salario promedio.\n"
               "7-Salir.\n","\nError, opcion invalida.\n",1,7,3,&opcion);
                system("cls");//system("clear");

               switch (opcion)
               {
                   case 1:
                       if (findEmptyPlace(empleados,QTY_EMPLEADOS,&posLibre)==0)
                       {
                           fflush(stdin);//__fpurge(stdin);
                            if (getName("Ingrese nombre del empleado.\n","Error, nombre no valido.\n",2,51,TRIES,auxName)==0 &&
                            getApellido("Ingrese apellido:\n","Error, apellido no valido.\n",2,51,TRIES,auxLastName)==0 &&
                            getFloat("Ingrese salario (Minimo 15.000 Maximo 30000):\n","Error,salario no valido.\n",15000,30000,TRIES,&auxSalary)==0 &&
                            getInt("Ingrese sector: \n1-Sector Uno. \n2.Sector Dos.\n3-Sector Tres.\n","Error, sector no valido.\n",1,3,TRIES,&auxSector)==0)
                            {
                              if (addEmployees(empleados,idEmployee,auxName,auxLastName,auxSalary,auxSector,QTY_EMPLEADOS)==0)
                              {
                                  idEmployee++;
                                  flag=1;
                                  printf("\nLos datos del empleado fueron cargados con exito\n");
                              }else
                              {
                                  printf("Carga incorrecta.\n");
                              }
                            }
                       }else
                        {
                            printf("\nNo hay espacio disponible.\n");
                        }
                    break;
                   case 2:
                       if (flag==1)
                       {
                           printArray(empleados,QTY_EMPLEADOS);
                           if (modifyEmployees(empleados,idEmployee,QTY_EMPLEADOS)==0)
                           {
                               printf("Las modificaciones fueron exitosas.\n");
                           }
                       }else
                        {
                            printf("\nNo hay empleados cargados.\n");
                        }
                    break;
                   case 3:
                       if (flag==1)
                       {
                           printArray(empleados, QTY_EMPLEADOS);
                           removeEmployee(empleados,idEmployee,QTY_EMPLEADOS);
                       }else
                        {
                            printf ("\nNo hay empleados cargados.\n");
                        }
                    break;
                   case 4:
                       if (flag==1)
                       {
                          printArray(empleados, QTY_EMPLEADOS);
                       }else
                        {
                            printf("\nNo hay empleados cargados.\n");
                        }

                    break;
                   case 5:
                       if (flag==1)
                       {
                           fflush(stdin);//__fpurge(stdin);
                           getInt("\n0-Ordena descendente.\n1-Ordena ascendente.\n2-Salir de ordenamiento.\nINGRESE OPCION: \n","Error, opcion no valida.",0,2,TRIES,&ordena);
                           switch (ordena)
                           {
                           case 0:
                               sortEmployeesCero(empleados,0,QTY_EMPLEADOS);
                               printArray(empleados, QTY_EMPLEADOS);
                            break;
                           case 1:
                               sortEmployeesUno(empleados,1,QTY_EMPLEADOS);
                               printArray(empleados, QTY_EMPLEADOS);
                            break;
                           case 2:
                            break;
                           }
                       }else
                       {
                           printf("\nNo hay empleados cargados.\n");
                       }
                    break;
                   case 6:
                       if (flag==1)
                       {
                           averageSalary(empleados,QTY_EMPLEADOS);
                       }else
                       {
                           printf("\nNo hay empleados cargados.\n");
                       }
                    break;
                   case 7:
                    break;
               }
    }
    return 0;
}
