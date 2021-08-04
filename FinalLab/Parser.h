#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

/** \brief  Parseo los Datos
 *
 * \param pData FILE* Archivo a Parsear
 * \param pArrayParticipantes LinkedList* Lista a Utilizar
 * \return int Devuelve si los datos se puedieron Parsear
 *
 */
int parser_FromText(FILE* pData, LinkedList* pArrayParticipantes);

#endif // PARSER_H_INCLUDED
