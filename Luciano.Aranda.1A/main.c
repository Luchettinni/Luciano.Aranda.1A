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
    sPrestamos prestamo[TAM_PRESTAMOS] = {
    {1,1,2,0, {8,6,2019} },
    {2,2,2,0, {8,7,2019} },
    {3,2,6,0, {7,5,2019} },
    {5,2,2,0, {7,5,2019} }
    };// dale, DALE, PONETE A HARDCODEAR, NUNCA VAS A ROMPER MI ABM *Risa de villano generica* (?

    char confirma;
    int confirma2;
    int confirma3;

    int codigoSocio = 0;
    int codigoPrestamoo = 0;

    inicializarEstructuras(socios, TAM_SOCIOS, prestamo, TAM_PRESTAMOS,libros,TAM_LIBROS,autor,TAM_AUTORES);
    hardcodeDeEstructuras(socios, autor , libros, prestamo );

    buscarUltimoCodigoIncremental(socios,TAM_SOCIOS,&codigoSocio);

    do {
        system("cls");
        switch (menuDeOpciones())
        {
            case 1:
                confirma2 = 0;
                while (confirma2 != 5)
                {
                    switch(menuDeSocios())
                    {
                        case 1:
                            AltaSocio(socios, TAM_SOCIOS, &codigoSocio);
                            system("pause");
                            break;

                        case 2:
                            if ( codigoSocio != 0 )
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
                            if ( codigoSocio != 0 )
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
                            if ( codigoSocio != 0 )
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
                            if ( codigoSocio != 0 )
                            {
                                altaPrestamo(socios,TAM_SOCIOS,autor,TAM_AUTORES,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS, &codigoPrestamoo);
                            }
                            else
                            {
                                printf("\n\nNo existen socios para hacer prestamos...\n\n");
                            }
                            ListarPrestamos(socios,TAM_SOCIOS,autor,TAM_AUTORES,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        case 8:
                            printf("volviendo...");
                            system("pause");
                            confirma2 = 5;
                            break;

                        default:
                            printf("\nEl comando ingresado es desconocido...\n\n");
                            system("pause");
                            break;
                    }
                }
                break;

            case 2:
                confirma3 = 0;
                while (confirma3 != 7)
                {
                    switch(menuDeListado())
                    {
                        case 1:
                            prestamosTotalesyDiarios (prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        case 2:
                            promedioNoSuperado(prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        case 3:
                            listarPorLibroDeterminado(socios,TAM_SOCIOS,autor,TAM_AUTORES,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        case 4:
                            listarLibrosPorSocioDeterminado(socios,TAM_SOCIOS,autor,TAM_AUTORES,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS, &codigoSocio);
                            system("pause");
                            break;

                        case 5:
                            informarLibroMenosPrestado(libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        case 6:
                            socioMenosPrestamos(socios,TAM_SOCIOS,prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        case 7:
                            listarLibrosPorFechaDeterminada(libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        case 8:
                            listarSociosPorFechaDeterminada(socios, TAM_SOCIOS,prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        case 9:
                            listarLibrosAscendente(libros,TAM_LIBROS);
                            system("pause");
                            break;

                        case 10:
                            listarYOrdenarPorInsercion(socios,TAM_SOCIOS,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        case 11:
                            confirma3 = 7;
                            break;

                        case 12:
                            ListarPrestamos(socios,TAM_SOCIOS,autor,TAM_AUTORES,libros,TAM_LIBROS,prestamo,TAM_PRESTAMOS);
                            system("pause");
                            break;

                        default:
                            printf("\nEl comando ingresado es desconocido...\n\n");
                            system("pause");
                            break;
                    }
                }
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
