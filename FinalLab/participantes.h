#ifndef PARTICIPANTES_H_INCLUDED
#define PARTICIPANTES_H_INCLUDED

typedef struct
{
    int id_cuatri;
    char nombre[100];
    char categoria[100];
    int tiempo;
    int promedio;
}eParticipantes;

eParticipantes* participantes_new();

eParticipantes* participantes_newParametros(char* id_cuatri,char* nombre,char* categoria,char* tiempo,char* promedio);

int participantes_setIdToCuatri(eParticipantes* this,int id_cuatri);
int participantes_getIdToCuatri(eParticipantes* this,int* id_cuatri);

int participantes_setNombre(eParticipantes* this,char* nombre);
int participantes_GetNombre(eParticipantes* this,char* nombre);

int participantes_setCategoria(eParticipantes* this,char* categoria);
int participantes_GetCategoria(eParticipantes* this,char* categoria);

int participantes_SetTiempo(eParticipantes* this,int tiempo);
int participantes_GetTiempo(eParticipantes* this,int* tiempo);

int participantes_SetPromedio(eParticipantes* this,int promedio);
int participantes_GetPromedio(eParticipantes* this,int* promedio);

int filtrarCategoriaMX1(void* pElement);
int filtrarCategoriaMX2(void* pElement);
int filtrarCategoriaMX3(void* pElement);
int filtrarCategoriaSuper(void* pElement);

int ordenarCategoria(void* e1, void* e2);
int ordenarNombre(void* e1, void* e2);
int ordenarIdCuatri(void* e1, void* e2);



#endif // PARTICIPANTES_H_INCLUDED
