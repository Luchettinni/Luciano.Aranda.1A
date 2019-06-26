#include <stdio.h>
#include "string.h"

//---------------------------------------------

#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

#include "Autores.h"

#endif // AUTORES_H_INCLUDED

//---------------------------------------------

void ordenarAutores(sAutores aut[], int tam_Autores)
{
    sAutores autAux;

    for ( int i = 0; i < tam_Autores; i++ )
    {
        for (int j = i+1; j < tam_Autores; j++ )
        {
            if( stricmp(aut[i].apellido, aut[j].apellido) > 0)
            {
                autAux = aut[i]; //socAux ahora vale B
                aut[i] = aut[j]; // empI ahora vale A
                aut[j] = autAux; // empJ ahora vale B
            }

            if( stricmp(aut[i].nombre, aut[j].nombre) > 0)
            {
                autAux = aut[i]; //socAux ahora vale B
                aut[i] = aut[j]; // empI ahora vale A
                aut[j] = autAux; // empJ ahora vale B
            }
        }
    }
}

void listarAutores(sAutores aut[], int tam_Autores)
{
    printf("\nCodigo del autor / nombre / apellido\n");

    for (int i = 0; i < tam_Autores; i++)
    {
        if ( aut[i].isEmpty == 0)
        {
            printf("%d %s %s\n", aut[i].codigoDelAutor, aut[i].nombre, aut[i].apellido);
        }
    }
}