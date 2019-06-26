#include <stdio.h>
#include "string.h"

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

void ordenarLibros(sLibros lib[], int tam_libros)
{
    sLibros libAux;

    for ( int i = 0; i < tam_libros; i++ )
    {
        for (int j = i+1; j < tam_libros; j++ )
        {
            if( stricmp(lib[i].titulo, lib[j].titulo) > 0)
            {
                libAux = lib[i]; //socAux ahora vale B
                lib[i] = lib[j]; // empI ahora vale A
                lib[j] = libAux; // empJ ahora vale B
            }
        }
    }
}


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

