#include "Employee.h"
#include "validaciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ID 5000
#define MAX_HORAS 500
#define MAX_SUELDO 2000000

/** \brief Reserva espacio en memoria para un empleado
 * \param void
 * \return Employee*
 */
Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

/** \brief Valida los campos y los carga en una variable Employee
 *
 * \param idStr char* id en modo texto.
 * \param nombreStr char*
 * \param horasTrabajadasStr char* horas trabajadas en texto.
 * \param sueldo char* sueldo en texto.
 * \return Employee* pAuxEmployee, NULL si puntero a idStr/nombreStr/horasTrabajdasStr/sueldo NULL, pAuxEmployee si salio todo bien.
 *
 */
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

/** \brief Valida los campos y los carga en una variable Employee
 * \param empleado Employee
 * \return Employee*
 */
Employee* employee_newBinario(Employee empleado)
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
/** \brief Libera el espacio reservado en memoria para un empleado.
 *
 * \param Employee* this
 * \return int retorno -1 si this NULL, 0 si logro liberar correctamente.
 *
 */
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

/** \brief Valida el id y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param id int
 * \return int retorno -1 si this es NULL, id menor a 0 o si id no es un numero, 0 si ok.
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno=-1;

    if (this!=NULL && id>=0 && isValidInt(id,1,MAX_ID))
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el id de un empleado.
 *
 * \param this Employee* empleado
 * \param int* id
 * \return int retorno -1 si this es NULL o id es NULL, 0 si se obtuvo bien.
 *
 */
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

/** \brief Valida el nombre y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param nombre char*
 * \return int retorno -1 si this es NULL, si nombre es NULL o si nombre no es un nombre, 0 si logra validar y cargar.
 *
 */
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

/** \brief Obtiene el nombre de un empleado.
 *
 * \param this Employee* empleado
 * \param char* nombre
 * \return int retorno -1 si this es NULL o nombre es NULL, 0 si se obtuvo bien.
 *
 */
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

/** \brief Valida las horas trabajdas y la carga en la variable Employee
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int retorno -1 si this es NULL, horasTrabajadas menor a 0 o si horasTrabajadas no es un numero, 0 si ok.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;

    if (this!=NULL && horasTrabajadas>=0 && isValidInt(horasTrabajadas,1,MAX_HORAS))
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param this Employee* empleado
 * \param int* horasTrabajadas
 * \return int retorno -1 si this es NULL o horasTrabajadas es NULL, 0 si se obtuvo bien.
 *
 */
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

/** \brief Valida el sueldo y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param sueldo int
 * \return int retorno -1 si this es NULL, sueldo menor a 0 o si sueldo no es un numero, 0 si ok.
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

    if (this!=NULL && sueldo>=0 && isValidInt(sueldo,1,MAX_SUELDO))
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtiene el sueldo de un empleado.
 *
 * \param this Employee* empleado
 * \param int* sueldo
 * \return int retorno -1 si this es NULL o sueldo es NULL, 0 si se obtuvo bien.
 *
 */
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

/** \brief Valida el id y lo carga en la variable Employee
 *
 * \param Employee* this
 * \param id char* id string.
 * \return int retorno -1 si this es NULL, si id es NULL o si id no es un numero.
 *
 */
int employee_setIdString(Employee* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id!=NULL)
    {
        if (isValidNumber(id))
        {
            retorno = employee_setId(this,atoi(id));
        }
    }
    return retorno;
}

/** \brief Obtiene el id de un empleado como string.
 *
 * \param this Employee* empleado
 * \param char* id
 * \return int retorno -1 si this es NULL o id es NULL, 0 si todo ok.
 *
 */
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
/** \brief Valida las horas trabajadas y lo carga en la variable Employee
 *
 * \param Employee* this
 * \param horasTrabajadasStr char* horas trabajadas string.
 * \return int retorno -1 si this es NULL, si horasTrabajadasStr es NULL o si horas trabajadas no es un numero.
 *
 */
int employee_setHorasTrabajadasString(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas!=NULL)
    {
        if (isValidNumber(horasTrabajadas))
        {
            retorno= employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
        }
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado como string.
 *
 * \param this Employee* empleado
 * \param char* horasTrabajadas
 * \return int retorno -1 si this es NULL o horasTrabajadas es NULL, 0 si todo ok.
 *
 */
int employee_getHorastrabajadasString(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && horasTrabajadas != NULL)
    {
        employee_getHorasTrabajadas(this,&buffer);
        sprintf(horasTrabajadas,"%d",buffer);
        retorno = 0;
    }
    return retorno;
}

/** \brief Valida el sueldo y lo carga en la variable Employee
 *
 * \param Employee* this
 * \param sueldoStr char* sueldo string.
 * \return int retorno -1 si this es NULL, si sueldo es NULL o si sueldo no es un numero.
 *
 */
int employee_setSueldoString(Employee* this, char* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo!=NULL)
    {
        if (isValidNumber(sueldo))
        {
            retorno= employee_setSueldo(this,atoi(sueldo));
        }
    }
    return retorno;
}

/** \brief Obtiene el sueldo de un empleado como string.
 *
 * \param this Employee* empleado
 * \param char* sueldo
 * \return int retorno -1 si this es NULL o sueldo es NULL, 0 si todo ok.
 *
 */
int employee_getSueldoString(Employee* this, char* sueldo)
{
    int retorno = -1;
    int buffer;

    if(this != NULL && sueldo != NULL)
    {
        employee_getSueldo(this,&buffer);
        sprintf(sueldo,"%d",buffer);//sprintf convierte un int en una cadena
        retorno = 0;
    }
    return retorno;
}

/** \brief Compara entre 2 nombres
 *
 * \param this1 void* primer empleado.
 * \param this2 void* segundo empleado
 * \return int retorno: -1 si el segundo nombre es el mayor, 1 si el primer nombre es el mayor, 0 si son iguales.
 *
 */
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
