
/** \brief Apertura del archivo y llamado a funcion parser.
 *
 * \param path char* Ruta del archivo.
 * \param pArrayListEmployee LinkedList*
 * \return int 1 apertura y carga correcta, 0 error.
 *
 */
int controller_Aguirre_cargarArchivosPilotos(char* path , LinkedList* pArrayListPilotos);
int controller_Aguirre_cargarArchivosVuelos(char* path , LinkedList* pArrayListVuelos);

/** \brief Separa el archivo que ingresa por el caracter ';' ,carga en memoria dinamica los empleados y los agrega a la LinkedList.
 *
 * \param pFile FILE* Archivo.
 * \param pArrayListEmployee LinkedList* LinkedList.
 * \return int 1 carga correcta, 0 no se pudo cargar.
 *
 */
int parser_VueloFromText(FILE* pFile , LinkedList* pArrayListVuelos);

/** \brief Lista los empleados cargados en la LinkedList.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1 listado correcto.
 *
 */

int parser_PilotoFromText(FILE* pFile , LinkedList* pArrayListPilotos);

int controller_Aguirre_ListVuelos(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);

int controller_Aguirre_cantPasajeros(LinkedList* pArrayListVuelos);

int controller_Aguirre_filterVuelosCortos(LinkedList* pArrayListVuelos);

int controller_Aguirre_saveAsText(char* path, LinkedList* pArrayListVuelos);

int controller_Aguirre_filterVuelosPortugal(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);

int controller_Aguirre_filterPiloto(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);
int controller_Aguirre_filterAlexLifeson(LinkedList* pArrayListVuelos,LinkedList* pArrayListPilotos);


