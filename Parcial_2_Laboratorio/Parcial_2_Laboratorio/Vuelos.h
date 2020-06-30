typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[10];
    int cantPasajeros;
    char destino[30];
    int horaDespegue;
    int horaLlegada;

}eVuelo;


/*****************************************************************************************************************************/
/*CONSTRUCTORES*/

/** \brief Pide memoria dinamica para guardar un vuelo.
 *
 * \return Employee* Puntero a donde se encontro memoria para guardar el vuelo.
 *
 */
eVuelo* vuelo_new();


/** \brief Constructor con parametros.
 *
 * \param idStr char* ID del empleado.
 * \param nombreStr char* Nombre del empleado.
 * \param horasTrabajadasStr char* HS trabajadas.
 * \param sueldoStr char* Sueldo del empleado.
 * \return Employee* Puntero a empleado inicializado.
 *
 */
eVuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada);


/*****************************************************************************************************************************/
/*SETTERS*/

int vuelo_setIdVuelo(eVuelo* this,char* idVuelo);
int vuelo_setIdAvion(eVuelo* this,char* idAvion);
int vuelo_setIdPiloto(eVuelo* this,char* idPiloto);
int vuelo_setFecha(eVuelo* this,char* fecha);
int vuelo_setDestino(eVuelo* this,char* destino);
int vuelo_setCantPasajeros(eVuelo* this,char* cantPasajeros);
int vuelo_setHoraDespegue(eVuelo* this,char* horaDespegue);
int vuelo_setHoraLlegada(eVuelo* this,char* horaLlegada);

/*****************************************************************************************************************************/
/*GETTERS*/

int vuelo_getIdVuelo(eVuelo* this,int* idVuelo);
int vuelo_getIdAvion(eVuelo* this,int* idAvion);
int vuelo_getIdPiloto(eVuelo* this,int* idPiloto);
int vuelo_getFecha(eVuelo* this,char* fecha);
int vuelo_getDestino(eVuelo* this,char* destino);
int vuelo_getCantPasajeros(eVuelo* this,int* cantPasajeros);
int vuelo_getHoraDespegue(eVuelo* this,int* horaDespegue);
int vuelo_getHoraLlegada(eVuelo* this,int* horaLlegada);

/*****************************************************************************************************************************/
/*FUNCIONES CRITERIOS*/

int cantidadPasajerosTotal(eVuelo* this);
int cantidadPasajerosDestino(eVuelo* this);
int vuelosCortos(eVuelo* this);
int vuelosPortugal(eVuelo* this);
int vuelosSinAlexLifeson(eVuelo* this);

int vuelosSinPiloto(eVuelo* this,int idPilotoFiltrar);
