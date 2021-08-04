#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "input.h"
#include "participantes.h"
#include "Controller.h"
#include "Parser.h"

int Hamer_controller_loadFromText(char* path, LinkedList* pArrayParticipantes)
{
    FILE* pData=NULL;

    pData = fopen(path,"r");

    if(pArrayParticipantes!=NULL && pData!=NULL)
    {
        parser_FromText(pData, pArrayParticipantes);
    }

    return 1;
}

int Hamer_controller_ImprimirLista(LinkedList* pArrayParticipantes)
{
    int i;

    eParticipantes* auxParticipantes;

    int id_cuatriAux;
    int tiempoAux;
    int promedioAux;

    char nombre[100];
    char categoriaAux[100];

    int retorno = -1;
    int len = 0;

    if(pArrayParticipantes != NULL)
    {
        printf("\n ID CUATRI--NOMBRE PILOTO ------- CATEGORIA --------- TIEMPO -------- PROMEDIO --- \n");
        retorno = 0;
        len = ll_len(pArrayParticipantes);
        for(i=0; i< len; i++)
        {
            auxParticipantes = ll_get(pArrayParticipantes, i);

            participantes_getIdToCuatri(auxParticipantes, &id_cuatriAux);

            participantes_GetTiempo(auxParticipantes, &tiempoAux);

            participantes_GetPromedio(auxParticipantes,&promedioAux);

            participantes_GetNombre(auxParticipantes, nombre);

            participantes_GetCategoria(auxParticipantes, categoriaAux);


            printf("%5d %20s %14s %9d %12d \n", id_cuatriAux, nombre, categoriaAux, tiempoAux, promedioAux);
        }
    }
    return retorno;
}

int Hamer_controller_saveAsText(char* path, LinkedList* pArrayParticipantes)
{
    FILE* pFile;
    eParticipantes* auxParticipantes;

    int i;

    int* id_cuatriAux;
    int* tiempoAux;
    int* promedioAux;

    char* nombre;
    char* categoriaAux;

    int len;
    if(path != NULL && pArrayParticipantes != NULL)
    {
        id_cuatriAux = malloc(sizeof(int));
        tiempoAux = malloc(sizeof(int));
        promedioAux = malloc(sizeof(int));
        nombre = malloc(sizeof(char)*100);
        categoriaAux = malloc(sizeof(char)*100);

        pFile = fopen(path, "w");
        fprintf(pFile, "id_cuatri,nombre,categoria,tiempo,promedio\n");
        len = ll_len(pArrayParticipantes);
        for(i=0; i < len; i++)
        {
            auxParticipantes = ll_get(pArrayParticipantes, i);

            participantes_getIdToCuatri(auxParticipantes, id_cuatriAux);

            participantes_GetNombre(auxParticipantes, nombre);

            participantes_GetCategoria(auxParticipantes, categoriaAux);

            participantes_GetTiempo(auxParticipantes, tiempoAux);

            participantes_GetPromedio(auxParticipantes, promedioAux);


            fprintf(pFile,"%d,%s,%s,%d,%d\n", *id_cuatriAux, nombre, categoriaAux, *tiempoAux, *promedioAux);
        }
        free(id_cuatriAux);
        free(tiempoAux);
        free(promedioAux);
        free(nombre);
        free(categoriaAux);
        fclose(pFile);
        printf("Se guardaron los datos correctamente\n");
    }
    else
    {
        printf("No se guardó el archivo\n");
    }
    return 1;
}

int Hamer_controller_Tipo(LinkedList* pArrayParticipantes)
{
    int eleccion;

    LinkedList* ListaFiltradaTipo = ll_newLinkedList();

    utn_getNumero(&eleccion,"Que Categoria Desea Filtrar?:1.MX1, 2.MX2, 3.MX3, 4.SUPERATV.","Error Ingrese una Categoria Valida,",1,4,3);
        if(eleccion==1)
        {
           ListaFiltradaTipo = ll_filter(pArrayParticipantes, filtrarCategoriaMX1);
        }
        if(eleccion==2)
        {
           ListaFiltradaTipo = ll_filter(pArrayParticipantes, filtrarCategoriaMX2);
        }
        if(eleccion==3)
        {
           ListaFiltradaTipo = ll_filter(pArrayParticipantes, filtrarCategoriaMX3);
        }
        if(eleccion==4)
        {
           ListaFiltradaTipo = ll_filter(pArrayParticipantes, filtrarCategoriaSuper);
        }

    int retorno = 0;

    if(ListaFiltradaTipo != NULL)
    {
        Hamer_controller_saveAsText("ListaFiltradaTipo.csv", ListaFiltradaTipo);
    }
    ll_deleteLinkedList(ListaFiltradaTipo);
    return retorno;
}

int controller_sortParticipantes(LinkedList* pArrayParticipantes)
{
	    int opcion;
	    int size=0;
	    int retSort;

	    size = ll_len(pArrayParticipantes);

	    if(size>0)
	    {
	        do
	        {
	            system("cls");
	            printf("*** Menu ordenar ***\n");
	            printf("1.Ordenar por Categoria.\n");
	            printf("2.Ordenar por Nombre de la Z-A\n");
	            printf("3.Ordenar por Id Cuatri menor a mayor\n");
	            printf("4.Ordenar por Id Cuatri mayor a menor\n");
	            printf("5.Salir del menu ordenar\n");
	            utn_getNumero(&opcion,"Seleccione una opcion: ", "\nError, ingrese una opcion valida: ",1, 5,3);
	            system("cls");

	            switch(opcion)
	            {
	            case 1:
	                printf("*Ordenando la lista, un momento por favor.\n\n");
	                retSort = ll_sort(pArrayParticipantes, ordenarCategoria, 1);
	                if(retSort!=-1)
	                {
	                    Hamer_controller_ImprimirLista(pArrayParticipantes);
	                }
	                else
	                {
	                    printf("*El ordenamiento fallo\n\n");
	                }
	                system("pause");
	                break;

	            case 2:
	                printf("*Ordenando la lista, un momento por favor...\n\n");
	                retSort = ll_sort(pArrayParticipantes, ordenarNombre, 0);
	                if(retSort!=-1)
	                {
	                    Hamer_controller_ImprimirLista(pArrayParticipantes);
	                }
	                else
	                {
	                    printf("*El ordenamiento fallo\n\n");
	                }
	                system("pause");
	                break;

	            case 3:
	                printf("*Ordenando la lista, un momento por favor...\n\n");
	                retSort = ll_sort(pArrayParticipantes, ordenarIdCuatri, 1);
	                if(retSort!=-1)
	                {
	                    Hamer_controller_ImprimirLista(pArrayParticipantes);
	                }
	                else
	                {
	                    printf("*El ordenamiento fallo\n\n");
	                }
	                system("pause");
	                break;

	            case 4:
	                printf("*Ordenando la lista, un momento por favor...\n\n");
	                retSort = ll_sort(pArrayParticipantes, ordenarIdCuatri, 0);
	                if(retSort!=-1)
	                {
	                    Hamer_controller_ImprimirLista(pArrayParticipantes);
	                }
	                else
	                {
	                    printf("*El ordenamiento fallo\n\n");
	                }
	                system("pause");
	                break;
	            }
	        }
	        while(opcion!=5);
	        printf("*Saliendo del menu ordenar...\n\n");
	    }
	    else if(size==0)
	    {
	        printf("*No hay empleados cargados, ingrese 1 o 2 para cargarlos o 3 para dar de alta uno\n\n");
	    }
	    return 1;
}
