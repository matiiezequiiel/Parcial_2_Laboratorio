#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesUtiles.h"
#include "LinkedList.h"
#include "Vuelos.h"
#include "Pilotos.h"
#include "Controller.h"

int controller_Aguirre_cargarArchivosVuelos(char* path, LinkedList* pArrayListVuelos)
{
    //ABRIR ARCHIVOS
    FILE* fileArchivo;
    char cabeceraIdVuelo[20];
    char cabeceraIdAvion[20];
    char cabeceraIdPiloto[20];
    char cabeceraFecha[20];
    char cabeceraDestino[20];
    char cabeceraCantPasajeros[20];
    char cabeceraHoraDespegue[20];
    char cabeceraHoraLlegada[20];
    int retorno=0;

    if(pArrayListVuelos != NULL)
    {
        fileArchivo=fopen(path,"r");

        if(fileArchivo!=NULL)
        {
            printf("Archivo abierto correctamente.\n");

            fscanf(fileArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",cabeceraIdVuelo,cabeceraIdAvion,cabeceraIdPiloto,cabeceraFecha,
                                                                                    cabeceraDestino,cabeceraCantPasajeros,cabeceraHoraDespegue,cabeceraHoraLlegada);
            if(parser_VueloFromText(fileArchivo,pArrayListVuelos))
            {
                retorno=1;
            }
            else
            {
                retorno=0;
            }
        }
        else
        {
            printf("No se pudo abrir el archivo.");
        }
        fclose(fileArchivo);
    }

    return retorno;
}

int controller_Aguirre_cargarArchivosPilotos(char* path, LinkedList* pArrayListPilotos)
{
    //ABRIR ARCHIVOS
    FILE* fileArchivo;
    char cabeceraId[20];
    char cabeceraIdNombre[20];
    char cabeceraIdApellido[20];

    int retorno=0;

    if(pArrayListPilotos != NULL)
    {
        fileArchivo=fopen(path,"r");

        if(fileArchivo!=NULL)
        {
            printf("Archivo abierto correctamente.\n");

            fscanf(fileArchivo,"%[^,],%[^,],%[^\n]\n",cabeceraId,cabeceraIdNombre,cabeceraIdApellido);

            if(parser_PilotoFromText(fileArchivo,pArrayListPilotos))
            {
                retorno=1;
            }
            else
            {
                retorno=0;
            }
        }
        else
        {
            printf("No se pudo abrir el archivo.");
        }
        fclose(fileArchivo);
    }

    return retorno;
}


int parser_PilotoFromText(FILE* pFile, LinkedList* pArrayListPilotos)
{
    char id[20];
    char nombre[20];
    char apellido[20];
    int retorno=0;

    ePiloto* pPiloto;

   // printf("%d--%d--%d--%d--%d--%d--%d--%d",&idVuelo,&idAvion,&idPiloto,&fecha,&destino,&cantPasajeros,&horaDespegue,&horaLlegada);
   // system("pause");

    while(!feof(pFile))
    {

        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,nombre,apellido);

        // printf("%d--%d--%d--%d--%d--%d--%d--%d",strlen(idVuelo),strlen(idAvion),strlen(fecha),strlen(destino),strlen(cantPasajeros),strlen(horaDespegue),strlen(horaLlegada),strlen(idVuelo));
        // system("pause");

        pPiloto=piloto_newParametros(id,nombre,apellido);

        if(pPiloto!=NULL && pArrayListPilotos!=NULL)
        {
            ll_add(pArrayListPilotos,pPiloto);
            retorno=1;
        }
    }

    return retorno;

}

int parser_VueloFromText(FILE* pFile, LinkedList* pArrayListVuelos)
{
    char idVuelo[20];
    char idAvion[20];
    char idPiloto[20];
    char fecha[20];
    char destino[20];
    char cantPasajeros[20];
    char horaDespegue[20];
    char horaLlegada[20];
    int retorno=0;
    eVuelo* pVuelo;

   // printf("%d--%d--%d--%d--%d--%d--%d--%d",&idVuelo,&idAvion,&idPiloto,&fecha,&destino,&cantPasajeros,&horaDespegue,&horaLlegada);
   // system("pause");

    while(!feof(pFile))
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino
                                                                        ,cantPasajeros,horaDespegue,horaLlegada);

        // printf("%d--%d--%d--%d--%d--%d--%d--%d",strlen(idVuelo),strlen(idAvion),strlen(fecha),strlen(destino),strlen(cantPasajeros),strlen(horaDespegue),strlen(horaLlegada),strlen(idVuelo));
        // system("pause");

        pVuelo=vuelo_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);

        if(pVuelo!=NULL && pArrayListVuelos!=NULL)
        {
            ll_add(pArrayListVuelos,pVuelo);
            retorno=1;
        }
    }

    return retorno;

}


int controller_Aguirre_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    eVuelo* vuelo;
    int contMostrados=0;

    printf("ID VUELO ID AVION  NOMBRE Y APE PILOTO     FECHA VUELO     DESTINO      CANT PASAJEROS    HORA DESPEGUE  HORA LLEGADA");
    for(int i=0;i<ll_len(pArrayListVuelos);i++)
    {

        if(contMostrados==100)
        {
            printf("\nLista de vuelos muy larga, se mostraran de 100 vuelos por vez.");
            printf("\n\n");
            system("pause");
            contMostrados=0;

        }
        vuelo=ll_get(pArrayListVuelos,i);
        mostrarVuelos(vuelo,pArrayListPilotos);
        contMostrados++;


    }
    printf("\n\nFIN DE LA LISTA");
    printf("\n\n");
    system("pause");
    return 1;
}

int controller_Aguirre_cantPasajeros(LinkedList* pArrayListVuelos)
{
    int opcion;
    int retorno;
    char entrada[5];
    int cantidadPasajeros=0;

    printf("Ingrese 1 para conocer la cantidad de pasajeros total en cada vuelo.");
    printf("\nIngrese 2 para conocer la cantidad de pasajeros total a Irlanda.");
    printf("\n\nIngrese opcion: " );
    gets(entrada);

    opcion=validarIntEntreRangos(entrada,1,2);

    switch(opcion)
    {
    case 1:
        cantidadPasajeros=ll_count(pArrayListVuelos,cantidadPasajerosTotal);
        printf("La cantidad de pasajeros totales es de: %d \n\n",cantidadPasajeros);
        system("pause");
        retorno=1;
        break;
    case 2:
        cantidadPasajeros=ll_count(pArrayListVuelos,cantidadPasajerosDestino);
        printf("La cantidad de pasajeros a Irlanda es de: %d \n\n",cantidadPasajeros);
        system("pause");
        retorno=1;
        break;
    }

    return retorno;
}

int controller_Aguirre_filterVuelosCortos(LinkedList* pArrayListVuelos)
{
    int retorno=-1;
    char nombreFile[10];
    LinkedList* pLinkedListVuelosCortos=NULL;

    if(pArrayListVuelos != NULL)
    {
        pLinkedListVuelosCortos=ll_filter(pArrayListVuelos,vuelosCortos);

        if(pLinkedListVuelosCortos != NULL)
        {
            printf("Ingrese nombre del nuevo archivo a crear: ");
            gets(nombreFile);
            retorno=controller_Aguirre_saveAsText(nombreFile,pLinkedListVuelosCortos);

        }


    }

    return retorno;

}

int controller_Aguirre_saveAsText(char* path, LinkedList* pArrayListVuelos)
{
    FILE* fileText;
    eVuelo* p;
    int i;
    int retorno=0;

    fileText=fopen(path,"w");

    if(fileText!=NULL)
    {
        fprintf(fileText,"%s,%s,%s,%s,%s,%s,%s,%s\n","idVuelo","idAvion","idPiloto","fecha","destino","cantPasajeros","horaDespegue","horaLlegada");

        for(i=0; i < ll_len(pArrayListVuelos); i++)
        {
            p = (eVuelo*)ll_get(pArrayListVuelos, i);
            fprintf(fileText,"%d,%d,%d,%s,%s,%d,%d,%d\n",p->idVuelo,p->idAvion,p->idPiloto,p->fecha,p->destino,p->cantPasajeros,p->horaDespegue,p->horaLlegada);
        }
        retorno=1;
        fclose(fileText);
    }
    return retorno;
}

int controller_Aguirre_filterVuelosPortugal(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos)
{
    int retorno=-1;
    LinkedList* pLinkedListVuelosPortugal=NULL;

    if(pArrayListVuelos != NULL)
    {
        pLinkedListVuelosPortugal=ll_filter(pArrayListVuelos,vuelosPortugal);

        if(pLinkedListVuelosPortugal != NULL)
        {
           controller_Aguirre_ListVuelos(pLinkedListVuelosPortugal,pArrayListPilotos);
           retorno=1;

        }


    }

    return retorno;


}

int controller_Aguirre_filterAlexLifeson(LinkedList* pArrayListVuelos,ePiloto listaPilotos[])
{
    int retorno=-1;
    LinkedList* pLinkedListVuelosSinAlex=NULL;

    if(pArrayListVuelos != NULL)
    {
        pLinkedListVuelosSinAlex=ll_filter(pArrayListVuelos,vuelosSinAlexLifeson);

        if(pLinkedListVuelosSinAlex != NULL)
        {
           controller_Aguirre_ListVuelos(pLinkedListVuelosSinAlex,listaPilotos);
           retorno=1;

        }


    }

    return retorno;


}
