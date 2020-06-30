#include"Vuelos-Pilotos.h"

#include<stdio.h>


void mostrarVuelos(eVuelo* pVuelo,LinkedList* pArrayListPilotos)
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[20];
    char destino[20];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    ePiloto* pPiloto=NULL;


    vuelo_getIdVuelo(pVuelo,&idVuelo);
    vuelo_getIdAvion(pVuelo,&idAvion);
    vuelo_getIdPiloto(pVuelo,&idPiloto);
    vuelo_getFecha(pVuelo,fecha);
    vuelo_getDestino(pVuelo,destino);
    vuelo_getCantPasajeros(pVuelo,&cantPasajeros);
    vuelo_getHoraDespegue(pVuelo,&horaDespegue);
    vuelo_getHoraLlegada(pVuelo,&horaLlegada);


    printf("\n");
    printf("%5d\t",idVuelo);
    printf("%5d\t",idAvion);

    for(int i=0;i<ll_len(pArrayListPilotos);i++)
    {
        pPiloto=(ePiloto*)ll_get(pArrayListPilotos,i);
    /*    printf("%d",pPiloto->idPiloto);
        printf("%s",pPiloto->nombre);
        printf("%s",pPiloto->apellido);
        system("pause");*/

        if(pPiloto->idPiloto==idPiloto)
        {
             printf("%10s",pPiloto->nombre);
             printf("%10s\t",pPiloto->apellido);
             break;
        }
    }
    printf("%15s\t",fecha);
    printf("%10s\t",destino);
    printf("%10d\t",cantPasajeros);
    printf("%10d\t",horaDespegue);
    printf("%5d",horaLlegada);

}

/*int vuelosFiltroPiloto(eVuelo* this,LinkedList* pArrayListPilotos,char* nombreApellido)
{

    int retorno=-1;
    ePiloto* pPiloto;
    char nombre[20];
    char apellido[20];
    int pilotoFiltro;

    for(int i=0;i<strlen(nombreApellido);i++)
    {
        if(nombreApellido[i]==',')
        {
            strncpy(nombre,nombreApellido,i-1);
            strncpy(apellido,nombreApellido,i+1);
            printf("%s",nombre);
            printf("%s",apellido);
            system("pause");
        }
    }

     for(int i=0;i<ll_len(pArrayListPilotos);i++)
    {
        pPiloto=(ePiloto*)ll_get(pArrayListPilotos,i);
        if(strcmp(pPiloto->nombre,nombre)==0 && strcmp(pPiloto->apellido,apellido)==0)
        {
            pilotoFiltro=pPiloto->idPiloto;
          //  printf("%d",pilotoFiltro);
           // system("pause");
           break;

        }

    }

    if(this != NULL)
    {
        if(this->idPiloto != pilotoFiltro)
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
*/
