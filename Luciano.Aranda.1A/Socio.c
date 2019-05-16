#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "Socio.h"

#endif // SOCIO_H_INCLUDED

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED

void borrarBaseDeDatos(sSocios soc[], int tam, sPrestamo prest[], int tam2, sLibros lib[],int tam3, sAutores aut[], int tam4)
{
    for(int i=0; i< tam; i++)
    {
        soc[i].isEmpty = 0;
    }

    /*for(int i=0; i< tam2; i++)
    {
        prest[i].isEmpty = 0;
    }*/

    for(int i=0; i< tam3; i++)
    {
        lib[i].isEmpty = 0;
    }

    for(int i=0; i< tam4; i++)
    {
        aut[i].isEmpty = 0;
    }

}

void inicializacionDeEstructuras(sSocios socios[], int tam, sAutores autores[], int tam2, sLibros libros[], int tam3)
{

    sSocios sociosAux[] = {
    {1,1, "luchito", "aranda", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {1,2, "kevin", "ahumada", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {1,3, "thomas", "alvarez", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {1,4, "brenda", "frias", 'f', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} },
    {1,5, "ubuwewewe", "osas", 'm', "42115262", "LuchettinniDev@outlook.com", {2,2,2019} }
    };

    for (int i = 0; i < 5; i++)
    {
        socios[i] = sociosAux[i];
    }

    sAutores autoresAux[] = {
    {1,1, "Peter", "Ahumada"},
    {1,2, "Thomas", "Alvarez"},
    {1,3, "Ricardo", "Milos"},
    {1,4, "Christian", "Bauss"}
    };

    for (int i = 0; i < 4; i++)
    {
        autores[i] = autoresAux[i];
    }
    sLibros librosAux[] = {
    { 1,1,1, "Peter y sus notas veganas"},
    { 1,4,4, "Ricardo milanga: dota2"},
    { 1,4,3, "Programacion en C para profesionales"},
    { 1,3,5, "Los errores de C mas comunes"},
    { 1,4,6, "AYUDA NO ME COMPILA, parte 1"},
    { 1,3,2, "The work of a genius"}
    };

    for (int i = 0; i < 6; i++)
    {
        libros[i] = librosAux[i];
    }
}

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
    int opcion;
    system("cls");
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

void AltaSocio (sSocios soc[], int tam, int* UltimoCodigoDeSocio)
{
    int indice = buscarEspacioLibreSocios(soc, tam);
    if (indice == -1)
    {
        printf("\n no hay mas espacio en el sistema :c");
    }
    else
    {
        *UltimoCodigoDeSocio = buscarUltimoCodigoSocio(soc, tam, UltimoCodigoDeSocio);
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

        soc[indice].isEmpty = 1;

        printf("Alta empleado exitosa!!!\n\n");
    }
}

void bajaSocio (sSocios soc[], int tam)
{
    int indice;
    char respuesta;

    printf("Ingrese el legajo del empleado que desea dar de baja...: ");
    scanf("%d", &indice);

    indice = buscarSocio(soc, tam, indice);

    if ( soc[indice].isEmpty == 1)
    {
        printf("\nel siguiente empleado se eliminara del sistema...\n");
        mostrarSocio(soc, indice);

        getResp(&respuesta, "\n\nEliminar?: ");

        if (respuesta == 's')
        {
            soc[indice].isEmpty = 0;
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

void modificarSocio(sSocios soc[], int tam)
{
    int indice;
    char respuesta;

    printf("\ningrese el codigo del socio que desea modificar: ");
    scanf("%d", &indice);
    indice = buscarSocio(soc, tam, indice);

    if(indice == -1)
    {
            printf("\nEse legajo no existe...\n");
    }
    else
    {
        printf("\nel siguiente empleado se eliminara del sistema...\n");
        mostrarSocio(soc, indice);
        getResp(&respuesta, "\n\nEsta seguro que desea continuar? (s/n): ?: ");

        if (respuesta == 's')
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
                    break;

                default:
                    printf("comando desconocido...");
                    break;
            }
        }
        else
        {
            printf("\n\nVolviendo...\n\n");
        }
    }





}

void ListarSocios ( sSocios soc[], int tam)
{
    printf("\n  Codigo  Nombre           Apellido         Genero  Telefono          Email                            D/MM/AAAA\n\n");

    ordenarSocios(soc, tam);

    for(int  j = 0; j < tam; j++ )
    {
        if( soc[j].isEmpty == 1)
        {
            printf("    %04d  %-15s  %-15s  %-6c  %-16s  %-31s  %2.2d/%.2d/%.4d\n", soc[j].codigoDeSocio, soc[j].nombre, soc[j].apellido, soc[j].sexo, soc[j].telefono, soc[j].eMail, soc[j].fecha.dia, soc[j].fecha.mes, soc[j].fecha.year);
        }
    }

    /*for( int i = 0; i < tam2; i++)
    {
        for(int  j = 0; j < tam; j++ )
        {
            if( soc[j].isEmpty == 1)
            {
                printf("    %04d  %15s  %15s  %6.f  %.2d/%.2d/%.4d\n", soc[j].codigoDeSocio, soc[j].nombre, soc[j].apellido, soc[j].sexo, soc[j].fecha.diaDeIngreso, soc[j].fecha.mesDeIngreso, soc[j].fecha.yearDeIngreso);
            }
        }
    }*/
}

void mostrarSocio (sSocios soc[], int i)
{
    printf("\n  Codigo  Nombre           Apellido         Genero  Telefono          Email                            D/MM/AAAA\n\n");

    printf("    %04d  %-15s  %-15s  %-6c  %-16s  %-31s  %2.2d/%.2d/%.4d\n", soc[i].codigoDeSocio, soc[i].nombre, soc[i].apellido, soc[i].sexo, soc[i].telefono, soc[i].eMail, soc[i].fecha.dia, soc[i].fecha.mes, soc[i].fecha.year);

}

void ordenarSocios(sSocios emp[], int tam)
{
    sSocios empAux;
    for ( int i = 0; i < tam; i++ )
    {
        for (int j = i+1; j < tam; j++ )
        {
            if( stricmp(emp[i].apellido, emp[j].apellido) > 0)
            {
                empAux = emp[i]; //empAux ahora vale B
                emp[i] = emp[j]; // empI ahora vale A
                emp[j] = empAux; // empJ ahora vale B
            }

            if(stricmp(emp[i].nombre, emp[j].nombre) > 0)
            {
                empAux = emp[i]; //empAux ahora vale B
                emp[i] = emp[j]; // empI ahora vale A
                emp[j] = empAux; // empJ ahora vale B
            }

        }
    }
}

int buscarEspacioLibreSocios (sSocios soc[], int tam)
{
    int indice = -1;

    for (int i = 0; i < tam; i++)
    {
        if (soc[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarSocio(sSocios soc[], int tam, int codigo)
{
    int indice = -1;

    for ( int i = 0; i < tam; i++)
    {
        if ( soc[i].codigoDeSocio == codigo && soc[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarUltimoCodigoSocio (sSocios soc[], int tam, int* ultimoCodigo)
{
    for (int i = 0; i < tam; i++)
    {
        if (soc[i].isEmpty == 1 && *ultimoCodigo < soc[i].codigoDeSocio)
        {
            *ultimoCodigo = soc[i].codigoDeSocio;
        }

    }
    return *ultimoCodigo + 1;
}

void getResp (char* respuesta, char mensaje[])
{
    printf(mensaje);
    *respuesta = getche();

    while(tolower(*respuesta) != 's' && tolower(*respuesta) != 'n')
    {
        printf("\n\nEsa respuesta es invalida intente nuevamente...");
        printf(mensaje);
        *respuesta = getche();
    }
}

void listarLibros(sLibros lib[], int tam)
{
    printf("\nCodigo del autor  Codigo del libro  titulo del libro\n\n");

    for(int  j = 0; j < tam; j++ )
    {
        if(lib[j].isEmpty == 1)
        {
            printf("%-16d  %-16d  %-51s \n", lib[j].codigoAutor, lib[j].codigoLibro, lib[j].titulo);
        }
    }
}

void listarAutores(sAutores aut[], int tam)
{
    printf("\nCodigo del autor / nombre / apellido\n");
    for (int i = 0; i < tam; i++)
    {
        if ( aut[i].isEmpty == 1)
        {
            printf("%d %s %s\n", aut[i].codigoDelAutor, aut[i].nombre, aut[i].apellido);
        }
    }
}

//-------------------------------------------------------------------------

void informarTotalYProm (sPrestamo prest[], int tam)
{
    int contador;
    int contadorDias = 0;
    float promedio = 0;

    for (int i = 0; i < 31; i++) // recorro los dias de un mes
    {
        contador = 0;
        for (int j = 0; j < tam; j++) // recorro los prestamos
        {
           if (prest[j].fecha.dia == i+1 && prest[j].isEmpty == 1 )
            {
                contador++;
            }
        }

        if (contador != 0)
        {
            contadorDias++;
        }

        promedio = promedio + contador;
    }

    printf("\ntotal general = %.f\n", promedio);
    promedio = promedio / contadorDias;
    printf("promedio diario = %.2f\n\n", promedio);
}

void listarPorLibroDeterminado(sSocios soc[], int tam, sAutores aut[], int tam2, sLibros lib[], int tam3, sPrestamo prest[], int tam4)
{
    int libro;
    listarLibros(lib,tam3);
    getInt(&libro, "\nIngrese el codigo del libro que desea mostrar: ", "\nERROR, ese libro no existe...", 1, 6);

    printf("\nCodigo de prestamo  Codigo de socio  Nombre           Apellido         Codigo de libro  D/MM/AAAA\n\n");

    for( int j = 0; j < tam4; j++ ) // recorre los prestamos
    {
        //printf("%d prestcodigolibro %d\n", libro, prest[j].codigoLibro);
        if( libro == prest[j].codigoLibro )
        {
            for( int k = 0; k < tam; k++ ) // recorro los socios
            {
                if( soc[k].isEmpty == 1 && prest[j].isEmpty == 1 && lib[libro-1].isEmpty == 1 && prest[j].codigoSocio == soc[k].codigoDeSocio )
                {
                    //printf("soc[%d].isEmpty = %d / prest[%d].isEmpty = %d / prest[%d].codigoEmpleado = %d / soc[%d].codigoDeSocio = %d\n\n", k, soc[k].isEmpty, j,prest[j].isEmpty,j, prest[j].codigoEmpleado, k, soc[k].codigoDeSocio);
                    printf("%-16d   %-16d  %-15s  %-15s  %-15d  %2.2d/%.2d/%.4d\n", prest[j].codigo, soc[k].codigoDeSocio, soc[k].nombre, soc[k].apellido, prest[j].codigoLibro, prest[j].fecha.dia, prest[j].fecha.mes, prest[j].fecha.year);
                }
            }
        }
    }
}

void listarLibrosPorSocioDeterminado (sSocios soc[], int tam, sAutores aut[], int tam2, sLibros lib[], int tam3, sPrestamo prest[], int tam4, int* ultimoCodigo)
{
    int socio;

    ListarSocios(soc,tam);
    getInt(&socio, "\nIngrese el codigo del socio:  ", "\nERROR, ese socio no existe...", 1, *ultimoCodigo);

    printf("\nCodigo de prestamo  Codigo de socio  Nombre           Apellido         Codigo de libro  D/MM/AAAA\n\n");

    for( int j = 0; j < tam4; j++ ) // recorre los prestamos
    {
        //printf("%d prestcodigolibro %d\n", libro, prest[j].codigoLibro);
        if( socio == prest[j].codigoSocio ) // si el socio esta en un prestamo
        {
            for( int k = 0; k < tam; k++ ) // recorro los socios
            {
                if( soc[k].isEmpty == 1 && prest[j].isEmpty == 1 && lib[socio-1].isEmpty == 1 && prest[j].codigoSocio == soc[k].codigoDeSocio )
                {
                    //printf("soc[%d].isEmpty = %d / prest[%d].isEmpty = %d / prest[%d].codigoEmpleado = %d / soc[%d].codigoDeSocio = %d\n\n", k, soc[k].isEmpty, j,prest[j].isEmpty,j, prest[j].codigoEmpleado, k, soc[k].codigoDeSocio);
                    printf("%-16d   %-16d  %-15s  %-15s  %-15d  %2.2d/%.2d/%.4d\n", prest[j].codigo, soc[k].codigoDeSocio, soc[k].nombre, soc[k].apellido, prest[j].codigoLibro , prest[j].fecha.dia, prest[j].fecha.mes, prest[j].fecha.year);
                }
            }
        }
    }
}

void informarLibroMenosPrestado (sLibros lib[],int tam2, sPrestamo prest[], int tam3)
{

    int min = 0;
    int contador;
    int flag = 0;

    for (int i = 0; i < tam2; i++) // recorro los libros
    {
        contador = 0;
        for (int j = 0; j < tam3; j++) // recorro los prestamos por cada libro
        {
            if ( lib[i].codigoLibro == prest[j].codigoLibro && prest[j].isEmpty == 1 && lib[i].isEmpty == 1 ) // si encuentro uno de esos libros en el prestamo, verifico cuantos prestamos se hicieron para ese libro...
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
    for ( int i = 0; i < tam2; i++ ) // este for, recorre nuevamente todo, comparando el minimo encontrado
    {
        contador = 0;
        for ( int j = 0; j < tam3; j++ )
        {
            if ( lib[i].codigoLibro == prest[j].codigoLibro && prest[j].isEmpty == 1 && lib[i].isEmpty == 1 ) // si encuentro uno de esos libros en el prestamo, verifico cuantos prestamos se hicieron para ese libro...
            {
                contador++;
            }
        }
        if (contador == min)
        {
            printf("%-16d  %-16d  %-51s \n", lib[i].codigoAutor, lib[i].codigoLibro, lib[i].titulo);
        }
    }
}

void listarYOrdenarPorInsercion(sSocios soc[], int tam, sLibros lib[],int tam2, sPrestamo prest[], int tam3)
{
    sSocios auxSoc[tam];
    int j;
    for (int i = 1; i < tam; i++)
    {
        auxSoc[i] = soc[i];
        j = i - 1;

        while ( j >= 0 && stricmp(soc[j].apellido, auxSoc[i].apellido ) > 0 )
        {
            soc[j + 1] = soc[j];
            j--;
        }
        soc[j + 1] = auxSoc[i];
    }

    printf("\n  Codigo  Nombre           Apellido         Genero  Telefono          Email                            D/MM/AAAA\n\n");

    for(int  j = 0; j < tam; j++ )
    {
        if( soc[j].isEmpty == 1)
        {
            printf("    %04d  %-15s  %-15s  %-6c  %-16s  %-31s  %2.2d/%.2d/%.4d\n", soc[j].codigoDeSocio, soc[j].nombre, soc[j].apellido, soc[j].sexo, soc[j].telefono, soc[j].eMail, soc[j].fecha.dia, soc[j].fecha.mes, soc[j].fecha.year);
        }
    }
}

void listarLibrosPorFechaDeterminada(sLibros lib[], int tam, sPrestamo prest[], int tam2)
{

    sFecha fechaAux;
    getInt(&fechaAux.dia, "Ingrese dia de ingreso: ", "ERROR: debe ser un numero entre 32 y 1. ", 1, 32);
    getInt(&fechaAux.mes, "Ingrese mes de ingreso: ", "ERROR: debe ser un numero entre 1 y 12. ", 1, 12);
    getInt(&fechaAux.year, "Ingrese year de ingreso: ", "ERROR: debe ser un numero entre 2000 y 2019. ", 2000, 2019);

    printf("\nCodigo del autor  Codigo del libro  titulo del libro\n\n");

    for( int j = 0; j < tam; j++ ) // recorre los libros
    {
        for( int k = 0; k < tam2; k++ ) // recorro los prestamos
        {
            if( fechaAux.dia == prest[k].fecha.dia && fechaAux.mes == prest[k].fecha.mes && fechaAux.year == prest[k].fecha.year)
            {
                if( lib[j].isEmpty == 1 && prest[k].isEmpty == 1 && prest[k].codigoLibro == lib[j].codigoLibro )
                {
                    printf("%-16d  %-16d  %-51s \n", lib[j].codigoAutor, lib[j].codigoLibro, lib[j].titulo);
                    break;

                }
            }
        }
    }
}

void listarLibrosAscendente(sLibros lib[], int tam_libros)
{
    int flagNoEstaOrdenado = 1;
    sLibros auxLib[tam_libros];
    while (flagNoEstaOrdenado == 1)
    {
        flagNoEstaOrdenado = 0;
        for (int i = 1; i < tam_libros; i++)
        {
            if (stricmp(lib[i].titulo, lib[i-1].titulo) > 0 && lib[i].isEmpty == 1 )
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

void promedioNoSuperado (sPrestamo prest[], int tam_prestamos)
{
    int contador;
    int contadorDias = 0;
    float promedio = 0;

    for (int i = 0; i < 31; i++) // recorro los dias de un mes
    {
        promedio = 3.50; // este numero es hardcodeo, pero deberia venir de la funcion que saca pormedios diarios
        contador = 0;
        for (int j = 0; j < tam_prestamos; j++) // recorro los prestamos
        {
           if (prest[j].fecha.dia == i+1 && prest[j].isEmpty == 1 )
            {
                contador++;
            }
        }

        if (contador != 0 && contador < promedio)
        {
            contadorDias++;
        }
    }

    printf("los dias que no superan al prestamo son: %d", contadorDias);
}

void socioMasPrestamos (sSocios soc[],int tam, sPrestamo prest[], int tam2)
{

    int max = 0;
    int contador;
    int flag = 0;

    for (int i = 0; i < tam; i++) // recorro los socios
    {
        contador = 0;
        for (int j = 0; j < tam2; j++) // recorro los prestamos por cada socio
        {
            if ( soc[i].codigoDeSocio == prest[j].codigoSocio && prest[j].isEmpty == 1 && soc[i].isEmpty == 1 ) // si encuentro uno de esos libros en el prestamo, verifico cuantos prestamos se hicieron para ese libro...
            {
                contador++;
            }
        }

        if ( flag == 0 && contador != 0) // con esto seteo un minimo a la primer cantidad de libros que le llegue
        {
            max = contador;
            flag = 1;
        }
        else if ( contador >= max && contador != 0)
        {
            max = contador;
        }

    }

    printf("\nCodigo de socio  Nombre           Apellido         Codigo de libro\n\n");
    for ( int i = 0; i < tam; i++ ) // este for, recorre nuevamente todo, comparando el minimo encontrado
    {
        contador = 0;
        for ( int j = 0; j < tam2; j++ )
        {
            if ( soc[i].codigoDeSocio == prest[j].codigoSocio && prest[j].isEmpty == 1 && soc[i].isEmpty == 1 ) // si encuentro uno de esos libros en el prestamo, verifico cuantos prestamos se hicieron para ese libro...
            {
                contador++;
            }
        }
        if (contador == max)
        {
            printf("%-16d  %-15s  %-15s  %-15d\n", soc[i].codigoDeSocio, soc[i].nombre, soc[i].apellido, prest[i].codigoLibro);
        }
    }
}

void listarSociosPorFechaDeterminada(sSocios soc[], int tam, sPrestamo prest[], int tam2)
{
    sFecha fechaAux;
    getInt(&fechaAux.dia, "Ingrese dia de ingreso: ", "ERROR: debe ser un numero entre 32 y 1. ", 1, 32);
    getInt(&fechaAux.mes, "Ingrese mes de ingreso: ", "ERROR: debe ser un numero entre 1 y 12. ", 1, 12);
    getInt(&fechaAux.year, "Ingrese year de ingreso: ", "ERROR: debe ser un numero entre 2000 y 2019. ", 2000, 2019);

    printf("\nCodigo de prestamo  Codigo de socio  Nombre           Apellido         Codigo de libro\n\n");

    for( int j = 0; j < tam; j++ ) // recorre los soc
    {
        for( int k = 0; k < tam2; k++ ) // recorro los prestamos
        {
            if( fechaAux.dia == prest[k].fecha.dia && fechaAux.mes == prest[k].fecha.mes && fechaAux.year == prest[k].fecha.year)
            {
                if( soc[j].isEmpty == 1 && prest[k].isEmpty == 1 && prest[k].codigoSocio == soc[j].codigoDeSocio )
                {
                   printf("%-16d   %-16d  %-15s  %-15s  %-15d\n", prest[k].codigo, soc[j].codigoDeSocio, soc[j].nombre, soc[j].apellido, prest[k].codigoLibro);

                }
            }
        }
    }
}
