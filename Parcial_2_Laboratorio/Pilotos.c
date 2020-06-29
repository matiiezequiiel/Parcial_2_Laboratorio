#include <string.h>
#include <stdIO.h>
#include <stdlib.h>
#include "Pilotos.h"

void hardcodearPilotos(ePiloto listaPilotos[])
{
    int idPiloto[5]= {1,2,3,4,5};
    char nombre[5][20]={"Alex","Richard","Jhon","Erwin","Stephen"};
    char apellido[5][20]={"Lifeson","Bach","Kerry","Rommel","Coonts"};
    int i;


    for(i=0;i<5;i++)
    {
        listaPilotos[i].idPiloto=idPiloto[i];
        strcpy(listaPilotos[i].nombre,nombre[i]);
        strcpy(listaPilotos[i].apellido,apellido[i]);
    }

  /*  for(i=0;i<5;i++)
    {
        printf("%d---%s---%s\n",listaPilotos[i].idPiloto,listaPilotos[i].nombre,listaPilotos[i].apellido);

    }
  */
}

