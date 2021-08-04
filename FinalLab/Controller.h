#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int Hamer_controller_loadFromText(char* path, LinkedList* pArrayParticipantes);

int Hamer_controller_ImprimirLista(LinkedList* pArrayParticipantes);

int Hamer_controller_Tipo(LinkedList* pArrayParticipantes);

int Hamer_controller_saveAsText(char* path, LinkedList* pArrayParticipantes);

#endif // CONTROLLER_H_INCLUDED
