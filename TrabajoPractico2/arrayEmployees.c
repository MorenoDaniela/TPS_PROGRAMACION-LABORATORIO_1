#ifndef ARRAYEMPLOYEES_C_INCLUDED
#define ARRAYEMPLOYEES_C_INCLUDED
#include "arrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TRIES 3
#define TRUE 1
#define FALSE 0

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
 *(isEmpty) en TRUE en todas las posiciones del array.
 * \param Employee* lista puntero al array de empleados.
 * \param int len el len del array.
 * \return int retorna -1 si el len es invalido o el puntero es nulo, retorna 0
 * si salio todo bien.
 */
int initEmployees(Employee* lista, int len)
{
    int retorno = -1;
    int i;
    if (lista!=NULL && len>0)
    {
        for (i=0; i<=len; i++)
        {
            lista[i].isEmpty = TRUE;
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Recorre el array buscando una posicion libre.
 * \param Employee* lista puntero al array de empleados.
 * \param int len es el limite del array.
 * \param int puntero a result posicion libre.
 * \return int retorna -1 si el puntero a lista es nulo, o el limite es menor a 0 o el puntero a resultado es nulo, 0 si todo salio bien.
 */
int findEmptyPlace (Employee* lista,int len, int* result)
{
    int retorno=-1;
    int i;

    if (lista!=NULL && len>0 && result!=NULL)
    {
       for (i=0;i<=len;i++)
        {
            if (lista[i].isEmpty==TRUE)
            {
                *result=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Adhiere en una lista existente de empleados los valores recibidos como parametros en la primer posicion libre.
 *\param Employee* lista puntero al array de empleados.
 * \param int len, limite del array de empleados.
 * \param int id, id del empleado.
 *\param char name, nombre recibido.
 *\param char lastName, apellido recibido.
 *\param salary float, salario recibido.
 *\param int sector, sector recibido.
 * \return int retorna -1 si el puntero es nulo o el limite es menor a 0, retorna 0 si todo salio bien.
 */
int addEmployees(Employee* lista,int id,char name[51],char lastName[51],float salary,int sector,int len)
{
    int retorno=-1;
    fflush(stdin);
    if (lista!=NULL && len>0)
    {
        lista[id].id=id;
        strncpy(lista[id].name,name,51);
        strncpy(lista[id].lastName,lastName,51);
        lista[id].salary=salary;
        lista[id].sector=sector;
        lista[id].isEmpty=FALSE;
        retorno=0;
    }else
        {
            printf("Error, intente de nuevo.\n");
        }
    return retorno;
}

/** \brief Imprime el array de empleados en todas las posiciones que esten ocupadas por un empleado.
 * \param Employee* puntero a la lista de empleados.
 * \param int len, limite del array de empleados.
 * \return void.
 */
void printArray(Employee* lista, int len)
{
    int i;

    printf ("\n*** Lista ***\n");

    for (i=0;i<len;i++)
    {
        if (lista[i].isEmpty==FALSE)
        {
            printf ("\n********************************************");
            printf ("\nNombre del empleado: %s ",lista[i].name);
            printf ("\nApellido del empleado: %s ",lista[i].lastName);
            printf ("\nSector del empleado: %d ",lista[i].sector);
            printf ("\nSalario del empleado: %2.f ",lista[i].salary);
            printf ("\nId del empleado: %d ",lista[i].id);
            printf ("\nPosicion: %d ",i);
            printf ("\nEstado : %d \n",lista[i].isEmpty);
        }
    }
}

/** \brief Recorre el array de empleados buscando el id ingresado.
 * \param Employee* lista puntero al array de empleados.
 * \param int id, id del empleado.
 *\param int len, limite del array de empleados.
 * \return Retorna -1 si no encuentra el id del empleado, si el puntero es nulo
 o el limite es menor a 0, retorna el id del empleado si todo salio bien.
 */
int findEmployeeById(Employee* lista,int id, int len)
{
    int i;
    int retorno=-1;
    Employee buffer;
    if (lista!=NULL && len>0)
    {
        if (getInt("Ingrese el id del empleado: \n","Error, ingreso incorrecto.\n",0,len,TRIES,&buffer.id)==0)
        {
            for (i=0;i<=len;i++)
            {
                if (buffer.id == lista[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief Elimina de manera logica (isEmpty FALSE) y lo convierte en TRUE.
 * \param Employee* lista a puntero de array de empleados.
 * \param int id, id del empleado.
 *\param int len, limite del array de empleados.
 * \return retorna -1 si el puntero al array es nulo, -1 si el limite es menor a 0, -1 si no encuentra el id del empleado
 *retorna 0 si salio todo bien.
 */
int removeEmployee(Employee* lista, int id, int len)
{
    int retorno=-1;
    int pos;
    if (lista!=NULL && len>0)
    {
        pos=findEmployeeById(lista,id,len);

        if(pos!=-1)
        {
             if (lista[pos].isEmpty==FALSE)
             {
                 lista[pos].isEmpty=TRUE;
                 printf("Se borro el empleado con id: %d \n",lista[pos].id);
                 retorno=0;
             }
        }else
            {
                printf("No se encontro el empleado.\n");
            }
    }
    return retorno;
}

/** \brief Modifica los campos nombre, apellido, salario o sector segun se elija.
 * \param Employee* lista puntero al array de empleados.
 * \param int id, del empleado.
 *\param int len, limite del array de empleados.
 * \return Retorna -1 si el puntero a lista es nulo, -1 si el limite es menor a 0, -1 si no encuentra el id de empleado, -1 si no se pudo modificar con exito.
 *retorna 0 si salio todo bien y las modificaciones fueron exitosas.
 */
int modifyEmployees(Employee* lista, int id, int len)
{
    int retorno=-1;
    int posicion;
    int opcion;
    int auxSector;
    float auxSalary;

    if (lista!=NULL && len>0)
    {
        fflush(stdin);
        posicion=findEmployeeById(lista,id,len);
        if (posicion!=-1)
        {
            while (opcion!=5)
            {
                fflush(stdin);
                getInt("\n1-Modificar nombre.\n2-Modificar apellido.\n3-Modificar sector.\n4-Modificar salario.\n"
                       "5-Salir de modificacion.\nINGRESE UNA OPCION:\n","Error, opcion incorrecta.\n",1,5,TRIES,&opcion);

                switch(opcion)
                {
                case 1:
                    fflush(stdin);
                    if (getName("\nIngrese nuevo nombre: \n","Error, nombre no valido.\n",2,51,TRIES,lista[posicion].name)==0)
                    {
                       printf("Modificacion con exito.\n");
                    }else
                        {
                            printf("Error, no se pudo modificar.\n");
                        }
                    break;
                case 2:
                    fflush(stdin);
                    if (getApellido("\nIngrese nuevo apellido: \n","Error, apellido no valido.\n",2,51,TRIES,lista[posicion].lastName)==0)
                    {
                        printf("Modificacion con exito.\n");
                    }else
                        {
                            printf("Error, no se pudo modificar.\n");
                        }
                    break;
                case 3:
                    fflush(stdin);
                    if(getInt("\nIngrese el nuevo sector: 1-Sector uno.\n2-Sector dos.\n3-Sector tres.\n","Error, sector no valido.",1,3,TRIES,&auxSector)==0)
                    {
                        lista[posicion].sector=auxSector;
                        printf("Modificacion con exito.\n");
                    }else
                        {
                            printf("Error, no se pudo modificar.\n");
                        }
                    break;
                case 4:
                    fflush(stdin);
                    if (getFloat("\nIngrese el salario nuevo: \n","Error, salario no valido.\n",15000,30000,TRIES,&auxSalary)==0)
                    {
                        lista[posicion].salary=auxSalary;
                        printf("Modificacion con exito.\n");
                    }else
                        {
                            printf("Error, no se pudo modificar.\n");
                        }
                    break;
                case 5:
                    break;
                }
            }
            retorno=0;
        }else
            {
                printf("No se encontro el id del empleado.\n");
            }
    }
    return retorno;
}

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 * \param Employee* lista puntero al array de empleados.
 * \param int order, 1 indica UP (ascendente) 0 indica DOWN (descendente)
 *\param int len, limite del array de empleados.
 * \return Retorna -1 si el puntero es nulo o el limite es menor a 0, 0 si salio todo bien y fue ordenado con exito.
 */
int sortEmployees(Employee* lista, int order, int len)
{
    int i;
    int j;
    Employee buffer;
    int retorno = -1;
    if(lista!= NULL && len > 0)
    {
        if (order==1)
        {
            for(i=0; i<=len; i++)
            {
                 if(lista[i].isEmpty==TRUE || lista[i+1].isEmpty==TRUE)
                {
                    continue;
                }

                for(j=i+1; j<=len; j++)
                {
                    if(strncmp(lista[i].lastName,lista[j].lastName,51)>0)
                    {
                        buffer = lista[i];
                        lista[i] = lista[j];
                        lista[j] = buffer;
                    }
                    else if(strncmp(lista[i].lastName,lista[j].lastName,51)==0)
                    {
                        if(lista[i].sector > lista[j].sector)
                        {
                            buffer = lista[i];
                            lista[i] = lista[j];
                            lista[j] = buffer;
                        }
                    }
                retorno = 0;
                }
            }
        }else if(order==0)
        {
             for(i=0; i<=len; i++)
            {
                 if(lista[i].isEmpty==TRUE || lista[i+1].isEmpty==TRUE)
                {
                    continue;
                }

                for(j=i+1; j<=len; j++)
                {
                    if(strncmp(lista[i].lastName,lista[j].lastName,51)<0)
                    {
                        buffer = lista[i];
                        lista[i] = lista[j];
                        lista[j] = buffer;
                    }
                    else if(strncmp(lista[i].lastName,lista[j].lastName,51)==0)
                    {
                        if(lista[i].sector < lista[j].sector)
                        {
                            buffer = lista[i];
                            lista[i] = lista[j];
                            lista[j] = buffer;
                        }
                    }
                retorno = 0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Calcula el salario promedio, el total de los salarios y la cantidad de empleados que superaron el salario promedio.
 * \param Employee* lista puntero al array de empleados.
 * \param int len, limite del array de empleados.
 * \return retorna -1 si el puntero es nulo o el limite es menor a 0, retorna 0 si salio todo bien.
 */
int averageSalary(Employee* lista, int len)
{
    int i;
    int j;
    int retorno=-1;
    float average=0;
    float promedio=0;
    int empleado=0;
    int exceedsAverage=0;

    if (lista!=NULL && len>0)
    {
        for (i=0;i<=len;i++)
        {
            if(lista[i].isEmpty==FALSE)
            {
                average = average + lista[i].salary;
                empleado++;

            }
        }
        promedio=average/empleado;
        printf("\nEl promedio de todos los salarios es: %2.f \n",promedio);
        printf("\nLa suma de todos los salarios es: %2.f \n",average);
        for (j=0;j<=len;j++)
        {
            if (lista[j].isEmpty==FALSE)
            {
                if (lista[j].salary>=promedio)
                {
                    exceedsAverage++;
                }
            }
        }

        printf("\nLa cantidad de empleados que supera el salario promedio es: %d \n",exceedsAverage);
        retorno=0;
    }
    return retorno;
}

#endif // ARRAYEMPLOYEES_C_INCLUDED
