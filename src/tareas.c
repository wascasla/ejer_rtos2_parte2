#include "FreeRTOS.h"
#include "queue.h"
#include "sapi.h"
#include "fsm_debounce.h"
#include "tareas.h"
#include "string.h"

extern xQueueHandle cola;

// Tarea A: Encender periódicamente un LED. Cada vez que el LED encienda, se deberá enviar un mensaje "LED ON"
void tarea_A(void* taskParmPtr) {
	// ---------- CONFIGURACIONES ------------------------------

	// ---------- REPETIR POR SIEMPRE --------------------------

	TickType_t tiempo_inicio;
	tiempo_inicio = xTaskGetTickCount();
	const char mensaje[] = "LED ON"; // Mensaje a enviar, de 7 caracteres

	while (1) {
		gpioToggle( LEDB );

		portENTER_CRITICAL ( ); 			// Entrada a seccion critica

		char * p = pvPortMalloc(7);         // malloc

		portEXIT_CRITICAL ( );				// Salida de seccion critica

		if (p != NULL){

			memcpy(p,mensaje, 7);       // Inicializo el mensaje nuevo

			xQueueSend(cola, (void *) &p, portMAX_DELAY); // Envío en la cola el puntero al nuevo mensaje
		}

		//cada 6 segundos
		vTaskDelayUntil(&tiempo_inicio, 6000 / portTICK_RATE_MS);
	}

	vTaskDelete(NULL);
}



// tarea tecla
void tarea_B(void* taskParmPtr) {
	fsmButtonInit();

	//gpioMap_t* tecla = (gpioMap_t*) taskParmPtr;
	tTecla* config = (tTecla*) taskParmPtr;
	printf("INIT\r\n");

	// ---------- REPETIR POR SIEMPRE --------------------------
	while (1) {

			fsmButtonUpdate(config->tecla);


		//fsmButtonUpdate(TEC1);
		vTaskDelay( 1 / portTICK_RATE_MS );

	}
}


// Recibe los mensajes, los imprime, y libera la memoria
void tarea_C(void* taskParmPtr) {
	// ---------- CONFIGURACIONES ------------------------------

	// ---------- REPETIR POR SIEMPRE --------------------------

	char * mensaje;

	while(1) {
		xQueueReceive(cola, &mensaje, portMAX_DELAY);

		printf("Mensaje: %s\r\n", mensaje);

		portENTER_CRITICAL ( ); 			// Entrada a seccion critica
		vPortFree(mensaje);
		portEXIT_CRITICAL ( );				// Salida de seccion critica

   }
}

// Recibe los mensajes, y descarta
void tarea_D(void* taskParmPtr) {
	// ---------- CONFIGURACIONES ------------------------------

	// ---------- REPETIR POR SIEMPRE --------------------------

	char * mensaje;

	while(1) {
		xQueueReceive(cola, &mensaje, portMAX_DELAY);

		portENTER_CRITICAL ( ); 			// Entrada a seccion critica
		vPortFree(mensaje);
		portEXIT_CRITICAL ( );				// Salida de seccion critica

   }
}
