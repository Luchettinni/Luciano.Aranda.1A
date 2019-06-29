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

void inicializarEstructuraSocios(sSocios soc[], int tam_Socios)
{
    int i;

    for(i=0; i< tam_Socios; i++)
    {
        soc[i].isEmpty = 1;
    }

}

void hardcodeDeEstructuraSocios(sSocios socios[])
{
    int i;

    sSocios sociosAux[] = {
    {0,1, "luchito", "aranda", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {0,2, "kevin", "ahumada", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {0,3, "thomas", "alvarez", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {0,4, "brenda", "frias", 'f', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {0,5, "ubuwewewe", "osas", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} }
    };

    for (i = 0; i < 5; i++)
    {
        socios[i] = sociosAux[i];
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
    int j;
    printf("\n  Codigo  Nombre           Apellido         Genero  Telefono          Email                            D/MM/AAAA\n\n");

    for( j = 0; j < tam_Socios; j++ )
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
    int i;
    int j;
    sSocios socAux;

    for ( i = 0; i < tam_Socios; i++ )
    {
        for ( j = i+1; j < tam_Socios; j++ )
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
    int i;
    int indice = -1;

    for ( i = 0; i < tam_Socios; i++ )
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
    int i;
    int indice = -1;

    for ( i = 0; i < tam_Socios; i++ )
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
    int i;
    ultimoCodigo = 0;

    for ( i = 0; i < tam_Socios; i++ )
    {
        if (soc[i].isEmpty == 0 && ultimoCodigo < soc[i].codigoDeSocio)
        {
            ultimoCodigo = soc[i].codigoDeSocio;
        }

    }

    return ultimoCodigo;
}

//-------------------------------------------------------------------------
