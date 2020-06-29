typedef struct
{
    int idPiloto;
    char nombre[20];
    char apellido[20];

}ePiloto;

/*****************************************************************************************************************************/
/*CONSTRUCTORES*/


ePiloto* piloto_new();

ePiloto* piloto_newParametros(char* id,char* nombre,char* apellido);

/*****************************************************************************************************************************/
/*SETTERS*/

int piloto_setId(ePiloto* this,char* id);
int piloto_setNombre(ePiloto* this,char* nombre);
int piloto_setApellido(ePiloto* this,char* apellido);

/*****************************************************************************************************************************/
/*GETTERS*/

int piloto_getId(ePiloto* this,int* id);
int piloto_getNombre(ePiloto* this,char* nombre);
int piloto_getApellido(ePiloto* this,char* apellido);
