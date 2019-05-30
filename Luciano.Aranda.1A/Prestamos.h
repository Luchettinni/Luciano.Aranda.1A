#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "Socio.h"

#endif // SOCIO_H_INCLUDED

void altaPrestamo(sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos, int* codigoPrestamo);
void ListarPrestamos (sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos);

//-----------------------------------------------------------------------------------------------------

int buscarUltimoCodigoPrest (sPrestamos prest[], int tam_Prestamos);
int buscarEspacioLibrePrestamos (sPrestamos prest[], int tam_Prestamos);
