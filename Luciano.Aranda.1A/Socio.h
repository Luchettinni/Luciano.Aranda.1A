typedef struct // Fecha
{
    int dia;
    int mes;
    int year;

} sFecha;

typedef struct // Socios
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

typedef struct // Autores
{
    int isEmpty;
    int codigoDelAutor;
    char nombre[31];
    char apellido[31];

} sAutores;

typedef struct // Libros
{
    int isEmpty;
    int codigoAutor;
    int codigoLibro;
    char titulo[51];

} sLibros;

typedef struct // Prestamos
{
    int codigo;
    int codigoSocio;
    int codigoLibro;
    int isEmpty;
    sFecha fecha;

} sPrestamos;

/** \brief "Inicializa" estructuras, rellenandolas con sus campos "isEmpty" en 1.
 *
 * \param soc[] es la estructura de tipo "sSocios" a rellenar con unos en su campo isEmpty.
 * \param prest[] es la estructura de tipo "sSocios" a rellenar con unos en su campo isEmpty.
 * \param lib[] es la estructura de tipo "sSocios" a rellenar con unos en su campo isEmpty.
 * \param tam es el tamaño de la estructura "sSocios".
 * \param prest[] es la estructura de tipo "sPrestamo" a rellenar con unos en su campo isEmpty.
 * \param tam2 es el tamaño de la estructura "sPrestamo".
 * \return retorna vacio
 *
 */
void inicializarEstructuras(sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos, sLibros lib[],int tam_Libros, sAutores aut[], int tam_Autores);

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
void hardcodeDeEstructuras(sSocios socios[], sAutores autores[], sLibros libros[], sPrestamos prest[]);

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
void AltaSocio (sSocios soc[], int tam_Socios, int* UltimoCodigoDeSocio);

/** \brief da de baja un socio realizando una baja logica, rellenando el campo "isEmpty" del socio con un cero.
 *
 * \param soc[] es la estructura que contiene el campo isEmpty necesario para la baja logica.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return retorna vacio
 *
 */
void bajaSocio (sSocios soc[], int tam_Socios);

/** \brief modifica uno de los campos de la estructura socios.
 *
 * \param soc[] es la estructura que se va a utilizar para modificar sus campos.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return retorna vacio
 *
 */
void modificarSocio(sSocios soc[], int tam_Socios);

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
void ListarSocios ( sSocios soc[], int tam_Socios);

/** \brief ordena una estructura por apellido (ascendente) y nombre (ascendente)
 *
 * \param soc[] es la estructura que sera ordenada por los criterios ya mencionados
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return
 *
 */
void ordenarSocios(sSocios soc[], int tam_Socios);

//-----------------------------------------------------------------------------------------------------

/** \brief busca un espacio vacio en una estructura
 *
 * \param soc[] es la estructura que se va a utilizar para buscar dicho espacio
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return retorna un entero que corresponde al indice de la estructura en el cual existe un espacio libre.
 *
 */
int buscarEspacioLibreSocios (sSocios soc[], int tam_Socios);

/** \brief Busca a un socio especifico por su codigo correspondiente
 *
 * \param soc[] es la estructura en la que se va a buscar el socio especifico
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param codigo es el codigo correspondiente al socio a buscar.
 * \return retorna el indice de la estructura al que partenece el socio
 *
 */
int buscarSocio(sSocios soc[], int tam_Socios, int codigo);

/** \brief busca en una estructura, el ultimo codigo del ultimo socio y lo incrementa
 *
 * \param soc[] es la estructura en la que se realizara la busqueda del ultimo codigo
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param ultimoCodigo es el ultimo codigo del ultimo socio hasta el momento.
 * \return retorna el ultimo codigo existente incrementado en uno
 *
 */
int buscarUltimoCodigo (sSocios soc[], int tam_Socios, int ultimoCodigo);

/** \brief muestra un pregunta o un mensaje y ofrece como opcion de respuesta (s/n)
 *
 * \param respuesta se utiliza para guardar la respuesta del usuario
 * \param mensaje es el mensaje que se mostrara en pantalla para indicarle al usuario que hacer
 * \return retorna vacio
 *
 */
void getResp (char* respuesta, char mensaje[]);

//-----------------------------------------------------------------------------------------------------

void listarAutores(sAutores aut[], int tam_Autores);

//------------------------------------------------------------------------

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void obtenerPrestTotalYDiario(sPrestamos prest[], int tam_Prestamos, float* contadorDePrestamos, int* contadorDias);
void prestamosTotalesyDiarios (sPrestamos prest[], int tam_Prestamos);
void promedioNoSuperado (sPrestamos prest[], int tam_Prestamos);
void listarPorLibroDeterminado(sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos);
void listarLibrosPorSocioDeterminado (sSocios soc[], int tam_Socios, sLibros lib[], sPrestamos prest[], int tam_Prestamos, int* ultimoCodigo);
void listarYOrdenarPorInsercion(sSocios soc[], int tam_Socios);
void listarLibrosPorFechaDeterminada(sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos);
void socioMenosPrestamos (sSocios soc[],int tam_Socios, sPrestamos prest[], int tam_Prestamos);
void listarLibrosDecendente(sLibros lib[], int tam_libros);
void listarSociosPorFechaDeterminada(sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos);
void informarLibroMenosPrestado (sLibros lib[],int tam_Libros, sPrestamos prest[], int tam_Prestamos);
