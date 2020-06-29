#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pilotos.h"
#include "FuncionesUtiles.h"

/*****************************************************************************************************************************/
/*CONSTRUCTORES*/

ePiloto* piloto_new()
{
    ePiloto* pNuevoPiloto=NULL;

    pNuevoPiloto=(ePiloto*)malloc(sizeof(ePiloto));

    return pNuevoPiloto;

}


ePiloto* piloto_newParametros(char* id,char* nombre,char* apellido)
{
    ePiloto* pNuevoPiloto=NULL;

    pNuevoPiloto=piloto_new();


    piloto_setId(pNuevoPiloto,id);
    piloto_setNombre(pNuevoPiloto,nombre);
    piloto_setApellido(pNuevoPiloto,apellido);


    return pNuevoPiloto;

}

/*****************************************************************************************************************************/
/*SETTERS*/

int piloto_setId(ePiloto* this,char* id)
{
    int idPilotoNuevo;
    int retorno=0;

    if(this != NULL)
    {
        idPilotoNuevo=getInt(id);
        this->idPiloto=idPilotoNuevo;
        retorno=1;
    }

    return retorno;

}

int piloto_setNombre(ePiloto* this,char* nombre)
{
    int retorno=0;

    formatearCadena(nombre);

    if(this != NULL)
    {
        while(!validarCadena(nombre))
        {
            printf("Nombre con formato invalido.\n\n");
            printf("Ingrese nombre correctamente: ");
            fflush(stdin);
            gets(nombre);
            formatearCadena(nombre);
            validarCadena(nombre);
        }

        strcpy(this->nombre,nombre);


        retorno=1;
    }

    return retorno;

}

int piloto_setApellido(ePiloto* this,char* apellido)
{
    int retorno=0;

    formatearCadena(apellido);

    if(this != NULL)
    {
        while(!validarCadena(apellido))
        {
            printf("Apellido con formato invalido.\n\n");
            printf("Ingrese apellido correctamente: ");
            fflush(stdin);
            gets(apellido);
            formatearCadena(apellido);
            validarCadena(apellido);
        }

        strcpy(this->apellido,apellido);


        retorno=1;
    }

    return retorno;

}

/*****************************************************************************************************************************/
/*GETTERS*/

int piloto_getId(ePiloto* this,int* idPiloto)
{
    int retorno=0;

    if(this != NULL && idPiloto != NULL)
    {
        *idPiloto=this->idPiloto;
        retorno=1;
    }

    return retorno;

}

int piloto_getNombre(ePiloto* this,char* nombre)
{
    int retorno=0;

    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }

    return retorno;

}

int piloto_getApellido(ePiloto* this,char* apellido)
{
    int retorno=0;

    if(this != NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=1;
    }

    return retorno;

}



