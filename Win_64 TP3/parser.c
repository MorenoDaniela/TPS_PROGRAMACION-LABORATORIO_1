#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param FILE* pFile puntero a archivo.
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si pFile NULL o pArrayListEmployee NULL, 0 si logro parsear bien.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    char auxNombre[500];
    char auxId[500];
    char auxHoras[500];
    char auxSueldo[500];
    int flag=0;

    Employee* pAuxEmployee;

    if (pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while (!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo);

            if (flag==0)
            {
                flag++;
                continue;
            }
            pAuxEmployee = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);
            if (pAuxEmployee !=NULL)
            {
                ll_add(pArrayListEmployee,pAuxEmployee);
                retorno=0;
            }
        }
        fclose(pFile);
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param FILE* pFile puntero a archivo.
 * \param pArrayListEmployee LinkedList* puntero al array de empleados.
 * \return int retorno -1 si pFile NULL o pArrayListEmployee NULL, 0 si logro parsear bien.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* pEmpleado;
    Employee empleado;

    if (pFile!=NULL && pArrayListEmployee!=NULL)
    {
        while (!feof(pFile))
        {
            pEmpleado = employee_newBinario(empleado);
            fread(&empleado,sizeof(Employee),1,pFile);

            if(pEmpleado!=NULL)
            {
                ll_add(pArrayListEmployee,pEmpleado);
                retorno=0;
            }
        }
        fclose(pFile);
    }
    return retorno;
}
