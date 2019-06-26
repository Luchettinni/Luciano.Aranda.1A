typedef struct // Autores
{
    int isEmpty;
    int codigoDelAutor;
    char nombre[31];
    char apellido[31];

} sAutores;

/** \brief muestra en pantalla un listado con los autores de los libros y su codigo de autor
 *
 * \param aut[] es la estructura que contiene los autores a listar
 * \param tam_Autores es el tamaño de la estructura
 * \return void
 *
 */
void listarAutores(sAutores aut[], int tam_Autores);

/** \brief ordena una estructura de autores por nombre (ascendente) y apellido (ascendente)
 *
 * \param aut[] es la estructura que sera ordenada con los criterios ya mencionados
 * \param tam_Autores es el tamaño de la estructura
 * \return void
 *
 */
void ordenarAutores(sAutores aut[], int tam_Autores);
