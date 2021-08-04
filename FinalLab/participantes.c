#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "participantes.h"

eParticipantes* participantes_new()
{
    eParticipantes* auxParticipantes;
    return auxParticipantes = (eParticipantes*)malloc(sizeof(eParticipantes));
}

eParticipantes* participantes_newParametros(char* id_cuatri,char* nombre,char* categoria,char* tiempo,char* promedio)
{
    eParticipantes* auxParticipantes;
    auxParticipantes = participantes_new();

    int AuxId_cuatri;
    int AuxTiempo;
    int AuxPromedio;

    AuxId_cuatri = atoi(id_cuatri);
    AuxTiempo = atoi(tiempo);
    AuxPromedio = atoi(promedio);


    if(auxParticipantes != NULL)
    {
        participantes_setIdToCuatri(auxParticipantes, AuxId_cuatri);

        participantes_SetTiempo(auxParticipantes, AuxTiempo);

        participantes_SetPromedio(auxParticipantes, AuxPromedio);

        participantes_setNombre(auxParticipantes,nombre);

        participantes_setCategoria(auxParticipantes, categoria);

    }
    return auxParticipantes;
}


//SETTERS Y GETTERS

int participantes_setIdToCuatri(eParticipantes* this,int id_cuatri)
{
    int retorno = -1;
    if(this != NULL && id_cuatri > 0)
    {
        this->id_cuatri =  id_cuatri;
        retorno = 0;
    }
    return retorno;
}

int participantes_getIdToCuatri(eParticipantes* this,int* id_cuatri)
{
    int retorno = -1;
    if(this != NULL && id_cuatri > 0)
    {
        *id_cuatri = this->id_cuatri;
        retorno = 0;
    }
    return retorno;
}


///////////////////////
int participantes_setNombre(eParticipantes* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}


int participantes_GetNombre(eParticipantes* this,char* nombre)
{
    int retorno = -1;
    if(this!= NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}

////////////
int participantes_setCategoria(eParticipantes* this,char* categoria)
{
    int retorno = -1;
    if(this != NULL && categoria != NULL)
    {
        strcpy(this->categoria, categoria);
        retorno = 0;
    }
    return retorno;
}


int participantes_GetCategoria(eParticipantes* this,char* categoria)
{
    int retorno = -1;
    if(this!= NULL && categoria != NULL)
    {
        strcpy(categoria, this->categoria);
        retorno = 0;
    }
    return retorno;
}

////////////////////////
int participantes_SetTiempo(eParticipantes* this,int tiempo)
{
    int retorno = -1;
    if(this != NULL && tiempo > -1)
    {
        this->tiempo = tiempo;
        retorno = 0;
    }
    return retorno;
}

int participantes_GetTiempo(eParticipantes* this,int* tiempo)
{
    int retorno = -1;
    if(this != NULL && *tiempo > -1)
    {
        *tiempo = this->tiempo;
        retorno = 0;
    }
    return retorno;
}


//////////////////////////

int participantes_SetPromedio(eParticipantes* this,int promedio)
{
    int retorno = -1;
    if(this != NULL && promedio > -1)
    {
        this->promedio = promedio;
        retorno = 0;
    }
    return retorno;
}

int participantes_GetPromedio(eParticipantes* this,int* promedio)
{
    int retorno = -1;
    if(this != NULL && *promedio > -1)
    {
        *promedio = this->promedio;
        retorno = 0;
    }
    return retorno;
}


int filtrarCategoriaMX1(void* pElement)
{
    int returnAux = 0;
    char categoriaAux[50];
    if(pElement != NULL)
    {
        participantes_GetCategoria(pElement, categoriaAux);
        if(strcmpi(categoriaAux, "MX1") == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;

}

int filtrarCategoriaMX2(void* pElement)
{
    int returnAux = 0;
    char categoriaAux[50];
    if(pElement != NULL)
    {
        participantes_GetCategoria(pElement, categoriaAux);
        if(strcmpi(categoriaAux, "MX2") == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;

}

int filtrarCategoriaMX3(void* pElement)
{
    int returnAux = 0;
    char categoriaAux[50];
    if(pElement != NULL)
    {
        participantes_GetCategoria(pElement, categoriaAux);
        if(strcmpi(categoriaAux, "MX3") == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;

}

int filtrarCategoriaSuper(void* pElement)
{
    int returnAux = 0;
    char categoriaAux[50];
    if(pElement != NULL)
    {
        participantes_GetCategoria(pElement, categoriaAux);
        if(strcmpi(categoriaAux, "SUPER_ATV") == 0)
        {
            returnAux = 1;
        }
    }
    return returnAux;

}

int ordenarCategoria(void* e1, void* e2)
{
    eParticipantes* categoria1 = (eParticipantes*) e1;
    eParticipantes* categoria2 = (eParticipantes*) e2;
    int ret;

    char nombreCategoria1[51];
    char nombreCategoria2[51];

    participantes_GetCategoria(categoria1, nombreCategoria1);
    participantes_GetCategoria(categoria2, nombreCategoria2);

    if(categoria1!=NULL && categoria2!=NULL)
    {
        ret = strcmp(nombreCategoria1, nombreCategoria2);
    }
    else
    {
        ret = -1;
    }
    return ret;
}

int ordenarNombre(void* e1, void* e2)
{
    eParticipantes* nombre1 = (eParticipantes*) e1;
    eParticipantes* nombre2 = (eParticipantes*) e2;
    int ret;

    char nombreCategoria1[51];
    char nombreCategoria2[51];

    participantes_GetNombre(nombre1, nombreCategoria1);
    participantes_GetNombre(nombre2, nombreCategoria2);

    if(nombre1!=NULL && nombre2!=NULL)
    {
        ret = strcmp(nombreCategoria1, nombreCategoria2);
    }
    else
    {
        ret = -1;
    }
    return ret;
}

int ordenarIdCuatri(void* e1, void* e2)
{
    eParticipantes* participante1 = (eParticipantes*) e1;
    eParticipantes* participante2 = (eParticipantes*) e2;
    int ret;
    int idCuatri1;
    int idCuatri2;

    participantes_getIdToCuatri(participante1, &idCuatri1);
    participantes_getIdToCuatri(participante2, &idCuatri2);

    if(participante1!=NULL && participante2!=NULL)
    {
        if(idCuatri1 > idCuatri2)
        {
            ret = 1;
        }
        else
        {
            if(idCuatri1 < idCuatri2)
            {
                ret = -1;
            }
            else
            {
                ret = 0;
            }
        }
    }
    return ret;
}
