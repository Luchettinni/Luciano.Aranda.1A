typedef struct
{
    int dia;
    int mes;
    int year;

} sFecha;

typedef struct
{
    int isEmpty;
    int codigoDeSocio;

    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char eMail[31];

    sFecha fecha;

} sSocios;

typedef struct
{
    int isEmpty;
    int codigoDelAutor;
    char nombre[31];
    char apellido[31];

} sAutores;

typedef struct
{
    int isEmpty;
    int codigoAutor;
    int codigoLibro;
    char titulo[51];

} sLibros;

typedef struct
{
    int codigo;
    int codigoSocio;
    int codigoLibro;
    int isEmpty;
    sFecha fecha;

} sPrestamo;

/** \brief rellenana los campos "isEmpty" de las estructuras con 1.
 *
 * \param soc[] es la estructura de tipo "sSocios" a rellenar con unos en su campo isEmpty.
 * \param tam es el tamaño de la estructura "sSocios".
 * \param prest[] es la estructura de tipo "sPrestamo" a rellenar con unos en su campo isEmpty.
 * \param tam2 es el tamaño de la estructura "sPrestamo".
 * \return retorna vacio
 *
 */
void borrarBaseDeDatos(sSocios soc[], int tam, sPrestamo prest[], int tam2, sLibros lib[],int tam3, sAutores aut[], int tam4);

/** \brief Inicializa estructuras
 *
 * \param socios[] es una de las estructura a inicializar.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param autores[] es una de las estructura a inicializar.
 * \param tam2 es el tamaño de la estructura correspondiente a autores.
 * \param libros[] es una de las estructura a inicializar.
 * \param tam3 es el tamaño de la estructura correspondiente a libros.
 * \return retorna vacio
 *
 */
void inicializacionDeEstructuras(sSocios socios[], int tam, sAutores autores[], int tam2, sLibros libros[], int tam3);

/** \brief muestra en pantalla un menu de opciones y pregunta por la opcion a efectuar
 *
 * \return el numero correspondiente a la opcion elegida.
 *
 */
int menuDeOpciones();

/** \brief muestra en pantalla un menu de opciones y pregunta por la opcion a efectuar
 *
 * \return el numero correspondiente a la opcion elegida.
 *
 */
int menuDeSocios();

int menuDeListado();

/** \brief muestra en pantalla un menu de opciones y pregunta por la opcion a efectuar
 *
 * \return el numero correspondiente a la opcion elegida.
 *
 */
int subMenuModificarSocio();

//-----------------------------------------------------------------------------------------------------

/** \brief da de alta un socio rellenando asi, varios campos de la estructura con informacion del mismo
 *
 * \param soc[] es la estructura que se va a utilizar para rellenar sus campos con informacion del socio a dar de alta.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param UltimoCodigoDeSocio se utiliza para otorgarle un codigo al socio dado de alta, este parametro es autoincremental
 * \return retorna vacio
 *
 */
void AltaSocio (sSocios soc[], int tam, int* UltimoCodigoDeSocio);

/** \brief da de baja un socio realizando una baja logica, rellenando el campo "isEmpty" del socio con un cero.
 *
 * \param soc[] es la estructura que contiene el campo isEmpty necesario para la baja logica.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return retorna vacio
 *
 */
void bajaSocio (sSocios soc[], int tam);

/** \brief modifica uno de los campos de la estructura socios.
 *
 * \param soc[] es la estructura que se va a utilizar para modificar sus campos.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return retorna vacio
 *
 */
void modificarSocio(sSocios emp[], int tam);

/** \brief muestra a un unico "socio" especifico
 *
 * \param soc[] es la estructura que se va a utilizar para encontrar al socio que mostrar y sus datos.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return retorna vacio
 *
 */
void mostrarSocio (sSocios soc[], int i);

/** \brief muestra un listado completo de todos los socios actuales
 *
 * \param soc[] es la estructura que se va a utilizar para listar a los socios con sus respectivos datos sus datos.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return retorna vacio
 *
 */
void ListarSocios ( sSocios soc[], int tam);

/** \brief ordena una estructura por apellido (ascendente) y nombre (ascendente)
 *
 * \param soc[] es la estructura que sera ordenada por los criterios ya mencionados
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return
 *
 */
void ordenarSocios(sSocios emp[], int tam);

//-----------------------------------------------------------------------------------------------------

/** \brief busca un espacio vacio en una estructura
 *
 * \param soc[] es la estructura que se va a utilizar para buscar dicho espacio
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return retorna un entero que corresponde al indice de la estructura en el cual existe un espacio libre.
 *
 */
int buscarEspacioLibreSocios (sSocios soc[], int tam);

/** \brief Busca a un socio especifico por su codigo correspondiente
 *
 * \param soc[] es la estructura en la que se va a buscar el socio especifico
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param codigo es el codigo correspondiente al socio a buscar.
 * \return retorna el indice de la estructura al que partenece el socio
 *
 */
int buscarSocio(sSocios soc[], int tam, int codigo);

/** \brief busca en una estructura, el ultimo codigo del ultimo socio y lo incrementa
 *
 * \param soc[] es la estructura en la que se realizara la busqueda del ultimo codigo
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param ultimoCodigo es el ultimo codigo del ultimo socio hasta el momento.
 * \return retorna el ultimo codigo existente incrementado en uno
 *
 */
int buscarUltimoCodigoSocio (sSocios soc[], int tam, int* ultimoCodigo);

/** \brief muestra un pregunta o un mensaje y ofrece como opcion de respuesta (s/n)
 *
 * \param respuesta se utiliza para guardar la respuesta del usuario
 * \param mensaje es el mensaje que se mostrara en pantalla para indicarle al usuario que hacer
 * \return retorna vacio
 *
 */
void getResp (char* respuesta, char mensaje[]);

//-----------------------------------------------------------------------------------------------------

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void listarLibros(sLibros lib[], int tam);
void listarAutores(sAutores aut[], int tam);

//------------------------------------------------------------------------

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void obtenerPrestTotalYDiario(sPrestamo prest[], int tam, float* contadorDePrestamos, int* contadorDias);
void prestamosTotalesyDiarios (sPrestamo prest[], int tam);
void promedioNoSuperado (sPrestamo prest[], int tam);
void listarPorLibroDeterminado(sSocios soc[], int tam, sAutores aut[], int tam2, sLibros lib[], int tam3, sPrestamo prest[], int tam4);
void listarLibrosPorSocioDeterminado (sSocios soc[], int tam, sAutores aut[], int tam2, sLibros lib[], int tam3, sPrestamo prest[], int tam4, int* ultimoCodigo);
void informarLibroMenosPrestado (sLibros lib[],int tam2, sPrestamo prest[], int tam3);
void listarYOrdenarPorInsercion(sSocios soc[], int tam, sLibros lib[],int tam2, sPrestamo prest[], int tam3);
void listarLibrosPorFechaDeterminada(sLibros lib[], int tam3, sPrestamo prest[], int tam2);
void socioMasPrestamos (sSocios soc[],int tam, sPrestamo prest[], int tam2);
void listarLibrosAscendente(sLibros lib[], int tam_libros);
void listarSociosPorFechaDeterminada(sSocios soc[], int tam, sPrestamo prest[], int tam2);
