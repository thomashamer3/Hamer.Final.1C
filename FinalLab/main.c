#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "input.h"
#include "participantes.h"
#include "Controller.h"
#include "Parser.h"


int main()
{
    LinkedList* misParticipantes = ll_newLinkedList();
    int opcion;
    int flagParticipantes = 0;


    do
    {
        Menu(opcion);
        utn_getNumero(&opcion,"\nIngrese una Opcion:","Error Ingrese una Opcion entre 1-7",1,7,3);

        switch(opcion)
        {
        case 1:
            system("cls");
            if(flagParticipantes == 0)
            {
                flagParticipantes = Hamer_controller_loadFromText("enduro.csv", misParticipantes);
            }
            else
            {
                printf("Error. Ya se Cargaron los Datos de los Participantes.\n");
            }
            break;

        case 2:
            system("cls");
            if(flagParticipantes == 1)
            {
                Hamer_controller_ImprimirLista(misParticipantes);

            }
            else
            {
                printf("No hay datos que listar.\n");
            }
            break;

        case 4:
            system("cls");
            if(flagParticipantes == 1)
            {
                Hamer_controller_Tipo(misParticipantes);
            }
            else
            {
                printf("No hay datos que listar.\n");
            }
            break;

        case 5:
            if(flagParticipantes == 1)
            {
                controller_sortParticipantes(misParticipantes);
            }
            else
            {
                printf("No hay datos que listar.\n");
            }
            break;

        case 6:
            system("cls");
            if(flagParticipantes == 1)
            {
                Hamer_controller_saveAsText("enduro.csv",misParticipantes);
            }
            else
            {
                printf("No hay datos que Guardar\n");
            }
            break;

        case 7:
            system("cls");
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion incorrecta, por favor ingrese una opcion valida\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion != 7);

    return 0;
}
