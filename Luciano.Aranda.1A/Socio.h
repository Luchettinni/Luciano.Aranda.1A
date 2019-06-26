#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

#include "Libros.h"

#endif // LIBROS_H_INCLUDED

#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

#include "Autores.h"

#endif // AUTORES_H_INCLUDED

typedef struct // Fecha
{
    int dia;
    int mes;
    int year;

} sFecha;

typedef struct // Socios
{
    int isEmpty;
    int codigoDeSocio;

    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char eMail[31];

    sFecha fecha;

} sSocios;

typedef struct // Prestamos
{
    int codigo;
    int codigoSocio;
    int codigoLibro;
    int isEmpty;
    sFecha fecha;

} sPrestamos;



/** \brief "Inicializa" estructuras, rellenandolas con sus campos "isEmpty" en 1.
 *
 * \param soc[] es la estructura de tipo "sSocios" a rellenar con unos en su campo isEmpty.
 * \param prest[] es la estructura de tipo "sSocios" a rellenar con unos en su campo isEmpty.
 * \param lib[] es la estructura de tipo "sSocios" a rellenar con unos en su campo isEmpty.
 * \param tam es el tamaño de la estructura "sSocios".
 * \param prest[] es la estructura de tipo "sPrestamo" a rellenar con unos en su campo isEmpty.
 * \param tam2 es el tamaño de la estructura "sPrestamo".
 * \return void
 *
 */
void inicializarEstructuras(sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos, sLibros lib[],int tam_Libros, sAutores aut[], int tam_Autores);

/** \brief Inicializa estructuras
 *
 * \param socios[] es una de las estructura a inicializar.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param autores[] es una de las estructura a inicializar.
 * \param tam2 es el tamaño de la estructura correspondiente a autores.
 * \param libros[] es una de las estructura a inicializar.
 * \param tam3 es el tamaño de la estructura correspondiente a libros.
 * \return void
 *
 */
void hardcodeDeEstructuras(sSocios socios[], sAutores autores[], sLibros libros[], sPrestamos prest[]);

/** \brief muestra en pantalla un menu de opciones y pregunta por la opcion a efectuar
 *
 * \return el numero correspondiente a la opcion elegida.
 *
 */
int menuDeOpciones();

/** \brief muestra en pantalla un menu de opciones y pregunta por la opcion a efectuar
 *
 * \return el numero correspondiente a la opcion elegida.
 *
 */
int menuDeSocios();

/** \brief muestra en pantalla un menu de opciones y pregunta por la opcion a efectuar
 *
 * \return el numero correspondiente a la opcion elegida.
 *
 */
int menuDeListado();

/** \brief muestra en pantalla un menu de opciones y pregunta por la opcion a efectuar
 *
 * \return el numero correspondiente a la opcion elegida.
 *
 */
int subMenuModificarSocio();

//-----------------------------------------------------------------------------------------------------

/** \brief da de alta un socio rellenando asi, varios campos de la estructura con informacion del mismo
 *
 * \param soc[] es la estructura que se va a utilizar para rellenar sus campos con informacion del socio a dar de alta.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param UltimoCodigoDeSocio se utiliza para otorgarle un codigo al socio dado de alta, este parametro es autoincremental
 * \return void
 *
 */
void AltaSocio (sSocios soc[], int tam_Socios, int* UltimoCodigoDeSocio);

/** \brief da de baja un socio realizando una baja logica, rellenando el campo "isEmpty" del socio con un cero.
 *
 * \param soc[] es la estructura que contiene el campo isEmpty necesario para la baja logica.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return void
 *
 */
void bajaSocio (sSocios soc[], int tam_Socios);

/** \brief modifica uno de los campos de la estructura socios.
 *
 * \param soc[] es la estructura que se va a utilizar para modificar sus campos.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return void
 *
 */
void modificarSocio(sSocios soc[], int tam_Socios);

/** \brief muestra a un unico "socio" especifico
 *
 * \param soc[] es la estructura que se va a utilizar para encontrar al socio que mostrar y sus datos.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return void
 *
 */
void mostrarSocio (sSocios soc[], int i);

/** \brief muestra un listado completo de todos los socios actuales
 *
 * \param soc[] es la estructura que se va a utilizar para listar a los socios con sus respectivos datos sus datos.
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return void
 *
 */
void ListarSocios ( sSocios soc[], int tam_Socios);

/** \brief ordena una estructura por apellido (ascendente) y nombre (ascendente)
 *
 * \param soc[] es la estructura que sera ordenada con los criterios ya mencionados
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return void
 *
 */
void ordenarSocios(sSocios soc[], int tam_Socios);

//-----------------------------------------------------------------------------------------------------

/** \brief busca un espacio vacio en una estructura
 *
 * \param soc[] es la estructura que se va a utilizar para buscar dicho espacio
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \return retorna un entero que corresponde al indice de la estructura en el cual existe un espacio libre.
 *
 */
int buscarEspacioLibreSocios (sSocios soc[], int tam_Socios);

/** \brief Busca a un socio especifico por su codigo correspondiente
 *
 * \param soc[] es la estructura en la que se va a buscar el socio especifico
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param codigo es el codigo correspondiente al socio a buscar.
 * \return retorna el indice de la estructura al que partenece el socio
 *
 */
int buscarSocio(sSocios soc[], int tam_Socios, int codigo);

/** \brief busca en una estructura, el ultimo codigo del ultimo socio y lo incrementa
 *
 * \param soc[] es la estructura en la que se realizara la busqueda del ultimo codigo
 * \param tam es el tamaño de la estructura correspondiente a socios.
 * \param ultimoCodigo es el ultimo codigo del ultimo socio hasta el momento.
 * \return retorna el ultimo codigo existente incrementado en uno
 *
 */
int buscarUltimoCodigo (sSocios soc[], int tam_Socios, int ultimoCodigo);

/** \brief muestra un pregunta o un mensaje y ofrece como opcion de respuesta (s/n)
 *
 * \param respuesta se utiliza para guardar la respuesta del usuario
 * \param mensaje es el mensaje que se mostrara en pantalla para indicarle al usuario que hacer
 * \return void
 *
 */
void getResp (char* respuesta, char mensaje[]);

//-----------------------------------------------------------------------------------------------------

/** \brief obtiene la cantidad de prestamos y de dias que se realizaron prestamos
 *
 * \param prest[] es la estructura que se va a utilizar para obtener los prestamos y los dias
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \param contadorDePrestamos es donde se guardara el total de prestamos
 * \param contadorDias es donde se guardara el total de dias con prestamos
 * \return void
 *
 */
void obtenerPrestTotalYDiario(sPrestamos prest[], int tam_Prestamos, float* contadorDePrestamos, int* contadorDias);

/** \brief
 *
 * \param prest[] es la estructura con la que se va a trabajar para conseguir los prestamos totales y promedio diarios
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void prestamosTotalesyDiarios (sPrestamos prest[], int tam_Prestamos);

/** \brief muestra la cantidad de dias que el promedio no es superado
 *
 * \param prest[] es la estructura con la que se va a trabajar para conseguir los datos deseados
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void promedioNoSuperado (sPrestamos prest[], int tam_Prestamos);

/** \brief lista todos los socios que solicitaron el prestamos de un libro determinado
 *
 * \param soc[] es la estructura de socios que se va a utilizar para encontrar los socios
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param lib[] es la estructura de libros que se va a utilizar para mostrar y preguntar que libro fue el solicitado a prestamos
 * \param tam_Libros es el tamaño de la estructura de libros
 * \param prest[] es la estructura de prestamos que se va a utilizar para encontrar los socios
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void listarPorLibroDeterminado(sSocios soc[], int tam_Socios, sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos);

/** \brief
 *
 * \param soc[] es la estructura de socios que se va a utilizar para encontrar los socios y mostra y preguntar que socio solicito los libros
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param prest[] es la estructura de prestamos que se va a utilizar para encontrar los libros solicitados a prestamo
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void listarLibrosPorSocioDeterminado (sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos, int* ultimoCodigo);

/** \brief lista el/los libro/s menos solicitado/s a prestamo
 *
 * \param lib[] es la estructura de libros que se va a utilzar para encontrar el libro menos prestado
 * \param tam_Libros es el tamaño de la estructura de libros
 * \param prest[] es la estructura de prestamos que se va a utilzar para encontrar el libro menos prestado comparando si hay prestamos existentes y si ellos tienen un libro correspondiente a los de la estructura lib[]
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void informarLibroMenosPrestado (sLibros lib[],int tam_Libros, sPrestamos prest[], int tam_Prestamos);

/** \brief lista todos los libros solicitados a prestamo en una fecha determinada
 *
 * \param lib[] es la estructura de libros que se va a utilzar para encontrar los libros solicitados a prestamo en una fecha determinada
 * \param tam_Libros es el tamaño de la estructura de libros
 * \param prest[] es la estructura de prestamos que se va a utilzar para encontrar los libros solicitados a prestamo en una fecha determinad comparando si hay prestamos existentes, si coinciden con la fecha deseada y si ellos tienen un libro correspondiente a los de la estructura lib[]
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void listarLibrosPorFechaDeterminada(sLibros lib[], int tam_Libros, sPrestamos prest[], int tam_Prestamos);

/** \brief Listar todos los socios que realizaron un prestamo en una fecha determianda
 *
 * \param soc[] es la estructura de socios que se va a utilzar para encontrar los socios que solicitaron prestamos en una fecha determinada
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param prest[] es la estructura de prestamos que se va a utilizar para encontrar los socios que solicitaron prestamos en una fecha determinada ya que estos contienen, justamente los prestamos.
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void listarSociosPorFechaDeterminada(sSocios soc[], int tam_Socios, sPrestamos prest[], int tam_Prestamos);

/** \brief Lista el/los socios que realizaron mas solicitudes de prestamos
 *
 * \param soc[] es la estructura de socios que se va a utilzar para encontrar el socio que realizo menos prestamos
 * \param tam_Socios es el tamaño de la estructura de socios
 * \param prest[] es la estructura de prestamos que se va a utilzar para encontrar el socio que realizo menos prestamos
 * \param tam_Prestamos es el tamaño de la estructura de prestamos
 * \return void
 *
 */
void socioMenosPrestamos (sSocios soc[],int tam_Socios, sPrestamos prest[], int tam_Prestamos);

 /** \brief Listar a todos los libros ordenados por titulo (decendente)
 *
 * \param lib[] es la estrucutra de libros a ordenar
 * \param tam_libros es el tamaño de la estructura libros
 * \return void
 *
 */
void listarLibrosDecendente(sLibros lib[], int tam_libros);

/** \brief Lista todos los socios ordenador por apellido (ascendente), utilizando el metodo de insercion.
 *
 * \param soc[] es la estructura de socios a ordenar
 * \param tam_Socios es el tamaño de la estructura de socios
 * \return void
 *
 */
void listarYOrdenarPorInsercion(sSocios soc[], int tam_Socios);
