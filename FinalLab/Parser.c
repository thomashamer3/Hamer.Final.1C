#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "input.h"
#include "Controller.h"
#include "Parser.h"

#include "participantes.h"

int parser_FromText(FILE* pData, LinkedList* pArrayParticipantes)
{
    int retorno = 0;

    char id_cuatri[50];
    char nombre[50];
    char categoria[50];
    char tiempo[50];
    char promedio[50];

    eParticipantes* auxParticipantes;
    int flag = 1;
    if(pData == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }
    do
    {
        if(flag)
        {
            fscanf(pData, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_cuatri, nombre, categoria, tiempo, promedio);
            flag = 0;
        }
        fscanf(pData, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id_cuatri, nombre, categoria, tiempo, promedio);

        auxParticipantes = participantes_newParametros(id_cuatri, nombre, categoria, tiempo, promedio);
        if(auxParticipantes != NULL)
        {
            ll_add(pArrayParticipantes, auxParticipantes);
            retorno = 1;

        }
    }
    while(!feof(pData));
    printf("Los Datos de los Participantes fueron Cargados en Modo Texto.\n");
    return retorno;

}



























