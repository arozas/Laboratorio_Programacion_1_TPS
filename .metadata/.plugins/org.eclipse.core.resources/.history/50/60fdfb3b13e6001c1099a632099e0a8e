/*
 * eFlight.h
 *
 * Created on: 5 may. 2022
 * Author: Alejandro Alberto Martín Rozas  - División H.
 * Esta bilioteca contiene los datos de la estructura eFlights
 * Versión 1.0 del 13 de Mayo de 2022.
 * */

#ifndef EFLIGHT_H_
#define EFLIGHT_H_
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
	char flycode[FLYCODE_LENGTH];
	int statusFlight;

	int id;
	int isEmpty;

}eFlight;

int eFlight_init(eFlight eFlightList[], int length);
int eFlight_searchEmptyIndex(eFlight toSearchStruc[], int length);
int eFlight_searchUsedIndex(eFlight toSearchStruc[], int length);
void eFlight_printOne(eFlight toPrintStruc);
int eFlight_printAll(eFlight toPrintStruc[], int length);
int eFlight_create(eFlight *flightList);
int eFlight_searchIndexId(eFlight toSearchStruc[], int length);
int eFlight_searchIndexFlycodeStatus(eFlight toSearchStruc[], int length, char flycode[], int status);

#endif /* EFLIGHT_H_ */
