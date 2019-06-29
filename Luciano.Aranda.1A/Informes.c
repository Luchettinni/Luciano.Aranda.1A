#include <stdio.h>
#include <stdlib.h>
#include "string.h"

//---------------------------------------------

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "Informes.h"

#endif // INFORMES_H_INCLUDED

//---------------------------------------------

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED

//---------------------------------------------

void obtenerPrestTotalYDiario(sPrestamos prest[], int tam_Prestamos, float* contadorDePrestamos, int* contadorDias)
{
    int contador;
    int i;
    int j;
    int k;

    for ( i = 0; i < 12; i++ ) // recorro todos los meses de un año
    {
        for ( j = 0; j < 31; j++ ) // recorro los 31 dias de un mes
        {
            contador = 0;
            for ( k = 0; k < tam_Prestamos; k++ ) // recorro los prestamos
            {
                if (prest[k].fecha.dia == j+1 && prest[k].fecha.mes == i+1 && prest[k].isEmpty == 0 )
                {
                    contador++;
                }
            }
            if (contador != 0)
            {
                *contadorDias = *contadorDias + 1;
            }

            *contadorDePrestamos = *contadorDePrestamos + contador;
        }
    }
}

void prestamosTotalesyDiarios (sPrestamos prest[], int tam_Prestamos)
{
    float promedio = 0;
    int contadorDeDias = 0;

    obtenerPrestTotalYDiario(prest,tam_Prestamos,&promedio,&contadorDeDias);

    printf("Prestamos totales = %.f \n", promedio);
    promedio = promedio / contadorDeDias;
    printf("Promedio diario = %.2f \n", promedio);
}

void promedioNoSuperado (sPrestamos prest[], int tam_Prestamos)
{
    int contador = 0;
    float promedio = 0;
    int contadorDias = 0;
    int i;
    int j;
    int k;

    obtenerPrestTotalYDiario(prest,tam_Prestamos,&promedio,&contadorDias);
    promedio = promedio / contadorDias;
    printf("(promedio diario: %.2f...)\n", promedio);
    contadorDias = 0;

    for ( i = 0; i < 12; i++ ) // recorro todos los meses de un año
    {

        for ( j = 0; j < 31; j++ ) // recorro los dias de un mes
        {
            contador = 0;
            for ( k = 0; k < tam_Prestamos; k++ ) // recorro los prestamos
            {
                if (prest[k].fecha.dia == j+1 && prest[k].fecha.mes == i+1 && prest[k].isEmpty == 0 )
                {
                    contador++;
                }
            }

            if (contador != 0 && contador < promedio)
            {
                contadorDias++;
            }
        }
    }

    printf("los dias que no superan al prestamo son: %d \n\n", contadorDias);
}

void listarPorLibroDeterminado(sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos)
{
    int libro;
    listarLibros(lib,tam_Libros);
    getInt(&libro, "\nIngrese el codigo del libro que desea mostrar: ", "\nERROR, ese libro no existe...", 1, 6);
    int j;
    int k;

    printf("\nCodigo de prestamo  Codigo de socio  Nombre           Apellido         Codigo de libro  D/MM/AAAA\n\n");

    for( j = 0; j < tam_Prestamos; j++ ) // recorre los prestamos
    {
        if( prest[j].isEmpty == 0 && libro == prest[j].codigoLibro )
        {
            for( k = 0; k < tam_Socios; k++ ) // recorro los socios
            {
                if( soc[k].isEmpty == 0 && prest[j].isEmpty == 0 && prest[j].codigoSocio == soc[k].codigoDeSocio )
                {
                    printf("%-16d   %-16d  %-15s  %-15s  %-15d  %2.2d/%.2d/%.4d\n", prest[j].codigo, soc[k].codigoDeSocio, soc[k].nombre, soc[k].apellido, prest[j].codigoLibro, prest[j].fecha.dia, prest[j].fecha.mes, prest[j].fecha.year);
                }
            }
        }
    }
}

void listarLibrosPorSocioDeterminado (sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos, int* ultimoCodigo)
{
    int socio;
    int j;
    int k;

    ListarSocios(soc,tam_Socios);
    getInt(&socio, "\nIngrese el codigo del socio:  ", "\nERROR, ese socio no existe...", 1, *ultimoCodigo);

    printf("\nCodigo de prestamo  Codigo de socio  Nombre           Apellido         Codigo de libro  Dia que realizo el prestamo (D/MM/AAAA)\n\n");

    for( j = 0; j < tam_Prestamos; j++ ) // recorre los prestamos
    {
        if( socio == prest[j].codigoSocio ) // si el socio esta en un prestamo
        {
            for( k = 0; k < tam_Socios; k++ ) // recorro los socios
            {
                if( soc[k].isEmpty == 0 && prest[j].isEmpty == 0 && prest[j].codigoSocio == soc[k].codigoDeSocio )
                {
                    printf("%-16d   %-16d  %-15s  %-15s  %-15d  %2.2d/%.2d/%.4d\n", prest[j].codigo, soc[k].codigoDeSocio, soc[k].nombre, soc[k].apellido, prest[j].codigoLibro , prest[j].fecha.dia, prest[j].fecha.mes, prest[j].fecha.year);
                }
            }
        }
    }
}

void informarLibroMenosPrestado (sLibros lib[],int tam_Libros, sPrestamos prest[], int tam_Prestamos)
{

    int min = 0;
    int contador;
    int flag = 0;
    int i;
    int j;

    for ( i = 0; i < tam_Libros; i++) // recorro los libros
    {
        contador = 0;
        for ( j = 0; j < tam_Prestamos; j++) // recorro los prestamos por cada libro
        {
            if ( lib[i].codigoLibro == prest[j].codigoLibro && prest[j].isEmpty == 0 && lib[i].isEmpty == 0 ) // si encuentro uno de esos libros en el prestamo, verifico cuantos prestamos se hicieron para ese libro...
            {
                contador++;
            }
        }

        if ( flag == 0 && contador != 0) // con esto seteo un minimo a la primer cantidad de libros que le llegue
        {
            min = contador;
            flag = 1;
        }
        else if ( contador <= min && contador != 0)
        {
            min = contador;
        }

    }

    printf("\nCodigo del autor  Codigo del libro  titulo del libro\n\n");
    for ( i = 0; i < tam_Libros; i++ ) // este for, recorre nuevamente todo, comparando el minimo encontrado
    {
        contador = 0;
        for ( j = 0; j < tam_Prestamos; j++ )
        {
            if ( lib[i].codigoLibro == prest[j].codigoLibro && prest[j].isEmpty == 0 && lib[i].isEmpty == 0 ) // si encuentro uno de esos libros en el prestamo, verifico cuantos prestamos se hicieron para ese libro...
            {
                contador++;
            }
        }
        if (contador == min && lib[i].isEmpty == 0)
        {
            printf("%-16d  %-16d  %-51s \n", lib[i].codigoAutor, lib[i].codigoLibro, lib[i].titulo);
        }
    }
}

void listarYOrdenarPorInsercion(sSocios soc[], int tam_Socios)
{
    sSocios auxSoc[tam_Socios];
    int j;
    int i;

    for ( i = 1; i < tam_Socios; i++)
    {
        auxSoc[i] = soc[i];
        j = i - 1;

        while ( (j >= 0) && stricmp(soc[j].apellido, auxSoc[i].apellido ) > 0 )
        {
            soc[j + 1] = soc[j];
            j--;
        }
        soc[j + 1] = auxSoc[i];
    }

    ListarSocios(soc, tam_Socios);
}

void listarLibrosPorFechaDeterminada(sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos)
{

    sFecha fechaAux;
    getInt(&fechaAux.dia, "Ingrese dia de ingreso: ", "ERROR: debe ser un numero entre 32 y 1. ", 1, 32);
    getInt(&fechaAux.mes, "Ingrese mes de ingreso: ", "ERROR: debe ser un numero entre 1 y 12. ", 1, 12);
    getInt(&fechaAux.year, "Ingrese year de ingreso: ", "ERROR: debe ser un numero entre 2000 y 2019. ", 2000, 2019);
    int j;
    int k;

    printf("\nCodigo del autor  Codigo del libro  titulo del libro\n\n");

    for( j = 0; j < tam_Libros; j++ ) // recorre los libros
    {
        for( k = 0; k < tam_Prestamos; k++ ) // recorro los prestamos
        {
            if( fechaAux.dia == prest[k].fecha.dia && fechaAux.mes == prest[k].fecha.mes && fechaAux.year == prest[k].fecha.year)
            {
                if( lib[j].isEmpty == 0 && prest[k].isEmpty == 0 && prest[k].codigoLibro == lib[j].codigoLibro )
                {
                    printf("%-16d  %-16d  %-51s \n", lib[j].codigoAutor, lib[j].codigoLibro, lib[j].titulo);
                    break;

                }
            }
        }
    }
}

void listarLibrosDecendente(sLibros lib[], int tam_libros)
{
    int flagNoEstaOrdenado = 1;
    sLibros auxLib[tam_libros];
    int i;

    while (flagNoEstaOrdenado == 1)
    {
        flagNoEstaOrdenado = 0;
        for ( i = 1; i < tam_libros; i++)
        {
            if (stricmp(lib[i].titulo, lib[i-1].titulo) > 0 && lib[i].isEmpty == 0 )
            {
                auxLib[0] = lib[i];
                lib[i] = lib[i-1];
                lib[i-1] = auxLib[0];
                flagNoEstaOrdenado = 1;
            }
        }
    }

    listarLibros(lib,tam_libros);
}

void socioMenosPrestamos (sSocios soc[],int tam_Socios, sPrestamos prest[], int tam_Prestamos)
{

    int max = 0;
    int contador;
    int flag = 0;
    int i;
    int j;

    for ( i = 0; i < tam_Socios; i++) // recorro los socios
    {
        contador = 0;
        for ( j = 0; j < tam_Prestamos; j++) // recorro los prestamos por cada socio
        {
            if ( soc[i].codigoDeSocio == prest[j].codigoSocio && prest[j].isEmpty == 0 && soc[i].isEmpty == 0 ) // si ese socio realizo un prestamo, lo cuento
            {
                contador++; // cantidad de prestamos que un socio realizo
            }
        }

        if ( flag == 0 && contador != 0) // con esto seteo un minimo a la primer cantidad de libros que le llegue
        {
            max = contador;
            flag = 1;
        }
        else if ( contador > max && contador != 0)
        {
            max = contador;
        }

    }

    printf("\nCodigo de socio   Nombre           Apellido         Codigo de libro\n\n");

    for ( i = 0; i < tam_Socios; i++ ) // este for, recorre nuevamente todo, comparando el minimo encontrado
    {
        contador = 0; // seteo la cantidad de prestamos en cero para este socio a recorrer
        for ( j = 0; j < tam_Prestamos; j++ )
        {
            if ( soc[i].codigoDeSocio == prest[j].codigoSocio && prest[j].isEmpty == 0 && soc[i].isEmpty == 0 )
            {
                contador++; // cantidad de prestamos que realizo
            }
        }
        if (contador == max && soc[i].isEmpty == 0)
        {
            printf("%-16d  %-15s  %-15s  %-15d\n", soc[i].codigoDeSocio, soc[i].nombre, soc[i].apellido, prest[i].codigoLibro);
        }
    }
}

void listarSociosPorFechaDeterminada(sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos)
{
    int j;
    int k;
    sFecha fechaAux;
    getInt(&fechaAux.dia, "Ingrese dia de ingreso: ", "ERROR: debe ser un numero entre 32 y 1. ", 1, 32);
    getInt(&fechaAux.mes, "Ingrese mes de ingreso: ", "ERROR: debe ser un numero entre 1 y 12. ", 1, 12);
    getInt(&fechaAux.year, "Ingrese year de ingreso: ", "ERROR: debe ser un numero entre 2000 y 2019. ", 2000, 2019);

    printf("\nCodigo de prestamo  Codigo de socio  Nombre           Apellido         Codigo de libro\n\n");

    for( j = 0; j < tam_Socios; j++ ) // recorre los soc
    {
        for( k = 0; k < tam_Prestamos; k++ ) // recorro los prestamos
        {
            if( fechaAux.dia == prest[k].fecha.dia && fechaAux.mes == prest[k].fecha.mes && fechaAux.year == prest[k].fecha.year)
            {
                if( soc[j].isEmpty == 0 && prest[k].isEmpty == 0 && prest[k].codigoSocio == soc[j].codigoDeSocio )
                {
                   printf("%-16d   %-16d  %-15s  %-15s  %-15d\n", prest[k].codigo, soc[j].codigoDeSocio, soc[j].nombre, soc[j].apellido, prest[k].codigoLibro);

                }
            }
        }
    }
}
