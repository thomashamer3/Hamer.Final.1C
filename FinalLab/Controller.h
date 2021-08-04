#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/** \brief Carga un archivo en formato Texto.
 *
 * \param path char* Nombre del Archivo
 * \param pArrayParticipantes LinkedList* Lista a Utilizar
 * \return int Devuelve si el Archivo se Cargo
 *
 */
int Hamer_controller_loadFromText(char* path, LinkedList* pArrayParticipantes);


/** \brief Imprimo la Lista
 *
 * \param pArrayParticipantes LinkedList* Lista a Utilizar
 * \return int Devuelve si la Lista se puedo Mostrar
 *
 */
int Hamer_controller_ImprimirLista(LinkedList* pArrayParticipantes);



/** \brief Filtro la Lista segun el Elemento pedido.
 *
 * \param pArrayParticipantes LinkedList* Lista a Utilizar
 * \return int Devuelve si la Lista se pudo Filtrar
 *
 */
int Hamer_controller_Tipo(LinkedList* pArrayParticipantes);


/** \brief Guardo los Datos en Formato Archivo Csv
 *
 * \param path char* Nombre del Archivo
 * \param pArrayParticipantes LinkedList* Lista a Utilizar
 * \return int
 *
 */
int Hamer_controller_saveAsText(char* path, LinkedList* pArrayParticipantes);


/** \brief Ordeno Los datos de la Lista
 *
 * \param pArrayParticipantes LinkedList* Lista a Utilizar
 * \return int Devuelve si se Pudo Ordenar los Datos
 *
 */
int controller_sortParticipantes(LinkedList* pArrayParticipantes);

#endif // CONTROLLER_H_INCLUDED
