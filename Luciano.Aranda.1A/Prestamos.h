#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "Socio.h"

#endif // SOCIO_H_INCLUDED

/** \brief Da de alta un prestamo
 *
 * \param soc[] es la estructura de socios que se va a utilizar para dar de alta un prestamo a un socio determinado
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param lib[] es la estructura de libros que se va a utilizar para saber que libro dar de alta como prestamo
 * \param tam_Libros es el tamaño de la estructura de libros
 * \param prest[] es la estructura de prestamos que se va a utilizar para dar cargar el prestamo realizado en uno de los indices de la misma
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \param codigoPrestamo es el codigo del prestamo que se esta dando de alta
 * \return void
 *
 */
void altaPrestamo(sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos, int* codigoPrestamo);

/** \brief genera un listado de todos los prestamos
 *
 * \param soc[] es la estructura de socios que se va a utilizar para encontrar los prestamos
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param lib[] es la estructura de libros que se va a utilizar para para encontrar los prestamos
 * \param tam_Libros es el tamaño de la estructura de libros
 * \param prest[] es la estructura de prestamos que se va a utilizar para para encontrar los prestamos
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void ListarPrestamos (sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos);

//-----------------------------------------------------------------------------------------------------

/** \brief busca el codigo del ultimo prestamo
 *
 * \param prest[] es la estructura de prestamos que se va a utilizar para buscar el codigo del ultimo prestamo
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return retorna (0) si no hay ningun prestamo o el codigo del ultimo prestamo
 *
 */
int buscarUltimoCodigoPrest (sPrestamos prest[], int tam_Prestamos);

/** \brief busca el indice en una array de estructura de prestamos que tenga espacio libre
 *
 * \param prest[] es la estructura de prestamos que se va a utilizar para buscar el espacio libre
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return retorna (-1) si no hay lugares vacios o el indice del lugar vacio
 *
 */
int buscarEspacioLibrePrestamos (sPrestamos prest[], int tam_Prestamos);
