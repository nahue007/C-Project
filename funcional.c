#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "funcional.h"

//      Implementacion de cada una de las funciones

void menu()                        // Funcion Menu , muestra cada una de las opciones del menu
{
    printf("\t\t\t\t\t\tBIENVENIDOS !! \n");// funcion void menu
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("MENU PRINCIPAL :\n");
    printf("\n");
    printf("\n\tIngrese una de las siguientes opciones \n\n");
    printf("\t1)\t Ingresar la informacion de cada PAIS. \n");
    printf("\t2)\t Listar por pantalla los REGISTROS de cada PAIS.\n");
    printf("\t3)\t INFORMACION por DENSIDAD.\n");
    printf("\t4)\t INFORMACION por CONTINENTE.\n");
    printf("\t5)\t Salir\n");




}
// Funcion para cargar los datos de los paises
void generar_carga(int TAM,struct pais registro[TAM])
{
    for (int i=0; i<TAM; i++)                    // Ciclo de repeticion for , que permite al usuario ir cargando los distintos datos de cada pais
    {
        printf("Ingrese el NOMBRE del pais (%d): ",i+1);
        fflush(stdin);
        gets(registro[i].nombre);
        printf("Ingrese la POBLACION: ");
        scanf("%d",&registro[i].poblacion);
        fflush(stdin);
        printf("Ingrese la SUPERFICIE: ");
        scanf("%f",&registro[i].superficie);
        printf("Ingrese el CONTINENTE: ");
        fflush(stdin);
        gets(registro[i].continente);
        fflush(stdin);
        printf("\n ");
        registro[i].densidad=registro[i].poblacion/registro[i].superficie; // En la estructura el campo DENSIDAD , se va cargando solo
        system("cls");


    }
    printf("\n\t\t\t\tFINALIZO la carga de los DATOS de los PAISES\n\n\n\n");
    system("pause");



}
//Funcion que muestra la lista de paises cargados por pantalla.
void mostrar(int TAM,struct pais registro[TAM])
{
    for(int i=0; i<TAM; i++)            // Recorre el vector registro , imprimiendo los paises por pantalla
    {
        printf("\n\nNOMBRE : %s\n",registro[i].nombre);
        printf("POBLACION : %i\n",registro[i].poblacion);
        printf("SUPERFICIE : %f\n",registro[i].superficie);
        printf("CONTINENTE: %s\n",registro[i].continente);
        printf("DENSIDAD : %.2f\n\n",registro[i].densidad);
        printf("\t\t ");
    }
}
//Funcion que ordena los paises segun su densidad
void densidad_ordenar(int TAM,struct pais registro[TAM]) //Ordenado por metodo Burbejeo.
{
    struct pais aux;
    for(int i=0; i<TAM; i++)
    {
        for(int j=0; j<TAM; j++)
        {
            if(registro[i].densidad>registro[j].densidad)
            {
                aux =registro[i];
                registro[i]=registro[j];
                registro[j]=aux;
            }
        }
    }
}
// Funcion estructura que busca el de MAYOR DENSIDAD , retorna valor de estructura con el pais de mayor densidad
struct pais mayor_densidad(int TAM, struct pais registro[TAM])
{
    struct pais mayor;
    mayor=registro[0];
    for(int i=1; i<TAM; i++)                     // recorre el vector comparando cual es el mayor por densidad y lo guarda en la variable a retornar.
        if(mayor.densidad<registro[i].densidad)
        {
            mayor=registro[i];
        }

    return mayor;}


// Funcion estructura que busca el de MENOR DENSIDAD , retorna valor de estructura con el pais de menor densidad
struct pais menor_densidad(int TAM, struct pais registro[TAM])
{
    struct pais menor;
    menor=registro[0];
    for(int i=1; i<TAM; i++)  // recorre el vector comparando cual es el menor por densidad y lo guarda en la variable a retornar.
    {
        if(menor.densidad>registro[i].densidad)
        {
            menor=registro[i];
        }
    }
    return menor;

}

//Funcion PROMEDIO , retorna valor float
float formu_prom(int TAM,struct pais registro [TAM])
{
    float sum=0,promed;
    for (int i=0; i<TAM; i++)      // recorre el vector sumando los valores de densidad con una variable sumadora
    {
        sum=sum+registro[i].densidad;
    }
    promed=(float)sum/TAM;
    return promed;
}

// Funcion Void lista por CONTINENTE, muestra el MAYOR,MENOR por CONTINENTE
void  info_continente (int TAM,struct pais registro[TAM])
{
    int pos,tos;                      // variables enteras que van a guardar los subindice del MAYOR y MENOR
    struct pais menor={.densidad=1000};         // Se inicializa variable menor  del tipo estructura , el campo densidad para cuando se empieza a comparar para saber cual es el menor.
  struct pais mayor={.densidad=(-1000)};        // Se inicializa variable mayor  del tipo estructura , el campo densidad para cuando se empieza a comparar para saber cual es el mayor.
    struct pais lista[TAM];                     // Vector lista del tipo estructura
    char conti_ingresado [10];                   // Vector char para el ingreso del continente.
    printf("Ingrese el continente para el informe : ");
    fflush(stdin);
    gets(conti_ingresado);
    system("cls");
    printf("Lista de paises de %s :\n",conti_ingresado);
    for (int i=0; i<TAM; i++)
    {

        if (strcmp( conti_ingresado,registro[i].continente)==0) // Se recorre comparando si el continente es el mismo y se imprime
        {

            lista[i]=registro[i];
            printf("\n\nNOMBRE : %s\n",lista[i].nombre);
            printf("POBLACION : %i\n",lista[i].poblacion);
            printf("SUPERFICIE : %f\n",lista[i].superficie);
            printf("CONTINENTE: %s\n",lista[i].continente);
            printf("DENSIDAD : %.2f\n\n",lista[i].densidad);
        }
    }
    system("pause");
    system("cls");

    for (int i=0; i<TAM; i++) // Se recorre nuevamente el vector lista buscando el de menor DENSIDAD
    {

        if (strcmp( conti_ingresado,registro[i].continente)==0)
        {
            if(menor.densidad>lista[i].densidad)
            {
                menor=lista[i];
                pos=i;
            }
        }
    }
    printf("\n\nEl pais de MENOR densidad de %s es : %s con %.2f\n\n\n\n",conti_ingresado,lista[pos].nombre,lista[pos].densidad);

    system("pause");
system("cls");

    for (int i=0; i<TAM; i++)        // Se recorre nuevamente el vector lista buscando el de mayor DENSIDAD
    {

        if (strcmp( conti_ingresado,registro[i].continente)==0)
        {
            if(mayor.densidad<lista[i].densidad)
            {
                mayor=lista[i];
                tos=i;
            }
        }
    }
    printf("\n\nEl pais de MAYOR densidad de %s es : %s con %.2f\n\n\n\n",strupr(conti_ingresado),lista[tos].nombre,lista[tos].densidad);

    system("pause");
    system("cls");



}














