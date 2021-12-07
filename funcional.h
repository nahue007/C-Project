#ifndef FUNCIONAL_H_INCLUDED
#define FUNCIONAL_H_INCLUDED

//Declaraciones de las funciones utilizadas en el programa

struct pais                 //    Estructura de datos llamada pais , el cual contiene 5 campos de los cuales 4 son ingresados por el usuario.
{
    char nombre[10];
    int poblacion;
    float superficie;
    char continente[10];
    float densidad;


};
void menu ();                             // Funcion void que muestra el menu.
void generar_carga(int TAM,struct pais registro[TAM]);   // Funcion void que genera la carga de los datos de ls paises.
void mostrar(int TAM,struct pais registro[TAM]);              //Funcion void lista los paises cargados por pantalla
void densidad_ordenar(int TAM,struct pais registro[TAM]);       // Funcion void muestra los paises ORDENADOS de mayor a menor por DENSIDAD
struct pais mayor_densidad(int TAM, struct pais registro[TAM]);  // Funcion estructura que busca el de mayor densidad ,retorna valor de estructura con el pais de mayor DENSIDAD
struct pais menor_densidad(int TAM, struct pais registro[TAM]);// Funcion estructura que busca el de menor densidad ,retorna valor de estructura con el pais de menor DENSIDAD
float formu_prom(int TAM,struct pais registro [TAM]);            // Funcion que calcula el PROMEDIO.
void info_continente (int TAM,struct pais registro[TAM]);        // Funcion void que muetra lista por CONTINENTE  y dentro de la lista el mayor y el menor por su DENSIDAD.




#endif // FUNCIONAL_H_INCLUDED
