#ifndef UTN-FUNCIONES_C_INCLUDED
#define UTN-FUNCIONES_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>


/** \brief Se muestra un mensaje que se le pide a traves de un puntero y se guarda un numero que se le pidio en el mensaje.
 *
 * \param mensaje correspondiente a lo que pide el usuario
 * \param numero correspondiente que ingresa el usuario
 * \return retorna cero para indicarle al main que un numero ya fue ingresado
 *
 */
int ingresarNumero(char *mensaje, float *unOperador)
{
    float numero;
    printf ("%s",mensaje);
    scanf ("%f",&numero);
    *unOperador = numero;
    return 0;
}

/** \brief Recibe dos numeros y dos retornos, suma los dos numeros.
 *
 * \param es el primer numero recibido
 * \param es el segundo numero recibido
 * \param primer retorno recibido
 * \param segundo retorno recibido
 * \return retorna un 0 y un mensaje con el resultado de la suma si todo salio bien, retorna -1 y un mensaje de error si el usuario no ingreso un numero
 *
 */
int sumar (float numeroUnoSuma, float numeroDosSuma, int retorno1, int retorno2)
{
    int retornoSuma = -1;
    float suma;

    if (retorno1==-1 || retorno2==-1)
    {
        printf ("\nError, no se ingreso un operando.\n");
    }
    else
    {
        suma = numeroUnoSuma + numeroDosSuma;
        printf ("\nEl resultado de la suma es: %.2f\n",suma);
        return 0;
    }
    return retornoSuma;
}

/** \brief Recibe dos numeros y dos retornos, resta los dos numeros.
 *
 * \param es el primer numero recibido
 * \param es el segundo numero recibido
 * \param primer retorno recibido
 * \param segundo retorno recibido
 * \return retorna un 0 y un mensaje con el resultado de la resta si todo salio bien, retorna -1 y un mensaje de error si el usuario no ingreso un numero
 *
 */
int restar(float numeroUnoResta, float numeroDosResta, int retorno1, int retorno2)
{
    int retornoResta = -1;
    float resta;

    if (retorno1==-1 || retorno2==-1)
    {
        printf ("\nError, no se ingreso un operando.\n");
    }
    else
    {
        resta = numeroUnoResta - numeroDosResta;
        printf ("\nEl resultado de la resta es: %.2f\n",resta);
        return 0;
    }
    return retornoResta;
}

/** \brief Recibe dos numeros y dos retornos, multiplica los dos numeros.
 *
 * \param es el primer numero recibido
 * \param es el segundo numero recibido
 * \param primer retorno recibido
 * \param segundo retorno recibido
 * \return retorna un 0 y un mensaje con el resultado de la multiplicacion si todo salio bien, retorna -1 y un mensaje de error si el usuario no ingreso un numero
 *
 */
int multiplicar(float numeroUnoMultiplicador, float numeroDosMultiplicador, int retorno1, int retorno2)
{
    int retornoMultiplicacion = -1;
    float multiplicacion;
    if (retorno1==-1 || retorno2==-1)
    {
        printf ("\nError, no se ingreso un operando.\n");
    }
    else
    {
        multiplicacion = numeroUnoMultiplicador * numeroDosMultiplicador;
        printf ("\nEl resultado de la multiplicacion es: %.2f\n",multiplicacion);
        return 0;
    }
    return retornoMultiplicacion;
}

/** \brief Recibe dos numeros y dos retornos, divide los dos numeros.
 *
 * \param es el primer numero recibido
 * \param es el segundo numero recibido
 * \param primer retorno recibido
 * \param segundo retorno recibido
 * \return retorna un 0 y un mensaje con el resultado de la division si todo salio bien, retorna -1 y un mensaje de error si el usuario no ingreso un numero o intento hacer una division por 0.
 *
 */
int dividir(float numeroUnoDividendo, float numeroDosDivisor, int retorno1, int retorno2)
{
    int retornoDivision = -1;
    float division;
    if (retorno1==-1 || retorno2==-1)
    {
        printf ("\nError, no se ingreso un operando.\n");
    }
    else
    {
        if (numeroDosDivisor == 0)
        {
            printf ("\nError, no se puede dividir por cero.\n");
        }
        else
        {
            division = numeroUnoDividendo / numeroDosDivisor;
            printf ("\nEl resultado de la division es: %.2f\n",division);
            retornoDivision = 0;
        }
    }
    return retornoDivision;
}

/** \brief Recibe un numero y un retorno, calcula el factorial del numero recibido.
 *
 * \param es el primer numero recibido
 * \param retorno recibido
 * \return retorna un 0 y un mensaje con el resultado del factorial si todo salio bien, retorna -1 y un mensaje de error si el usuario no ingreso un numero o si el usuario intento calcular el factorial de un numero negativo
 *
 */
int factorial (int numeroFactorial, int retorno1)
{
    int retornoFactorial=-1;
    int resultadoFactorial=1;

    if (retorno1 ==-1)
    {
        printf ("\n Error, no se ingreso el operando.\n");
    }
    else
        {
            if (numeroFactorial<0)
            {
                printf ("\nNo se puede calcular el factorial de un numero negativo.\n");
                return retornoFactorial;
            }
            else
            {
                for (int contador=1;contador<=numeroFactorial;contador++)
                {
                    resultadoFactorial=resultadoFactorial*contador;
                }
                printf ("\n El resultado del factorial de %.2d es : %.2d\n",numeroFactorial,resultadoFactorial);

            }
        }

    return 0;
}


#endif // UTN-FUNCIONES_C_INCLUDED
