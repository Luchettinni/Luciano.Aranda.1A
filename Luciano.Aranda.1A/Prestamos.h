#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "Socio.h"

#endif // SOCIO_H_INCLUDED

void altaPrestamo(sSocios soc[], int tam, sAutores aut[], int tam2, sLibros lib[], int tam3, sPrestamos prest[], int tam4, int* codigoPrestamo);
void ListarPrestamos (sSocios soc[], int tam, sAutores aut[], int tam2, sLibros lib[], int tam3, sPrestamos prest[], int tam4);

//-----------------------------------------------------------------------------------------------------

int buscarultimoCodigoPrest (sPrestamos prest[], int tam, int* codigoPrest);
int buscarEspacioLibrePrestamos (sPrestamos prest[], int tam);
