//---------------------------------------------

#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "Socio.h"

#endif // SOCIO_H_INCLUDED

//---------------------------------------------

#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

#include "Prestamos.h"

#endif // PRESTAMOS_H_INCLUDED

//---------------------------------------------

#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

#include "Libros.h"

#endif // LIBROS_H_INCLUDED

//---------------------------------------------

/** \brief obtiene la cantidad de prestamos y de dias que se realizaron prestamos
 *
 * \param prest[] es la estructura que se va a utilizar para obtener los prestamos y los dias
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \param contadorDePrestamos es donde se guardara el total de prestamos
 * \param contadorDias es donde se guardara el total de dias con prestamos
 * \return void
 *
 */
void obtenerPrestTotalYDiario(sPrestamos prest[], int tam_Prestamos, float* contadorDePrestamos, int* contadorDias);

/** \brief
 *
 * \param prest[] es la estructura con la que se va a trabajar para conseguir los prestamos totales y promedio diarios
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void prestamosTotalesyDiarios (sPrestamos prest[], int tam_Prestamos);

/** \brief muestra la cantidad de dias que el promedio no es superado
 *
 * \param prest[] es la estructura con la que se va a trabajar para conseguir los datos deseados
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void promedioNoSuperado (sPrestamos prest[], int tam_Prestamos);

/** \brief lista todos los socios que solicitaron el prestamos de un libro determinado
 *
 * \param soc[] es la estructura de socios que se va a utilizar para encontrar los socios
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param lib[] es la estructura de libros que se va a utilizar para mostrar y preguntar que libro fue el solicitado a prestamos
 * \param tam_Libros es el tamaño de la estructura de libros
 * \param prest[] es la estructura de prestamos que se va a utilizar para encontrar los socios
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void listarPorLibroDeterminado(sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos);

/** \brief
 *
 * \param soc[] es la estructura de socios que se va a utilizar para encontrar los socios y mostra y preguntar que socio solicito los libros
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param prest[] es la estructura de prestamos que se va a utilizar para encontrar los libros solicitados a prestamo
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void listarLibrosPorSocioDeterminado (sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos, int* ultimoCodigo);

/** \brief lista el/los libro/s menos solicitado/s a prestamo
 *
 * \param lib[] es la estructura de libros que se va a utilzar para encontrar el libro menos prestado
 * \param tam_Libros es el tamaño de la estructura de libros
 * \param prest[] es la estructura de prestamos que se va a utilzar para encontrar el libro menos prestado comparando si hay prestamos existentes y si ellos tienen un libro correspondiente a los de la estructura lib[]
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void informarLibroMenosPrestado (sLibros lib[],int tam_Libros, sPrestamos prest[], int tam_Prestamos);

/** \brief lista todos los libros solicitados a prestamo en una fecha determinada
 *
 * \param lib[] es la estructura de libros que se va a utilzar para encontrar los libros solicitados a prestamo en una fecha determinada
 * \param tam_Libros es el tamaño de la estructura de libros
 * \param prest[] es la estructura de prestamos que se va a utilzar para encontrar los libros solicitados a prestamo en una fecha determinad comparando si hay prestamos existentes, si coinciden con la fecha deseada y si ellos tienen un libro correspondiente a los de la estructura lib[]
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void listarLibrosPorFechaDeterminada(sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos);

/** \brief Listar todos los socios que realizaron un prestamo en una fecha determianda
 *
 * \param soc[] es la estructura de socios que se va a utilzar para encontrar los socios que solicitaron prestamos en una fecha determinada
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param prest[] es la estructura de prestamos que se va a utilizar para encontrar los socios que solicitaron prestamos en una fecha determinada ya que estos contienen, justamente los prestamos.
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void listarSociosPorFechaDeterminada(sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos);

/** \brief Lista el/los socios que realizaron mas solicitudes de prestamos
 *
 * \param soc[] es la estructura de socios que se va a utilzar para encontrar el socio que realizo menos prestamos
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param prest[] es la estructura de prestamos que se va a utilzar para encontrar el socio que realizo menos prestamos
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void socioMenosPrestamos (sSocios soc[],int tam_Socios, sPrestamos prest[], int tam_Prestamos);

 /** \brief Listar a todos los libros ordenados por titulo (decendente)
 *
 * \param lib[] es la estrucutra de libros a ordenar
 * \param tam_libros es el tamaño de la estructura libros
 * \return void
 *
 */
void listarLibrosDecendente(sLibros lib[], int tam_libros);

/** \brief Lista todos los socios ordenador por apellido (ascendente), utilizando el metodo de insercion.
 *
 * \param soc[] es la estructura de socios a ordenar
 * \param tam_Socios es el tamaño de la estructura de socios
 * \return void
 *
 */
void listarYOrdenarPorInsercion(sSocios soc[], int tam_Socios);

