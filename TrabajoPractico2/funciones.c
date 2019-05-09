#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(char *msj, char *errorMsj, int minimo, int maximo, int reintentos, int *resultado)
{
    int retorno = -1;
    int buffer;
    if(msj != NULL && errorMsj != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", msj);
            scanf("%d", &buffer);
            if(isValidInt(buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s", errorMsj);
            }
            reintentos--;
        }while(reintentos >= 0);
    }
    return retorno;
}

int getFloat(char *msj, char *errorMsj, float minimo, float maximo, int reintentos, float *resultado)
{
    int retorno = -1;
    float buffer;
    if(msj != NULL && errorMsj != NULL && resultado != NULL && maximo>=minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", msj);
            scanf("%f", &buffer);
            if(isValidFloat(buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s", errorMsj);
            }
            reintentos--;
        }while(reintentos >= 0);
    }
    return retorno;
}

int getChar(char *msj, char *errorMsj, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer;
    int retorno = -1;
    if(msj != NULL && errorMsj != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", msj);
            fflush(stdin);
            //__fpurge(stdin); para linux _____  //fflush(stdin); para windows
            scanf("%c", &buffer);
            if(isValidChar(buffer, minimo, maximo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }else
            {
                printf("%s", errorMsj);
            }
            reintentos--;
        }while(reintentos >= 0);
    }
    return retorno;
}

int getString(char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msj != NULL && errorMsj != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msj);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",errorMsj);
        }while(reintentos>=0);
    }
    return retorno;
}

int getName (char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msj != NULL && errorMsj != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        while(retorno==-1)
        {
            if(!getString(msj,errorMsj,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidName(bufferStr))
                {
                    strncpy(resultado, bufferStr,maximo);
                    retorno = 0;
                    break;
                }
                else
                    {
                        reintentos--;
                        printf (errorMsj);
                    }
            }
        }
    }
    return retorno;
}

int getApellido (char* msj, char* errorMsj, int minimo, int maximo, int reintentos, char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msj != NULL && errorMsj != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        while (retorno==-1)
        {
            if(!getString(msj,errorMsj,minimo,maximo,reintentos,bufferStr))
            {
                if(isValidApellido(bufferStr))
                {
                    strncpy(resultado, bufferStr,maximo);
                    retorno = 0;
                }
                else
                {
                    reintentos--;
                    printf (errorMsj);
                }
            }
        }
    }
    return retorno;
}

int getDni (char* msj, char* errorMsj,int minimo, int maximo, int reintentos, char* resultado)
{
    char bufferString[50];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(msj,errorMsj,minimo,maximo,reintentos,bufferString)&&(resultado!=NULL)&&(isDni(bufferString)))
        {
            strncpy(resultado,bufferString,50);
            retorno=0;
        }
        else
        {
            printf("%s",errorMsj);
            reintentos--;
        }
    }
    return retorno;
}

int getCuit (char* msg, char* msgError,int minimo, int maximo,int reintentos,char* resultado)
{
    char bufferString[20];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferString)&&(resultado!=NULL)&&(isCuit(bufferString)))
        {
            strncpy(resultado,bufferString,20);
            retorno=0;
        }
        else
        {
            printf("%s",msgError);
            reintentos--;
        }
    }
    return retorno;
}

int getTelefono (char* msg, char* msgError,int minimo, int maximo,int reintentos,char* resultado)
{
    char bufferString[20];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferString)&&(resultado!=NULL)&&(isTelefono(bufferString)))
        {
            strncpy(resultado,bufferString,20);
            retorno=0;
        }
        else
        {
            printf("%s",msgError);
            reintentos--;
        }
    }
    return retorno;
}


#endif // FUNCIONES_C_INCLUDED
