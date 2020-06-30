#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesUtiles.h"
#include "LinkedList.h"
#include "Vuelos.h"

/*****************************************************************************************************************************/
/*CONSTRUCTORES*/

eVuelo* vuelo_new()
{
    eVuelo* pNuevoVuelo=NULL;

    pNuevoVuelo=(eVuelo*)malloc(sizeof(eVuelo));

    return pNuevoVuelo;

}


eVuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada)
{
    eVuelo* pNuevoVuelo=NULL;

    pNuevoVuelo=vuelo_new();


    vuelo_setIdVuelo(pNuevoVuelo,idVuelo);
    vuelo_setIdAvion(pNuevoVuelo,idAvion);
    vuelo_setIdPiloto(pNuevoVuelo,idPiloto);
    vuelo_setFecha(pNuevoVuelo,fecha);
    vuelo_setDestino(pNuevoVuelo,destino);
    vuelo_setCantPasajeros(pNuevoVuelo,cantPasajeros);
    vuelo_setHoraDespegue(pNuevoVuelo,horaDespegue);
    vuelo_setHoraLlegada(pNuevoVuelo,horaLlegada);

    return pNuevoVuelo;

}

/*****************************************************************************************************************************/
/*SETTERS*/

int vuelo_setIdVuelo(eVuelo* this,char* idVuelo)
{
    int idVueloNuevo;
    int retorno=0;

    if(this != NULL)
    {
        idVueloNuevo=getInt(idVuelo);
        this->idVuelo=idVueloNuevo;
        retorno=1;
    }

    return retorno;
}
int vuelo_setIdAvion(eVuelo* this,char* idAvion)
{
    int idAvionNuevo;
    int retorno=0;

    if(this != NULL)
    {
        idAvionNuevo=getInt(idAvion);
        this->idAvion=idAvionNuevo;
        retorno=1;
    }

    return retorno;

}
int vuelo_setIdPiloto(eVuelo* this,char* idPiloto)
{
    int idPilotoNuevo;
    int retorno=0;

    if(this != NULL)
    {
        idPilotoNuevo=getInt(idPiloto);
        this->idPiloto=idPilotoNuevo;
        retorno=1;
    }

    return retorno;

}
int vuelo_setFecha(eVuelo* this,char* fecha)
{
    int retorno=0;


    if(this != NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=1;

    }




    return retorno;

}
int vuelo_setDestino(eVuelo* this,char* destino)
{
    int retorno=0;

    formatearCadena(destino);

    if(this != NULL)
    {
        while(!validarCadena(destino))
        {
            printf("Destino con formato invalido.\n\n");
            printf("Ingrese destino correctamente: ");
            fflush(stdin);
            gets(destino);
            formatearCadena(destino);
            validarCadena(destino);
        }

        strcpy(this->destino,destino);


        retorno=1;
    }

    return retorno;

}
int vuelo_setCantPasajeros(eVuelo* this,char* cantPasajeros)
{
    int cantPasajerosNuevo;
    int retorno=0;

    if(this != NULL)
    {
        cantPasajerosNuevo=getInt(cantPasajeros);
        this->cantPasajeros=cantPasajerosNuevo;
        retorno=1;
    }

    return retorno;

}
int vuelo_setHoraDespegue(eVuelo* this,char* horaDespegue)
{
    int horaDespegueNuevo;
    int retorno=0;

    if(this != NULL)
    {
        horaDespegueNuevo=getInt(horaDespegue);
        this->horaDespegue=horaDespegueNuevo;
        retorno=1;
    }

    return retorno;

}
int vuelo_setHoraLlegada(eVuelo* this,char* horaLlegada)
{

    int horaLlegadaNuevo;
    int retorno=0;

    if(this != NULL)
    {
        horaLlegadaNuevo=getInt(horaLlegada);
        this->horaLlegada=horaLlegadaNuevo;
        retorno=1;
    }

    return retorno;

}

/*****************************************************************************************************************************/
/*GETTERS*/

int vuelo_getIdVuelo(eVuelo* this,int* idVuelo)
{
    int retorno=0;

    if(this != NULL && idVuelo != NULL)
    {
        *idVuelo=this->idVuelo;
        retorno=1;
    }

    return retorno;

}
int vuelo_getIdAvion(eVuelo* this,int* idAvion)
{
    int retorno=0;

    if(this != NULL && idAvion != NULL)
    {
        *idAvion=this->idAvion;
        retorno=1;
    }

    return retorno;

}
int vuelo_getIdPiloto(eVuelo* this,int* idPiloto)
{
    int retorno=0;

    if(this != NULL && idPiloto != NULL)
    {
        *idPiloto=this->idPiloto;
        retorno=1;
    }

    return retorno;

}
int vuelo_getFecha(eVuelo* this,char* fecha)
{
    int retorno=0;


    if(this != NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=1;
    }



    return retorno;

}
int vuelo_getDestino(eVuelo* this,char* destino)
{
    int retorno=0;

    if(this != NULL)
    {
        strcpy(destino,this->destino);
        retorno=1;
    }

    return retorno;

}
int vuelo_getCantPasajeros(eVuelo* this,int* cantPasajeros)
{
    int retorno=0;

    if(this != NULL && cantPasajeros != NULL)
    {
        *cantPasajeros=this->cantPasajeros;
        retorno=1;
    }

    return retorno;

}
int vuelo_getHoraDespegue(eVuelo* this,int* horaDespegue)
{
    int retorno=0;

    if(this != NULL && horaDespegue != NULL)
    {
        *horaDespegue=this->horaDespegue;
        retorno=1;
    }

    return retorno;

}
int vuelo_getHoraLlegada(eVuelo* this,int* horaLlegada)
{
    int retorno=0;

    if(this != NULL && horaLlegada != NULL)
    {
        *horaLlegada=this->horaLlegada;
        retorno=1;
    }

    return retorno;

}
/*****************************************************************************************************************************/
/*FUNCIONES CRITERIOS*/

int cantidadPasajerosTotal(eVuelo* this)
{
    int retorno=-1;
    int cantPasajeros=0;

    if(this != NULL)
    {
        vuelo_getCantPasajeros(this,&cantPasajeros);
        retorno=cantPasajeros;
    }

    return retorno;

}

int cantidadPasajerosDestino(eVuelo* this)
{
    int retorno=-1;
    int cantPasajeros=0;

    if(this != NULL)
    {
        if(strcmp(this->destino,"Irlanda")==0)
        {
            vuelo_getCantPasajeros(this,&cantPasajeros);
            retorno=cantPasajeros;
        }
        else
        {
            retorno=0;
        }


    }

    return retorno;

}

int vuelosCortos(eVuelo* this)
{
    int retorno=-1;

    if(this != NULL)
    {
        if((this->horaLlegada-this->horaDespegue)<3)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

int vuelosPortugal(eVuelo* this)
{

    int retorno=-1;

    if(this != NULL)
    {
        if(strcmp(this->destino,"Portugal")==0)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

int vuelosSinAlexLifeson(eVuelo* this)
{

    int retorno=-1;

    if(this != NULL)
    {
        if(this->idPiloto != 1)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

int vuelosSinPiloto(eVuelo* this,int idPilotoFiltrar)
{

    int retorno=-1;

    if(this != NULL)
    {
        if(this->idPiloto != idPilotoFiltrar)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

