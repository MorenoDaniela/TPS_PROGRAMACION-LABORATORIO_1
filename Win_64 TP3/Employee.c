#include "Employee.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Employee* retorno=NULL;
    Employee* pAuxEmployee;

    if (idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo!=NULL)
    {
        pAuxEmployee=employee_new();
        if (pAuxEmployee!=NULL)
        {
            if (!employee_setIdString(pAuxEmployee,idStr) &&
                !employee_setNombre(pAuxEmployee,nombreStr) &&
                !employee_setHorasTrabajadasString(pAuxEmployee,horasTrabajadasStr)&&
                !employee_setSueldoString(pAuxEmployee,sueldo))
                {
                    retorno=pAuxEmployee;
                }else
                     {
                        employee_delete(pAuxEmployee);
                     }
        }
    }
    return retorno;
}

Employee* employee_newFileBinario(Employee empleado)
{
    Employee* retorno = NULL;
    Employee* pAux = employee_new();
    if(pAux != NULL)
    {
        if(!employee_setId(pAux,empleado.id)&&
           !employee_setNombre(pAux,empleado.nombre) &&
            !employee_setHorasTrabajadas(pAux,empleado.horasTrabajadas)&&
           !employee_setSueldo(pAux,empleado.sueldo))
        {
                retorno = pAux;
        }else
            {
                employee_delete(pAux);
            }
    }
    return retorno;
}

int employee_delete(Employee* this)
{
    int retorno=-1;

    if (this!=NULL )
    {
        free (this);
        retorno=0;
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidInt(id,1,2000000))
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;

    if (this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if (this!=NULL && nombre!=NULL )
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;

    if (this!=NULL && horasTrabajadas>=0 && isValidInt(horasTrabajadas,1,500))
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;

    if (this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

    if (this!=NULL && sueldo>=0 && isValidInt(sueldo,1,2000000))
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;

    if (this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_setIdString(Employee* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id!=NULL)
    {
        if (isNumber(id)==1)
        {
            retorno = employee_setId(this,atoi(id));
        }
    }
    return retorno;
}

int employee_getIdString(Employee* this, char* id)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && id != NULL)
    {
        employee_getId(this,&buffer);
        sprintf(id,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadasString(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas!=NULL)
    {
        if (isNumber(horasTrabajadas)==1)
        {
            retorno= employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
        }
    }
    return retorno;
}

int employee_getHorastrabajadasString(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && horasTrabajadas != NULL)
    {
        employee_getId(this,&buffer);
        sprintf(horasTrabajadas,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldoString(Employee* this, char* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo!=NULL)
    {
        if (isNumber(sueldo)==1)
        {
            retorno= employee_setSueldo(this,atoi(sueldo));
        }
    }
    return retorno;
}

int employee_getSueldoString(Employee* this, char* sueldo)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && sueldo != NULL)
    {
        employee_getSueldo(this,&buffer);
        sprintf(sueldo,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

int employee_compararNombre(void* this1, void* this2)
{
    int retorno=0;
    int comparacion;
    char auxStr1[4096];
    char auxStr2[4096];
    employee_getNombre((Employee*)this1,auxStr1);
    employee_getNombre((Employee*)this2,auxStr2);
    comparacion= strcmp(auxStr1,auxStr2);
    if (comparacion >0)
    {
        retorno=1;
    }else if (comparacion<0)
        {
            retorno= -1;
        }

    return retorno;
}
