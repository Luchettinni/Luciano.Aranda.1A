#include <stdio.h>
#include "string.h"

//---------------------------------------------

#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

#include "Libros.h"

#endif // LIBROS_H_INCLUDED

//---------------------------------------------

void inicializarEstructuraLibros(sLibros lib[],int tam_Libros)
{
    int i;

    for( i=0; i< tam_Libros; i++)
    {
        lib[i].isEmpty = 1;
    }

}

void hardcodeDeEstructuraLibros( sLibros libros[] )
{
    int i;

    sLibros librosAux[] = {
    { 0,1,1, "Peter y sus notas veganas"},
    { 0,4,4, "Ricardo milanga: dota2"},
    { 0,4,3, "Programacion en C para profesionales"},
    { 0,3,5, "Los errores de C mas comunes"},
    { 0,4,6, "AYUDA NO ME COMPILA, parte 1"},
    { 0,3,2, "The work of a genius"}
    };

    for (i = 0; i < 6; i++)
    {
        libros[i] = librosAux[i];
    }
}

void ordenarLibros(sLibros lib[], int tam_libros)
{
    sLibros libAux;
    int i;
    int j;

    for ( i = 0; i < tam_libros; i++ )
    {
        for ( j = i+1; j < tam_libros; j++ )
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
    int  j;
    printf("\nCodigo del autor  Codigo del libro  titulo del libro\n\n");

    for( j = 0; j < tam_Libros; j++ )
    {
        if(lib[j].isEmpty == 0)
        {
            printf("%-16d  %-16d  %-51s \n", lib[j].codigoAutor, lib[j].codigoLibro, lib[j].titulo);
        }
    }
}

