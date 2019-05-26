#include <stdio.h>
#include <stdlib.h>

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

void altaPrestamo(sSocios soc[], int tam, sAutores aut[], int tam2, sLibros lib[], int tam3, sPrestamos prest[], int tam4, int* codigoPrestamo)
{
    char respuesta;
    int opcion;

    printf("Ingrese codigo del socio: ");
    int codigo;
    scanf("%d", &codigo);

    int indice = buscarSocio(soc, tam, codigo);

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
            listarLibros(lib, tam3);
            getInt(&opcion, "\n\nSeleccione un libro: ", "\nERROR: ese libro no existe...", 1,6);

            int indice2 = buscarEspacioLibrePrestamos(prest, tam4);
            prest[indice2].codigoSocio = soc[indice].codigoDeSocio;

            prest[indice2].codigoLibro = opcion;
            *codigoPrestamo = buscarultimoCodigoPrest(prest, tam4, codigoPrestamo);
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

void ListarPrestamos (sSocios soc[], int tam, sAutores aut[], int tam2, sLibros lib[], int tam3, sPrestamos prest[], int tam4)
{
    printf("\nCodigo de prestamo  Codigo de socio  Nombre                        Apellido         Libro prestado                       D/MM/AAAA\n\n");

    for( int i = 0; i < tam3; i++) // recorre los libros
    {
        for( int j = 0; j < tam4; j++ ) // recorre los prestamos
        {
            if( lib[i].codigoLibro == prest[j].codigoLibro )
            {
                for( int k = 0; k < tam; k++ ) // recorro los ...?
                {

                    if( soc[k].isEmpty == 0 && prest[j].isEmpty == 0 && lib[i].isEmpty == 0 && prest[j].codigoSocio == soc[k].codigoDeSocio )
                    {
                        //printf("soc[%d].isEmpty = %d / prest[%d].isEmpty = %d / prest[%d].codigoEmpleado = %d / soc[%d].codigoDeSocio = %d\n\n", k, soc[k].isEmpty, j,prest[j].isEmpty,j, prest[j].codigoEmpleado, k, soc[k].codigoDeSocio);
                        printf("%-04d                %-04d             %-15s               %-15s  %-35s  %-2.2d/%.2d/%.4d\n", prest[j].codigo, soc[k].codigoDeSocio, soc[k].nombre, soc[k].apellido, lib[i].titulo, prest[j].fecha.dia, prest[j].fecha.mes, prest[j].fecha.year);
                    }
                }
            }
        }
    }
}

int buscarultimoCodigoPrest (sPrestamos prest[], int tam, int* codigoPrest)
{
    for (int i = 0; i < tam; i++)
    {
        if (prest[i].isEmpty == 0 && *codigoPrest < prest[i].codigo)
        {
            *codigoPrest = prest[i].codigo;
        }
    }
    return *codigoPrest + 1;
}

int buscarEspacioLibrePrestamos (sPrestamos prest[], int tam)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (prest[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

