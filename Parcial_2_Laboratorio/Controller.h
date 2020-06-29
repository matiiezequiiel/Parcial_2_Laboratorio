
/** \brief Apertura del archivo y llamado a funcion parser.
 *
 * \param path char* Ruta del archivo.
 * \param pArrayListEmployee LinkedList*
 * \return int 1 apertura y carga correcta, 0 error.
 *
 */
int controller_cargarArchivos(char* path , LinkedList* pArrayListVuelos);

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
int controller_ListVuelos(LinkedList* pArrayListVuelos,ePiloto listaPilotos[]);

int controller_cantPasajeros(LinkedList* pArrayListVuelos);

int controller_filterVuelosCortos(LinkedList* pArrayListVuelos);

int controller_saveAsText(char* path, LinkedList* pArrayListVuelos);

int controller_filterVuelosPortugal(LinkedList* pArrayListVuelos,ePiloto listaPilotos[]);


