#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define AR_ENTEROS "enteros.dat"

#define ESC 27
#define DIM 5

void menu ();
int factorial (int x);
int potencia (int x, int y);
int cargaArregloRandom(int a[],int v, int dim);
void mostrarArregloRecursivo (int a[], int validos, int c);
void mostrarArregloRecursivoInvertido (int a[], int validos, int c);
int capicua (int a[], int validos, int c);
int sumaRecursiva (int a[], int validos, int c);
int buscaMenorRecursivo (int a[], int validos, int c);
void arreglo2ArchivoCompleto(int a[], int v);
void muestraArchEnteros ();
int buscaMenorArchRecursivo (FILE *pArchEnteros);
int cuentaEnterosArch (FILE *pArchEnteros);
void invertirEnterosArch (FILE *pArchEnteros, int c, int u);


int main()
{
    int numero, pot, ban, val=0, ejercicio, option, cant;
    int arregloEnteros [DIM];
    srand(time(NULL));
    val = cargaArregloRandom(arregloEnteros,val, DIM);


    do {
        system("cls");
        menu();
        scanf("%d", &ejercicio);
        switch (ejercicio) {
            case 1:
                printf("\nIngrese un numero\n");
                scanf("%d", &numero);
                printf("\n El factorial del numero %d es %d\n", numero, factorial(numero));
                break;
            case 2:
                printf("\nIngrese la potencia del numero\n");
                scanf("%d", &pot);
                printf("\n El numero %d elevado a la potencia %d es %d\n", numero, pot, potencia(numero, pot));
                break;
            case 3:
                mostrarArregloRecursivo(arregloEnteros, val, 0);
                break;
            case 4:
                mostrarArregloRecursivoInvertido(arregloEnteros, val, 0);
                break;
            case 5:
                ban = capicua(arregloEnteros, val, 0);
                if (ban == 0){
                    printf("\nNo es capicua\n");
                } else {
                    printf("\nEs capicua\n");
                }
                break;
            case 6:
                printf("\nLa suma del arreglo es de: %d\n", sumaRecursiva(arregloEnteros, val, 0));
                break;
            case 7:
                printf("\nEl menor del arrreglo es: %d\n", buscaMenorRecursivo(arregloEnteros, val, 0));
                break;
            case 8:
                arreglo2ArchivoCompleto(arregloEnteros, val);
                FILE *pArchInt = fopen(AR_ENTEROS, "r+b");
                muestraArchEnteros();
                printf("\nEl menor del archivo de enteros es: %d\n", buscaMenorArchRecursivo(pArchInt));
                break;
            case 9:
                cant = cuentaEnterosArch(pArchInt);
                invertirEnterosArch(pArchInt, 0, cant);
                muestraArchEnteros();
                break;
            default:
                printf("\nOpcion incorrecta\n");
            }
        printf("\nDesea continuar? Presione ESC para salir...");
        option=getch();
    }   while(option!=ESC);

    return 0;
}

void menu ()
{
    printf("\n\n\t\t TRABAJO PRACTICO NUMERO 3\n\n");
    printf("EJERCICIO 1. Calcular factorial de un numero\n");
    printf("EJERCICIO 2. Calcular potencia de un numero\n");
    printf("EJERCICIO 3. Mostrar elementos del arreglo\n");
    printf("EJERCICIO 4. Mostrar elementos del arreglo de forma invertida\n");
    printf("EJERCICIO 5. Determinar si el arreglo es capicua\n");
    printf("EJERCICIO 6. Suma de los elementos del arreglo\n");
    printf("EJERCICIO 7. Buscar el menor del arreglo\n");
    printf("EJERCICIO 8. Buscar el menor de un archivo de enteros\n");
    printf("EJERCICIO 9. Invertir los enteros del archivo\n");
}
/// EJERCICIO 1. Calcular el factorial de un número en forma recursiva.

int factorial (int x)
{
    int respuesta;

    if (x == 0){
        respuesta = 1;
    } else {
        respuesta = x * factorial(x-1);
    }
    return respuesta;
}

/// EJERCICIO 2. Calcular la potencia de un número en forma recursiva.

int potencia (int x, int y)
{
    int respuesta;

    if (y == 1){
        respuesta = x;
    } else {
        respuesta = x * potencia(x, (y-1));
    }

    return respuesta;
}

/// EJERCICIO 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.

int cargaArregloRandom(int a[],int v, int dim)
{
    for(;v<dim;v++){
        a[v]=rand()%10;
    }
    return v;
}

void mostrarArregloRecursivo (int a[], int validos, int c)
{
    if (c<validos){
        printf("%d - ", a[c]);
        mostrarArregloRecursivo(a, validos, c+1);
    }
}

/// EJERCICIO 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo)

void mostrarArregloRecursivoInvertido (int a[], int validos, int c)
{
    if (c<validos){
        mostrarArregloRecursivoInvertido(a, validos, c+1);
        printf("%d - ", a[c]);
    }
}

/// EJERCICIO 5. Determinar en forma recursiva si un arreglo es capicúa.

int capicua (int a[], int u, int c)
{
    int respuesta = 1;

    if(c<u){
        if( a[c] == a[u] ) {
            respuesta = capicua(a, c+1, u-1);
       } else {
            respuesta = 0;
        }
    }
    return respuesta;
}


/// 6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.

int sumaRecursiva (int a[], int validos, int c)
{
    int suma=0;
    if (c<validos){
        suma= a[c] + sumaRecursiva(a, validos, c+1);
    }
    return suma;
}

/// 7. Buscar el menor elemento de un arreglo en forma recursiva.

int buscaMenorRecursivo (int a[], int validos, int c)
{
    int menor;

    if (c == validos-1){
        menor = a[c];
    } else {
        menor=buscaMenorRecursivo(a, validos, c+1);
        if(a[c]<menor){
            menor = a[c];
        }
    }
    return menor;
}

/// 8. Buscar el menor elemento de un archivo de números enteros de forma recursiva.

void arreglo2ArchivoCompleto(int a[], int v)
{
    FILE *pArchEnteros = fopen(AR_ENTEROS, "ab");
    if(pArchEnteros){
        fwrite(a, sizeof(int), v, pArchEnteros);
        fclose(pArchEnteros);
    }
}

void muestraArchEnteros ()
{
    FILE *pArchEnteros = fopen(AR_ENTEROS, "rb");

    int nro;
    if (pArchEnteros) {
        while (fread(&nro, sizeof(int), 1, pArchEnteros) > 0) {
            printf(" %d ", nro);
        }
       fclose(pArchEnteros);
    }
    printf("\n");
}

int buscaMenorArchRecursivo (FILE *pArchEnteros)
{
    int menor, aux;

    if (fread(&aux, sizeof(int), 1, pArchEnteros) == 0){
        fseek(pArchEnteros, sizeof(int)*(-1), SEEK_END);
        fread(&menor, sizeof(int), 1, pArchEnteros);
    } else {
        menor = buscaMenorArchRecursivo(pArchEnteros);
        if (aux<menor){
            menor = aux;
        }
    }
    return menor;
}

/// 9. Invertir los elementos de un archivo de números enteros de forma recursiva.

int cuentaEnterosArch (FILE *pArchEnteros)
{
    int total=0;

    fseek(pArchEnteros, 0, SEEK_END);
    total = ftell(pArchEnteros)/sizeof(int);

    return total;
}

void invertirEnterosArch (FILE *pArchEnteros, int c, int u)
{
    int inicio;
    int aux;
    int fin;

    if (c<u){
        fseek(pArchEnteros, c*sizeof(int), SEEK_SET);
        if (fread(&aux, sizeof(int), 1, pArchEnteros)>0){
            inicio = aux;
        }
        fseek(pArchEnteros, (u-1)*sizeof(int), SEEK_SET);
        if (fread(&aux, sizeof(int), 1, pArchEnteros)>0){
            fin = aux;
        }
        fseek(pArchEnteros, c*sizeof(int), SEEK_SET);
        fwrite(&fin, sizeof(int), 1, pArchEnteros);
        fseek(pArchEnteros, (u-1)*sizeof(int), SEEK_SET);
        fwrite(&inicio, sizeof(int), 1, pArchEnteros);

        invertirEnterosArch(pArchEnteros, c+1, u-1);
    }
}
