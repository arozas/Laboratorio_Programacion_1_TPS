#include "LinkedList.h"
#include "Passenger.h"
#include "Flight.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFlightsFromText(char* path , LinkedList* pArrayListFlights);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_loadFlightsFromBinary(char* path , LinkedList* pArrayListFlights);
int controller_addPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlights);
int controller_editPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlights);
int controller_removePassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlights);
int controller_ListPassenger(LinkedList* pArrayListPassenger, LinkedList* pArrayListFlights);
int controller_ListFlights(LinkedList* pArrayListFlights);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveFlightsAsText(char* path , LinkedList* pArrayListFlights);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_saveFlightAsBinary(char* path , LinkedList* pArrayFlights);
int controller_searchLastId(LinkedList* pArrayListPassenger);
void controller_printPassenger(Passenger* this, LinkedList* flightList);
void controller_printFlight(Flight* this);
Passenger* controller_searchPassengerId(LinkedList* pArrayListPassenger,int idSearch);
Flight* controller_searchFlycode(LinkedList* pArrayFlights,char* passengerFlycode);
int controller_changeAllFlycodes(LinkedList* pArrayListPassenger, LinkedList* pArrayFlights, char* oldFlyCode, char* newFlyCode);


