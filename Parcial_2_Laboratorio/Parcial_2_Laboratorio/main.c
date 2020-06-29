#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pilotos.h"
#include "FuncionesUtiles.h"
#include "Controller.h"


int main()
{
    int opcion;
    int retorno;
    char nombreArchivo[20];
    int archivoCargado=0;

    LinkedList* listaVuelos;
    LinkedList* ListaPilotos;

    listaVuelos=ll_newLinkedList();
    ListaPilotos=ll_newLinkedList();



    do
    {
        system("cls");
        opcion=mostrarMenuABM();

        switch(opcion)
        {
        case 1:
          //  printf("Ingrese nombre del archivo de vuelos: ");
          //  gets(nombreArchivo);
            retorno=controller_Aguirre_cargarArchivosVuelos("Vuelos.csv",listaVuelos);


                if(retorno)
                {
                    system("cls");
                    printf("\nArchivo de vuelos cargado correctamente.\n\n");
                    system("pause");
                    archivoCargado=1;
                }
                else
                {
                    system("cls");
                    printf("\nNo se pudo cargar el archivo de vuelos.\n\n");
                    system("pause");
                }



             //  printf("Ingrese nombre del archivo de pilotos: ");
          //  gets(nombreArchivo);

            retorno=controller_Aguirre_cargarArchivosPilotos("Pilotos.csv",ListaPilotos);

                if(retorno)
                {
                    system("cls");
                    printf("\nArchivo pilotos cargado correctamente.\n\n");
                    system("pause");
                    archivoCargado=1;
                }
                else
                {
                    system("cls");
                    printf("\nNo se pudo cargar el archivo de pilotos.\n\n");
                    system("pause");
                }



            break;

        case 2:
            controller_Aguirre_ListVuelos(listaVuelos,ListaPilotos);
            break;

        case 3:
            controller_Aguirre_cantPasajeros(listaVuelos);
            break;

        case 4:
             controller_Aguirre_cantPasajeros(listaVuelos);
            break;

        case 5:
            retorno=controller_Aguirre_filterVuelosCortos(listaVuelos);
            if(retorno)
            {
                system("cls");
                printf("\nArchivo guardado correctamente.\n\n");
                system("pause");
                archivoCargado=1;
            }
            else
            {
                system("cls");
                printf("\nNo se pudo guardar el archivo.\n\n");
                system("pause");
            }
            //ARREGLAR FECHA QUE CARGA DESTINO

            break;

        case 6:
            controller_Aguirre_filterVuelosPortugal(listaVuelos,ListaPilotos);
            break;

        case 7:
            controller_Aguirre_filterAlexLifeson(listaVuelos,ListaPilotos);
            break;
         case 8:
            controller_Aguirre_filterPiloto(listaVuelos,ListaPilotos);
            break;

        default:
            break;

        }


    }while(opcion != 9);

    return 0;
}
