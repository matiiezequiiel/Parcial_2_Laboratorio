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
