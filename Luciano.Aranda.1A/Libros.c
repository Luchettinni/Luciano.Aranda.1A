#include <stdio.h>

//---------------------------------------------

#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "Socio.h"

#endif // SOCIO_H_INCLUDED

//---------------------------------------------

#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

#include "Libros.h"

#endif // LIBROS_H_INCLUDED

//---------------------------------------------

void listarLibros(sLibros lib[], int tam_Libros)
{
    printf("\nCodigo del autor  Codigo del libro  titulo del libro\n\n");

    for(int  j = 0; j < tam_Libros; j++ )
    {
        if(lib[j].isEmpty == 0)
        {
            printf("%-16d  %-16d  %-51s \n", lib[j].codigoAutor, lib[j].codigoLibro, lib[j].titulo);
        }
    }
}
