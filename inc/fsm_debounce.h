#ifndef PROGS_EJERCICIO1_RTOS2_INC_FSM_DEBOUNCE_H_
#define PROGS_EJERCICIO1_RTOS2_INC_FSM_DEBOUNCE_H_

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

typedef enum
{
    STATE_BUTTON_UP,
    STATE_BUTTON_DOWN,
    STATE_BUTTON_FALLING,
    STATE_BUTTON_RISING
} fsmButtonState_t;

void fsmButtonError( void );
void fsmButtonInit( void );
void fsmButtonUpdate( gpioMap_t tecla );
void buttonPressed( void );
void buttonReleased( gpioMap_t tecla );
void mensaje_al_presionar_tecla(gpioMap_t tecla, portTickType tiempoPresionado);

fsmButtonState_t fsmButtonState;

TickType_t tiempo_down;
TickType_t tiempo_up;
TickType_t tiempo_diff;

#endif /* PROGS_EJERCICIO1_RTOS2_INC_FSM_DEBOUNCE_H_ */
