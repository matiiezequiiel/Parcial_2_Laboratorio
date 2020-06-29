#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesUtiles.h"


int mostrarMenuABM(void)
{
        char entrada[10];
        int opcion;


        printf("BIENVENIDOS: \n\n");
        printf("1. Cargar archivo.");
        printf("\n2. Imprimir vuelos.");
        printf("\n3. Cantidad de pasajeros. ");
        printf("\n4. Cantidad de pasajeros a Irlanda.");
        printf("\n5. Filtrar vuelos cortos.");
        printf("\n6. Listar vuelos a Portugal. ");
        printf("\n7. Filtrar a Alex Lifeson. ");
        printf("\n8. Salir.");

        printf("\n\nOpcion elegida:");
        fflush(stdin);
        gets(entrada);

        opcion=validarIntEntreRangos(entrada,1,8);
        system("cls");
        return opcion;


}

int validarIntEntreRangos(char entrada[],int rangoMinimo,int rangoMaximo)
{
    int numeroValidar;

    numeroValidar=getInt(entrada);

    while(numeroValidar<rangoMinimo || numeroValidar>rangoMaximo)
    {

        printf("Numero invalido, reeingrese un numero valido: \n");
        printf("Ingrese opcion:");
        gets(entrada);
        numeroValidar=getInt(entrada);

    }

    return numeroValidar;

}

int getInt(char* entero)
{
    int retorno;
    int enteroValidado;

    retorno=validarEntero(entero);

    while(retorno)
    {
        printf("Numero invalido.\n\n");
        printf("Reeingrese el numero: ");
        gets(entero);
        retorno=validarEntero(entero);
    }

    enteroValidado=atoi(entero);

    return enteroValidado;

}

int validarEntero (char* numeroValidar)
{
    int i;
    int lenght;
    int retorno=0;

    lenght=strlen(numeroValidar);

    if (lenght==0)  //VACIO
    {
        retorno=1;
    }

    for(i=0; i<lenght; i++)
    {

        if(isdigit(numeroValidar[i])==0) //0 NO ES NUMERO. !=0 ES NUMERO
        {
            retorno=1;
            break;
        }
    }

    return retorno;

}


int validarCadena(char cadenaValidar[])
{
    int retorno=0;
    int lenght;
    int i;
    int contadorEspacios=0;

    lenght=strlen(cadenaValidar);

    for(i=0; i<lenght; i++)
    {
        if(cadenaValidar[i]==' ')
        {
            contadorEspacios++;
        }


        if( (cadenaValidar[i]>='a' && cadenaValidar[i]<='z') || (cadenaValidar[i]>='A' && cadenaValidar[i]<='Z') )
        {
            retorno=1;
        }
        else
        {
            retorno=0;
            break;
        }

    }


    return retorno;


}

/** \brief Formatea una cadena al siguiente formato: Cadena.
 *
 * \param Cadena
 *
 */
void formatearCadena (char* cadena)
{
    char cadenaFormateada[20];

    strlwr(cadena);

    cadena[0]=toupper(cadena[0]);

    strcpy(cadenaFormateada, cadena);

}




