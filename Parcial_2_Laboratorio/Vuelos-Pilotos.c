#include"Vuelos-Pilotos.h"
#include<stdio.h>


void mostrarVuelos(eVuelo* pVuelo,ePiloto listaPilotos[])
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[20];
    char destino[20];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;


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

    for(int i=0;i<5;i++)
    {
        if(listaPilotos[i].idPiloto==idPiloto)
        {
             printf("%10s",listaPilotos[i].nombre);
             printf("%10s\t",listaPilotos[i].apellido);
             break;
        }
    }
    printf("%15s\t",fecha);
    printf("%10s\t",destino);
    printf("%10d\t",cantPasajeros);
    printf("%10d\t",horaDespegue);
    printf("%5d",horaLlegada);

}
