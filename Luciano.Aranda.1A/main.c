#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------

#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include "Socio.h"

#endif // SOCIO_H_INCLUDED}

//---------------------------------------------

#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED

#include "Prestamos.h"

#endif // PRESTAMOS_H_INCLUDED

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

#define TAM_SOCIOS 10
#define TAM_AUTORES 10
#define TAM_LIBROS 20
#define TAM_PRESTAMOS 100

int main()
{
    sSocios socios[TAM_SOCIOS];
    sAutores autor[TAM_AUTORES];
    sLibros libros[TAM_LIBROS];
    sPrestamos prestamo[TAM_PRESTAMOS];


    char confirma;

    int codigoSocio = 0;
    int codigoPrestamo = 0;

    inicializarEstructuras(socios, TAM_SOCIOS, prestamo, TAM_PRESTAMOS,libros,TAM_LIBROS,autor,TAM_AUTORES);
    hardcodeDeEstructuras(socios, autor , libros, prestamo );

    codigoSocio = buscarUltimoCodigo(socios,TAM_SOCIOS,codigoSocio);
    codigoPrestamo = buscarUltimoCodigoPrest(prestamo, TAM_PRESTAMOS);

    do {
        system("cls");
        confirma = '0';
        switch (menuDeOpciones())
        {
            case 1:
                do
                {
                    switch(menuDeSocios())
                    {
                        case 1:
                            AltaSocio(socios, TAM_SOCIOS, &codigoSocio);
                            system("pause");
                            break;

                        case 2:
                            if ( buscarUltimoCodigo(socios,TAM_SOCIOS,codigoSocio) )
                            {
                                bajaSocio(socios, TAM_SOCIOS);
                            }
                            else
                            {
                                printf("\nNo existen socios a dar de baja...\n\n");
                            }

                            system("pause");
                            break;

                        case 3:
                            if ( buscarUltimoCodigo(socios,TAM_SOCIOS,codigoSocio) )
                            {
                                modificarSocio(socios, TAM_SOCIOS);
                            }
                            else
                            {
                                printf("\nNo existen socios que modificar...\n\n");
                            }

                            system("pause");
                            break;

                        case 4:
                            if ( buscarUltimoCodigo(socios,TAM_SOCIOS,codigoSocio) )
                            {
                               ListarSocios(socios, TAM_AUTORES);

                            }
                            else
                            {
                                printf("\nno hay socios que mostrar...\n\n");
                            }

                            system("pause");
                            break;

                        case 5:
                            listarLibros(libros, TAM_LIBROS);
                            system("pause");
                            break;

                        case 6:
                            listarAutores(autor, TAM_AUTORES);
                            system("pause");
                            break;

                        case 7:
                            if ( buscarUltimoCodigo(socios,TAM_SOCIOS,codigoSocio) )
                            {
                                altaPrestamo(socios,TAM_SOCIOS,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS, &codigoPrestamo);
                                ListarPrestamos(socios,TAM_SOCIOS,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            }
                            else
                            {
                                printf("\n\nNo existen socios para hacer prestamos...\n\n");
                            }

                            system("pause");
                            break;

                        case 8:
                            printf("volviendo...");
                            system("pause");
                            confirma = '1';
                            break;

                        default:
                            printf("\nEl comando ingresado es desconocido...\n\n");
                            system("pause");
                            break;
                    }
                } while (confirma != '1');
                break;

            case 2:
                do
                {
                    switch(menuDeListado())
                    {
                        case 1:
                            if ( buscarUltimoCodigoPrest(prestamo, TAM_PRESTAMOS) )
                            {
                                prestamosTotalesyDiarios (prestamo,TAM_PRESTAMOS);
                            }
                            else
                            {
                                printf("\nNo se encontraron prestamos para realizar esta opcion... \n\n");
                            }

                            system("pause");
                            break;

                        case 2:
                            if ( buscarUltimoCodigoPrest(prestamo, TAM_PRESTAMOS) )
                            {
                                promedioNoSuperado(prestamo,TAM_PRESTAMOS);
                            }
                            else
                            {
                                printf("\nNo se encontraron prestamos para realizar esta opcion... \n\n");
                            }

                            system("pause");
                            break;

                        case 3:
                            if ( buscarUltimoCodigoPrest(prestamo, TAM_PRESTAMOS) )
                            {
                                listarPorLibroDeterminado(socios,TAM_SOCIOS,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            }
                            else
                            {
                                printf("\nNo se encontraron prestamos para realizar esta opcion... \n\n");
                            }

                            system("pause");
                            break;

                        case 4:
                            if ( buscarUltimoCodigoPrest(prestamo, TAM_PRESTAMOS) || buscarUltimoCodigo(socios,TAM_SOCIOS,codigoSocio) )
                            {
                                listarLibrosPorSocioDeterminado(socios, TAM_SOCIOS, libros, prestamo, TAM_PRESTAMOS, &codigoSocio);
                            }
                            else
                            {
                                printf("\nNo se encontraron prestamos para realizar esta opcion... \n\n");
                            }

                            system("pause");
                            break;

                        case 5:
                            if ( buscarUltimoCodigoPrest(prestamo, TAM_PRESTAMOS) )
                            {
                                informarLibroMenosPrestado(libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            }
                            else
                            {
                                printf("\nNo se encontraron prestamos para realizar esta opcion... \n\n");
                            }
                            system("pause");
                            break;

                        case 6:
                            if ( buscarUltimoCodigoPrest(prestamo, TAM_PRESTAMOS) )
                            {
                                socioMenosPrestamos(socios,TAM_SOCIOS,prestamo,TAM_PRESTAMOS);
                            }
                            else
                            {
                                printf("\nNo se encontraron prestamos para realizar esta opcion... \n\n");
                            }
                            system("pause");
                            break;

                        case 7:
                            if ( buscarUltimoCodigoPrest(prestamo, TAM_PRESTAMOS) )
                            {
                                listarLibrosPorFechaDeterminada(libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            }
                            else
                            {
                                printf("\nNo se encontraron prestamos para realizar esta opcion... \n\n");
                            }

                            system("pause");
                            break;

                        case 8:
                            if ( buscarUltimoCodigoPrest(prestamo, TAM_PRESTAMOS) || buscarUltimoCodigo(socios,TAM_SOCIOS,codigoSocio) )
                            {
                                listarSociosPorFechaDeterminada(socios, TAM_SOCIOS,prestamo,TAM_PRESTAMOS);
                            }
                            else
                            {
                                printf("\nNo se encontraron prestamos para realizar esta opcion... \n\n");
                            }
                            system("pause");
                            break;

                        case 9:
                            listarLibrosDecendente(libros,TAM_LIBROS);
                            system("pause");
                            break;

                        case 10:
                            if ( buscarUltimoCodigo(socios,TAM_SOCIOS,codigoSocio) )
                            {
                                listarYOrdenarPorInsercion(socios,TAM_SOCIOS);
                            }
                            else
                            {
                                printf("\nNo se encontraron socios para realizar esta opcion... \n\n");
                            }

                            system("pause");
                            break;

                        case 11:
                            confirma = '2';
                            break;

                        case 12:
                            ListarPrestamos(socios,TAM_SOCIOS,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        default:
                            printf("\nEl comando ingresado es desconocido...\n\n");
                            system("pause");
                            break;
                    }
                } while (confirma != '2');
                system("pause");
                break;

            case 3:
                getAnswer(&confirma, "esta seguro que desea salir? (s/n): ");
                printf("\n");
                break;

            default:
                printf("\nEl comando ingresado es desconocido...\n\n");
                system("pause");
                break;
        }
    } while (confirma != 's');

    return 0;
}
