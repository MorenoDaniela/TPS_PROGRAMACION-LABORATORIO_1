#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        getInt("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n"
                "3. Alta de empleado.\n4. Modificar datos de empleado.\n5. Baja de empleado.\n6. Listar empleados\n7. Ordenar empleados.\n"
                "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                "9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n"
                "10. Salir\n","\nError, opcion incorrecta.\n",1,10,3,&option);
        system("cls");
        switch(option)
        {
            case 1:
                if (!controller_loadFromText("data.csv",listaEmpleados))
                {
                    flag++;
                }
                break;
            case 2:
                if (!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    flag++;
                }
                break;
            case 3:
                if (!controller_addEmployee(listaEmpleados))
                {
                    flag++;
                }
                break;
            case 4:
                if (flag>0)
                {
                    controller_editEmployee(listaEmpleados);
                }else
                    printf ("\nLista vacia, debe cargar la lista o dar de alta un empleado para poder modificar.\n");
                break;
            case 5:
                if (flag>0)
                {
                    controller_removeEmployee(listaEmpleados);
                }else
                    printf ("\nLista vacia, debe cargar la lista o dar de alta un empleado para poder eliminar.\n");
                break;
            case 6:
                if (flag>0)
                {
                    controller_ListEmployee(listaEmpleados);
                }else
                    printf ("\nLista vacia, debe cargar la lista o dar de alta un empleado para listar.\n");
                break;
            case 7:
                if (flag>0)
                {
                    printf ("Espere unos segundos mientras se ordena.\n");
                    controller_sortEmployee(listaEmpleados);
                    controller_ListEmployee(listaEmpleados);
                }else
                    printf ("\nLista vacia, debe cargar la lista o dar de alta un empleado para poder ordenar.\n");
                break;
            case 8:
                if (flag>0)
                {
                    controller_saveAsText("data.csv",listaEmpleados);
                }else
                    printf ("\nNo se ha cargado nada, no hay nada nuevo que guardar.\n");
                break;
            case 9:
                if (flag>0)
                {
                    controller_saveAsBinary("data.bin",listaEmpleados);
                }else
                    printf ("\nNo se ha cargado nada, no hay nada nuevo que guardar.\n");
                break;
        }
    }while(option != 10);
    return 0;
}
