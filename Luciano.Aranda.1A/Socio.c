#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

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

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED

//---------------------------------------------

void inicializarEstructuras(sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos, sLibros lib[],int tam_Libros, sAutores aut[], int tam_Autores)
{
    for(int i=0; i< tam_Socios; i++)
    {
        soc[i].isEmpty = 1;
    }

    for(int i=0; i< tam_Prestamos; i++)
    {
        prest[i].isEmpty = 1;
    }

    for(int i=0; i< tam_Libros; i++)
    {
        lib[i].isEmpty = 1;
    }

    for(int i=0; i< tam_Autores; i++)
    {
        aut[i].isEmpty = 1;
    }

}

void hardcodeDeEstructuras(sSocios socios[], sAutores autores[], sLibros libros[], sPrestamos prest[])
{

    sSocios sociosAux[] = {
    {0,1, "luchito", "aranda", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {0,2, "kevin", "ahumada", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {0,3, "thomas", "alvarez", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {0,4, "brenda", "frias", 'f', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {0,5, "ubuwewewe", "osas", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} }
    };

    for (int i = 0; i < 5; i++)
    {
        socios[i] = sociosAux[i];
    }

    sAutores autoresAux[] = {
    {0,1, "Peter", "Ahumada"},
    {0,2, "Thomas", "Alvarez"},
    {0,3, "Ricardo", "Milos"},
    {0,4, "Christian", "Bauss"}
    };

    for (int i = 0; i < 4; i++)
    {
        autores[i] = autoresAux[i];
    }
    sLibros librosAux[] = {
    { 0,1,1, "Peter y sus notas veganas"},
    { 0,4,4, "Ricardo milanga: dota2"},
    { 0,4,3, "Programacion en C para profesionales"},
    { 0,3,5, "Los errores de C mas comunes"},
    { 0,4,6, "AYUDA NO ME COMPILA, parte 1"},
    { 0,3,2, "The work of a genius"}
    };

    for (int i = 0; i < 6; i++)
    {
        libros[i] = librosAux[i];
    }

    sPrestamos prestAux [] = {
    {1,1,2,0, {8,6,2019} },
    {1,1,2,0, {8,6,2019} },
    {2,4,2,0, {8,7,2019} },
    {3,4,6,0, {7,5,2019} },
    {5,4,2,0, {7,5,2019} }
    };

    for (int i = 0; i < 5; i++)
    {
        prest[i] = prestAux[i];
    }
}

//-------------------------------------------------------------------------

int menuDeOpciones()
{
    int opcion;

    printf("-----Administracion de prestamo de libros-----");
    printf("\n1) Socios");
    printf("\n2) Informes");
    printf("\n3) Salir");
    printf("\n\n... Que desea hacer?: ");

    scanf("%d", &opcion);

    return opcion;
}

int menuDeSocios()
{
    int opcion;
    system("cls");
    printf("-----Administracion de prestamo de libros----- // SOCIOS");
    printf("\n1) Alta socio");
    printf("\n2) Baja socio");
    printf("\n3) Modificar socio");
    printf("\n4) Listar socios");
    printf("\n5) Listar libros");
    printf("\n6) Listar autores");
    printf("\n7) Prestamos");
    printf("\n8) Volver hacia atras");
    printf("\n\n... Que desea hacer?: ");

    scanf("%d", &opcion);

    return opcion;
}

int menuDeListado()
{
    int opcion;
    system("cls");
    printf("-----Administracion de prestamo de libros----- // LISTAR");
    printf("\n1) Informar el total general y promedio diario");
    printf("\n2) Informar la cantidad de dias que el promedio no es superado"); // falta
    printf("\n3) listar todos los socios que solicitaron el prestamos de un libro determinado");
    printf("\n4) listar todos los libros que fueron solicitados a prestamo por un socio determinado");
    printf("\n5) listar el/los libro/s menos solicitado/s en prestamo");
    printf("\n6) Listar el/los socios que realizaron mas solicitudes de prestamos"); // falta
    printf("\n7) listar todos los libros solicitados a prestamo en una fecha determinada");
    printf("\n8) Listar todos los socios que realizaron un prestamo en una fecha determianda");
    printf("\n9) Listar a todos los libros ordenados por titulo(decendente)");
    printf("\n10) Listar todos los socios ordenador por apellido (ascendente), utilizando el metodo de insercion.");
    printf("\n11) Volver hacia atras");
    printf("\n\n... Que desea hacer?: ");

    scanf("%d", &opcion);

    return opcion;
}

int subMenuModificarSocio()
{
    system("cls");
    int opcion;
    printf("-----Administracion de prestamo de libros----- // SOCIOS // MODIFICAR SOCIO");
    printf("\n1) Modificar apellido");
    printf("\n2) Modificar nombre");
    printf("\n3) Modificar sexo");
    printf("\n4) Modificar telefono");
    printf("\n5) Modificar eMail");
    printf("\n6) Volver hacia atras");
    printf("\n\n... Que desea hacer?: ");

    scanf("%d", &opcion);

    return opcion;
}

//-------------------------------------------------------------------------

void AltaSocio (sSocios soc[], int tam_Socios, int* UltimoCodigoDeSocio)
{
    int indice = buscarEspacioLibreSocios(soc, tam_Socios);
    if (indice == -1)
    {
        printf("\n no hay mas espacio en el sistema :c");
    }
    else
    {
        *UltimoCodigoDeSocio += 1;
        fflush(stdin);
        soc[indice].codigoDeSocio = *UltimoCodigoDeSocio;

        getString(soc[indice].nombre, "Ingrese su nombre: ", "ERROR: El nombre es muy corto o es demasiado largo.", 3, 25);

        getString(soc[indice].apellido, "Ingrese su apellido: ", "ERROR: El apellido es muy corto o es demasiado largo.", 3, 25);

        getCharGenero(&soc[indice].sexo, "Ingrese su genero: ", "ERROR: Utilice 'm' para masculino o 'f' para femenino.", 'm', 'f');

        getString(soc[indice].telefono, "Ingrese su telefono: ", "ERROR: use solo numeros!.", 8, 16);

        getString(soc[indice].eMail, "Ingrese su Email: ", "ERROR: El Email es muy corto o es demasiado largo.", 13, 31);

        getInt(&soc[indice].fecha.dia, "Ingrese dia de ingreso: ", "ERROR: debe ser un numero entre 32 y 1. ", 1, 32);

        getInt(&soc[indice].fecha.mes, "Ingrese mes de ingreso: ", "ERROR: debe ser un numero entre 1 y 12. ", 1, 12);

        getInt(&soc[indice].fecha.year, "Ingrese year de ingreso: ", "ERROR: debe ser un numero entre 2000 y 2019. ", 2000, 2019);

        soc[indice].isEmpty = 0;

        printf("Alta empleado exitosa!!!\n\n");
    }
}

void bajaSocio (sSocios soc[], int tam_Socios)
{
    int indice;
    char respuesta;

    printf("Ingrese el legajo del empleado que desea dar de baja...: ");
    scanf("%d", &indice);

    indice = buscarSocio(soc, tam_Socios, indice);

    if ( soc[indice].isEmpty == 0)
    {
        printf("\nel siguiente empleado se eliminara del sistema...\n");
        mostrarSocio(soc, indice);

        getAnswer(&respuesta, "\n\nEliminar?: ");

        if (respuesta == 's')
        {
            soc[indice].isEmpty = 1;
            printf("\n\nEl empleado se elimino correctamente\n\n");
        }
        else
        {
            printf("\n\nVolviendo...\n\n");
        }

    }
    else
    {
        printf("\nno se encontro este empleado en el sistema.\n\n");
    }


}

void modificarSocio(sSocios soc[], int tam_Socios)
{
    int opcion = 0;
    int indice;
    char respuesta;

    printf("\ningrese el codigo del socio que desea modificar: ");
    scanf("%d", &indice);
    indice = buscarSocio(soc, tam_Socios, indice);

    if(indice == -1)
    {
            printf("\nEse legajo no existe...\n");
    }
    else
    {
        printf("\nel siguiente empleado se eliminara del sistema...\n");
        mostrarSocio(soc, indice);
        getAnswer(&respuesta, "\n\nEsta seguro que desea continuar? (s/n): ?: ");

        if (respuesta == 's')
        {
            do
            {
                switch(subMenuModificarSocio())
                {
                    fflush(stdin);
                    char apellido[31];
                    char nombre[31];
                    char sexo;
                    char telefono[16];
                    char eMail[31];

                    case 1:
                        getString(apellido, "Ingrese el apellido nuevo: ", "ERROR: apellido demasiado corto, o demasiado largo...", 2, 31);
                        strcpy(soc[indice].apellido, apellido);
                        break;
                    case 2:
                        getString(nombre, "Ingrese el nombre nuevo: ", "ERROR: nombre demasiado corto, o demasiado largo...", 2, 31);
                        strcpy(soc[indice].nombre, nombre);
                        break;
                    case 3:
                        getCharGenero(&sexo, "Ingrese el genero nuevo: ", "ERROR: genero invalido...", 'm', 'f');
                        soc[indice].sexo = sexo;
                        break;
                    case 4:
                        getString(telefono, "ingrese el numero de telefono nuevo", "ERROR: el numero es muy largo o muy corto...", 8, 16);
                        strcpy(soc[indice].telefono, telefono);
                        break;

                    case 5:
                        getString(eMail, "Ingrese su Email: ", "ERROR: El Email es muy corto o es demasiado largo.", 13, 31);
                        strcpy(soc[indice].eMail, eMail);
                        break;

                    case 6:
                        printf("\n");
                        opcion = 1;
                        break;

                    default:
                        printf("comando desconocido...");
                        break;
                }
            } while (opcion != 1);
        }
        else
        {
            printf("\n\nVolviendo...\n\n");
        }
    }





}

void ListarSocios ( sSocios soc[], int tam_Socios)
{
    printf("\n  Codigo  Nombre           Apellido         Genero  Telefono          Email                            D/MM/AAAA\n\n");

    for(int  j = 0; j < tam_Socios; j++ )
    {
        if( soc[j].isEmpty == 0)
        {
            printf("    %04d  %-15s  %-15s  %-6c  %-16s  %-31s  %2.2d/%.2d/%.4d\n", soc[j].codigoDeSocio, soc[j].nombre, soc[j].apellido, soc[j].sexo, soc[j].telefono, soc[j].eMail, soc[j].fecha.dia, soc[j].fecha.mes, soc[j].fecha.year);
        }
    }
}

void mostrarSocio (sSocios soc[], int i)
{
    printf("\n  Codigo  Nombre           Apellido         Genero  Telefono          Email                            D/MM/AAAA\n\n");

    printf("    %04d  %-15s  %-15s  %-6c  %-16s  %-31s  %2.2d/%.2d/%.4d\n", soc[i].codigoDeSocio, soc[i].nombre, soc[i].apellido, soc[i].sexo, soc[i].telefono, soc[i].eMail, soc[i].fecha.dia, soc[i].fecha.mes, soc[i].fecha.year);

}

void ordenarSocios(sSocios soc[], int tam_Socios)
{
    sSocios socAux;

    for ( int i = 0; i < tam_Socios; i++ )
    {
        for (int j = i+1; j < tam_Socios; j++ )
        {
            if( stricmp(soc[i].apellido, soc[j].apellido) > 0)
            {
                socAux = soc[i]; //socAux ahora vale B
                soc[i] = soc[j]; // empI ahora vale A
                soc[j] = socAux; // empJ ahora vale B
            }

            if(stricmp(soc[i].nombre, soc[j].nombre) > 0)
            {
                socAux = soc[i]; //empAux ahora vale B
                soc[i] = soc[j]; // empI ahora vale A
                soc[j] = socAux; // empJ ahora vale B
            }
        }
    }
}

int buscarEspacioLibreSocios (sSocios soc[], int tam_Socios)
{
    int indice = -1;

    for (int i = 0; i < tam_Socios; i++)
    {
        if (soc[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarSocio(sSocios soc[], int tam_Socios, int codigo)
{
    int indice = -1;

    for ( int i = 0; i < tam_Socios; i++)
    {
        if ( soc[i].codigoDeSocio == codigo && soc[i].isEmpty == 0 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarUltimoCodigo (sSocios soc[], int tam_Socios, int ultimoCodigo)
{
    ultimoCodigo = 0;

    for (int i = 0; i < tam_Socios; i++)
    {
        if (soc[i].isEmpty == 0 && ultimoCodigo < soc[i].codigoDeSocio)
        {
            ultimoCodigo = soc[i].codigoDeSocio;
        }

    }

    return ultimoCodigo;
}

//-------------------------------------------------------------------------

void obtenerPrestTotalYDiario(sPrestamos prest[], int tam_Prestamos, float* contadorDePrestamos, int* contadorDias)
{
    int contador;
    for (int i = 0; i < 12; i++) // recorro todos los meses de un año
    {
        for (int j = 0; j < 31; j++) // recorro los 31 dias de un mes
        {
            contador = 0;
            for (int k = 0; k < tam_Prestamos; k++) // recorro los prestamos
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

    obtenerPrestTotalYDiario(prest,tam_Prestamos,&promedio,&contadorDias);
    promedio = promedio / contadorDias;
    printf("(promedio diario: %.2f...)\n", promedio);
    contadorDias = 0;

    for (int i = 0; i < 12; i++) // recorro todos los meses de un año
    {

        for (int j = 0; j < 31; j++) // recorro los dias de un mes
        {
            contador = 0;
            for (int k = 0; k < tam_Prestamos; k++) // recorro los prestamos
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

    printf("\nCodigo de prestamo  Codigo de socio  Nombre           Apellido         Codigo de libro  D/MM/AAAA\n\n");

    for( int j = 0; j < tam_Prestamos; j++ ) // recorre los prestamos
    {
        if( prest[j].isEmpty == 0 && libro == prest[j].codigoLibro )
        {
            for( int k = 0; k < tam_Socios; k++ ) // recorro los socios
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

    ListarSocios(soc,tam_Socios);
    getInt(&socio, "\nIngrese el codigo del socio:  ", "\nERROR, ese socio no existe...", 1, *ultimoCodigo);

    printf("\nCodigo de prestamo  Codigo de socio  Nombre           Apellido         Codigo de libro  Dia que realizo el prestamo (D/MM/AAAA)\n\n");

    for( int j = 0; j < tam_Prestamos; j++ ) // recorre los prestamos
    {
        if( socio == prest[j].codigoSocio ) // si el socio esta en un prestamo
        {
            for( int k = 0; k < tam_Socios; k++ ) // recorro los socios
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

    for (int i = 0; i < tam_Libros; i++) // recorro los libros
    {
        contador = 0;
        for (int j = 0; j < tam_Prestamos; j++) // recorro los prestamos por cada libro
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
    for ( int i = 0; i < tam_Libros; i++ ) // este for, recorre nuevamente todo, comparando el minimo encontrado
    {
        contador = 0;
        for ( int j = 0; j < tam_Prestamos; j++ )
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

    for (int i = 1; i < tam_Socios; i++)
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

    printf("\nCodigo del autor  Codigo del libro  titulo del libro\n\n");

    for( int j = 0; j < tam_Libros; j++ ) // recorre los libros
    {
        for( int k = 0; k < tam_Prestamos; k++ ) // recorro los prestamos
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
    while (flagNoEstaOrdenado == 1)
    {
        flagNoEstaOrdenado = 0;
        for (int i = 1; i < tam_libros; i++)
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

    for (int i = 0; i < tam_Socios; i++) // recorro los socios
    {
        contador = 0;
        for (int j = 0; j < tam_Prestamos; j++) // recorro los prestamos por cada socio
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
    for ( int i = 0; i < tam_Socios; i++ ) // este for, recorre nuevamente todo, comparando el minimo encontrado
    {
        contador = 0; // seteo la cantidad de prestamos en cero para este socio a recorrer
        for ( int j = 0; j < tam_Prestamos; j++ )
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
    sFecha fechaAux;
    getInt(&fechaAux.dia, "Ingrese dia de ingreso: ", "ERROR: debe ser un numero entre 32 y 1. ", 1, 32);
    getInt(&fechaAux.mes, "Ingrese mes de ingreso: ", "ERROR: debe ser un numero entre 1 y 12. ", 1, 12);
    getInt(&fechaAux.year, "Ingrese year de ingreso: ", "ERROR: debe ser un numero entre 2000 y 2019. ", 2000, 2019);

    printf("\nCodigo de prestamo  Codigo de socio  Nombre           Apellido         Codigo de libro\n\n");

    for( int j = 0; j < tam_Socios; j++ ) // recorre los soc
    {
        for( int k = 0; k < tam_Prestamos; k++ ) // recorro los prestamos
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
