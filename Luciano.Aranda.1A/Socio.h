//---------------------------------------------

#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

#include "Autores.h"

#endif // AUTORES_H_INCLUDED

//---------------------------------------------

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


/** \brief "Inicializa" una estructura de socios, rellenandola con sus campos "isEmpty" en 1.
 *
 * \param soc[] es la estructura de tipo "sSocios" a rellenar con unos en su campo isEmpty.
 * \param tam_Socios es el tamaño de la estructura "sSocios".
 * \return void
 *
 */
void inicializarEstructuraSocios(sSocios soc[], int tam_Socios);

/** \brief Realiza el hardcodeo de una estructura de socios
 *
 * \param socios[] es la estructura a inicializar.
 * \return void
 *
 */
void hardcodeDeEstructuraSocios(sSocios socios[]);

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
 * \param tam_Socios es el tamaño de la estructura correspondiente a socios.
 * \param UltimoCodigoDeSocio se utiliza para otorgarle un codigo al socio dado de alta, este parametro es autoincremental
 * \return void
 *
 */
void AltaSocio (sSocios soc[], int tam_Socios, int* UltimoCodigoDeSocio);

/** \brief da de baja un socio realizando una baja logica, rellenando el campo "isEmpty" del socio con un cero.
 *
 * \param soc[] es la estructura que contiene el campo isEmpty necesario para la baja logica.
 * \param tam_Socios es el tamaño de la estructura correspondiente a socios.
 * \return void
 *
 */
void bajaSocio (sSocios soc[], int tam_Socios);

/** \brief modifica uno de los campos de la estructura socios.
 *
 * \param soc[] es la estructura que se va a utilizar para modificar sus campos.
 * \param tam_Socios es el tamaño de la estructura correspondiente a socios.
 * \return void
 *
 */
void modificarSocio(sSocios soc[], int tam_Socios);

/** \brief muestra a un unico "socio" especifico
 *
 * \param soc[] es la estructura que se va a utilizar para encontrar al socio que mostrar y sus datos.
 * \param i es el indice para encontrar al socio a mostrar
 * \return void
 *
 */
void mostrarSocio (sSocios soc[], int i);

/** \brief muestra un listado completo de todos los socios actuales
 *
 * \param soc[] es la estructura que se va a utilizar para listar a los socios con sus respectivos datos sus datos.
 * \param tam_Socios es el tamaño de la estructura correspondiente a socios.
 * \return void
 *
 */
void ListarSocios ( sSocios soc[], int tam_Socios);

/** \brief ordena una estructura por apellido (ascendente) y nombre (ascendente)
 *
 * \param soc[] es la estructura que sera ordenada con los criterios ya mencionados
 * \param tam_Socios es el tamaño de la estructura correspondiente a socios.
 * \return void
 *
 */
void ordenarSocios(sSocios soc[], int tam_Socios);

//-----------------------------------------------------------------------------------------------------

/** \brief busca un espacio vacio en una estructura
 *
 * \param soc[] es la estructura que se va a utilizar para buscar dicho espacio
 * \param tam_Socios es el tamaño de la estructura correspondiente a socios.
 * \return retorna un entero que corresponde al indice de la estructura en el cual existe un espacio libre.
 *
 */
int buscarEspacioLibreSocios (sSocios soc[], int tam_Socios);

/** \brief Busca a un socio especifico por su codigo correspondiente
 *
 * \param soc[] es la estructura en la que se va a buscar el socio especifico
 * \param tam_Socios es el tamaño de la estructura correspondiente a socios.
 * \param codigo es el codigo correspondiente al socio a buscar.
 * \return retorna el indice de la estructura al que partenece el socio
 *
 */
int buscarSocio(sSocios soc[], int tam_Socios, int codigo);

/** \brief busca en una estructura, el ultimo codigo del ultimo socio y lo incrementa
 *
 * \param soc[] es la estructura en la que se realizara la busqueda del ultimo codigo
 * \param tam_Socios es el tamaño de la estructura correspondiente a socios.
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
