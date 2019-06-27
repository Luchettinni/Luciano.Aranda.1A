#include <stdio.h>
#include <stdlib.h>

#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

#include "Prestamos.h"

#endif // PRESTAMOS_H_INCLUDED

//---------------------------------------------

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED

//---------------------------------------------

void inicializarEstructuraPrestamos(sPrestamos prest[], int tam_Prestamos)
{
    int i;

    for( i = 0; i < tam_Prestamos; i++)
    {
        prest[i].isEmpty = 1;
    }

}

void hardcodeDeEstructuraPrestamos(sPrestamos prest[])
{
    int i;

    sPrestamos prestAux [] = {
    {1,1,2,0, {8,6,2019} },
    {1,1,2,0, {8,6,2019} },
    {2,4,2,0, {8,7,2019} },
    {3,4,6,0, {7,5,2019} },
    {5,4,2,0, {7,5,2019} }
    };

    for (i = 0; i < 5; i++)
    {
        prest[i] = prestAux[i];
    }
}

//-------------------------------------------------------------------------

void altaPrestamo(sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos, int* codigoPrestamo)
{
    char respuesta;
    int opcion;

    printf("Ingrese codigo del socio: ");
    int codigo;
    scanf("%d", &codigo);

    int indice = buscarSocio(soc, tam_Socios, codigo);

    if (indice == -1)
    {
        printf("\nNo se encontro ese socio en el sistema.\n\n");
    }
    else
    {
        printf("\nSe realizara el alta del siguiente socio...\n");
        mostrarSocio(soc, indice);
        getAnswer(&respuesta, "\n\nEsta seguro que desea continuar?: ");

        if(respuesta == 's')
        {
            system("cls");
            printf("-----Administracion de prestamo de libros----- // SOCIOS // PRESTAMOS\n\n");
            listarLibros(lib, tam_Libros);
            getInt(&opcion, "\n\nSeleccione un libro: ", "\nERROR: ese libro no existe...", 1,6);

            int indice2 = buscarEspacioLibrePrestamos(prest, tam_Prestamos);
            prest[indice2].codigoSocio = soc[indice].codigoDeSocio;

            prest[indice2].codigoLibro = opcion;
            *codigoPrestamo += 1;
            prest[indice2].isEmpty = 0;
            prest[indice2].codigo = *codigoPrestamo;

            getInt(&prest[indice2].fecha.dia, "Ingrese el dia actual: ", "ERROR: debe ser un numero entre 32 y 1. ", 1, 32);

            getInt(&prest[indice2].fecha.mes, "Ingrese el mes actual: ", "ERROR: debe ser un numero entre 1 y 12. ", 1, 12);

            getInt(&prest[indice2].fecha.year, "Ingrese el year actual: ", "ERROR: debe ser un numero entre 2000 y 2019. ", 2000, 2019);

        }
        else
        {
            printf("\n\nVolviendo... ");
        }
    }
}

void ListarPrestamos (sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos)
{
    printf("\nCodigo de prestamo  Codigo de socio  Nombre                        Apellido         Libro prestado                       D/MM/AAAA\n\n");

    for( int i = 0; i < tam_Libros; i++) // recorre los libros
    {
        for( int j = 0; j < tam_Prestamos; j++ ) // recorre los prestamos
        {
            if( lib[i].codigoLibro == prest[j].codigoLibro ) // si el libro de la iteracion aparece en un prestamo...
            {
                for( int k = 0; k < tam_Socios; k++ ) // recorro los socios para encontrar cuales socios pidieron ese libro
                {
                    if( soc[k].isEmpty == 0 && prest[j].isEmpty == 0 && lib[i].isEmpty == 0 && prest[j].codigoSocio == soc[k].codigoDeSocio )
                    {
                        printf("%-.4d                %-.4d             %-15s               %-15s  %-35s  %-2.2d/%.2d/%.4d\n", prest[j].codigo, soc[k].codigoDeSocio, soc[k].nombre, soc[k].apellido, lib[i].titulo, prest[j].fecha.dia, prest[j].fecha.mes, prest[j].fecha.year);
                    }
                }
            }
        }
    }
}

int buscarUltimoCodigoPrest (sPrestamos prest[], int tam_Prestamos)
{
    int codigoPrest = 0;

    for (int i = 0; i < tam_Prestamos; i++)
    {
        if (prest[i].isEmpty == 0 && codigoPrest < prest[i].codigo)
        {
            codigoPrest = prest[i].codigo;
        }
    }
    return codigoPrest;
}

int buscarEspacioLibrePrestamos (sPrestamos prest[], int tam_Prestamos)
{
    int indice = -1;

    for (int i = 0; i < tam_Prestamos; i++)
    {
        if (prest[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

