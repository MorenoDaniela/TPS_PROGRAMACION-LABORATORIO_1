#include <stdio.h>
#include <stdlib.h>
#include "utn-funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno;
    float numeroDos;
    int retornoUno = -1;
    int retornoDos = -1;

    while(seguir=='s')
    {
        if (retornoUno == -1 || retornoDos == -1)
        {
            printf("\n1- Ingresar 1er operando (A=x)\n");
            printf("\n1- Ingresar 2do operando (B=y)\n");
        }
        else
         {
            printf("\n1- Ingresar 1er operando (A=%.2f)\n",numeroUno);
            printf("\n1- Ingresar 2do operando (B=%.2f)\n",numeroDos);
         }
        printf("\n3- Calcular la suma (A+B)\n");
        printf("\n4- Calcular la resta (A-B)\n");
        printf("\n5- Calcular la division (A/B)\n");
        printf("\n6- Calcular la multiplicacion (A*B)\n");
        printf("\n7- Calcular el factorial (A!)\n");
        printf("\n8- Calcular todas las operaciones\n");
        printf("\n9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                retornoUno = ingresarNumero ("\n 1- Ingresar primer operando: \n", &numeroUno);
                break;
            case 2:
                retornoDos = ingresarNumero ("\n 2-Ingresar el segundo operando; \n", &numeroDos);
                break;
            case 3:
                sumar (numeroUno, numeroDos, retornoUno, retornoDos);
                break;
            case 4:
                restar (numeroUno, numeroDos, retornoUno, retornoDos);
                break;
            case 5:
                dividir (numeroUno, numeroDos, retornoUno, retornoDos);
                break;
            case 6:
                multiplicar (numeroUno, numeroDos, retornoUno, retornoDos);
                break;
            case 7:
                factorial (numeroUno, retornoUno);
                break;
            case 8:
                    sumar (numeroUno, numeroDos, retornoUno, retornoDos);
                    restar (numeroUno, numeroDos, retornoUno, retornoDos);
                    dividir (numeroUno, numeroDos, retornoUno, retornoDos);
                    multiplicar (numeroUno, numeroDos, retornoUno, retornoDos);
                    factorial (numeroUno, retornoUno);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
