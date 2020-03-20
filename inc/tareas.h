#include "sapi.h"

#define msg_t void*

typedef struct
{
	gpioMap_t tecla;			//config

} tTecla;

void tarea_A(void* taskParmPtr);
void tarea_B(void* taskParmPtr);
void tarea_C(void* taskParmPtr);
void tarea_D(void* taskParmPtr);
