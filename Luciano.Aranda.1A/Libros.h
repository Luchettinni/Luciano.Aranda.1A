typedef struct // Libros
{
    int isEmpty;
    int codigoAutor;
    int codigoLibro;
    char titulo[51];

} sLibros;

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
