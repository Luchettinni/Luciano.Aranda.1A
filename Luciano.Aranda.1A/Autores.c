#include <stdio.h>
#include "string.h"

//---------------------------------------------

#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

#include "Autores.h"

#endif // AUTORES_H_INCLUDED

//---------------------------------------------

void inicializarEstructuraAutores(sAutores aut[], int tam_Autores)
{
    int i;

    for( i=0; i< tam_Autores; i++)
    {
        aut[i].isEmpty = 1;
    }

}

void hardcodeDeEstructuraAutores( sAutores autores[] )
{
    int i;

    sAutores autoresAux[] = {
    {0,1, "Peter", "Ahumada"},
    {0,2, "Thomas", "Alvarez"},
    {0,3, "Ricardo", "Milos"},
    {0,4, "Christian", "Bauss"}
    };

    for (i = 0; i < 4; i++)
    {
        autores[i] = autoresAux[i];
    }
}

void ordenarAutores(sAutores aut[], int tam_Autores)
{
    int i;
    int j;
    sAutores autAux;

    for ( i = 0; i < tam_Autores; i++ )
    {
        for ( j = i+1; j < tam_Autores; j++ )
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
    int i;
    printf("\nCodigo del autor / nombre / apellido\n");

    for ( i = 0; i < tam_Autores; i++ )
    {
        if ( aut[i].isEmpty == 0)
        {
            printf("%d %s %s\n", aut[i].codigoDelAutor, aut[i].nombre, aut[i].apellido);
        }
    }
}
