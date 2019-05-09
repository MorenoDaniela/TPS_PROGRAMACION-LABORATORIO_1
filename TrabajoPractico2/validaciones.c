#ifndef VALIDACIONES_C_INCLUDED
#define VALIDACIONES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int isValidInt(int numero, int minimo, int maximo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int isValidFloat(float numero, float minimo, float maximo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    return 0;
}

int isValidChar(char letra, char minimo, char maximo)
{
    if(letra>=minimo && letra <= maximo)
    {
        return 1;
    }
    return 0;
}

int isValidName (char* cadena)
{
    int retorno = 1;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int isValidApellido (char* cadena)
{
    int retorno = 1;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}

int isDni (char* pString)
{
    int i=0;
    while(pString[i]!='\0')
    {
        if(!isNumber(pString))
        {
            return 0;
        }
        if(strlen(pString)<7 || strlen(pString)>8)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isNumber (char* pString)
{
    int i=0;
    while(pString[i]!='\0')
    {
        if(pString[i]<'0' || pString[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isCuit (char* pString)
{
    int retorno=0;
    int i=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            return 0;
        }
        else if((pString[2]=='-')&&(pString[10]=='-' || pString[11]=='-'))
        {
            retorno=1;
        }
        i++;
    }
    return retorno;
}

int isTelefono (char* pString)
{
    int i=0;
    int contadorGuion=0;
    while(pString[i]!='\0')
    {
        if((pString[i]!=' ')&&(pString[i]!='-')&&(pString[i]<'0' || pString[i]>'9'))
        {
            return 0;
        }
        if(pString[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return 1;
        }
    return 0;
}

int isEmail(char* cadena)
{
    int retorno=0;
    int contadorArroba=0;
    int i;
    for (i=0;i<30;i++)
    {
       while (cadena[i]!='\0')
        {
            if ((cadena[i]=='-')&&(cadena[i]=='_')&& (cadena[i]=='.')
                && (cadena[i]>='0' || cadena[i]<='9') && (cadena[i]<'A'||cadena[i]>'Z') &&
                (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]=='@'))
            {
                retorno=0;
            }
            if(cadena[i]=='@')
            {
                contadorArroba++;
            }
            if(contadorArroba>1)
            {
                retorno=1;
            }
        }
    }

    return retorno;
}


#endif // VALIDACIONES_C_INCLUDED
