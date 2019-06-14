#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"
#include "Controller.h"
#define MAX_ID 5000
#define MAX_HORAS 500
#define MAX_SUELDO 2000000
#define SORT_DOWN 0
#define SORT_UP 1

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si path NULL o pArrayListEmployee NULL - 0 si logra cargar los datos correctamente.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;
    FILE* pFile = NULL;

    if (path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen (path, "r");
        getInt("Esta a punto de cargar la lista: \nSi desea conservar los cambios hechos debe volver al menu y elegir la opcion 8.\n"
                "Si ya ha guardado los cambios o esta es la primera vez que carga la lista solo seleccione continuar.\n\n 1-Volver al menu.\n 2-Continuar.\n","Error, opcion invalida.\n",1,2,3,&opcion);
            if(opcion==2)
            {
                if (pFile!=NULL)
                {
                    ll_clear(pArrayListEmployee);
                    if (!parser_EmployeeFromText(pFile,pArrayListEmployee))
                    {
                        retorno=0;
                        printf ("Carga ok.\n");
                    }
                }
            }
        fclose (pFile);
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char* archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si path NULL o pArrayListEmployee NULL - 0 si logra cargar los datos correctamente.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE *pFile = NULL;
    int opcion;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");
        getInt("Esta a punto de cargar la lista: \nSi desea conservar los cambios hechos debe volver al menu y elegir la opcion 8.\n"
                "Si ya ha guardado los cambios o esta es la primera vez que carga la lista solo seleccione continuar.\n\n 1-Volver al menu.\n 2-Continuar.\n","Error, opcion invalida.\n",1,2,3,&opcion);
            if(opcion==2)
            {
                if(pFile != NULL)
                {
                    ll_clear(pArrayListEmployee);
                    if (!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
                    {
                        retorno=0;
                        printf ("Carga binaria ok.\n");
                    }
                }
            }
         fclose(pFile);
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si pArrayListEmployee NULL o si no logra agregar al empleado nuevo - 0 si logra agregarlo correctamente
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* pAuxEmployee = employee_new();
    int bufferSueldo;
    int bufferHoras;
    char bufferName[500];
    int ID;

    if (pArrayListEmployee!=NULL && pAuxEmployee!=NULL)
    {
        ID=controller_maxId(pArrayListEmployee);
        if (getName("\nIngrese nombre: \n","Error, nombre no valido.\n",2,35,3,bufferName)==0 &&
            getInt("Ingrese cantidad horas trabajadas: ","Error, horas no validas.\n",1,MAX_HORAS,3,&bufferHoras)==0 &&
            getInt("Ingrese sueldo: ","Error, sueldo no valido.\n",500,MAX_SUELDO,3,&bufferSueldo)==0)
            {
                employee_setId(pAuxEmployee,ID);
                employee_setNombre(pAuxEmployee,bufferName);
                employee_setHorasTrabajadas(pAuxEmployee,bufferHoras);
                employee_setSueldo(pAuxEmployee,bufferSueldo);
                ll_add(pArrayListEmployee,pAuxEmployee);
                printf ("Empleado agregado correctamente.\n");
                retorno=0;
            }else
                printf ("\nNo se pudo agregar el empleado nuevo.\n");
    }
    return retorno;
}
/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si puntero a pArrayLinkedlist NULL o si no se encuentra el id -0 si logra modificar los datos del empleado.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int bufferSueldo;
    int bufferHoras;
    char bufferNombre[500];
    int ID;
    int index;
    int opcion;
    Employee* pAux;

    if (pArrayListEmployee!=NULL)
    {
        if (getInt("\nIngrese id del empleado para modificar sus datos: \n","Error, id no valido.",1,MAX_ID,3,&ID)==0)
        {
            index = controller_returnIndex(pArrayListEmployee,&ID);
            pAux = ll_get(pArrayListEmployee,index);
            printf ("\n El id del empleado a modificar es: %d\n",ID);
            if (index!=-1 && pAux!=NULL)
            {
                do
                {
                    getInt ("Ingrese opcion a modificar:\n 1-Nombre.\n 2-Sueldo.\n 3-Horas trabajadas.\n 4-Salir de modificacion.\n","Error, opcion no valida.\n",1,4,3,&opcion);
                    switch (opcion)
                    {
                    case 1:
                        if (getName("Ingrese nuevo nombre del empleado: \n","Error, nombre no valido.\n",2,50,3,bufferNombre)==0)
                        {
                            employee_setNombre(pAux,bufferNombre);
                            printf("\nModificacion exitosa.\n");
                            retorno=0;
                        }else
                            printf ("\nModificacion sin exito.\n");
                        break;
                    case 2:
                        fflush(stdin);
                        if (getInt("Ingrese nuevo sueldo: \n","Error, sueldo no valido.\n",1,MAX_SUELDO,3,&bufferSueldo)==0)
                        {
                            employee_setSueldo(pAux,bufferSueldo);
                            printf("\nModificacion exitosa.\n");
                            retorno=0;
                        }else
                            printf ("\nModificacion sin exito.\n");
                        break;
                    case 3:
                        fflush(stdin);
                        if (getInt("Ingrese horas trabajadas nuevas: \n","Error, horas no validas.\n",1,MAX_HORAS,3,&bufferHoras)==0)
                        {
                            employee_setHorasTrabajadas(pAux,bufferHoras);
                            printf("\nModificacion exitosa.\n");
                            retorno=0;
                        }else
                            printf ("\nModificacion sin exito.\n");
                        break;
                    case 4:
                        break;
                    }
                }while(opcion!=4);
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si puntero a pArrayLinkedlist NULL o si no se encuentra el id, 0 si logra eliminar el empleado.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int ID;
    int index;
    Employee* pAux=NULL;

    if (pArrayListEmployee!=NULL)
    {
        if (getInt("Ingrese id del empleado a dar de baja: ","Error, id no valido.\n",1,MAX_ID,3,&ID)==0)
        {
            index=controller_returnIndex(pArrayListEmployee,&ID);
            if (index!=-1)
            {
                pAux=ll_pop(pArrayListEmployee,index);
                if (pAux!=NULL)
                {
                    employee_delete(pAux);
                    printf ("\nBaja exitosa del empleado con id: %d.\n",ID);
                    retorno=0;
                }else
                    printf ("\nNo se pudo dar de baja.\n");
            }else
                printf ("\nNo se encontro el id. Intente de nuevo.\n");
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si puntero a pArrayListEmployee NULL, 0 si logra listar correctamente.
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* pEmpleado;
    int auxId;
    int auxSueldo;
    int auxHoras;
    char bufferName[500];
    int length;
    int i;

    if (pArrayListEmployee!=NULL)
    {
        length=ll_len(pArrayListEmployee);
        for (i=0;i<length;i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            if (pEmpleado!=NULL)
            {
                if (!employee_getId(pEmpleado,&auxId) &&
                !employee_getNombre(pEmpleado, bufferName) &&
                !employee_getSueldo(pEmpleado,&auxSueldo) &&
                !employee_getHorasTrabajadas(pEmpleado,&auxHoras))
                {
                    printf("ID:%d Nombre:%s Horas:%d Sueldo:%d\n",auxId, bufferName, auxHoras, auxSueldo);
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordena los empleados de forma ascendente.
 *
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si puntero a pArrayListEmployee NULL - 0 si logra ordenar.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if (pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_compararNombre,SORT_UP);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* puntero al archivo data.csv
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si path NULL o pArrayListEmployee NULL, 0 si logra guardar los datos correctamente.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int lenth;
    int id;
    char name[4096];
    int horas;
    int sueldo;

    Employee *pEmployee=NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            lenth= ll_len(pArrayListEmployee);
            for(i=0;i<lenth;i++)
            {
                pEmployee =ll_get(pArrayListEmployee,i);
                if ( pEmployee!=NULL &&
                    !employee_getId(pEmployee,&id) &&
                    !employee_getNombre(pEmployee,name) &&
                    !employee_getHorasTrabajadas(pEmployee,&horas) &&
                    !employee_getSueldo(pEmployee,&sueldo))
                    {
                        fprintf(pFile,"%d,%s,%d,%d\n",id,name,horas,sueldo);
                    }else
                        employee_delete(pEmployee);
            }
            retorno = 0;
        }
        if (retorno==0)
        {
            printf ("\nLista guardada correctamente.\n");
        }else
            printf ("\nNo se pudo guardar la lista correctamente.\n");
        fclose(pFile);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* puntero al archivo data.bin
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si path NULL o pArrayListEmployee NULL, 0 si logra guardar los datos correctamente.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int lenth;
    Employee *pEmployee=NULL;
    FILE *pFile = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            lenth= ll_len(pArrayListEmployee);
            for(i=0;i<lenth;i++)
            {
                pEmployee = ll_get(pArrayListEmployee,i);
                if (pEmployee!=NULL)
                {
                    fwrite(pEmployee,sizeof(Employee),1,pFile);
                }
            }
            retorno = 0;
        }

        if (retorno==0)
        {
            printf ("\nLista en modo binario guardada correctamente.\n");
        }else
            printf ("\nNo se pudo guardar la lista correctamente.\n");
        fclose(pFile);
    }
    return retorno;
}

/** \brief Recorre el array de empleados, busca el id maximo y lo incrementa.
 *
 * \param LinkedList* pArrayEmployee puntero al array de empleados.
 * \return int retorno -1 si pArrayEmployee NULL - si encuentra el id maximo lo retorna incrementado.
 *
 */

int controller_maxId(LinkedList* pArrayEmployee)
{
    int retorno=-1;
    int lenth;
    int ID;
    int maxID=0;
    int i;
    Employee* pAuxEmployee;

    lenth= ll_len(pArrayEmployee);

    if (pArrayEmployee!=NULL)
    {
        for (i=0;i<lenth;i++)
        {
            pAuxEmployee=ll_get(pArrayEmployee,i);
            if (pAuxEmployee!=NULL)
            {
                 employee_getId(pAuxEmployee,&ID);
                if (ID>maxID)
                {
                    maxID=ID;
                }
            }
        }
        maxID=maxID+1;
        retorno=maxID;
    }
    return retorno;
}
/** \brief Devuelve la posicion en la que se encuentra el elemento buscado.
 *
 * \param LinkedList* pArrayEmployee puntero al array de empleados.
 * \param int *valorBuscado puntero al valor a buscar.
 * \return int retorno -1 si pArrayEmployee NULL o valorBuscado NULL, retorna la posicion si logra encontrar el valor buscado
 *
 */

int controller_returnIndex(LinkedList* pArrayEmployee,int* valorBuscado)
{
    int retorno=-1;
    int i;
    int ID;
    int lenth = ll_len(pArrayEmployee);
    Employee* pAuxEmployee;

    if (pArrayEmployee!=NULL && valorBuscado!=NULL)
    {
        for (i=0;i<=lenth;i++)
        {
            pAuxEmployee= ll_get(pArrayEmployee,i);
            employee_getId(pAuxEmployee,&ID);
            if (ID==*valorBuscado)
            {
                *valorBuscado=ID;
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
