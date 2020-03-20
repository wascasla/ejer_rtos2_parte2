#include "gestor_mensajes.h"


typedef struct {
	char * mensaje;
	xQueueHandle cola;
} Gestor;



/* constructor implementation */
void Gestor_ctor(Gestor * const me, char * mensaje, xQueueHandle cola) {
	me->mensaje = mensaje;
	me->cola = cola;
}
/* move-by operation implementation */
/*void Gestor_moveBy(Gestor * const me, char mensajex[], xQueueHandle colay) {
me->mensaje += mensajex;
me->cola += colay;
}*/
/* "getter" operations implementation */
char * Gestor_getMsg(Gestor * const me) {
	return me->  mensaje;
}
xQueueHandle Gestor_getCola(Gestor * const me) {
	return me->cola;
}

void gestor_enviar_texo(Gestor * const me,char * mensaje, xQueueHandle cola){



}

void gestor_imprimir_texto(Gestor * const me,char * mensaje, xQueueHandle cola){



}

void gestor_eliminar_texto(Gestor * const me,char mensaje[], xQueueHandle cola){



}

