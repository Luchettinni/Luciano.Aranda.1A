typedef struct // Libros
{
    int isEmpty;
    int codigoAutor;
    int codigoLibro;
    char titulo[51];

} sLibros;

/** \brief "Inicializa" una estructura de libros, rellenandola con sus campos "isEmpty" en 1.
 *
 * \param lib[] es la estructura de tipo "sLibros" a rellenar con unos en su campo isEmpty.
 * \param tam_Libros es el tamaño de la estructura "sLibros".
 * \return void
 *
 */
void inicializarEstructuraLibros(sLibros lib[],int tam_Libros);

/** \brief Realiza el hardcodeo de una estructura de libros
 *
 * \param libros[] es la estructura a inicializar.
 * \return void
 *
 */
void hardcodeDeEstructuraLibros( sLibros libros[] );

/** \brief muestra en pantalla un listado con los libros, y el ID correspondiente a sus autores y a si mismos.
 *
 * \param lib[] es la estructura que contiene los libros a listar
 * \param tam_libros es el tamaño de la estructura
 * \return void
 *
 */
void listarLibros(sLibros lib[], int tam_Libros);

/** \brief ordena una estructura de libros por titulo (ascendente)
 *
 * \param lib[] es la estructura que sera ordenada con los criterios ya mencionados
 * \param tam es el tamaño de la estructura correspondiente a libros.
 * \return void
 *
 */
void ordenarLibros(sLibros lib[], int tam_libros);
