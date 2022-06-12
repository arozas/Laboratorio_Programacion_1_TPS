/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "menu.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

// *************************************** STRING LENGTH **************************************
#define NAME_LENGTH 51
#define FLYCODE_LENGTH 15
// ************************************** ISEMPTY STATUS **************************************
#define TRUE 1
#define FALSE 0
#define UNREGISTERED -1
// *************************************** FLIGHT STATUS **************************************
#define SCHEDULED 1
#define DELAYED 2
#define LANDED 3
#define IN_AIR 4
// ************************************** PASSENGER TYPES **************************************
#define ECONOMY_CLASS 1
#define FIRST_CLASS 2
#define EXECUTIVE_CLASS 3
// *************************************** OTHER DEFINES  **************************************
#define RETRIES 3
#define MAX_PRICE 1000000
#define MIN_PRICE 2000

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[4];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char*apellidoStr,char* precioStr, char* tipoPasajeroStr,char* codigoVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setData(Passenger* this);

int Passenger_sortById(void* pElementOne,void* pElementTwo);
int Passenger_sortByName(void* pElementOne,void* pElementTwo);
int Passenger_sortByLastName(void* pElementOne,void* pElementTwo);
int Passenger_sortByPrice(void* pElementOne,void* pElementTwo);
int Passenger_sortByPassengerType(void* pElementOne,void* pElementTwo);
int Passenger_sortByFlycode(void* pElementOne,void* pElementTwo);

#endif /* PASSENGER_H_ */
