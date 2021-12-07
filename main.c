#include <stdio.h>                                 // LIBRERIAS
#include <stdlib.h>
#include "funcional.h"                             //LIBRERIA con las FUNCIONES creadas
#include <string.h>                                // LIBRERIA para funciones con caracteres
#include <stdbool.h>                               // LIBRERIA para usar boolianos.
#define TAM 8                                      // CONSTANTE define cantidad paises a cargar


int main()                                         // Funcion PRINCIPAL
{

    int opcion;                                     // variable entera para ingresar a las opciones del menu
    float promedio;                                 // variable flotante para el promedio.
    struct pais registro[TAM];                      // Estructura de datos llamada pais ,se define vector registro.
    struct pais resultado;                          // Estructura de datos pais , se define variable resultado.

    bool carga_paises=false,listar_paises=false,info_den=false,info_cont=false,continuar=true;//diferentes condiciones booleanas para que no se ingrese , si no se cargaron los datos .Condiciones para salir del menu.
    enum opciones                  //enumeradores para las opciones del switch
    {
        cargaInfo =1,
        listar=2,
        infoDen=3,
        infoCont=4,
        salir=5,
    };
    do                                    // Necesario para la repeticion del menu.
    {
        menu();                            // Funcion Void Muestra el menu.
        scanf("%d",&opcion);               // Ingreso del usuario por menu.
        system("cls");                     // limpieza de pantalla.
        switch (opcion)                    // Entrada a las diferentes opciones del menu
        {
        case (cargaInfo):                  // Opcion para poder realizar carga de datos de los paises

            generar_carga(TAM,registro);                //funcion para cargar datos.
            carga_paises=true;                          // Condicion booleana, explicada mas arriba
            break;
        case (listar):                           // Opcion para poder listar los paises cargados.
            if (carga_paises)                    // valor de variable booleana .Condicion para que primero se carguen los paises.
            {
                printf("Lista de registros de PAISES:\n");

                mostrar(TAM,registro);             // Funcion muestra lista de paises cargados.
                listar_paises=true;                // una de las condiciones para la opcion Salir
                system("pause");
            }
            else
            {
                printf("\nPrimero tiene que cargar la informacion de cada PAIS\n\n\n");
                system("pause");
            }
            break;
        case (infoDen) :                                    //Opcion para el infome segun DENSIDAD.
            if (carga_paises)                               // Booleana condicion que obliga cargar primero los paises
            {
                printf("Lista de PAISES, ordenados de MAYOR a menor por su DENSIDAD :\n");
                densidad_ordenar(TAM,registro);                // Funcion ordena de mayor a menor por DENSIDAD.
                mostrar(TAM,registro);                         // Funcion lista en pantalla como quedo ordenado.
                system("pause");
                system("cls");

                resultado=mayor_densidad(TAM,registro);            // variable estructura pais es igual a funcion estructura que busca el de mayor DENSIDAD.
                printf("\n\nEL pais de MAYOR DENSIDAD es : %s con %.2f \n\n\n\n",resultado.nombre,resultado.densidad);
                system("pause");
                system("cls");

                resultado=menor_densidad(TAM,registro);              // variable estructura pais es igual a funcion estructura que busca el de mayor DENSIDAD.
                printf("\n\nEL pais de MENOR DENSIDAD es : %s con %.2f \n\n\n\n",resultado.nombre,resultado.densidad);
                system("pause");
                system("cls");
                promedio=formu_prom(TAM,registro);                  //variable float promedio es igual a la funcion que da el promedio.
                printf("\nEl PROMEDIO de DENSIDAD es %.2f\n\n\n\n",promedio);
                info_den=true;                                       // booleano condicion para poder salir.
                system("pause");
                system("cls");
            }
            else
            {
                printf("\nPrimero tiene que cargar la informacion de cada PAIS\n\n\n");
                system("pause");
            }
            break;
        case (infoCont):                                          // Opcion para realizar el informe por CONTINENTE
            if (carga_paises)                                      // booleano condicion de qu primero se carguen los paises
            {

                info_continente (TAM,registro);                   // funcion Void muestra el listado por CONTINENTE y dentro del listado el MAYOR y MENOR por su DENSIDAD.
                info_cont=true;                                   // Booleano condicion para poder salir
            }
            else
            {
                printf(" \nPrimero tiene que cargar la informacion de cada PAIS\n\n\n");
                system("pause");
            }
            break;
        case (salir):                              // Opcion para salir de menu.
            if (listar_paises&&info_den&&info_cont)                 // Booleanos condiciones que tienen que cambiar de estado para salir.
            {
                continuar=false;                                    // Booleana cambia cuando se cumple condicion anterior
            }
            else
            {
                printf("\n\nFALTAN PROCESAR DATOS\n\n\n");
                system("pause");
            }
            break;
        default :                                             // imprime cuando se ingresa cualquier numero , que no sea ninguna de las opciones.
            printf("\n\nOpcion Incorrecta.\n\n\n");
            system("pause");
            break;
        }
        system("cls");
    }
    while (continuar);                                         // Booleana condicion para salir.
    printf("\n\n\n\t\t\t\tGood Bye\tCHARLY\n\n\n\n\n\n");
    return 0;

}
