/*
 * eFlight.h
 *
 * Created on: 5 may. 2022
 * Author: Alejandro Alberto Martín Rozas  - División H.
 * Esta bilioteca contiene los datos de la estructura eFlights
 * Versión 1.0 del 13 de Mayo de 2022.
 * */

#ifndef FLIGHT_H_
#define FLIGHT_H_
// *************************************** STRING LENGTH **************************************
#define FLYCODE_LENGTH 10
// ************************************** ISEMPTY STATUS **************************************
#define TRUE 1
#define FALSE 0
#define UNREGISTERED -1
// *************************************** FLIGHT STATUS **************************************
#define SCHEDULED 1
#define DELAYED 2
#define DEPARTED 3
#define IN_AIR 4
#define EXPECTED 5
#define	DIVERTED 6
#define RECOVERY 7
#define LANDED 8
#define ARRIVED 9
#define CANCELLED 10
#define PAST_FLIGHT 11
// *************************************** OTHER DEFINES  **************************************
#define RETRIES 3
#define MAX_PRICE 1000000
#define MIN_PRICE 2000

#include "menu.h"
#include "input.h"

typedef struct
{
	char codigoVuelo[FLYCODE_LENGTH];
	int estadoVuelo;

}Flight;

Flight* Flight_new();
Flight* Flight_newParametros(char* flycode,char* codigoVuelo);
void Flight_delete(Flight* this);

int Flight_setId(Flight* this,int codigoVuelo);
int Flight_getId(Flight* this,int* codigoVuelo);

int Flight_setNombre(Flight* this,char* estadoVuelo);
int Flight_getNombre(Flight* this,char* estadoVuelo);

int Flight_setData(Flight* this);


#endif /* FLIGHT_H_ */
